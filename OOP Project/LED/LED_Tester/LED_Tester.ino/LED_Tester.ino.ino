#include "LED.h"

int pin = 13;
LED led1(pin);

void setup() {
}

void loop() {
  led1.turnON(100);
  led1.turnOFF(150);
  led1.turnON(250);
  led1.turnOFF(250);
  led1.turnON(100);
  led1.turnOFF(50);
  led1.turnON(50);
  led1.turnOFF(100);
  led1.turnON(250);
  led1.turnOFF(150);
  led1.turnON(250);
  led1.turnOFF(150);
  led1.turnON(1000);
  led1.turnOFF(500);
  led1.turnON(350);
  led1.turnOFF(350);
  led1.turnON(500);
  led1.turnOFF(500);
  led1.turnON(250);
  led1.turnOFF(250);
  led1.turnON(100);
  led1.turnOFF(150);
}
