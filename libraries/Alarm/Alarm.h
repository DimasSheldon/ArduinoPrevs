/*
   Alarm.h -
   Created by Dimas Sheldon, January 31,2017.
   Released into public domain
*/
#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"

class Alarm {
  public:
    Alarm(int pin, int onTime, int offTime, int freq);
    void on();
	void off();
  private:
    int _pin;
	int _onTime;
	int _offTime;
	int _freq;
	unsigned long _currentMillis;
	unsigned long _previousMillis;
	boolean _alarmState;
};

#endif