#include "WiFi.h"
// MY LIBS
#include "Smartplant.h"
//SET NAMESPACES
using namespace smartplant;
//GLOBALS PINS
Pin lightSensor(13);
Pin rainSensor(33);
Pin soilSensor(14);
Ultrasonic ultrasonic(4, 32);

Extensions extensions;

//NETWORK SETTINGS
const char* SSID = "moto100";
const char* PASSWD = "}KV-OI8v";
const char* MQTT_SERVER = "tcp://192.168.185.242:1883";  //IN CASE OF THIS GATEWAY CHANGES, AKS TO SOMEONE CONNECT TO NETWORK BY OTHER DEVICE AND SEE THE NEW IP

void initPins() {
  lightSensor.pinInput();
  rainSensor.pinInput();
  soilSensor.pinInput();
  ultrasonic.init();
}

void setup() {
  initPins();
  extensions.init();
  Serial.begin(9600);
  delay(10);
}

void loop() {
  int currentMilis = millis();
  extensions.toggleLed(currentMilis);
  extensions.log(currentMilis, lightSensor, soilSensor, rainSensor);
}
