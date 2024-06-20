#include <WiFi.h>
//GLOBALS PINS
class Pin {
public:
  Pin(int pin);
  void pinOutput();
  void pinInput();
  int read();
  int readAnalog();
  void write(int value);
  void writeAnalog(int value);
private:
  int pin;
};
Pin incorporatedLed(2);
Pin lightSensor(13);
Pin soilSensor(14);
Pin rainSensor(33);
Pin rele(27);
//GLOBALS VARIABLES
const int trigger = 4;
const int echo = 32;
//
const char* SSID = "moto100";
const char* PASSWD = "}KV-OI8v";
const char* MQTT_SERVER = "tcp://192.168.1.10:1883";

//IDEA ** PUT ALL IN SETUP AND USE LOOP ONLY TO UPDATE THE APP INFOS
void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  incorporatedLed.pinOutput();
  rele.pinOutput();
  lightSensor.pinInput();
  soilSensor.pinInput();
  rainSensor.pinInput();
  Serial.begin(9600);
  delay(10);
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

bool releToggle = false;

void loop() {
  int currentMilis = millis();
  toggleLed(currentMilis);
  log(currentMilis, lightSensor.readAnalog(), soilSensor.readAnalog(), rainSensor.readAnalog());


  // if (millisInSeconds(currentMilis) > 60 * 30) {
  //   ESP.restart();
  // }
}
