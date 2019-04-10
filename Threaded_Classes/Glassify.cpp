#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include "./include/SwitchThread.h"
#include "./include/MotorThread.h"
#include "./include/state.h"
#include "./include/Camera.h"
#include "./include/libServo.cpp"

//wiringPiSetupGpio();
State state(0);
State* stateptr= &state;
Servo servo(18);
Servo* servoptr = &servo;
acquireImage Classifier(stateptr);
MotorThread MotorTurning(stateptr,servoptr);

int main()
{
wiringPiSetupGpio () ;
while(true){

  SwitchThread switchCheck1;
 switchCheck1.start();
 switchCheck1.join();
  //pinMode (4, OUTPUT) ;
  //digitalWrite (4, HIGH);
MotorTurning.start();
printf("MotorTurning.start\n");
Classifier.classify();
MotorTurning.join();
}
}
