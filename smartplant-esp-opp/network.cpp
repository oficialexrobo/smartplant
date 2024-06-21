#include "esp32-hal.h"
#include "Smartplant.h"
#include "WiFi.h"
namespace smartplant {
LocalNetwork::LocalNetwork(char* ssid, char* passwd, char* mqttServe) {
  this->ssid = ssid;
  this->passwd = passwd;
  this->mqttServe = mqttServe;
}
void LocalNetwork::init() {
  WiFi.begin(ssid, passwd);
  WiFi.setAutoReconnect(true);
  while (WiFi.status() != WL_CONNECTED) {
    delay(150); 
    if (Unit::millisInSeconds(millis()) > 20) {
      ESP.restart();
    }
  }
}
}