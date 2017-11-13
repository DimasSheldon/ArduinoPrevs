#include "Lock.h"

int lockPin = 12;
Lock doorLock(lockPin);

void setup() {
  Serial.begin(38400);
}

void loop() {
  if (Serial.available() > 0) {
    for (int i = 0; i <= 5; i++) {
      Serial.println("Unlocked");
      doorLock.unlock();
      delay(1000);
      Serial.println("Locked");
      doorLock.lock();
      delay(1000);
    }

    for (int i = 0; i <= 10; i++) {
      Serial.println("Unlocked");
      doorLock.unlock();
      delay(500);
      Serial.println("Locked");
      doorLock.lock();
      delay(500);
    }

    for (int i = 0; i <= 10; i++) {
      Serial.println("Unlocked");
      doorLock.unlock();
      delay(250);
      Serial.println("Locked");
      doorLock.lock();
      delay(250);
    }

    for (int i = 0; i <= 10; i++) {
      Serial.println("Unlocked");
      doorLock.unlock();
      delay(125);
      Serial.println("Locked");
      doorLock.lock();
      delay(125);
    }

    for (int i = 0; i <= 20; i++) {
      Serial.println("Unlocked");
      doorLock.unlock();
      delay(65);
      Serial.println("Locked");
      doorLock.lock();
      delay(65);
    }
  }
}
