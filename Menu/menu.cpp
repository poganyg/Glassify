#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include "libServo.h"
#include <lcd.h>
#include <tuple>
/*
#define LCD_RS 5               //Register select pin
#define LCD_E 4               //Enable Pin
#define LCD_D4 8               //Data pin D4
#define LCD_D5 1               //Data pin D5 - REWRITE TO PIN 7 WITH NEW PCB
#define LCD_D6 16               //Data pin D6
#define LCD_D7 15
*/
using namespace std;

Menu::Menu(Display* _displayptr) //still need to add servo pointer and state pointer
  :M_BUTTON1 (22), M_BUTTON2 (27), M_EXIT_TIME (500000), M_DEBOUNCE (50000), M_HALT_ADJUST (100), M_SEP_ADJUST (5), M_REST_ADJUST (5), HALT_LOW_LIMIT (100), M_SEP_LOW_LIMIT (10), M_REST_LOW_LIMIT (10), M_HALT_UP_LIMIT (2000), M_SEP_UP_LIMIT (70), M_ARRAY_LENGTH (3), m_displayptr(_displayptr)
{
  //MUST MOVE THIS OUTSIDE INTO A MAIN SCRIPT
  wiringPiSetup();
  Display display;
  Display* displayptr = &display;
  Servo servo(18);
  // probably want a servo pointer too?

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pullUpDnControl(button1, PUD_DOWN);
  pullUpDnControl(button2, PUD_DOWN);

  M_REST_UP_LIMIT = 180-M_REST_LOW_LIMIT;
  m_menu_vector.push_back("Servo halt time");
  m_menu_vector.push_back("Separation angle");
  m_menu_vector.push_back("Rest position");
  m_i = 0;
  m_exit_counter = 0;

  m_halt_time = servo.getHaltTime();
  m_sep_angle = servo.getSepAngle();
  m_rest_position = servo.getRestPosition();

  //need to be given values to be able to call updateButtons
  m_prev_b1 = 0;
  m_prev_b2 = 0;
}


std::tuple<int, int, int, int, int, int> Menu::updateButtons(int prev_b1, int prev_b2)
{
  usleep(this->M_DEBOUNCE);
  int b1 = digitalRead(this->M_BUTTON1);
  int b2 = digitalRead(this->M_BUTTON2);

  int b1_changed;
  int b2_changed;

  // set b1_changed to true if button 1 was released, also update previous state
  if (b1 != prev_b1) {
    if (b1 == 0) {
      b1_changed = 1;
    }
    prev_b1 = b1;
  } else {
    b1_changed = 0;
  }
  // set b1_changed to true if button 2 was released, also update previous state
  if (b2 != prev_b2) {
    if (b2 == 0) {
      b2_changed = 1;
    }
    prev_b2 = b2;
  } else {
   b2_changed = 0;
  }

  return {b1, b2, prev_b1, prev_b2, b1_changed, b2_changed};
}

