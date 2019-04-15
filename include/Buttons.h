/**
* @file Menu.h
* @brief Class including all of the functions required for the menu to operate
* @author Gergerly Pogany
*/
#ifndef BUTTONS
#define BUTTONS

#include <iostream>
#include <wiringPi.h>
#include <vector>
#include <unistd.h>
#include <lcd.h>
#include "Display.h"
#include <chrono>
#include "state.h"
#include <string>

using namespace std;
/**
*@brief Full menu functionality
*/
class Buttons
{
  private:

  public:
    State* m_stateptr;       //!<  instance of state pointer in menu class
    int M_BUTTON1;          //!<  pin button 1 is located on
    int M_BUTTON2;          //!<  pin button 2 is located on
    int M_DEBOUNCE;          //!<  Time taken for debounce
    int b1;                        //!< state of button one
    int b2;                        //!< state of button two

    int testVector[1];         //!< Vector for unit testing

   /**
     * Constructor which initialises buttons and menu names and collects the calibrated values
     * @param[in] _displayptr pointer to display class
     * @param[in] _servoptr pointer to servo class
     * @param[in] _stateptr pointer to state class
     */

    Buttons(State* _stateptr);
     /**
      * Checks for and detects button presses on buttons one or two
      * @return whichButton Variable showing whch button was pressed and how. 0 means no press, 1 means button one, 2 means button two and three means a long press
      */
    int buttonPress();
};

#endif
