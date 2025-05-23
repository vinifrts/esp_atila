#include <WiFi.h>
#include <math.h>

const char* ssid = "ESP_AP";          
const char* password = "12345678";   

const int ledPin = 2; 

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);  

  WiFi.begin(ssid, password);  // p conectar ao Access Point

  Serial.print("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado ao AP!");
}

void loop() {
  long rssi = WiFi.RSSI();  // pega o valor do RSSI

  // Calcula a distância com base no RSSI (modelo empírico)
  float A = -69;  // rssi a 1 metro (estimativa)
  float n = 2.0;  // fator de perda
  float distancia = pow(10, (A - rssi) / (10 * n));

  Serial.print("RSSI: ");
  Serial.print(rssi);
  Serial.print(" dBm | Distância estimada: ");
  Serial.print(distancia);
  Serial.println(" metros");

  // ajusta o tempo do delay baseado na distância
  int delayTime;

  if (distancia < 1.0) {
    delayTime = 1000; // Muito perto = pisca devagar
  } else if (distancia < 2.0) {
    delayTime = 500;  // Distância média = pisca rápido
  } else {
    delayTime = 50;   // Distância grande = pisca muito rápido
  }

  // piscar o LED conforme a distância
  digitalWrite(ledPin, HIGH);
  delay(delayTime / 2);
  digitalWrite(ledPin, LOW);
  delay(delayTime / 2);
}
