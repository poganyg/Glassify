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
  cout<<"pastDisplay";
  State state;
  State* stateptr = &state;
  cout<<"paststate";
  Servo servo(18);
  cout<<"pastservoclass";
  Servo* servoptr = &servo;
  cout<<"past servo";
  Menu menu(displayptr, servoptr, stateptr);
  cout<<"pastsetup";
  menu.mainMenu();
}
