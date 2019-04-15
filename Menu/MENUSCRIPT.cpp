#include "Menu.h"
#include "Display.h"
#include "libServo.h"
#include "state.h"

int main()
{
  wiringPiSetup();
  int wiringPiSetupGpio (void);
  Display display;
  Display* displayptr = &display;
  State state;
  State* stateptr = &state;
  Servo servo(1);
  Servo* servoptr = &servo;
  Menu menu(displayptr, servoptr, stateptr);
  menu.mainMenu();
}
