class Thread {
public:
  void setCallback(void (*callback)()) {
    startMilis = millis();
    this->callback = callback;
  } 
  void run() {
    callback();
  }
  void delayedWithoutFreeze(int ms){}
private:
  void (*callback)();
  unsigned long startMilis;
  unsigned long delay;
};

int millisInSeconds(unsigned int millis) {
  return (int)(millis / 1000);
}