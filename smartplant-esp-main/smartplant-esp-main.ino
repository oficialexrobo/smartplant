#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncWebSocket.h>

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

// ws://192.168.185.17/smartp
AsyncWebSocket ws("smartp");

const char* SSID = "moto100";
const char* PASSWD = "}KV-OI8v";

void pinAll() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  incorporatedLed.pinOutput();
  rele.pinOutput();
  lightSensor.pinInput();
  soilSensor.pinInput();
  rainSensor.pinInput();
}


void setup() {
  //IDEA ** PUT ALL IN SETUP AND USE LOOP ONLY TO UPDATE THE APP INFOS
  pinAll();
  Serial.begin(9600);
  delay(10);
  initNetwork();

  ws.onEvent(onWebSocketEvent);
}

void loop() {
  int currentMilis = millis();
  toggleLed(currentMilis);
  log(currentMilis, lightSensor.readAnalog(), soilSensor.readAnalog(), rainSensor.readAnalog());
  
  ws.textAll(" ");

}
