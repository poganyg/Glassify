#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include "./include/state.h"
#include "./include/libServo.h"
#include "./include/Camera.h"
#include "./include/SwitchThread.h"
#include "./include/MotorThread.h"
#include "./include/Classifier.h"
#include "./include/ClassifierThread.h"

State state;
State* stateptr= &state;
Servo servo(18);
Servo* servoptr = &servo;
Camera camera;
Camera* cameraptr = &camera;
Classifier classifier(stateptr,cameraptr);
Classifier* classifierptr = &classifier;
ClassifierThread classifierThread(classifierptr);
MotorThread motorThread(stateptr,servoptr);
SwitchThread switchThread(stateptr,17);

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
classifierThread;
motorThread.start();
motorThread.join();
}
}
