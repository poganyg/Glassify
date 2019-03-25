#include "rpiServo.h"

const int rpiServo::ERRDEG;// Error code

/*********************************************************************************
 * rpiServo constructor - Calls rpiPWM1's overloaded constructor
 * which basically creates a 50Hz PWM waveform, wih a resolution count of 3600, 
 * a duty cycle of 7.5% (1.5ms ON pulse every 20ms to center servo shaft at 
 * 90 degree position) and traditional PWM mode (rpiPWM1::MSMODE)
 *
 * By setting count resolution to 3600 counts, one 20ms period is equivalent to
 * to 3600 counts, 2ms ON time (180 degree position)  is equivalent to 360 counts 
 * and 1ms ON time (0 degree position) is equivalent to 180 counts. This gives us
 * 180 counts between the 0 degree position and the 180 degree position hence we 
 * get 1 degree rotation resolution 
 *
 *********************************************************************************/

rpiServo::rpiServo():rpiPWM1(50.0,3600,7.5,rpiPWM1::MSMODE){
    // 20ms = 3600 counts (Period)
    // 2ms = 360 counts (10% duty cycle)  => angle 180
    // 1ms = 180 counts (5% duty cycle) => angle 0
    // 1.5ms = 180+90 = 270 (7.5%  duty cycle ) => angle = 90 //servo centered
}


/************************************************************************
 *setAngle() - function sets the angle of the servo's shaft 
 *Parameters - degrees - new shaft angle. Can be any value between 0 and 180 only
 *
 *return Value - If parameter 'degrees' was between 0 and 180 (inclusive) then
                 return value is 0 else its spiServo::ERRDEG
 ***********************************************************************/	

unsigned int  rpiServo::setAngle(unsigned int degrees){
	unsigned int retVal = 0;
	
	if((degrees < 0) || (degrees > 180 ))
		retVal = ERRDEG;
	else	
	this->setDutyCycleCount(180 + degrees); // call the necessary rpiPWM1 method
	
	return retVal;
}
