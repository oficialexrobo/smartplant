#include "Extensions.h"
#include "esp32-hal-gpio.h"
#include "Time.h"
using namespace synctime;
namespace extensions {
void toggleLed(unsigned long millis) {
  if (Unit::millisInSeconds(millis) % 2 == 0) {
    incorporatedLed.write(HIGH);
  } else {
    incorporatedLed.write(LOW);
  }
}
void log(unsigned long currentMillis, Pin lightSensor, Pin soilSensor, BehaviourDHT sensorDHT) {
  if (currentMillis % 1000 == 0) {
    Serial.print("Seconds running: ");
    Serial.println(Unit::millisInSeconds(currentMillis));
    Serial.print("Light: ");
    Serial.println(lightSensor.readAnalog());
    Serial.print("Soil humidity: ");
    Serial.println(soilSensor.readAnalog());
    Serial.print("Humidity: ");
    Serial.println(sensorDHT.humidity());
    Serial.print("Temperature: ");
    Serial.println(sensorDHT.temperature());
  }
}
}