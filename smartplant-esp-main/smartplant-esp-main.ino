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
//GLOBALS VARIABLES
char dataString[19] = "0,0,0,0,0,0";  //dataString IS A STRING TO TRASPORT DATA BETWEEN ESP AND SOCKET OR CLIENT
//TOGGLE COMPONENTS STATE
bool ledState = false;
bool pumpState = false;
//NETWORK SETTINGS
const char* SSID = "moto100";
const char* PASSWD = "WWnc,3(8elz;)2l%O#JPR/?$ct8b8Xjz";
IPAddress gateway;

//WEBSERVER && || SOCKET
AsyncWebServer server(80);
AsyncWebSocket ws("");

void pinAll() {
  incorporatedLed.pinOutput();
  rele.pinOutput();
  lightSensor.pinInput();
  soilSensor.pinInput();
  rainSensor.pinInput();
}

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
}
