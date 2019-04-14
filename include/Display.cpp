#include <wiringPi.h>
#include <lcd.h>
#include <iostream>
#include "Display.h"
//#include <wiringPiDev.h>

//class Display {

//Using the wiringPi numbering
/*
#define LCD_RS 5               //Register select pin
#define LCD_E 4               //Enable Pin
#define LCD_D4 8               //Data pin D4
#define LCD_D5 1               //Data pin D5 - REWRITE TO PIN 7 WITH NEW PCB
#define LCD_D6 16               //Data pin D6
#define LCD_D7 15               //Data pin D7
*/
using namespace std;

Display::Display()
{
}

void Display::simplePrint(std::string input)
{
  const char* cstr = input.c_str();
  lcdClear(M_LCD);
  lcdPuts(M_LCD,cstr);
  cout << cstr << endl;

}

void Display::concatenatePrint(int val, std::string input)
{
  std::string str;
  str += std::to_string(val);
  str += input;
  const char* cstr = str.c_str();
  lcdClear(M_LCD);
  lcdPuts(M_LCD, cstr);
  cout << cstr << endl;

}

void Display::concatenateThreePrint(std::string input, int val, std::string input2)
{
  input += std::to_string(val);
  input += input2;
  const char* cstr = input.c_str();
  lcdClear(M_LCD);
  lcdPuts(M_LCD, cstr);
  cout << cstr << endl;

}
