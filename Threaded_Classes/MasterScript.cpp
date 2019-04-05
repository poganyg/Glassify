#include <stdio.h>
#include "SwitchThread.h"
#include "ClassifyingThread.h"
#include "MotorThread.h"

int qq
int* ptr=&qq

int main ( int argc, const char* argv[] )
{
while(true){
  SwitchThread CheckingSwitch();
  ClassifyingThread Classification(ptr);
  CheckingSwitch.start();
  CheckingSwitch.join();
  Classification.start();
  Classification.join();
  MotorThread MotorTurning(qq);
  MotorTurning.start();
  MotorTurning.join();
}
}
