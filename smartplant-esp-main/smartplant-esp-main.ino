// MY LIBS
#include "Smartplant.h"
#include "Time.h"
#include "Extensions.h"
//SET NAMESPACES
using namespace smartplant;
using namespace synctime;
using namespace extensions;
 

//GLOBALS PINS
Pin lightSensor(12);
BehaviourDHT sensorDHT(1);
// Pin soildSensor();


void setup() {
  incorporatedLed.pinOutput();
  Serial.begin(9600);

  
}

void loop() {
  int currentMilis = millis();


  Serial.print("Seconds running: ");
  Serial.println(Unit::millisInSeconds(currentMilis));
  Serial.print("Light: ");
  Serial.println(lightSensor.readAnalog());
  Serial.print("Humidity: ");
  Serial.println(sensorDHT.humidity());
  Serial.print("Temperature: ");
  Serial.println(sensorDHT.temperature());
  toggleLed(currentMilis);
}
