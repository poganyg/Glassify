#ifndef DISPLAY
#define DISPLAY

#include <wiringPi.h>
#include <lcd.h>
#include <iostream>
#include <string>


#define LCD_RS 5               //Register select pin
#define LCD_E 4               //Enable Pin
#define LCD_D4 8               //Data pin D4
#define LCD_D5 7               //Data pin D5 - REWRITE TO PIN 7 WITH NEW PCB
#define LCD_D6 16               //Data pin D6
#define LCD_D7 15

using namespace std;

class Display
{
  private:

  public:
    int M_LCD = lcdInit (2, 16, 4, LCD_RS, LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);
    Display();
    void simplePrint(std::string input);
    void concatenatePrint(int val, std::string input);
    void concatenateThreePrint(std::string input, int val, std::string input2);

};

#endif
