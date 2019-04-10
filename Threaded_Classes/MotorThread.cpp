//#include <wiringPi.h>
#include <thread>
//#include <cstdlib>
#include <iostream>
#include "MotorThread.h"
//#include "libServo.h"
#include "libServo.cpp"


void MotorThread::run()
{
	printf("entered loop\n");
	wiringPiSetupGpio();
	Servo servo(pin);
	servo.init(90);
	//	if (*stateptr==0)
	//	{
	//		servo.move(90);
	//	}
 	// if(*stateptr==1)
	while(true){
	//printf("entered 2nd loop\n");
	state=stateptr->getState();
	//printf("acquired State: %i\n",state);
	std::cout << state << std::endl;
	if(state==0)
	{
		printf("servo to CLEAR/NEUTRAL\n");
    servo.move(90);
  }
	if(state==1)
	{
		printf("servo to GREEN\n");
    servo.move(45);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
  if (state==2)//*stateptr==2)
  {
		printf("servo to BROWN\n");
    servo.move(135);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
  if (state==3)//*stateptr==3)
  {
    servo.move(90);
		printf("servo to CLEAR/NEUTRAL\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}
}
