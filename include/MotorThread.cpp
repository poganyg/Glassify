#include <wiringPi.h>
#include <thread>
//#include <cstdlib>
#include <iostream>
#include "MotorThread.h"
//#include "libServo.h"
//#include "libServo.cpp"

MotorThread::MotorThread(State* _stateptr,Servo* _servoptr)
	:stateptr(_stateptr),servoptr(_servoptr),pin(18),m_delay(1000),m_state(0)
	{
		printf("constructed MotorThread\n");
	}

void MotorThread::run()
{
	while(stateptr->getState()!=0 || stateptr->getBuffer()!=0)
	{
	//printf("entered loop\n");
	//Servo servo(pin);
	//servo.init(90);

	//printf("entered 2nd loop\n");
	m_state=stateptr->getState();
	//printf("acquired State: %i\n",state);
	//std::cout << state << std::endl;

	if(m_state==1)
	{
		//printf("servo to GREEN\n");
		servoptr->moveGreen();
    //servo.move(45);
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay-stateptr->getLag()));
  }
  if (m_state==2)
  {
		//printf("servo to BROWN\n");
		servoptr->moveBrown();
    //servo.move(135);
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay-stateptr->getLag()));
  }
  if (m_state==3)
  {
		servoptr->moveClear();
		//servo.move(90);
		//printf("servo to CLEAR/NEUTRAL\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay-stateptr->getLag()));
  }
	m_state==0;
	{
		//printf("servo to CLEAR/NEUTRAL\n");
		servoptr->moveClear();
		//servo.move(90);
  }
	stateptr->removeState();
	}
}
