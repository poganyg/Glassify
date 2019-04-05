#include <stdio.h>
#include "SwitchThread.h"
#include "MotorThread.h"

//int qq
//int* ptr=&qq

int main()//(int argc, const char* argv[] )
{
  SwitchThread switchCheck1;
 switchCheck1.start();
  switchCheck1.join();
  MotorThread MotorTurning(1);
  MotorTurning.start();
  MotorTurning.join();
}
