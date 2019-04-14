#include <wiringPi.h>
#include <iostream>
#include <stdio.h>
#include "./include/state.h"
#include "./include/libServo.h"
#include "./include/Camera.h"
#include "./include/Display.h"
#include "./include/Menu.h"
#include "./include/SwitchThread.h"
#include "./include/MotorThread.h"
#include "./include/Classifier.h"
#include "./include/ClassifierThread.h"
#include "./include/MenuThread.h"
#include "./include/ActivePollThread.h"

int main()
{
  //INITIALISATION
  wiringPiSetup();
  State state;
  State* stateptr= &state;
  Servo servo(1);
  Servo* servoptr = &servo;
  Camera camera;
  Camera* cameraptr = &camera;
  Display display;
  Display* displayptr = &display;
  Menu menu(displayptr,servoptr,stateptr);
  Menu* menuptr = &menu;
  Classifier classifier(stateptr,cameraptr,servoptr);
  Classifier* classifierptr = &classifier;
  ClassifierThread classifierThread(classifierptr);
  MotorThread motorThread(stateptr,servoptr);
  SwitchThread switchThread(stateptr,17);
  MenuThread menuThread(menuptr);
  ActivePollThread activePollThread(stateptr,17);

  //MAIN SCRIPT
  while(true){
    menuThread.start();
    while(true){
      switchThread.start();
      switchThread.join();
      classifierThread.start();
      activePollThread.start();
      classifierThread.join();
      activePollThread.join();
    }
    menuThread.join();
  }
}
