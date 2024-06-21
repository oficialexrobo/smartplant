#include "esp32-hal.h"
#include "Smartplant.h"
namespace smartplant {
void Thread::setCallback(void (*callback)()) {
  startMilis = millis();
  this->callback = callback;
}
void Thread::run() {
  callback();
}
void Thread::delayedWithoutFreeze(int ms) {
}
unsigned int Unit::millisInSeconds(unsigned int millis) {
  return (int)(millis / 1000);
}
}