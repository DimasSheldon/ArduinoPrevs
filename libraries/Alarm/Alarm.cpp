/*
   Alarm.cpp -
   Created by Dimas Sheldon, January 31,2017.
   Released into public domain
*/
#include "Alarm.h"

Alarm::Alarm(int pin, int onTime, int offTime, int freq) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _onTime = onTime;
  _offTime = offTime;
  _freq = freq;
  _previousMillis = 0;
  _alarmState = false;
}

void Alarm::on() {
  _currentMillis = millis();

  if ((_alarmState == false) && (_currentMillis - _previousMillis >= _onTime))
  {
    _alarmState = true;  // Turn it off
    _previousMillis = _currentMillis;  // Remember the time
	tone(_pin, _freq);
  }
  else if ((_alarmState == true) && (_currentMillis - _previousMillis >= _offTime))
  {
    _alarmState = false;  // turn it on
    _previousMillis = _currentMillis;   // Remember the time
    noTone(_pin);
  }
}

void Alarm::off() {
	noTone(_pin);
}