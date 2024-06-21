#include "esp32-hal.h"
#ifndef SmartPlant_h
#define SmartPlant_h
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
class Ultrasonic {
public: 
  Ultrasonic(int trigger, int echo);
  void init();
  float distance();
private:
  int trigger;
  int echo;
};
/**
*/
class Thread {
public:
  void setCallback(void (*callback)());
  void run();
  void delayedWithoutFreeze(int ms);
private:
  void (*callback)();
  unsigned long startMilis;
  unsigned long delay;
};
/**
*/
class Unit {
public:
  static unsigned int millisInSeconds(unsigned int millis);
};
/**
*/
class Extensions {
public:
  void init();
  void toggleLed(unsigned long millis);
  void log(unsigned long currentMillis, Pin lightSensor, Pin soilSensor, Pin rainSensor);
private:
  Pin *incorporatedLed;
};
}
#endif