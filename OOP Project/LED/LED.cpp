LED::LED(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void LED::turnON(int millisec) {
  digitalWrite(_pin, HIGH);
  delay(millisec);
}

void LED::turnOFF(int millisec) {
  digitalWrite(_pin, LOW);
  delay(millisec);
}

void LED::turnON() {
  digitalWrite(_pin, HIGH);
}

void LED::turnOFF() {
  digitalWrite(_pin, LOW);
}
