#include <WiFi.h>

const char* ssid = ""; // Change this
const char* password = ""; // Change this
const char* host = ""; // Change this to the IP of the sender device

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("Connected to WiFi");

  client.connect(host, 80);
}

void loop() {
  if (client.connected()) {
    if (Serial.available()) {
      client.write(Serial.read());
    }
    if (client.available()) {
      Serial.write(client.read());
    }
  }
  else {
    Serial.println("Disconnected from server");
    delay(5000);
    ESP.restart();
  }
}
