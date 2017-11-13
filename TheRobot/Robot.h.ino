/*
   Robot.h - Library for controlling any 2 WD mobile platform.
   Created by Dimas Sheldon, January 30, 2017.
   Released into public domain
*/
#ifndef Robot_h
#define Robot_h

#include "Arduino.h"

class Robot {
  public:
    Robot(int enL, int enR, int dirL, int dirR);
    void forward();
    void backward();
    void turnLeft();
    void turnRight();
    void noMove();
  private:
    int _enL;
    int _enR;
    int _dirL;
    int _dirR;
};

#endif
