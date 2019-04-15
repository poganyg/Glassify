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
#include "Display.h"
#include <chrono>
#include "libServo.h"
#include "state.h"
#include <string>
#include "Buttons.h"

using namespace std;
/**
*@brief Full menu functionality
*/
class Menu
{
  private:

  public:
    Buttons* m_buttonptr;   //!< instance of display pointer in menu class
    Display* m_displayptr;   //!<  instance of display pointer in menu class
    Servo* m_servoptr;       //!<  instance of servo pointer in menu class
    State* m_stateptr;       //!<  instance of state pointer in menu class
    int M_BUTTON1;          //!<  pin button 1 is located on
    int M_BUTTON2;          //!<  pin button 2 is located on
    int M_DEBOUNCE;          //!<  Time taken for debounce
    int m_halt_time;          //!< Time that motor will rest after sorting glass
    int m_sep_angle;          //!< Seperation between the rest angle and the position for glass being sorted. This is symmetric on each side.
    int m_rest_position;          //!< Position that the motor stays in by default, also position which clear glass is sorted to
    int M_HALT_ADJUST;          //!< amount halt time will be adjusted by for each button press
    int M_SEP_ADJUST;          //!<  value the seperation angle is adjusted by for each button press
    int M_REST_ADJUST;          //!< value rest time for the motor is adjusted by for each button press
    int HALT_LOW_LIMIT;          //!< the lower limit for the rest time after motor movement
    int M_SEP_LOW_LIMIT;          //!< The lower limit for the speration angle between centre and classified positions
    int M_REST_LOW_LIMIT;          //!< The lower limit for the rest position of the motor
    int M_HALT_UP_LIMIT;          //!< The upper limit for the rest time after motor movement
    int M_SEP_UP_LIMIT;          //!< The upper limit for the seperation angle
    int M_REST_UP_LIMIT;          //!< The upper limit for the rest position of the motor
    int M_HALT_LOW_LIMIT;          //!< The lower limit for the rest time after motor movement
    vector<string> m_menu_vector;   //!< Vector containing the menu options of the main menu
    int M_ARRAY_LENGTH;             //!< Length of menu array
    int m_i;                        //!< m_i keeps track of which menu option is currently on screen 0=halt time menu, 1= seperation angle menu and 2 = rest angle menu
    int b1;                        //!< state of button one
    int b2;                        //!< state of button two
    int retVal;                        //!< return value from buttonPress function

   /**
     * Constructor which initialises buttons and menu names and collects the calibrated values
     * @param[in] _displayptr pointer to display class
     * @param[in] _servoptr pointer to servo class
     * @param[in] _stateptr pointer to state class
     */

    Menu(Display* _displayptr, Servo* _servoptr, State* _stateptr, Buttons* _buttonptr);
    /**
      * Section of the menu that allows callibration of the halt time of the motor after sorting
      */
    void haltTimeMenu();
     /**
       * Section of the menu that allows calibration of seperation angle
       */
   void separationAngleMenu();
    /**
      * Section of menu that allows calibration of the resting angle of the motor
      */
    void restAngleMenu();
   /**
     * Brings all of the menu portions together to allow selection of submenu to be enterred
     */
    int mainMenu();
};

#endif
