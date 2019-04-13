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

class Menu
{
  private:

  public:
    Display* m_displayptr;
    Servo* m_servoptr; //UNCHECK LATER
    State* m_stateptr; //UNCHECK LATER
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


    Menu(Display* _displayptr, Servo* _servoptr, State* _stateptr);
    int buttonPress();
    void haltTimeMenu();
    void separationAngleMenu();
    void restAngleMenu();
    void mainMenu();
};

#endif
