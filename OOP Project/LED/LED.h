#ifndef LED_h
#define LED_h

#include "Arduino.h"

class LED {
  public:
    LED(int pin);
    void turnON(int millisec);
    void turnOFF(int millisec);
    void turnON();
    void turnOFF();
  private:
    int _pin;
};
