<h1 align="center">
    <img alt="NextLevelWeek" title="#NextLevelWeek" src="./assets/mare cheia.svg" />
</h1>

<h3 align="center"> 
	 Maré Cheia  
</h3>

<p align="center">
  <a href="## 🎣 Problema abordado">🎣 Problema •</a>
  <a href="## 🦾 Solução proposta">🦾 Solução •</a>
  <a href="## 🚧 Protótipo">🦾 Protótipo • </a>
 <a href="## ⚙️ Configuração e execução">⚙️ Configuração e execução •  </a> 
 <a href="## ⚙️ Código fonte">⚙️ Código-fonte •</a> 
 <a href=" ## 👨🏽‍🏭👨🏽‍🔧👨🏽‍🏭 Autores">👨🏽‍🏭👨🏽‍🔧👨🏽‍🏭 Autores •</a>
 <a href="## 📝 Licença">📝 Licença •</a>
</p>


## 🎣 Problema abordado

A sobrepesca representa uma ameaça crítica aos ecossistemas marinhos, superando outras formas de degradação ambiental. A captura excessiva de peixes além do ritmo de reprodução natural causa um desequilíbrio nos ecossistemas oceânicos e leva à diminuição drástica das populações de diversas espécies. Este fenômeno afeta a biodiversidade marinha e tem implicações diretas para as comunidades que dependem dos recursos pesqueiros para sua subsistência. Implementar tecnologias inovadoras, como sensores para monitoramento em tempo real, é essencial para mitigar os efeitos da sobrepesca e garantir a sustentabilidade dos recursos pesqueiros para futuras gerações.


## 🦾 Solução proposta

Maré Cheia é um sistema de monitoramento e divulgação de dados sobre a sobrepesca e a saúde dos ecossistemas marinhos locais. Utilizando um conjunto de sensores na plataforma ESP 32 com uma carapaça impermeavél para medir parâmetros como pH, turbidez, temperatura e presença de peixes, os dados são coletados e analisados com um programa em Python. 

Em seguida, são publicados em um site baseado em React, oferecendo dashboards e textos explicativos acessíveis ao público. Este sistema resolve a falta de dados precisos, conscientização limitada, impactos socioeconômicos e a falta de controle e fiscalização, fornecendo informações críticas em tempo real para comunidades costeiras, empresas e governantes. 

A transparência e a acessibilidade dos dados promovem o engajamento comunitário e a implementação de políticas de pesca sustentável, contribuindo para a recuperação dos ecossistemas marinhos e a segurança alimentar das comunidades dependentes dos recursos pesqueiros.

## ✅ Features 
- [X] Site disponibilizando informações para usuário
- [X] Protótipo de sensores
- [X] Análise de dados
---

## 🚧 Protótipo

Essa versão trata-se de uma versão simplificada do projeto por conta das limitações de software e de praticidade. Dessa maneira, a simulação permite-nos armazenar variações de presença de peixes, turbidez da água e temperatura, inseridas durante os testes, nos sensores PIR, DHT22 e LDR, o sensor de pH não está disponível de simulação Wokwi. 

Dessa forma no sistema coleta a cada 1 minuto as média das medições, feitas a cada 5 segundos, que são enviadas para dashboards no Node-RED e na Tago.io de onde serão coletadas para análises estáticas e estudos ciênticas pelo nosso programa de análise dados em Python. Num cenário real, as médias serão coletadas a cada hora, além de ter mais conjuntos do sistema para possibilitar um maior área de estudo e uma rede de sensores.

#### Demonstração de protótipo:

