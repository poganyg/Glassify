/** @file
* @brief Defines class which enabels the LCD to print the any required input
* @author Gergerly Pogany
*/
#ifndef DISPLAY
#define DISPLAY

#include <wiringPi.h>
#include <lcd.h>
#include <iostream>
#include <string>


#define LCD_RS 5      //!<Register select pin
#define LCD_E 4       //!<Enable Pin
#define LCD_D4 8      //!<Data pin D4
#define LCD_D5 7      //!<Data pin D5
#define LCD_D6 16     //!<Data pin D6
#define LCD_D7 15     //!<Data pin D7

using namespace std;
/**
* @brief Initialises and allows wriiting to LCD display
*/
class Display
{
private:

public:
  /**
  *	@brief initialisation of LCD with correct pins and assigning it an integer to be
  *	later called by.
  */
  /**
  Constructor
  */
  Display();
  /**
  * @brief Clears then allows printing of a simple string to the LCD display
  * @param input string to be printed
  */
  void simplePrint(std::string input);
  /**
  * @brief Clears then writes a integer followed by a string to the LCD
  * @param val integer to be printed
  * @param input string to be printed after the integer
  */
  void concatenatePrint(int val, std::string input);
  /**
  * @brief Clears screen then prints a string, integer and second string
  * @param input The initial string to be printed
  * @param val The integer to be printed after the first string
  * @param input2 The final string to be printed
  */
  void concatenateThreePrint(std::string input, int val, std::string input2);

  int m_height=2;//!< Height of LCD display in lines
  int m_width=16;//!< Width of screen in characters
  int m_bits=4;//!< The control resolution of the LCD
  int M_LCD = lcdInit (this->m_height, this->m_width, this->m_bits, LCD_RS, LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);

};

#endif
