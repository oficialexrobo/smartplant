// MY LIBS
#include "Smartplant.h"
#include "Time.h"
#include "Extensions.h"
//SET NAMESPACES
using namespace smartplant;
using namespace synctime;
using namespace extensions;
//GLOBALS PINS
Pin lightSensor(12); // CHANGE TO 13 ???  BECAUSE 12 HAS A BOOT BEHAVIOUR EFFECT
BehaviourDHT sensorDHT(33); // SEE IF 33 IS OK
Pin soilSensor(14); // SEE IF 14 IS OK

void setup() {
  incorporatedLed.pinOutput();
  Serial.begin(9600);
}

void loop() {
  int currentMilis = millis();
  toggleLed(currentMilis);
  extensions::log(currentMilis, lightSensor, soilSensor, sensorDHT);
}
