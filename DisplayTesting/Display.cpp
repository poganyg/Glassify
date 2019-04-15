#include <wiringPi.h>
#include <lcd.h>
#include <iostream>

/*
//Using the standard GPIO numbering
#define LCD_RS  24               //Register select pin
#define LCD_E   23               //Enable Pin
//#define LCD_D0  29               //Data pin D0
//#define LCD_D1  28               //Data pin D1
//#define LCD_D2  27               //Data pin D2
//#define LCD_D3  26               //Data pin D3
//#define LCD_D4  21               //Data pin D4
//#define LCD_D5  18               //Data pin D5
//#define LCD_D6  23               //Data pin D6
//#define LCD_D7  24               //Data pin D7

#define LCD_D4  2               //Data pin D4
#define LCD_D5  18               //Data pin D5
#define LCD_D6  15               //Data pin D6
#define LCD_D7  14               //Data pin D7
*/

//Using the wiringPi numbering
#define LCD_RS 5               //Register select pin
#define LCD_E 4               //Enable Pin
//#define LCD_D0  29               //Data pin D0
//#define LCD_D1  28               //Data pin D1
//#define LCD_D2  27               //Data pin D2
//#define LCD_D3  26               //Data pin D3
//#define LCD_D4  21               //Data pin D4
//#define LCD_D5  18               //Data pin D5
//#define LCD_D6  23               //Data pin D6
//#define LCD_D7  24               //Data pin D7

#define LCD_D4 8               //Data pin D4
#define LCD_D5 1               //Data pin D5
#define LCD_D6 16               //Data pin D6
#define LCD_D7 15               //Data pin D7


using namespace std;
 
int main()
{
    int lcd;
    wiringPiSetup();
    int wiringPiSetupGpio (void);
    //lcd = lcdInit (2, 16, 8, LCD_RS, LCD_E, LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0);

    std:: cout << "Printing message to the display\n";

    lcdPuts(lcd, "Hello, world!");

	delay(2000);
}