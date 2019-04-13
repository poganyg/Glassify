#ifndef MOTOR_THREAD_H
#define MOTOR_THREAD_H
//#include "libServo.cpp"
#include "CppThread.h"
#include "state.h"
#include "libServo.h"
//#include <wiringPi.h>
/**
* @file MotorThread.h
* @brief This header file contains all definitions relating to the 
* use of the motor as a thread
* @author Ross Crawford
* @date 3/04/2019
*/

class MotorThread : public CppThread {

public:
  /**
  constructor that initialises all pointers and inputs
  @param stateptr pointer that shows state classifier outputted
  @param servoptr pointer to servo control class
  @param pin pin on which the motor is located
  @param m_delay time given for bottle to exit tube
  @param m_state instantiation of output from classifier
*/
  MotorThread(State* _stateptr,Servo* _servoptr)
    :stateptr(_stateptr),servoptr(_servoptr),pin(18),m_delay(500),m_state(0)
    {
      printf("constructed MotorThread\n");
    }

private:
/** This method carrys out the required motor movement depndent on
* the colour of glass that reaches it
* 
*/ 
  void run();

private:
State* stateptr;
Servo* servoptr;
int pin;
int m_state;
int m_delay;
};
#endif
