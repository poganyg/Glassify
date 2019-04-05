#include <stdio.h>
#include "SwitchThread.h"
#include "ClassifyingThread.h"
#include "MotorThread.h"

int main ( int argc, const char* argv[] )
{
while(true){
  SwitchThread CheckingSwitch();
  ClassifyingThread Classification();
  CheckingSwitch.start();
  CheckingSwitch.join();
  Output=Classification.start();
  Classification.join();
  MotorThread MotorTurning(Output);
  MotorTurning.start();
  MotorTurning.join();
}
}
