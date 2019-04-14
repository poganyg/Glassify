/** 
* @file Menu.h
* @brief Class including all of the functions required for the menu to operate
* @author Gergerly Pogany
*/
#ifndef MENU
#define MENU

#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <lcd.h>
#include <tuple>
#include "Display.h"
#include <chrono>
#include "libServo.h"
#include "state.h"
#include <string>

using namespace std;
/**
*@brief Full menu functionality
*/
class Menu
{
  private:

  public:
    Display* m_displayptr;
    Servo* m_servoptr; 
    State* m_stateptr; 
    int M_BUTTON1;
    int M_BUTTON2;
    int M_EXIT_TIME;
    int M_DEBOUNCE;
    int m_halt_time;
    int m_sep_angle;
    int m_rest_position;
    int M_HALT_ADJUST;
    int M_SEP_ADJUST;
    int M_REST_ADJUST;
    int HALT_LOW_LIMIT;
    int M_SEP_LOW_LIMIT;
    int M_REST_LOW_LIMIT;
    int M_HALT_UP_LIMIT;
    int M_SEP_UP_LIMIT;
    int M_REST_UP_LIMIT;
    int M_HALT_LOW_LIMIT;
    vector<string> m_menu_vector;
    int M_ARRAY_LENGTH;
    int m_i;
    int m_b1;
    int m_b2;
    int retVal;

   /**
     * Constructor which initialises buttons and menu names and collects the calibrated values
     * @param[in] _displayptr pointer to display class
     * @param[in] _servoptr pointer to servo class
     * @param[in] _stateptr pointer to state class
     * @param M_BUTTON1 pin button 1 is located on
     * @param M_BUTTON2 pin button 2 is located on
     * @param M_HALT_ADJUST value the halt time is adjusted by for each button press 
     * @param M_SEP_ADJUST value the seperation angle is adjusted by for each button press
     * @param M_REST_ADJUST value rest time for the motor is adjusted by for each button press
     * @param M_DEBOUNCE Brief pause in button reading to prevent button debounce
     * @param M_HALT_LOW_LIMIT the lower limit for the rest time after motor movement
     * @param M_SEP_LOW_LIMIT  The lower limit for the speration angle between centre and classified positions 
     * @param M_REST_LOW_LIMIT The lower limit for the rest position of the motor
     * @param M_HALT_UP_LIMIT  The upper limit for the rest time after motor movement
     * @param M_SEP_UP_LIMIT The upper limit for the seperation angle
     * @param M_ARRAY_LENGTH Length of menu array
     * @param m_displayptr instance of display pointer in this class
     * @param m_servoptr instance of servo pointer in this class
     * @param m_stateptr instance of state pointer in this class
     */
    
    Menu(Display* _displayptr, Servo* _servoptr, State* _stateptr);
     /**
      * Checks for and detects button presses on buttons one or two 
      * @return whichButton Variable showing whch button was pressed and how. 0 means no press, 1 means button one, 2 means button two and three means a long press 
      * @param b1 state of button one
      * @param b2 state of button two 
      */
    int buttonPress();
    /** 
      * Section of the menu that allows callibration of the halt time of the motor after sorting
      * @param retVal output value from button press function
      * @m_halt_time time that motor will rest after sorting glass
      * @M_HALT_ADJUST amount halt time will be adjusted by for each button press
      */
    void haltTimeMenu();
     /** 
       * Section of the menu that allows calibration of seperation angle
       * @param retVal Value returned from buttonPress function
       * @param m_sep_angle Seperation between the rest angle and the position for glass being sorted. This is symmetric on each side.
       * @param M_SEP_ADJUST Amount seperation angle is adjusted by for each button press
       */
   void separationAngleMenu();
    /**
      * Section of menu that allows calibration of the resting angle of the motor
      * @param  retVal Value returned from buttonPress function
      * @param m_rest_position Position that the motor stays in by default, also position which clear glass is sorted to
      * @param M_REST_ADJUST Amount rest position will be adjusted by for each button press; 
      */
    void restAngleMenu();
   /** 
     * Brings all of the menu portions together to allow selection of submenu to be enterred 
     * @param m_i keeps track of which menu option is currently on screen 0=halt time menu, 1= seperation angle menu and 2 = rest angle menu
     * @param retVal Value returned by buttonPress function
     */
    int mainMenu();
};

#endif
