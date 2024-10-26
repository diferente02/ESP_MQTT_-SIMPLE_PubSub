# ESP_MQTT_-SIMPLE_PubSub
Este script é um programa para um microcontrolador ESP8266 que utiliza a conexão WiFi e o protocolo MQTT para comunicação com um servidor MQTT (também conhecido como "broker"). Aqui está uma explicação sobre o funcionamento dele:

1. **Objetivo**: O programa conecta o ESP8266 a uma rede WiFi e a um broker MQTT específico (mqtt.eclipseprojects.io). Ele envia uma mensagem ao broker (função "publish") e recebe mensagens (função "subscribe"). Dependendo da mensagem recebida, o ESP8266 acende ou apaga um LED.

2. **Configurações**:
   - A rede WiFi é configurada com o nome da rede (SSID) e senha.
   - É utilizado o broker MQTT `mqtt.eclipseprojects.io`, e as credenciais de conexão e tópicos para comunicação são configurados.

3. **Funções Principais**:
   - **Conexão WiFi**: A função de conexão WiFi tenta conectar o ESP8266 à rede.
   - **Callback MQTT**: Quando uma mensagem é recebida no tópico MQTT inscrito, o ESP8266 verifica o conteúdo:
     - `0`: Apaga o LED conectado ao pino `D0`.
     - `1`: Acende o LED.
   - **Loop Principal**: Garante que a conexão com o broker e o WiFi sejam mantidas e publica/inscreve mensagens conforme configurado.

Esse script permite a comunicação bidirecional simples entre o ESP8266 e um servidor MQTT, controlando um LED de forma remota conforme as mensagens recebidas.

# ============ PROTOCOLO MQTT ==========
O MQTT (Message Queuing Telemetry Transport) é um protocolo de comunicação leve usado principalmente em redes de Internet das Coisas (IoT). Ele facilita a troca de dados entre dispositivos com recursos limitados (como sensores e atuadores) em redes de baixa largura de banda e alta latência. Abaixo estão os conceitos principais que explicam o funcionamento do MQTT:

### 1. **Arquitetura de Publicação e Assinatura (Pub/Sub)**
   - No MQTT, há dois papéis principais: o *publisher* (publicador) e o *subscriber* (assinante).
   - Os *publishers* enviam mensagens a um *broker* (servidor) em tópicos específicos, sem a necessidade de saber quais dispositivos irão receber as mensagens.
   - Os *subscribers* se inscrevem nesses tópicos e recebem as mensagens quando o *publisher* publica algo novo. Eles não precisam saber a origem das mensagens, apenas o tópico de interesse.     
<img src="https://github.com/user-attachments/assets/e21fd44d-f86d-4835-b770-e8e1e79a9920" alt="drawing" width="250"/>

### 2. **Tópicos**
   - Um tópico é como uma “categoria” ou “canal” para onde as mensagens são enviadas. É uma string hierárquica, como "casa/quarto/temperatura", que ajuda a organizar as mensagens por assunto.
   - Assinantes podem se inscrever em tópicos específicos ou em grupos de tópicos, como "casa/#" para receber todas as mensagens da casa.

### 3. **Broker**
   - O broker é o servidor que gerencia o tráfego de mensagens entre publicadores e assinantes. Ele é responsável por receber as mensagens dos publicadores e entregá-las aos assinantes dos tópicos correspondentes.
   - Os brokers também gerenciam sessões de clientes, mantêm mensagens de acordo com o nível de qualidade de serviço (QoS) e garantem a entrega de mensagens conforme as regras do protocolo.

# ======== CONECTANDO AO CELULAR ========
 - Para conectar o celular ao broker foi instalado no dispositivo o aplicativo "MyMQTT",mas acredito que pra qualquer aplicativo relacionado a protocolo mqtt seja a mesma configuração.No aplicativo deve-se colocar em Host e Port o mesmo link e a mesma porta do broker que foi passado ao ESP


