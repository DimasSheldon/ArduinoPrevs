/* Lock.h -
   Created by Dimas Sheldon, January 31, 2017.
   Released into public domain.
*/

#ifndef Lock_h
#define Lock_h
#include "Arduino.h"

class Lock {
  private:
    int _pin;
    int _lockState;
  public:
    Lock(int pin);
    void lock();
    void unlock();
};

#endif