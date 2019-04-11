#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include "./include/state.h"
#include "./include/libServo.h"
#include "./include/Camera.h"
#include "./include/SwitchThread.h"
#include "./include/MotorThread.h"
#include "./include/Classifier.h"

State state(0);
State* stateptr= &state;
Servo servo(18);
Servo* servoptr = &servo;
Camera camera;
Camera* cameraptr = &camera;
Classifier classifier(stateptr,cameraptr);
MotorThread motorThread(stateptr,servoptr);
SwitchThread switchThread(17);
int main()
{
while(true){
  wiringPiSetupGpio();
switchThread.start();
switchThread.join();
//pinMode (4, OUTPUT) ;
//digitalWrite (4, HIGH);
//MotorTurning.start();
printf("MotorTurning.start\n");
classifier.classify();
motorThread.start();
motorThread.join();
}
}
