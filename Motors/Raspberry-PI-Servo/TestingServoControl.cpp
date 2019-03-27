//#include <wiringPi.h>
//#include <cstdlib>
//#include <iostream>
//#include "libServo.h"
#include "ServoControl.h"
#include "libServo.cpp"

int main(){
	motorMove shift;
	shift.motorSetup();
	shift.isGreen();
	return 0;
}
