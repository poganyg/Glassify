//#include <wiringPi.h>
#include <thread>
//#include <cstdlib>
#include <iostream>
#include "MotorThread.h"
//#include "libServo.h"
#include "libServo.cpp"


void MotorThread::run()
{
	wiringPiSetupGpio();
    Servo servo(18);
    servo.init(90);
  if (colour==1)
  {
    servo.move(45);
  }
  if (colour==2)
  {
    servo.move(90);
  }
  if (colour==3)
  {
    servo.move(135);
  }
}
