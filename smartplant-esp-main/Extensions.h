#ifndef Extensions_h
#define Extensions_h
#include "Smartplant.h"
using namespace smartplant;
namespace extensions {
static Pin incorporatedLed(2);
void toggleLed(unsigned long millis);
}
#endif