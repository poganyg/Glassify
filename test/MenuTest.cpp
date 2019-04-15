#include <algorithm>
#include <iostream>
#include "Menu.h"
#include "assert_print.h"

using namespace std;


int main()
{
int origHalt;
int origSep;
int origRest;

wiringPiSetup()
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
menu.testVector={0};
menu.haltTimeMenu();
menu.separationAngleMenu();
menu.restAngleMenu();

//TEST RAISING VALUE TO LIMIT
menu.testVector={3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,0};
menu.haltTimeMenu();
if(menu.m_halt_time!=menu.M_HALT_UP_LIMIT){assert_print("Failed to increase halt time to the maximum value");}

//TEST LOWERING VALUE TO LIMIT
menu.testVector={3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0};
menu.haltTimeMenu();
if(menu.m_halt_time!=menu.M_HALT_LOW_LIMIT){assert_print("Failed to reduce halt time to the minimum value");}

//TEST LOWERING SEPARATION ANGLE TO LIMIT
menu.testVector={3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0};
menu.separationAngleMenu();
if(menu.m_sep_angle!=menu.M_SEP_LOW_LIMIT){assert_print("Failed to reduce separation angle to lower limit");}

//TEST RAISING SEPARATION ANGLE TO LIMIT
menu.testVector={3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,0};
menu.separationAngleMenu();
if(menu.m_sep_angle!=min((135-menu.m_rest_position),abs(45-menu.m_rest_position))){assert_print("Failed to reduce separation angle to lower limit");}

//TEST LOWERING REST ANGLE TO LIMIT
menu.testVector={3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0};
menu.restAngleMenu();
if(menu.m_rest_position!=45+menu.m_sep_angle){assert_print("Failed to reduce rest angle to lower limit");}

//TEST RAISING REST ANGLE TO LIMIT
menu.testVector={3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,0};
menu.restAngleMenu();
if(menu.m_rest_position!=135-menu.m_sep_angle){assert_print("Failed to raise rest angle to upper limit");}

menu.testVector={1,4}
menu.mainMenu();
if(m_menu_vector[m_i]!="Separation angle"){assert_print("Main menu scrolling dysfunctional");}

menu.testVector={2,2,4}
menu.mainMenu();
if(m_menu_vector[m_i]!="Rest position"){assert_print("Main menu scrolling dysfunctional");}


}
