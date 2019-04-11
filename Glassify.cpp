#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include "./include/SwitchThread.h"
#include "./include/MotorThread.h"
#include "./include/state.h"
#include "./include/Camera.h"
#include "./include/libServo.cpp"

//wiringPiSetupGpio();
State State(0);
State* stateptr= &State;
Servo Servo(18);
Servo* servoptr = &Servo;
acquireImage Classifier(stateptr);
MotorThread MotorTurning(stateptr,servoptr);
SwitchThread SwitchCheck;
int main()
{
wiringPiSetupGpio();
while(true){
SwitchCheck.start();
SwitchCheck.join();
//pinMode (4, OUTPUT) ;
//digitalWrite (4, HIGH);
//MotorTurning.start();
printf("MotorTurning.start\n");
Classifier.classify();
MotorTurning.start();
MotorTurning.join();
}
}
