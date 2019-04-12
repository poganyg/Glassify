#ifndef MOTOR_THREAD_H
#define MOTOR_THREAD_H
//#include "libServo.cpp"
#include "CppThread.h"
#include "state.h"
#include "libServo.h"
//#include <wiringPi.h>
class MotorThread : public CppThread {

public:
  MotorThread(State* _stateptr,Servo* _servoptr);

private:
  void run();

private:
State* stateptr;
Servo* servoptr;
int pin;
int m_state;
int m_delay;
};
#endif
