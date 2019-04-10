#include <wiringPi.h>
#include <thread>
//#include <cstdlib>
#include <iostream>
#include "MotorThread.h"
//#include "libServo.h"
//#include "libServo.cpp"


void MotorThread::run()
{
	printf("entered loop\n");
	//Servo servo(pin);
	//servo.init(90);
	while(true){
	//printf("entered 2nd loop\n");
	m_state=stateptr->getState();
	//printf("acquired State: %i\n",state);
	//std::cout << state << std::endl;
	if(m_state==0)
	{
		//printf("servo to CLEAR/NEUTRAL\n");
		servoptr->moveClear();
		//servo.move(90);
  }
	if(m_state==1)
	{
		//printf("servo to GREEN\n");
		servoptr->moveGreen();
    //servo.move(45);
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
  }
  if (m_state==2)
  {
		//printf("servo to BROWN\n");
		servoptr->moveBrown();
    //servo.move(135);
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
  }
  if (m_state==3)
  {
		servoptr->moveClear();
		//servo.move(90);
		//printf("servo to CLEAR/NEUTRAL\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
  }
	}
}
