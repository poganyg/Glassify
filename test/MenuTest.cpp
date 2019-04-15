#include "Menu.h"
#include "assert_print.h"

int concatenate(int arr1, int arr2)
{
  int * result = new int[sizeof(arr1) + sizeof(arr2)];
  std::copy(arr1, arr1 + sizeof(arr1), result);
  std::copy(arr2, arr2 + sizeof(arr2), result + sizeof(arr1));
  return result;
}

int main()
wiringPiSetup()
{
Display display;
Display* displayptr = &display;
State state;
State* stateptr = &state;
Servo servo(1);
Servo* servoptr = &servo;
Buttons button(stateptr);
Buttons* buttonptr = &button;
Menu menu(displayptr,servoptr,stateptr,buttonptr);

//TESTING THAT IT IS POSSIBLE TO EXIT SUBMENU -> IF NOT POSSIBLE, SCRIPT TIMES OUT
menu.testVector=testExit;
menu.haltTimeMenu();
menu.separationAngleMenu();
menu.restAngleMenu();

menu.testVector=concatenate

int testExit=0;
int testValueDown[3]={3,1,3};
int testValueUp[3]={3,2,3};
int testMinValue[32]={3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3};
int testMaxValue[32]={3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
int prefaceA=1;
int prefaceB[2]={1,1};
int prefaceC=2;
int prefaceD[2]={2,2};






//Testing Exits of Each submenu

//WAIT UNTIL BUTTONS ARE MADE A SEPARATE CLASS.



}
