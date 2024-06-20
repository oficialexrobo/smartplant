// MY LIBS
#include "Smartplant.h"
#include "Time.h"
#include "Extensions.h"
//SET NAMESPACES
using namespace smartplant;
using namespace synctime;
using namespace extensions;
//GLOBALS PINS
Pin lightSensor(13); 
Pin rainSensor(33); 
Pin soilSensor(14);

void setup() {
  incorporatedLed.pinOutput();
  Serial.begin(9600);
}

void loop() {
  int currentMilis = millis();
  toggleLed(currentMilis);
  extensions::log(currentMilis, lightSensor, soilSensor,rainSensor);
}
