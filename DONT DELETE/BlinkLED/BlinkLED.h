/*
   BlinkLED.h -
   Created by Dimas Sheldon, January 31,2017.
   Released into public domain
*/
#ifndef BlinkLED_h
#define BlinkLED_h

#include "Arduino.h"

class BlinkLED {
  public:
    BlinkLED(int pin, int onTime, int offTime);
    void doBlink();
	void off();
  private:
    int _pin;
	int _onTime;
	int _offTime;
	unsigned long _currentMillis;
	unsigned long _previousMillis;
	int _ledState;
};

#endif