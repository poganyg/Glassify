#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include "./include/SwitchThread.h"
#include "./include/MotorThread.h"
#include "./include/state.h"
#include "./include/Provisional0.h"
#include "./include/libServo.cpp"
//#include "ClassifyingThread.h"


//wiringPiSetup();
//wiringPiSetupGpio();
State state(0);
State* stateptr= &state;
Servo servo(18);
Servo* servoptr = &servo;
acquireImage Classifier(stateptr);
MotorThread MotorTurning(stateptr,servoptr);
//int yy=*stateptr;
//Setting up LED


int main()//(int argc, const char* argv[] )
{
wiringPiSetupGpio () ;
while(true){

  SwitchThread switchCheck1;
  //ClassifyingThread classification1(stateptr);
 switchCheck1.start();
 switchCheck1.join();
  //pinMode (4, OUTPUT) ;
  //digitalWrite (4, HIGH);
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
