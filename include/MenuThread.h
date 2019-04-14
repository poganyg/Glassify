#ifndef MENU_THREAD_H
#define MENU_THREAD_H
#include "CppThread.h"
#include "Menu.h"
//#include <wiringPi.h>
/**
* @file MotorThread.h
* @brief This header file contains all definitions relating to the
* use of the motor as a thread
* @author Ross Crawford
* @date 3/04/2019
*/

class MenuThread : public CppThread {

public:
  /**
  constructor that initialises all pointers and inputs
  @param stateptr pointer that shows state classifier outputted
  @param servoptr pointer to servo control class
  @param pin pin on which the motor is located
  @param m_delay time given for bottle to exit tube
  @param m_state instantiation of output from classifier
*/
  MenuThread(Menu* _menuptr);

private:
/** This method carrys out the required motor movement depndent on
* the colour of glass that reaches it
*
*/
  void run();

private:
Menu* m_menuptr;
};
#endif
