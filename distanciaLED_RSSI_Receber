#include <WiFi.h>

const char* ssid = "ESP_AP";         
const char* password = "12345678";   

void setup() {
  Serial.begin(115200);
  
 
  WiFi.softAP(ssid, password);

  Serial.println("Access Point iniciado!");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("IP do AP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {

}
