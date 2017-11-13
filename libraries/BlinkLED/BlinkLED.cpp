/*
   BlinkLED.h -
   Created by Dimas Sheldon, January 31,2017.
   Released into public domain
*/
#include "BlinkLED.h"

BlinkLED::BlinkLED(int pin, int onTime, int offTime) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _onTime = onTime;
  _offTime = offTime;
  _previousMillis = 0;
  _ledState = LOW;
}

void BlinkLED::doBlink() {
  _currentMillis = millis();

  if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime))
  {
    _ledState = LOW;  // Turn it off
    _previousMillis = _currentMillis;  // Remember the time
    digitalWrite(_pin, _ledState);  // Update the actual LED
  }
  else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime))
  {
    _ledState = HIGH;  // turn it on
    _previousMillis = _currentMillis;   // Remember the time
    digitalWrite(_pin, _ledState);   // Update the actual LED
  }
}