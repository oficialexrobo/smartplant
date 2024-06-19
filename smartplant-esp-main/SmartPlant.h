#ifndef SmartPlant_h
#define SmartPlant_h
#include "DHT.h"
namespace smartplant {
/**
*/
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
/**
*/
class BehaviourDHT {
public:
  BehaviourDHT(int pin);
  void start();
  float humidity();
  float temperature();
private:
  int pin;
  DHT *dht;
};
class WifiManager {
public:
  WifiManager();
private:
};
}
#endif