# ESP_MQTT_-SIMPLE_PubSub
Um projeto que consiste em demonstrar a utilização do ESP com um protocolo MQTT
Vou ler o script que você enviou e já volto com a explicação sobre como ele funciona.

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
