/*
 * Robot.cpp - Library for controlloing robot code.
 * Created by Dimas Sheldon. January 30, 2017.
 * Released into the public domain.
 */
#include "Arduino.h"
#include "Robot.h"

Robot::Robot(int enL, int enR, int dirL, int dirR) {
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  _enL = enL;
  _enR = enR;
  _dirL = dirL;
  -dirR = dirR;
}

// Function forward is a part of Robot class.
void Robot::forward() {
  digitalWrite(_dirL, LOW);
  digitalWrite(_dirR, HIGH);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void Robot::backward() {
  digitalWrite(_dirL, HIGH);
  digitalWrite(_dirR, LOW);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void Robot::turnLeft() {
  digitalWrite(_dirL, HIGH);
  digitalWrite(_dirR, HIGH);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void Robot::turnRight() {
  digitalWrite(_dirL, LOW);
  digitalWrite(_dirR, LOW);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}


void Robot::noMove() {
  analogWrite(_enL, 0);
  analogWrite(_enR, 0);
}
