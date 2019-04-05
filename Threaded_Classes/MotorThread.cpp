#include "MotorThread.h"
#include "libServo.cpp"
#include "libServo.h"

void MotorThread:run(int output)
{
    Servo servo(18);
    servo.init(90);
  if (ouput==1)
  {
    servo.move(45);
  }
  if (output==2)
  {
    servo.move(90);
  }
  if (output==3)
  {
    servo.move(135);
  }
}
