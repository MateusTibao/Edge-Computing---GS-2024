// Biblioteca
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Pinos dos sensores
#define DHTPIN 4             // Pino do sensor DHT22 (temperatura e umidade)
#define DHTTYPE DHT22        // Tipo do sensor DHT
DHT dht(DHTPIN, DHTTYPE);    // Inicialização do sensor DHT
#define LDR_PIN 34           // Pino do sensor de luminosidade (LDR)
#define PRESENCE_PIN 19      // Pino do sensor de presença

// Configurações WiFi
const char* ssid = "Wokwi-GUEST";  // Nome da rede WiFi
const char* password = "";         // Senha da rede WiFi

// Configurações MQTT
const char* mqtt_server = "test.mosquitto.org";  // Endereço do servidor MQTT
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;            // Timestamp da última mensagem enviada
unsigned long lastPresenceMsg = 0;    // Timestamp da última mensagem de presença
unsigned long lastPresenceWindow = 0; // Timestamp da última verificação de presença
float tempSum = 0;                    // Soma das leituras de temperatura
int tempCount = 0;                    // Contador das leituras de temperatura
int ldrSum = 0;                       // Soma das leituras de luminosidade
int ldrCount = 0;                     // Contador das leituras de luminosidade
int presenceCount = 0;                // Contador das leituras de presença

// Função para conectar ao WiFi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// Callback para receber mensagens MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
}

// Função para reconectar ao servidor MQTT se a conexão for perdida
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado");
      client.publish("/ThinkIOT/Publish", "Bem-vindo");
      client.subscribe("/ThinkIOT/Subscribe");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

// Configurações iniciais
void setup() {
  Serial.begin(115200);
  setup_wifi();                        // Conectar ao WiFi
  client.setServer(mqtt_server, 1883); // Configurar servidor MQTT
  client.setCallback(callback);        // Configurar callback para mensagens MQTT
  
  Serial.println("Inicializando sensores...");
  dht.begin();                         // Inicializar sensor DHT
  pinMode(LDR_PIN, INPUT);             // Configurar pino do LDR como entrada
  pinMode(PRESENCE_PIN, INPUT);        // Configurar pino do sensor de presença como entrada
  Serial.println("Sensores inicializados.");
}

// Loop principal
void loop() {
  if (!client.connected()) {
    reconnect(); // Reconectar ao servidor MQTT se desconectado
  }
  client.loop(); // Processar mensagens MQTT

  unsigned long now = millis();
  
  // Leitura de temperatura e luminosidade a cada 10 segundos
  if (now - lastMsg > 10000) {
    lastMsg = now;
    
    float temperature = dht.readTemperature(); // Ler temperatura do sensor DHT
    int ldrValue = analogRead(LDR_PIN);        // Ler valor do LDR

    if (isnan(temperature)) {
      Serial.println("Falha ao ler o sensor DHT!");
      return;
    }

    // Acumular leituras para calcular médias
    tempSum += temperature;
    tempCount++;
    ldrSum += ldrValue;
    ldrCount++;

    // Impressões no console para apoio
    Serial.print("Leitura atual de temperatura: ");
    Serial.println(temperature);
    Serial.print("Leitura atual de luminosidade: ");
    Serial.println(ldrValue);
  }

  // Verificação de presença a cada 5 segundos
  if (now - lastPresenceWindow > 5000) {
    lastPresenceWindow = now;

    int presence = digitalRead(PRESENCE_PIN); // Ler valor do sensor de presença
    if (presence == HIGH) {
      presenceCount++; // Incrementar contador de presença se detectada
      Serial.println("Presença detectada");
    }
  }

  // Enviar médias e contagem de presença a cada 60 segundos
  if (now - lastPresenceMsg > 60000) {
    lastPresenceMsg = now;

    float tempAvg = 0;
    float ldrAvg = 0;

    if (tempCount > 0) {
      tempAvg = tempSum / tempCount; // Calcular média de temperatura
    }

    if (ldrCount > 0) {
      ldrAvg = ldrSum / ldrCount;    // Calcular média de luminosidade
    }

    // Publicar dados no servidor MQTT
    String temp = String(tempAvg, 2);
    client.publish("/ThinkIOT/temp", temp.c_str());
    String ldr = String(ldrAvg);
    client.publish("/ThinkIOT/luminosity", ldr.c_str());
    String presenceStr = String(presenceCount);
    client.publish("/ThinkIOT/presence", presenceStr.c_str());

    Serial.print("Temperatura média: ");
    Serial.println(temp);
    Serial.print("Luminosidade média: ");
    Serial.println(ldr);
    Serial.print("Contagem de presença: ");
    Serial.println(presenceStr);

    // Resetar acumuladores e contadores
    tempSum = 0;
    tempCount = 0;
    ldrSum = 0;
    ldrCount = 0;
    presenceCount = 0;
  }
}
