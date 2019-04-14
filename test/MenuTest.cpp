

#include "Menu.h"
#include "assert_print.h"

int main()
wiringPiSetup()
{
Display display;
Display* displayptr = &display;
State state;
State* stateptr = &state;
Servo servo(1);
Servo* servoptr = &servo;

Menu menu(displayptr,servoptr,stateptr);

//Testing Exits of Each submenu

//WAIT UNTIL BUTTONS ARE MADE A SEPARATE CLASS.



}
