#include "libServo.h"
#include "assert_print.h"

using namespace std;

int main(int,char**)
{
  wiringPiSetup();

Servo servo(1);

if (servo.m_pin!=1){assert_print("Pin for servo is not set to that which is assigned.");}
if (servo.pwmClock!=384){assert_print("The PWM clock is not set to 384.");}
if (servo.pwmRange!=1000){assert_print("The PWM range is not set to 1000.");}
if (servo.m_clearAngle<55 || servo.m_clearAngle>125){assert_print("Centre angle is not between 55 degress and 125 degrees (inclusive). Check 'calibration_values' file.");}
if (servo.m_SepAngle<5 || servo.m_SepAngle>45){assert_print("Separation angle is not between 5 degress and 45 degress (inclusive). Check 'calibration_values' file.");}
if ((servo.m_clearAngle-servo.m_SepAngle)<45 || (servo.m_clearAngle+servo.m_SepAngle)>135){assert_print("Range of motion of servo is not within 45 degress and 135 degress (inclusive). Check 'calibration_values' file.");}
if (servo.m_HaltTime<200 || servo.m_HaltTime>2000){assert_print("Halt time is not between 200ms and 2000ms (inclusive). Check 'calibration_values' file.");}
if (servo.m_clearAngle==servo.m_greenAngle || servo.m_clearAngle==servo.m_brownAngle || servo.m_brownAngle==servo.m_greenAngle){assert_print("Output angles are calculated invalidly.");}

float origClear = servo.m_clearAngle;
float origSep = servo.m_SepAngle;
int origHalt = servo.m_HaltTime;

servo.setRestPosition(9999);
if (servo.getRestPosition()!=9999){assert_print("Getting or Setting of Rest Position dysfunctional.");}
servo.setHaltTime(9999);
if (servo.getHaltTime()!=9999){assert_print("Getting or Setting of Halt Time dysfunctional.");}
servo.setSepAngle(9999);
if (servo.getSepAngle()!=9999){assert_print("Getting or Setting of Separation Angle dysfunctional.");}

servo.saveCalibValues();

string line;
ifstream calibFile ("../include/calibration_values");
getline (calibFile,line);
servo.m_clearAngle = std::stoi( line );
getline (calibFile,line);
servo.m_HaltTime = std::stoi( line );
getline (calibFile,line);
servo.m_SepAngle = std::stoi( line );
if (servo.m_SepAngle!=9999 || servo.m_clearAngle!=9999 || servo.m_HaltTime!=9999){assert_print("Setting of calibration values failed");}

servo.m_clearAngle=origClear;
servo.m_SepAngle=origSep;
servo.m_HaltTime=origHalt;
servo.saveCalibValues();
}
