#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  // Modo STA é obrigatório antes de pedir o MAC
  WiFi.mode(WIFI_STA);
  delay(1000); // dá um tempinho pro Wi-Fi inicializar

  Serial.println("Endereço MAC do ESP32:");
  Serial.println(WiFi.macAddress());
}

void loop() {
}
