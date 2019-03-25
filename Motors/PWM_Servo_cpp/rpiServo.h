#ifndef RPI_SERVO_H
#define RPI_SERVO_H

#include "rpiPWM1.h"

/******************************************************************
 * rpiServo - This tiny C++ class is able to generate waveforms necessary to 
 * control servos. This class is derived from the rpiPWM1 class. 
 * It consists of a constructor that creates a 50Hz PWM waveform with
 * a 1.5ms ON time pulse...causing the servo to center itself to the
 * 90 degree position.
 *
 * The class also consists on a setAngle method that sets the angle of 
 * rotation to anything between 0 & 180 degrees
 * ****************************************************************/

class rpiServo : public rpiPWM1
{

public: 
	rpiServo();
	unsigned int  setAngle(unsigned int degrees);
	static const int ERRDEG=1;
};

#endif