int main() {

//DELETE IF THE CONSTRUCTOR ACTUALLY WORKS
/*
  // initialisations
  wiringPiSetup();

  Display display;
  Display* displayptr = &display;

  //int wiringPiSetupGpio (void);
  //int M_LCD = lcdInit (2, 16, 4, LCD_RS, LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);
  //Display();
  //void write(const char* input);

  //Display display;
  //Display* displayptr = &display;

  //Servo servo(18);


  int button1 = 22;
  int button2 = 27;
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pullUpDnControl(button1, PUD_DOWN);
  pullUpDnControl(button2, PUD_DOWN);

  //  MotorThread servo
  int EXIT_TIME = 500000;
  int DEBOUNCE = 50000;

  int halt_time = 1000; //servo.getHaltTime(); //1000;
  int sep_angle = 45; //servo.getSepAngle();//45;
  int rest_position;// = 90; //WHY ISNT THIS GETTED?
  int HALT_ADJUST = 100;
  int SEP_ADJUST = 5;
  int REST_ADJUST = 5 ;

  int HALT_LOW_LIMIT = 100;
  int SEP_LOW_LIMIT = 10;
  int REST_LOW_LIMIT = 10;
  int HALT_UP_LIMIT = 2000;
  int SEP_UP_LIMIT = 70;
  int REST_UP_LIMIT = 180-REST_LOW_LIMIT;
  vector<string> menu_vector;
  menu_vector.push_back("Servo halt time");
  menu_vector.push_back("Separation angle");
  menu_vector.push_back("Rest position");


//  menu_vector.clear();

  int array_length = 3;

  int i = 0;
  int exit_counter = 0;

*/

/* OPERATING THE DISPLAY
  const char* str = "boink";
  //const char* X = "servo halt time";
  //displayptr->write((string) menu_vector[i]);
  displayptr->write(str);
*/

  cout << m_menu_vector[m_i] << endl;

  while(true) {

// ------------- READ BUTTONS -------------

    // updating the button states
    auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);
/*  usleep(DEBOUNCE);
    b1 = digitalRead(button1);
    b2 = digitalRead(button2);

    if (b1 != prev_b1) {
      if (b1 == 0) {
        b1_changed = 1;
      }
      prev_b1 = b1;
    } else {
      b1_changed = 0;
    }
    if (b2 != prev_b2) {
      if (b2 == 0) {
        b2_changed = 1;
      }
      prev_b2 = b2;
    } else {
     b2_changed = 0;
    }
*/

// ------------- READ BUTTONS -------------

// ------------- NEXT MENU OPTION -------------
    // stepping to the next menu option
    if (m_b1_changed == 1 && m_b2 == 0) {

      m_i = m_i + 1;

      // moving back to the first menu item
      if (m_i > m_array_length - 1) {
        m_i = 0;
      }

      cout << m_menu_vector[i] << endl;
      //lcd.write(m_menu_vector[i]);
    }
// ------------- NEXT MENU OPTION -------------


    // entering a menu option
    if (m_b1 == 0 && m_b2_changed == 1) {

      // Have to set the servo halt time
      if (m_i == 0) {
        //cout << "Servo halt time" << endl;
	      cout << m_halt_time;
        cout << " ms" << endl;


        //longer so the buttonpress from entering the menu doesnt affect menu
        //options
	      usleep(M_DEBOUNCE*10);


        // updating button states prior to entering the loop
        auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);
        /*
        b1 = digitalRead(button1);
        b2 = digitalRead(button2);
        prev_b1 = b1;
        prev_b2 = b2;
        b1_changed = 0;
        b2_changed = 0;
        */
        // stay in the loop until a button is pressed down for a while
        while (m_exit_counter < M_EXIT_TIME/M_DEBOUNCE) {

          // ------------- READ BUTTONS -------------

          auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);

          // ------------- READ BUTTONS -------------


          // if either button is pressed down increase exit counter
        	if ((m_b1 || m_b2) == 1) {
            m_exit_counter += 1;
          }


         // int motor_angle = servo.getRestPosition();
         // cout << motor_angle <<endl;          //if button 1 was pressed then decrease the angle by MOTOR_ADJUST
          if (m_b1_changed == 1 && m_b2 == 0) {

            if (m_halt_time > 100) {
              m_halt_time -= M_HALT_ADJUST;
              cout << m_halt_time;
              cout << " ms" << endl;
              //servo.setHaltTime(m_halt_time);
	            //lcd.write(m_halt_time);
            } else {
              cout << "Can't further decrease" << endl;
            }
          }
          //if button 2 was pressed then increase the angle by MOTOR_ADJUST
          if (m_b2_changed == 1 && m_b1 == 0) {
            if (m_halt_time < 2000) {
              m_halt_time += M_HALT_ADJUST;
              cout << m_halt_time;
              cout << " ms"<< endl;
              //servo.setHaltTime(m_halt_time);
		          //lcd.write(m_halt_time);
            } else {
              cout << "Can't further increase" << endl;
            }
          }
        }
        m_exit_counter = 0;
        //needed so menu doesnt respond to the release of the button after exitting
        //a menu option
        m_prev_b1 = 0;
        m_prev_b2 = 0;
        cout << "Servo halt time" << endl;
        //allow time for the release of the button after exiting the menu option
        usleep(M_DEBOUNCE*20);
        //lcd.write("Servo halt time");
      }
      //have to set separation angle
      else if (m_i == 1) {
        //cout << "Separation angle" << endl;
	      cout << m_sep_angle;
        cout << "°" << endl;
	      usleep(M_DEBOUNCE*10);

        // updating on what state the GPIOs in prior to entering the loop
        auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);

        // stay in the loop until a button is pressed down for a while
        while (m_exit_counter < M_EXIT_TIME/M_DEBOUNCE) {

          auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);

          // if either button is pressed down increase exit counter
        	if ((m_b1 || m_b2) == 1) {
            m_exit_counter += 1;
          }

          //int motor_angle = servo.get_motor_angle();
          //if button 1 was pressed then decrease the angle by MOTOR_ADJUST
          if (m_b1_changed == 1 && m_b2 == 0) {

            if (m_sep_angle > 10) {
              m_sep_angle -= M_REST_ADJUST;
              cout << m_sep_angle;
              cout << "°" << endl;
              //servo.setSepAngle(m_sep_angle);
	            //lcd.write(m_sep_angle);
            } else {
              cout << "Can't further decrease" << endl;
            }
          }
          //if button 2 was pressed then increase the angle by MOTOR_ADJUST
          if (m_b2_changed == 1 && m_b1 == 0) {

            if (m_sep_angle < 70) {
              m_sep_angle += M_REST_ADJUST;
              cout << m_sep_angle;
              cout << "°" << endl;
	            //servo.setSepAngle(m_sep_angle);
              //lcd.write(m_sep_angle);
            } else {
              cout << "Can't further increase" << endl;
            }
          }
        }
        m_exit_counter = 0;
        //needed so menu doesnt respond to the release of the button after exitting
        //a menu option
        m_prev_b1 = 0;
        m_prev_b2 = 0;
        cout << "Separation angle" << endl;
        //allow time for the release of the button after exiting the menu option
        usleep(M_DEBOUNCE*20);

        //lcd.write("Separation angle");
      }
      //have to set the rest position
      else {
        //cout << "Rest position" << endl;
	      //cout << m_rest_position;
        // cout << "°" << endl;
	      usleep(M_DEBOUNCE * 10);

        // updating on what state the GPIOs in prior to entering the loop
        auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);

        //m_rest_position = servo.getRestPosition();
        cout << m_rest_position;

        // stay in the loop until a button is pressed down for a while
        while (m_exit_counter < M_EXIT_TIME/M_DEBOUNCE) {

          //reading button states
          auto [m_b1, m_b2, m_prev_b1, m_prev_b2, m_b1_changed, m_b2_changed] = Menu::updateButtons(m_prev_b1, m_prev_b2);

          // if either button is pressed down increase exit counter
        	if ((m_b1 || m_b2) == 1) {
            m_exit_counter += 1;
          }

          //int motor_angle = servo.get_motor_angle();
          //if button 1 was pressed then decrease the angle by MOTOR_ADJUST
          if (m_b1_changed == 1 && m_b2 == 0) {
            if (m_rest_position > REST_LOW_LIMIT + m_sep_angle) {
		          //servo.setClear(m_rest_position -= M_REST_ADJUST);
              m_rest_position -= M_REST_ADJUST;
              cout << m_rest_position;
              cout << "°"<< endl;
              //servo.setClear(m_rest_position);
	            //lcd.write(m_rest_position);
            } else {
              cout << "Can't further decrease" << endl;
            }
          }
          //if button 2 was pressed then increase the angle by MOTOR_ADJUST
          if (m_b2_changed == 1 && m_b1 == 0) {
            if (m_rest_position < REST_UP_LIMIT - m_sep_angle) {
              m_rest_position += M_REST_ADJUST;
              cout << m_rest_position<< "°"<< endl;
		          //servo.setClear(m_rest_position);
              //lcd.write(m_rest_position);
            } else {
              cout << "Can't further increase" << endl;
            }
          }
        }
        m_exit_counter = 0;
        //needed so menu doesnt respond to the release of the button after exitting
        //a menu option
        m_prev_b1 = 0;
        m_prev_b2 = 0;
        cout << "Rest position" << endl;
        //allow time for the release of the button after exiting the menu option
        usleep(M_DEBOUNCE*20);
        //lcd.write("Rest position");
      }
    }
  }
}

/*
PROBLEMS:

if button is held down for too long after exiting a menu then it reacts to it
as if an input was given to it
potential solution: wait (loop) until button is released and only go back to the
main loop once a change in button state was detected
*/
