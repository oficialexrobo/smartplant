#include "esp32-hal.h"
#include "HardwareSerial.h"
#include "Smartplant.h"
namespace smartplant {
void Extensions::init() {
  Pin initLedPin(2);
  initLedPin.pinOutput();
  incorporatedLed = &initLedPin;
}
void Extensions::toggleLed(unsigned long millis) {
  if (Unit::millisInSeconds(millis) % 2 == 0) {
    incorporatedLed->write(HIGH);
  } else {
    incorporatedLed->write(LOW);
  }
}
void Extensions::log(unsigned long currentMillis, Pin lightSensor, Pin soilSensor, Pin rainSensor, Ultrasonic ultrasonic) {
  if (currentMillis % 1000 == 0 && currentMillis % 2 == 0) {
    Serial.println("=================================");
    Serial.print("Seconds running: ");
    Serial.println(Unit::millisInSeconds(currentMillis));
    Serial.print("Light: ");
    Serial.println(lightSensor.readAnalog());
    Serial.print("Soil humidity: ");
    Serial.println(soilSensor.readAnalog());
    Serial.print("Rain: ");
    Serial.println(rainSensor.readAnalog());
    Serial.print("Distance: ");
    Serial.print(ultrasonic.distance());
    Serial.println("cm");
  }
}
}