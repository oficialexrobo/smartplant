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
}