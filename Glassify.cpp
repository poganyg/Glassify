/** @file Glassify.cpp
* @brief Main file which uses all previously written functions
* @author Reuben Docea
*/

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
/**
* @brief Activates all threads in sequence to classify glass and run menu
*/
int main()
{
  //INITIALISATION
  wiringPiSetup();
  State state;		  	 // Initialises state class
  State* stateptr= &state;	 //Sets up pointer to state class
  Servo servo(1); 	  	 //Initialises servo at pin 1
  Servo* servoptr = &servo; 	 //sets up pointer to servo class
  Camera camera; 		 // Initialises Camera class
  Camera* cameraptr = &camera;   //sets up pointer to servo class
  Display display; 		 //Initialises display class
  Display* displayptr = &display;// Sets up pointer to display class
  Menu menu(displayptr,servoptr,stateptr);// Initialises menu class
  Menu* menuptr = &menu; 	 //sets pointer to menu class
  Classifier classifier(stateptr,cameraptr,servoptr);// Initialises classifier
  Classifier* classifierptr = &classifier; 	//Sets pointer to classifier
  ClassifierThread classifierThread(classifierptr); //Initialises classifier thread
  MotorThread motorThread(stateptr,servoptr);	 //Initialises motor thread
  SwitchThread switchThread(stateptr,17); 	//Initialises switch thread
  MenuThread menuThread(menuptr); 		//Initialises menu thread

  ActivePollThread activePollThread(stateptr,17); //initialises active polling thread

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
