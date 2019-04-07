#ifndef MOTOR_THREAD_H
#define MOTOR_THREAD_H
//#include "libServo.cpp"
#include "CppThread.h"
#include "state.h"
//#include <wiringPi.h>
class MotorThread : public CppThread {

public:
  MotorThread(State* _stateptr)
    :stateptr(_stateptr),pin(18)
    {
      printf("constructed MotorThread\n");
    }

private:
  void run();

private:
State* stateptr;
int pin;
int state =0;
};
#endif
