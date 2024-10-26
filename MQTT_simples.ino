/* 
Este é um programa que estabelece uma conexão wifi e se conecta com um broker mqtt.eclipseprojects.io através do protocolo mqtt.
Nesse program o ESP manda apenas uma mensagem como publish 
e e recebe mensagem como subscribe.
Se receber 0 ou 1 apaga ou acende o led respectivamente

*/
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define led D0

// =================================== definindo parametros ==========================================
// Parametros de conexão wifi
const char* ssid = "*************"; // NOME DA REDE WIFI
const char* password = "*************"; // SENHA DA REDE WIFI

// link do broker MQTT
const char* mqtt_server = "*************"; // LINK DO BROKER MQTT

// wifi está associado a quem 
WiFiClient nodemcuClient;
PubSubClient client(nodemcuClient);

// mensagens
const char* topicoMensagem = "Hello word";
const char* mensagem_antiga; // variavel apenas de comparação

// =============================== void setup ========================================================
void setup(void)
{
  Serial.begin(9600);    // monitor Serial

  // outputs dos componentes eletrônicos
  pinMode(led, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT); // led interno do ESP

  // funções de conexão wifi e mqtt
  conectar_wifi();  // chamando a função que conecta ao wifi
  client.setServer(mqtt_server, 1883); //chamando a função que conecta o ESP ao broker
  client.setCallback(callback); // chamando a função que recebe os publish's
}

// ===================================== void loop ===================================================
void loop() {
  if(!client.connected()){
    reconectarMQTT(); // chamando função que reconecta ao broker caso o esp se desconecte
  }
  
  publicar_mensagem();
   
  client.subscribe("inTopic"); // definindo qual o topico que lê o subscribe
  client.setCallback(callback); // chamando a função responsavel por receber o subscribe 
  client.loop(); // código necessária para a função callback
}

// ============================== Função conectando ao wifi ===========================================
void conectar_wifi(){
  // Conectar ao wifi
  WiFi.begin(ssid, password);

  // aguardando conexão
  Serial.println();
  Serial.print("conectando");
  
  // enquanto não conectar ao wifi colocar ...... na tela
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  digitalWrite(led, HIGH);
  delay(5000);

  digitalWrite(led, LOW);
}

// ================================== função reconectar MQTT ===============================================
void reconectarMQTT(){
  while(!client.connected()){    // se desconectar
    client.connect("ESP8266");   // reestabelece uma conexão, necessário dar um nome para esse client
  }
}

// =================================== ENVIAR MENSAGEM =================================================
void publicar_mensagem(){
  if(topicoMensagem != mensagem_antiga){ // compara a mensagem com a antiga e só publica a mensagem se ela for nova 
    //             topico       mensagem     
  client.publish("outTopic", topicoMensagem); // código que publica a mensagem
  mensagem_antiga = topicoMensagem;    // só pra falar que essa mensagem já foi publicada
  Serial.println("mensagem publicada");
  }
  
}

// =================================== RECEBER MENSAGEM =================================================
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Messagem recebida [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println();
  
  // esse for aqui é para mostrar a mensagem toda, parece que o protocolo mqtt só entende byte 
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

 // parte responsavel por apagar e acender o led 
  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    client.publish("outTopic", "led acesso");
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
    client.publish("outTopic", "led apagado");
  }

}
