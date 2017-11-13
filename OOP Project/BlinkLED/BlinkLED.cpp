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
}

void BlinkLED::doBlink() {
  int ledState = LOW;
  unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  
  if ((ledState == HIGH) && (currentMillis - previousMillis >= _onTime))
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(ledPin, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= _offTime))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);   // Update the actual LED
  }
}

