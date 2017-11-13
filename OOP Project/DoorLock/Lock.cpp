/* Lock.h -
   Created by Dimas Sheldon, January 31, 2017.
   Released into public domain.
*/
#include "Lock.h"

Lock::Lock(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Lock::lock() {
  digitalWrite(_pin, LOW);
}

void Lock::unlock() {
  digitalWrite(_pin, HIGH);
}