#ifndef MOTOR_THREAD_H
#define MOTOR_THREAD_H

#include "CppThread.h"
//#include <wiringPi.h>
class MotorThread : public CppThread {

public:
  MotorThread(int Output)
    {
	 colour=Output;
         pin=18;
  //  wiringPiSetupGpio();
  }

private:
  void run();

private:
   int colour ;
   int pin;
};
#endif
