#include "Time.h"
#include "esp32-hal-gpio.h"
namespace synctime {

//>>>THREAD CLASS METHODS
void Thread::setCallback(void (*callback)()) {
  startMilis = millis();
  this->callback = callback;
}
//THREAD RUN
void Thread::run() {
  callback();
}
//THREAD RUN DELAYED
void Thread::delayedWithoutFreeze(int ms) {
}

unsigned int Unit::millisInSeconds(unsigned int millis) {
  return (int)(millis / 1000);
}
}