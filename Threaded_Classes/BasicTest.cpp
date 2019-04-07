#include <stdio.h>
#include "SwitchThread.h"
#include "MotorThread.h"
#include "Provisional1.h"

int main()
{
int gg;
while(true){
 AcquireImage Classification;
//  SwitchThread switchCheck1;
// switchCheck1.start();
//  switchCheck1.join();
  gg=Classification.Classify();
  MotorThread MotorTurning(gg);
  MotorTurning.start();
  MotorTurning.join();
}
}

