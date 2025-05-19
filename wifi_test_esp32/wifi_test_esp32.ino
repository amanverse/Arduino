#include <WiFi.h>

const char* ssid = ""; // ssid name
const char* password = ""; // ssid password

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your main code goes here
  // For example, you might want to send data to an MQTT broker,
  // receive data from a web server, or control other devices.
}