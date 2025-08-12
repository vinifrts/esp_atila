#include <WiFi.h>
#include <math.h>

const char* ssid = "ESP_AP";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado ao AP!");
}

void loop() {
  long rssi = WiFi.RSSI();  // força do sinal em dBm

  // formula p estimar distância
  float A = -69;  // RSSI a 1 metro (calibrável)
  float n = 2.0;  // fator de perda
  float distancia = pow(10, (A - rssi) / (10 * n));

  Serial.print("RSSI: ");
  Serial.print(rssi);
  Serial.print(" dBm | Estimado: ");
  Serial.print(distancia);
  Serial.println(" metros");

  delay(2000);
}
