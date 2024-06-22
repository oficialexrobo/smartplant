void initNetwork() {
  //NETWORK SETTINGS
  IPAddress ip(192, 168, 185, 17);
  //CHECK IF THIS IP STILL RIGHT
  IPAddress gateway(192, 168, 185, 242);
  IPAddress mask(255, 255, 255, 0);
  IPAddress dns0(8, 8, 8, 8);
  IPAddress dns1(8, 8, 4, 4);
  if (!WiFi.config(ip, gateway, mask)) {
    Serial.println("Error on setup IP");
    ESP.restart();
  }
  WiFi.begin(SSID, PASSWD);
  WiFi.setAutoReconnect(true);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    int currentMilis = millis();
    if (millisInSeconds(currentMilis) > 20) {
      ESP.restart();
    }
  }
}