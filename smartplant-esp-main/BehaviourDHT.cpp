#include "Smartplant.h"
//DHT sensor library by adafruit
//https://github.com/adafruit/DHT-sensor-library
#include "DHT.h"
namespace smartplant {
BehaviourDHT::BehaviourDHT(int pin) {
  this->pin = pin;
}

void BehaviourDHT::start() {
  DHT dht(11, pin);
  this->dht = &dht;
}

float BehaviourDHT::humidity() {
  return dht->readHumidity();
}

float BehaviourDHT::temperature() {
  return dht->readTemperature();
}
}