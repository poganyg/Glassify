#include <iostream>
#include <stdio.h>
#include "SwitchThread.h"
#include "MotorThread.h"
#include "state.h"
#include "Provisional0.h"
//#include "ClassifyingThread.h"

State state(0);
State* stateptr= &state;
acquireImage Classifier(stateptr);
MotorThread MotorTurning(stateptr);
//int yy=*stateptr;
//Setting up LED


int main()//(int argc, const char* argv[] )
{
  wiringPiSetupGpio () ;
  pinMode (4, OUTPUT) ;
  digitalWrite (4, HIGH);
while(true){

//  SwitchThread switchCheck1;
  //ClassifyingThread classification1(stateptr);
// switchCheck1.start();
 // switchCheck1.join();
  //classification1.start();
//  std::cout<<"%d"state<<std::endl;
 // MotorThread MotorTurning(stateptr);
// MotorTurning.start();
  //classification1.join();
MotorTurning.start();
printf("MotorTurning.start\n");
Classifier.classify();
MotorTurning.join();
}
}
