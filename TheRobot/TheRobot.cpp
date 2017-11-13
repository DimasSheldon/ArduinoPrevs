/*
 * Robot.cpp - Library for controlloing robot code.
 * Created by Dimas Sheldon. January 30, 2017.
 * Released into the public domain.
 */
#include "Arduino.h"
#include "TheRobot.h"

TheRobot::TheRobot(int enL, int enR, int dirL, int dirR) {
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
  _enL = enL;
  _enR = enR;
  _dirL = dirL;
  _dirR = dirR;
}

// Function forward is a part of Robot class.
void TheRobot::forward() {
  digitalWrite(_dirL, LOW);
  digitalWrite(_dirR, HIGH);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void TheRobot::backward() {
  digitalWrite(_dirL, HIGH);
  digitalWrite(_dirR, LOW);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void TheRobot::turnLeft() {
  digitalWrite(_dirL, HIGH);
  digitalWrite(_dirR, HIGH);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void TheRobot::turnRight() {
  digitalWrite(_dirL, LOW);
  digitalWrite(_dirR, LOW);
  analogWrite(_enL, 255);
  analogWrite(_enR, 255);
}

void TheRobot::noMove() {
  analogWrite(_enL, 0);
  analogWrite(_enR, 0);
}