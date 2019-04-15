#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <vector>
#include "Display.h"
#include <unistd.h>
#include "libServo.h"
#include <lcd.h>
#include <tuple>
#include "Menu.h"

using namespace std;
int testExit=0;
int testValueDown[3]={3,1,3};
int testValueUp[3]={3,2,3};
int testMinValue[32]={3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3};
int testMaxValue[32]={3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
int prefaceA=1;
int prefaceB[2]={1,1};
int prefaceC=2;
int prefaceD[2]={2,2};
int testVector;

Menu::Menu(Display* _displayptr, Servo* _servoptr, State* _stateptr) //still need to add servo pointer and state pointer
:M_BUTTON1 (2), M_BUTTON2 (3), M_EXIT_TIME (500000), M_DEBOUNCE (50000), M_HALT_ADJUST (100), M_SEP_ADJUST (5), M_REST_ADJUST (5), M_HALT_LOW_LIMIT (100), M_SEP_LOW_LIMIT (5), M_REST_LOW_LIMIT (50), M_HALT_UP_LIMIT (2000), M_SEP_UP_LIMIT (25), M_ARRAY_LENGTH (3), m_displayptr(_displayptr), m_servoptr(_servoptr), m_stateptr(_stateptr)
{
  pinMode(M_BUTTON1, INPUT);
  pinMode(M_BUTTON2, INPUT);
  pullUpDnControl(M_BUTTON1, PUD_DOWN);
  pullUpDnControl(M_BUTTON2, PUD_DOWN);
  M_REST_UP_LIMIT = 180-M_REST_LOW_LIMIT;
  m_menu_vector.push_back("Servo halt time");
  m_menu_vector.push_back("Separation angle");
  m_menu_vector.push_back("Rest position");
  m_i = 0;
  m_halt_time = m_servoptr->getHaltTime();
  m_sep_angle = m_servoptr->getSepAngle();
  m_rest_position = m_servoptr->getRestPosition();
}



int Menu::buttonPress()
{
  length = sizeof(testVector);
  if(length>1)
  {
    for(i=0,i<<(length-2),i++)
    {
      testVector[i]=testVector[i+1];
    }
  }
}


void Menu::haltTimeMenu()
{
  m_displayptr->concatenatePrint( m_halt_time, " ms" );
  while (true) {
    retVal = Menu::buttonPress();
    if (retVal == 1) {
      if (m_halt_time > 100) {
        m_halt_time -= M_HALT_ADJUST;
      } else
      {
        m_displayptr->simplePrint("Cannot further reduce");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
      m_displayptr->concatenatePrint(m_halt_time, "ms");
    }

    if (retVal == 3) {
      m_servoptr->setHaltTime(m_halt_time);
      m_displayptr->concatenateThreePrint( "Servo halt time set to ", m_halt_time, " ms"  );
      break;
    }

    if (retVal == 2) {
      if (m_halt_time < 2000) {
        m_halt_time += M_HALT_ADJUST;
      } else
      {
        m_displayptr->simplePrint("Cannot further increase");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

      }
      m_displayptr->concatenatePrint(m_halt_time, "ms");
    }

    if (retVal == 0){
      break;
    }
  }
}

void Menu::separationAngleMenu()
{
  m_displayptr->simplePrint( "Moved to Rest" );
  m_servoptr->moveCalib(m_rest_position);
  m_displayptr->concatenatePrint( m_sep_angle, "deg" );

  while (true) {
    retVal = Menu::buttonPress();
    digitalWrite(9,HIGH);
    if (retVal == 1) {
      if (m_sep_angle > 10 && (m_rest_position-m_sep_angle-M_REST_ADJUST)>=45 && (m_sep_angle+m_rest_position-M_REST_ADJUST)<=135){
        m_sep_angle -= M_SEP_ADJUST;
        m_displayptr->concatenatePrint( m_sep_angle, "deg" );
      }
      else {
        m_displayptr->simplePrint("Cannot further reduce");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
      m_servoptr->moveCalib(m_rest_position-m_sep_angle);
    }

    if (retVal == 3) {
      m_servoptr->setSepAngle(m_sep_angle);
      m_displayptr->concatenateThreePrint( "Separation angle set to ", m_sep_angle,  "deg" );
      digitalWrite(9,LOW);
      break;
    }

    if (retVal == 2) {
      if (m_sep_angle < 45 && (m_rest_position-m_sep_angle+M_REST_ADJUST)>=45 && (m_sep_angle+m_rest_position+M_REST_ADJUST)<=135) {
        m_sep_angle += M_SEP_ADJUST;
        m_displayptr->concatenatePrint( m_sep_angle, "deg" );
      }
      else
      {
        m_displayptr->simplePrint("Cannot further increase");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
      m_servoptr->moveCalib(m_rest_position-m_sep_angle);
    }

    if (retVal == 0){
      break;
    }
  }
}

void Menu::restAngleMenu()
{
  digitalWrite(9,HIGH);
  m_servoptr->moveCalib(m_rest_position);
  m_displayptr->concatenatePrint( m_rest_position, "deg" );
  while (true) {
    retVal = Menu::buttonPress();
    if (retVal == 1) {
      if (m_rest_position > 55 && (m_rest_position-m_sep_angle-M_REST_ADJUST)>=45 && (m_sep_angle+m_rest_position-M_REST_ADJUST)<=135) {
        m_rest_position -= M_REST_ADJUST;
        m_servoptr->moveCalib(m_rest_position);
        m_displayptr->concatenatePrint( m_rest_position, "deg" );
      }
      else {
        m_displayptr->simplePrint("Cannot further reduce");
      }
    }

    if (retVal == 3) {
      m_servoptr->setRestPosition(m_rest_position);
      //SET THE SELECTED VALUE
      m_displayptr->concatenateThreePrint( "Rest position set to ", m_rest_position, "deg" );
      digitalWrite(9,LOW);
      break;
    }

    if (retVal == 2) {
      if (m_rest_position < 125 && (m_rest_position-m_sep_angle+M_REST_ADJUST)>=45 && (m_sep_angle+m_rest_position+M_REST_ADJUST)<=135) {
        m_rest_position += M_REST_ADJUST;
        m_servoptr->moveCalib(m_rest_position);
        m_displayptr->concatenatePrint( m_rest_position, "deg" );
      }
      else {
        m_displayptr->simplePrint("Cannot further increase");
      }
    }

    if (retVal == 0){
      break;
    }

  }
}


int Menu::mainMenu() {
  m_displayptr->simplePrint( m_menu_vector[m_i] );
  int m_i = 0;
  while(true) {
    // ------------- NEXT MENU OPTION -------------
    // stepping to the next menu option
    //cout<<"INLOOP"<<endl;
    retVal = Menu::buttonPress();
    //cout<<retVal<<endl;
    if (retVal == 1) {
      m_i = m_i - 1;
      if (m_i == -1) {
        m_i = M_ARRAY_LENGTH-1;
      }
      m_displayptr->simplePrint( m_menu_vector[m_i] );
    }

    if (retVal == 2) {
      m_i = m_i + 1;
      if (m_i > M_ARRAY_LENGTH - 1) {
        m_i = 0;
      }
      m_displayptr->simplePrint( m_menu_vector[m_i] );
    }

    // ------------- NEXT MENU OPTION -------------
    // entering a menu option
    if (retVal == 3) {
      // Have to set the servo halt time
      if (m_i == 0) {
        Menu::haltTimeMenu();
      }
      //have to set separation angle
      else if (m_i == 1) {
        Menu::separationAngleMenu();
      }
      //have to set the rest position
      else {
        Menu::restAngleMenu();
      }
      m_servoptr->saveCalibValues();
    }
  }
}
