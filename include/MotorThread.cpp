#include <wiringPi.h>
#include <thread>
//#include <cstdlib>
#include <iostream>
#include "MotorThread.h"
//#include "libServo.h"
//#include "libServo.cpp"


void MotorThread::run()
{
	while(true){

	m_state=stateptr->getState();
	std::cout << "MOTOR GOT STATE >> " << m_state << std::endl;

	if(m_state==1)
	{
		servoptr->moveGreen();
		//std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
  }
  if (m_state==2)
  {
		servoptr->moveBrown();
		//std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
  }
  if (m_state==3)
  {
		servoptr->moveClear();
		//std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
  }
	m_state==0;
	{
		servoptr->moveClear();
  }
}
}
