#include "Lock.h"

int lockPin = 12;
Lock doorLock(lockPin);

char command = '\0';

void setup() {
  Serial.begin(38400);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    if (command == '1') {
      Serial.println("Unlocked");
      doorLock.unlock();
    }
    else {
      Serial.println("Locked");
      doorLock.lock();
    }
  }
}
