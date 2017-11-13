/*
   All the resources for this project: https://www.hackster.io/Aritro
   Modified by Aritro Mukherjee
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Lock.h>
#include <Alarm.h>

int lockPin = 8;
int alarmPin = 3;
int alarmPin2 = 2;
char command = '\0';

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Alarm alarm(alarmPin, 350, 150, 1325);
Alarm alarm2(alarmPin2, 10000, 250, 1000);
Lock doorLock(lockPin);

void setup()
{
  Serial.begin(38400);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop() {
  alarm2.on();
  if (Serial.available() > 0) {
    command = Serial.read();
    switch (command) {
      case '1':
        doorLock.unlock();
        Serial.println("Unlocked for you");
        break;

      case '0':
        doorLock.lock();
        Serial.println("Relocked");
        break;

      default:
        Serial.println("Who are you?");
        doorLock.lock();
        break;
    }
  }

  else {
    alarm.off();
    if ( ! mfrc522.PICC_IsNewCardPresent())
    {
      return;
    }
    if ( ! mfrc522.PICC_ReadCardSerial())
    {
      return;
    }
    String content = "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    content.toUpperCase();

    if (content.substring(1) == "10 B0 8A 7C" ) {
      //|| content.substring(1) == "F8 08 50 39"
      Serial.println("Oh, you're home");
      doorLock.unlock();
      delay(2000);
      doorLock.lock();
    } 
    else {
      Serial.println("Intruder!");
      while (true) {
        alarm.on();
        alarm2.off();
        if (Serial.read() == 's') {
          Serial.println("Alarm OFF");
          break;
        }
      }
    }
  }
}
