#include "MotorThread.h"
#include "libServo.cpp"
#include "libServo.h"

void MotorThread:run()
{
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
