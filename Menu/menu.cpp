#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include "Display.h"
#include "libServo.h"
#include <lcd.h>

#define LCD_RS 5               //Register select pin
#define LCD_E 4               //Enable Pin
#define LCD_D4 8               //Data pin D4
#define LCD_D5 1               //Data pin D5 - REWRITE TO PIN 7 WITH NEW PCB
#define LCD_D6 16               //Data pin D6
#define LCD_D7 15

using namespace std;


int main() {
  cout << "got into main" << endl;

  // initialisations

  wiringPiSetup();

  Display display;
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


cout << "inmenu" << endl;

  const char* str = "boink";
  //const char* X = "servo halt time";
  //displayptr->write((string) menu_vector[i]);
  display.write(str);

  cout << menu_vector[i] << endl;

 // printf("before digitalRead\n");

  int b1 = digitalRead(button1);
  int b2 = digitalRead(button2);
  int prev_b1 = b1;
  int prev_b2 = b2;
  int b1_changed = 0;
  int b2_changed = 0;

 // printf("passed digitalRead\n");

  while(true) {

    usleep(DEBOUNCE);
    b1 = digitalRead(button1);
    b2 = digitalRead(button2);
/*
    cout << b1;
    cout << b2;
    cout << prev_b1;
    cout << prev_b2;
    cout << b1_changed;
    cout << b2_changed << endl;
*/
    b1_changed = 0;
    b2_changed = 0;
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

    // stepping to the next menu option
    if (b1_changed == 1 && b2 == 0) {

      i = i + 1;

      // moving back to the first menu item
      if (i > array_length - 1) {
        i = 0;
      }

      cout << menu_vector[i] << endl;
      //lcd.write(menu_vector[i]);
    }

    // entering a menu option
    if (b1 == 0 && b2_changed == 1) {

      // Have to set the servo halt time
      if (i == 0) {
        //cout << "Servo halt time" << endl;
	      cout << halt_time;
        cout << " ms" << endl;
        //longer so the buttonpress from entering the menu doesnt affect menu
        //options
	      usleep(DEBOUNCE*10);
        // updating on what state the GPIOs in prior to entering the loop
        b1 = digitalRead(button1);
        b2 = digitalRead(button2);
        prev_b1 = b1;
        prev_b2 = b2;
        b1_changed = 0;
        b2_changed = 0;

        // stay in the loop until a button is pressed down for a while
        while (exit_counter < EXIT_TIME/DEBOUNCE) {
          //consider putting all of these in a "updateButtonReads" functions
          //debounce delay
          usleep(DEBOUNCE);
          //updating the pins state
          b1 = digitalRead(button1);
          b2 = digitalRead(button2);
          b1_changed = 0;
          b2_changed = 0;
          //checking if the button was pressed or released
          if (b1 != prev_b1) {
            if (b1 == 0) {
              b1_changed = 1;
              // if button was released reset exit counter
	            exit_counter = 0;
            }
            prev_b1 = b1;
          } else {
            b1_changed = 0;
          }
          if (b2 != prev_b2) {
            if (b2 == 0) {
              b2_changed = 1;
              // if button was released reset exit counter
              exit_counter = 0;
            }
            prev_b2 = b2;
          } else {
            b2_changed = 0;
          }

          // if either button is pressed down increase exit counter
        	if ((b1 || b2) == 1) {
            exit_counter += 1;
          }

         // int motor_angle = servo.getRestPosition();
         // cout << motor_angle <<endl;          //if button 1 was pressed then decrease the angle by MOTOR_ADJUST
          if (b1_changed == 1 && b2 == 0) {

            if (halt_time > 100) {
              halt_time -= HALT_ADJUST;
              cout << halt_time;
              cout << " ms"<< endl;
              //servo.setHaltTime(halt_time);
	            //lcd.write(halt_time);
            } else {
              cout << "Can't further decrease" << endl;
            }
          }
          //if button 2 was pressed then increase the angle by MOTOR_ADJUST
          if (b2_changed == 1 && b1 == 0) {
            if (halt_time < 2000) {
              halt_time += HALT_ADJUST;
              cout << halt_time;
              cout << " ms"<< endl;
              //servo.setHaltTime(halt_time);
		          //lcd.write(halt_time);
            } else {
              cout << "Can't further increase" << endl;
            }
          }
        }
        exit_counter = 0;
        //needed so menu doesnt respond to the release of the button after exitting
        //a menu option
        prev_b1 = 0;
        prev_b2 = 0;
        cout << "Servo halt time" << endl;
        //allow time for the release of the button after exiting the menu option
        usleep(DEBOUNCE*20);
        //lcd.write("Servo halt time");
      }
      //have to set separation angle
      else if (i == 1) {
        //cout << "Separation angle" << endl;
	      cout << sep_angle;
        cout << "°" << endl;
	      usleep(DEBOUNCE*10);

        // updating on what state the GPIOs in prior to entering the loop
        b1 = digitalRead(button1);
        b2 = digitalRead(button2);
        prev_b1 = b1;
        prev_b2 = b2;
        b1_changed = 0;
        b2_changed = 0;

        // stay in the loop until a button is pressed down for a while
        while (exit_counter < EXIT_TIME/DEBOUNCE) {

          //consider putting all of these in a "updateButtonReads" functions
          //debounce delay
          usleep(DEBOUNCE);
          //updating the pins state
          b1 = digitalRead(button1);
          b2 = digitalRead(button2);
          b1_changed = 0;
          b2_changed = 0;
          //checking if the button was pressed or released
          if (b1 != prev_b1) {
            if (b1 == 0) {
              b1_changed = 1;
              // if button was released reset exit counter
	            exit_counter = 0;
            }
            prev_b1 = b1;
          } else {
            b1_changed = 0;
          }
          if (b2 != prev_b2) {
            if (b2 == 0) {
              b2_changed = 1;
              // if button was released reset exit counter
              exit_counter = 0;
            }
            prev_b2 = b2;
          } else {
            b2_changed = 0;
          }

          // if either button is pressed down increase exit counter
        	if ((b1 || b2) == 1) {
            exit_counter += 1;
          }

          //int motor_angle = servo.get_motor_angle();
          //if button 1 was pressed then decrease the angle by MOTOR_ADJUST
          if (b1_changed == 1 && b2 == 0) {

            if (sep_angle > 10) {
              sep_angle -= SEP_ADJUST;
              cout << sep_angle;
              cout << "°" << endl;
              //servo.setSepAngle(sep_angle);
	            //lcd.write(sep_angle);
            } else {
              cout << "Can't further decrease" << endl;
            }
          }
          //if button 2 was pressed then increase the angle by MOTOR_ADJUST
          if (b2_changed == 1 && b1 == 0) {

            if (sep_angle < 70) {
              sep_angle += SEP_ADJUST;
              cout << sep_angle;
              cout << "°" << endl;
	            //servo.setSepAngle(sep_angle);
              //lcd.write(sep_angle);
            } else {
              cout << "Can't further increase" << endl;
            }
          }
        }
        exit_counter = 0;
        //needed so menu doesnt respond to the release of the button after exitting
        //a menu option
        prev_b1 = 0;
        prev_b2 = 0;
        cout << "Separation angle" << endl;
        //allow time for the release of the button after exiting the menu option
        usleep(DEBOUNCE*20);

        //lcd.write("Separation angle");
      }
      //have to set the rest position
      else {
        //cout << "Rest position" << endl;
	      //cout << rest_position;
        // cout << "°" << endl;
	      usleep(DEBOUNCE * 10);
        // updating on what state the GPIOs in prior to entering the loop
        b1 = digitalRead(button1);
        b2 = digitalRead(button2);
        prev_b1 = b1;
        prev_b2 = b2;
        b1_changed = 0;
        b2_changed = 0;

        //rest_position = servo.getRestPosition();
        cout << rest_position;

        // stay in the loop until a button is pressed down for a while
        while (exit_counter < EXIT_TIME/DEBOUNCE) {
          //consider putting all of these in a "updateButtonReads" functions
          //debounce delay
          usleep(DEBOUNCE);
          //updating the pins state
          b1 = digitalRead(button1);
          b2 = digitalRead(button2);
          b1_changed = 0;
          b2_changed = 0;
          //checking if the button was pressed or released
          if (b1 != prev_b1) {
            if (b1 == 0) {
              b1_changed = 1;
              // if button was released reset exit counter
	            exit_counter = 0;
            }
            prev_b1 = b1;
          } else {
            b1_changed = 0;
          }
          if (b2 != prev_b2) {
            if (b2 == 0) {
              b2_changed = 1;
              // if button was released reset exit counter
              exit_counter = 0;
            }
            prev_b2 = b2;
          } else {
            b2_changed = 0;
          }

          // if either button is pressed down increase exit counter
        	if ((b1 || b2) == 1) {
            exit_counter += 1;
          }

          //int motor_angle = servo.get_motor_angle();
          //if button 1 was pressed then decrease the angle by MOTOR_ADJUST
          if (b1_changed == 1 && b2 == 0) {
            if (rest_position > REST_LOW_LIMIT + sep_angle) {
		          //servo.setClear(rest_position -= REST_ADJUST);
              rest_position -= REST_ADJUST;
              cout << rest_position;
              cout << "°"<< endl;
              //servo.setClear(rest_position);
	            //lcd.write(rest_position);
            } else {
              cout << "Can't further decrease" << endl;
            }
          }
          //if button 2 was pressed then increase the angle by MOTOR_ADJUST
          if (b2_changed == 1 && b1 == 0) {
            if (rest_position < REST_UP_LIMIT - sep_angle) {
              rest_position += REST_ADJUST;
              cout << rest_position<< "°"<< endl;
		          //servo.setClear(rest_position);
              //lcd.write(rest_position);
            } else {
              cout << "Can't further increase" << endl;
            }
          }
        }
        exit_counter = 0;
        //needed so menu doesnt respond to the release of the button after exitting
        //a menu option
        prev_b1 = 0;
        prev_b2 = 0;
        cout << "Rest position" << endl;
        //allow time for the release of the button after exiting the menu option
        usleep(DEBOUNCE*20);
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
