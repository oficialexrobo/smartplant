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

// ws://192.168.185.17/smartplant
AsyncWebSocket ws("smartplant");

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

bool ledState = false;
bool pumpState = false;

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
  const int humidity = map(soilSensor.readAnalog(), 0, 4095, 0, 100);
  const int light = map(lightSensor.readAnalog(), 0, 4095, 0, 100);
  const int rain = map(rainSensor.readAnalog(), 0, 4095, 0, 100);
  const int waterQtd = map(distance(), 0, 4095, 0, 100);

  if (ledState) {
    toggleLed(currentMilis);
  }
  log(currentMilis, light, humidity, rain, waterQtd);
  char text[19];
  //ORDER -> humidity, light, rain, water,ledState,pumpState
  sprintf(text, "%d,%d,%d,%d,%d,%d", humidity, light, rain, waterQtd, ledState ? 1 : 0, pumpState ? 1 : 0);
  ws.textAll("text");
  delay(2000);
  if (pumpState) {
    rele.write(LOW);
    delay(5000);
    pumpState = false;
    rele.write(HIGH);
  }
}
