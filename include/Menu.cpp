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
  int whichButton = 4;
  while (m_stateptr->getBuffer()==0 && m_stateptr->getState()==0 && whichButton==4)
  {
    bool debounce = true;
    int b1 = digitalRead(M_BUTTON1);
    int b2 = digitalRead(M_BUTTON2);
    if(b1==1 || b2==1)
    {std::this_thread::sleep_for(std::chrono::milliseconds(M_DEBOUNCE));
      if(b1==1 || b2==2)
      {debounce=false;}
    }
    if (debounce == false){
      auto start = chrono::steady_clock::now();
      if(b1==1 && b2==1)
      {
        whichButton = 1;
      }
      else if(b1==1 && b2==0)
      {
        whichButton = 1;
      }
      else if(b1==0 && b2==1)
      {
        whichButton = 2;
      }
      while (m_stateptr->getBuffer()==0 && m_stateptr->getState()==0 && (b1==1 || b2==1))
      {
        b1 = digitalRead(M_BUTTON1);
        b2 = digitalRead(M_BUTTON2);
        auto end = chrono::steady_clock::now();
        if (((chrono::duration_cast<chrono::seconds>(end - start).count())>1) && ((chrono::duration_cast<chrono::seconds>(end - start).count())<10))
        {
          whichButton = 3;
        }
        if (chrono::duration_cast<chrono::seconds>(end - start).count()>10)
        {
          whichButton = 0;
          break;
        }
      }
    }
  }
  if (m_stateptr->getBuffer()!=0 && m_stateptr->getState()!=0)
  {
    whichButton = 0;
    while (m_stateptr->getBuffer()!=0 && m_stateptr->getState()!=0)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  }
  cout << whichButton << endl;
  return whichButton;
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
      } else  m_displayptr->simplePrint("hi Reuben");
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
