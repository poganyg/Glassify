#ifndef MOTOR_THREAD_H
#define MOTOR_THREAD_H

#include "CppThread.h"

class MotorThread : public CppThread {

public:
  MotorThread(int Output){
    output=Output;
    int pin=18;
    wiringPiSetupGpio();
  }

private:
  void run();

private:
  int output;

};
#endif