- [Link para o vídeo](https://youtu.be/RugcxLep43E)

## ⚙️ Configuração e execução

#### Acessos:

- [Link para o Projeto Wokwi](https://wokwi.com/projects/399357576985434113)

- [Link para o DashBoard Tago.io](https://660218f01a37490011c7e5f7.tago.run/dashboards/info/665ce467e101fe0008a7d4fc?anonymousToken=00000000-6602-18f0-1a37-490011c7e5f7)

#### Configurar Node-Red:
- Use a opção de importar fluxo, disponível no canto esquerdo do Node-RED, e copie o arquivo JSON abaixo para copiar o fluxo do projeto.

```json 
[
    {
        "id": "ad8ac3338478bb7f",
        "type": "tab",
        "label": "Tago",
        "disabled": false,
        "info": "",
        "env": []
    },
    {
        "id": "b38cb698652164f6",
        "type": "mqtt in",
        "z": "ad8ac3338478bb7f",
        "name": "Temperatura",
        "topic": "/ThinkIOT/temp",
        "qos": "0",
        "datatype": "auto",
        "broker": "4423636a2f303e43",
        "inputs": 0,
        "x": 170,
        "y": 220,
        "wires": [
            [
                "f01474b6605cb0eb"
            ]
        ]
    },
    {
        "id": "d4991842fa9fe766",
        "type": "mqtt in",
        "z": "ad8ac3338478bb7f",
        "name": "Luminosidade",
        "topic": "/ThinkIOT/luminosity",
        "qos": "0",
        "datatype": "auto",
        "broker": "4423636a2f303e43",
        "inputs": 0,
        "x": 170,
        "y": 360,
        "wires": [
            [
                "7652022241697a04"
            ]
        ]
    },
    {
        "id": "8c7706914d682eea",
        "type": "mqtt in",
        "z": "ad8ac3338478bb7f",
        "name": "Presença",
        "topic": "/ThinkIOT/presence",
        "qos": "0",
        "datatype": "auto",
        "broker": "4423636a2f303e43",
        "inputs": 0,
        "x": 160,
        "y": 480,
        "wires": [
            [
                "c80e208f1db39084"
            ]
        ]
    },
    {
        "id": "f01474b6605cb0eb",
        "type": "json",
        "z": "ad8ac3338478bb7f",
        "name": "",
        "property": "payload",
        "action": "",
        "pretty": false,
        "x": 370,
        "y": 220,
        "wires": [
            [
                "31c19ae1bf0b7891",
                "538d5f3b9ffc3a83"
            ]
        ]
    },
    {
        "id": "7652022241697a04",
        "type": "json",
        "z": "ad8ac3338478bb7f",
        "name": "",
        "property": "payload",
        "action": "",
        "pretty": false,
        "x": 390,
        "y": 360,
        "wires": [
            [
                "fb2920e8d1221e57",
                "f8e9984f1360e6f6"
            ]
        ]
    },
    {
        "id": "c80e208f1db39084",
        "type": "json",
        "z": "ad8ac3338478bb7f",
        "name": "",
        "property": "payload",
        "action": "",
        "pretty": false,
        "x": 390,
        "y": 480,
        "wires": [
            [
                "8d3c892cb35ef816",
                "8fb0aa62dc3fa4e5"
            ]
        ]
    },
    {
        "id": "31c19ae1bf0b7891",
        "type": "ui_chart",
        "z": "ad8ac3338478bb7f",
        "name": "Temperatura",
        "group": "group1",
        "order": 1,
        "width": 0,
        "height": 0,
        "label": "Temperatura (°C)",
        "chartType": "line",
        "legend": "false",
        "xformat": "HH:mm:ss",
        "interpolate": "linear",
        "nodata": "",
        "dot": false,
        "ymin": "0",
        "ymax": "50",
        "removeOlder": 1,
        "removeOlderPoints": "",
        "removeOlderUnit": "3600",
        "cutout": 0,
        "useOneColor": false,
        "useUTC": false,
        "colors": [
            "#00bfff",
            "#00bfff",
            "#00bfff",
            "#000000",
            "#000000",
            "#000000",
            "#000000",
            "#000000",
            "#000000"
        ],
        "outputs": 1,
        "useDifferentColor": false,
        "className": "",
        "x": 570,
        "y": 140,
        "wires": [
            []
        ]
    },
    {
        "id": "fb2920e8d1221e57",
        "type": "ui_chart",
        "z": "ad8ac3338478bb7f",
        "name": "Luminosidade",
        "group": "group1",
        "order": 2,
        "width": 0,
        "height": 0,
        "label": "Luminosidade",
        "chartType": "line",
        "legend": "false",
        "xformat": "HH:mm:ss",
        "interpolate": "linear",
        "nodata": "",
        "dot": false,
        "ymin": "0",
        "ymax": "1023",
        "removeOlder": 1,
        "removeOlderPoints": "",
        "removeOlderUnit": "3600",
        "cutout": 0,
        "useOneColor": false,
        "colors": [
            "#00bfff",
            "#00bfff",
            "#00bfff"
        ],
        "outputs": 1,
        "x": 600,
        "y": 320,
        "wires": [
            []
        ]
    },
    {
        "id": "8d3c892cb35ef816",
        "type": "ui_chart",
        "z": "ad8ac3338478bb7f",
        "name": "Presença",
        "group": "group1",
        "order": 3,
        "width": 0,
        "height": 0,
        "label": "Contagem de Presença",
        "chartType": "line",
        "legend": "false",
        "xformat": "HH:mm:ss",
        "interpolate": "linear",
        "nodata": "",
        "dot": false,
        "ymin": "0",
        "ymax": "",
        "removeOlder": 1,
        "removeOlderPoints": "",
        "removeOlderUnit": "3600",
        "cutout": 0,
        "useOneColor": false,
        "colors": [
            "#00bfff",
            "#00bfff",
            "#00bfff"
        ],
        "outputs": 1,
        "x": 580,
        "y": 460,
        "wires": [
            []
        ]
    },
    {
        "id": "538d5f3b9ffc3a83",
        "type": "function",
        "z": "ad8ac3338478bb7f",
        "name": "Preparar Dados Temp",
        "func": "msg.headers = {\n    'Content-Type': 'application/json',\n    'Device-Token': '4bd702ba-55ef-47d4-ae68-fd526b0815de'\n};\n\nmsg.payload = [\n    {\n        variable: 'temperatura',\n        value: parseFloat(msg.payload)\n    }\n];\n\nreturn msg;",
        "outputs": 1,
        "timeout": "",
        "noerr": 0,
        "initialize": "",
        "finalize": "",
        "libs": [],
        "x": 580,
        "y": 240,
        "wires": [
            [
                "75d45f449f2ba7cf"
            ]
        ]
    },
    {
        "id": "f8e9984f1360e6f6",
        "type": "function",
        "z": "ad8ac3338478bb7f",
        "name": "Preparar Dados Luminosidade",
        "func": "msg.headers = {\n    'Content-Type': 'application/json',\n    'Device-Token': '4bd702ba-55ef-47d4-ae68-fd526b0815de'\n};\n\nmsg.payload = [\n    {\n        variable: 'luminosidade',\n        value: parseInt(msg.payload)\n    }\n];\n\nreturn msg;",
        "outputs": 1,
        "timeout": "",
        "noerr": 0,
        "initialize": "",
        "finalize": "",
        "libs": [],
        "x": 630,
        "y": 400,
        "wires": [
            [
                "ee952fcf57ca9e26"
            ]
        ]
    },
    {
        "id": "8fb0aa62dc3fa4e5",
        "type": "function",
        "z": "ad8ac3338478bb7f",
        "name": "Preparar Dados Presença",
        "func": "msg.headers = {\n    'Content-Type': 'application/json',\n    'Device-Token': '4bd702ba-55ef-47d4-ae68-fd526b0815de'\n};\n\nmsg.payload = [\n    {\n        variable: 'presenca',\n        value: parseInt(msg.payload)\n    }\n];\n\nreturn msg;",
        "outputs": 1,
        "timeout": "",
        "noerr": 0,
        "initialize": "",
        "finalize": "",
        "libs": [],
        "x": 590,
        "y": 520,
        "wires": [
            [
                "287e72d27ca5491c"
            ]
        ]
    },
    {
        "id": "75d45f449f2ba7cf",
        "type": "http request",
        "z": "ad8ac3338478bb7f",
        "name": "Enviar Temperatura para Tago",
        "method": "POST",
        "ret": "txt",
        "paytoqs": "ignore",
        "url": "https://api.tago.io/data",
        "tls": "",
        "persist": false,
        "proxy": "",
        "x": 890,
        "y": 240,
        "wires": [
            [
                "cf9a468b3513497a"
            ]
        ]
    },
    {
        "id": "ee952fcf57ca9e26",
        "type": "http request",
        "z": "ad8ac3338478bb7f",
        "name": "Enviar Luminosidade para Tago",
        "method": "POST",
        "ret": "txt",
        "paytoqs": "ignore",
        "url": "https://api.tago.io/data",
        "tls": "",
        "persist": false,
        "proxy": "",
        "insecureHTTPParser": false,
        "authType": "",
        "senderr": false,
        "headers": [],
        "x": 950,
        "y": 400,
        "wires": [
            [
                "32607bbbdf45afd3"
            ]
        ]
    },
    {
        "id": "287e72d27ca5491c",
        "type": "http request",
        "z": "ad8ac3338478bb7f",
        "name": "Enviar Presença para Tago",
        "method": "POST",
        "ret": "txt",
        "paytoqs": "ignore",
        "url": "https://api.tago.io/data",
        "tls": "",
        "persist": false,
        "proxy": "",
        "insecureHTTPParser": false,
        "authType": "",
        "senderr": false,
        "headers": [],
        "x": 840,
        "y": 520,
        "wires": [
            [
                "160784a687d511b1"
            ]
        ]
    },
    {
        "id": "cf9a468b3513497a",
        "type": "debug",
        "z": "ad8ac3338478bb7f",
        "name": "Debug Temp",
        "active": true,
        "tosidebar": true,
        "console": false,
        "tostatus": false,
        "complete": "true",
        "targetType": "full",
        "x": 1170,
        "y": 240,
        "wires": []
    },
    {
        "id": "32607bbbdf45afd3",
        "type": "debug",
        "z": "ad8ac3338478bb7f",
        "name": "Debug Luminosidade",
        "active": true,
        "tosidebar": true,
        "console": false,
        "tostatus": false,
        "complete": "true",
        "targetType": "full",
        "x": 1240,
        "y": 400,
        "wires": []
    },
    {
        "id": "160784a687d511b1",
        "type": "debug",
        "z": "ad8ac3338478bb7f",
        "name": "Debug Presença",
        "active": true,
        "tosidebar": true,
        "console": false,
        "tostatus": false,
        "complete": "true",
        "targetType": "full",
        "x": 1110,
        "y": 520,
        "wires": []
    },
    {
        "id": "4423636a2f303e43",
        "type": "mqtt-broker",
        "name": "Mosquitto",
        "broker": "test.mosquitto.org",
        "port": "1883",
        "clientid": "",
        "usetls": false,
        "compatmode": false,
        "keepalive": "60",
        "cleansession": true,
        "birthTopic": "",
        "birthQos": "0",
        "birthPayload": "",
        "closeTopic": "",
        "closePayload": "",
        "willTopic": "",
        "willQos": "0",
        "willPayload": ""
    },
    {
        "id": "group1",
        "type": "ui_group",
        "name": "Medições",
        "tab": "tab1",
        "order": 1,
        "disp": true,
        "width": "6",
        "collapse": false
    },
    {
        "id": "tab1",
        "type": "ui_tab",
        "name": "Monitoramento",
        "icon": "dashboard",
        "order": 1
    }
]
```

#### Simular coleta de dados:
- Para isso, basta definir diferentes parâmetros para registro dos sensores em diversos períodos de medição antes do envio do minuto completo.

#### Visualização dos Dados nos Dashboards:
- Como dito, nosso projeto permite visualização tanto em Node-RED quanto Tago.io, ambos exibem os dados retirados.

## ⚙️ Código fonte
```cpp
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


## 👨🏽‍🏭👨🏽‍🔧👨🏽‍🏭 Autores
<p align="center">
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Gh0stE11">
        <img style="border-radius: 50%;" src="https://media.licdn.com/dms/image/C4E03AQGQNxYibVc4nA/profile-displayphoto-shrink_400_400/0/1655830181624?e=1723075200&v=beta&t=rWSJ14lOO0KYwGnE_JMGTHId1k7G9h1PRCWAk9HYbtQ" width="100px;" alt=""/>
        <br />
        <sub><b>Caio Hideki</b></sub> <sub><br><b>RM 553630</b></sub>
      </a>
      <br />
      🚀
    </td>
    <td align="center">
      <a href="https://github.com/JorgeBooz00">
        <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/107008455?v=4" width="100px;" alt=""/>
        <br />
        <sub><b>Jorge Booz</b></sub> <sub><br><b>RM 552700</b></sub>
      </a>
      <br />
      🚀
    </td>
    <td align="center">
      <a href="https://github.com/MateusTibao">
        <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/143664123?v=4" width="100px;" alt=""/>
        <br />
        <sub><b>Mateus Tibao</b></sub> <sub><br><b>RM 553267</b></sub>
      </a>
      <br />
      🚀
    </td>
  </tr>
</table>
</p>
```

## 📝 Licença

Este projeto esta sobe a licença [MIT](./LICENSE).

Feito com muita vontade de aprender por [Caio Hideki](https://www.linkedin.com/in/caio-hideki-cardenas-ishizu-24208a243/), [Jorge Booz](https://www.linkedin.com/in/jorge-booz-4038a2213/) e [Mateus Tibão](https://www.linkedin.com/in/mateustibao/) 👋🏻👋🏽👋🏽 

---
