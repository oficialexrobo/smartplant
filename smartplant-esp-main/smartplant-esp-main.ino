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
//ALL PINS
Pin incorporatedLed(2);
Pin lightSensor(35);
Pin soilSensor(34);
Pin rainSensor(33);
Pin rele(27);
Pin ultrasonic(32);
//GLOBALS VARIABLES
// const int trigger = 4;
// const int echo = 32; 
//dataString IS A STRING TO TRASPORT DATA BETWEEN ESP AND SOCKET OR CLIENT
char dataString[19] = "0,0,0,0,0,0";
//TOGGLE COMPONENTS STATE
bool ledState = false;
bool pumpState = false;
// ws://host/smartplant
const char* SSID = "moto100";
const char* PASSWD = "}KV-OI8v";
IPAddress gateway;
//WEBSERVER && || SOCKET
AsyncWebServer server(80);
AsyncWebSocket ws("smartplant"); 
void pinAll() {
  // pinMode(trigger, OUTPUT);
  // pinMode(echo, INPUT);
  incorporatedLed.pinOutput();
  rele.pinOutput();
  lightSensor.pinInput();
  soilSensor.pinInput();
  rainSensor.pinInput();
  ultrasonic.pinInput();
}

//IF MAKE WEB SOCKET SERVE (setupSocket and loopSocket) DONT WORK USE WS ARDUINO CLIENT + JS SERVE

void setup() {
  pinAll();
  Serial.begin(9600);
  delay(10);
  initNetwork();
  setupSocket();
}

void loop() {
  // mainLoop();
  // testRele();
  Serial.println(ultrasonic.analogRead());
}
