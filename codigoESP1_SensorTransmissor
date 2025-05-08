#include <WiFi.h>
#include <esp_now.h>
#include <DHT.h>
#include <ArduinoJson.h>

#define DHTPIN 14
#define DHTTYPE DHT11  // ou DHT11 se for o seu caso
DHT dht(DHTPIN, DHTTYPE);

String node_id = "10-1";
int msg_counter = 0;
uint8_t gateway_mac[] = {0xCC, 0xDB, 0xA7, 0x3F, 0xB8, 0xD8}; // <- trocar pelo MAC do ESP2

void onSend(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Mensagem enviada: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Sucesso" : "Falha");
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("Erro ao iniciar ESP-NOW");
    return;
  }

  esp_now_register_send_cb(onSend);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, gateway_mac, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (!esp_now_is_peer_exist(gateway_mac)) {
    esp_now_add_peer(&peerInfo);
  }
}

void loop() {
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro ao ler sensor!");
    delay(2000);
    return;
  }

  StaticJsonDocument<128> doc;
  doc["ID"] = node_id;
  doc["contador"] = msg_counter++;
  doc["temperatura"] = temp;
  doc["umidade"] = umid;
  doc["controle"] = true;

  char buffer[128];
  serializeJson(doc, buffer);

  esp_now_send(gateway_mac, (uint8_t *)buffer, strlen(buffer) + 1);

  delay(5000); // envia a cada 5 segundos
}
