#ifndef Time_h
#define Time_h
namespace synctime {
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
class Unit {
public:
  static unsigned int millisInSeconds(unsigned int millis);
};
}
#endif