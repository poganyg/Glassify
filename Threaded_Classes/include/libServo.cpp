#include <math.h>
#include <cmath>
#include <wiringPi.h>
#include "libServo.h"

Servo::Servo(int pin)
  :m_pin(pin),m_brownAngle(45),m_clearAngle(90),m_greenAngle(135)
{
    //this->pin=pin;
    wiringPiSetupGpio();
    pinMode(m_pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);
    pwmSetRange(1000);
    Servo::init(90);
}

void Servo::init(float degree)
{
    float t=degree*100/180+25;
//    pwmWrite(this->pin, t);
    m_lastDegree=degree;
    //delay(1000);
}

void Servo::move(float degree)
{
    float t=degree*100/180+25;
    float t2=abs(m_lastDegree-degree)*100/180;
    pwmWrite(this->m_pin, t);
    m_lastDegree=degree;
    //delay(t2*5);
}

void Servo::moveBrown()
{
  Servo::move(m_brownAngle);
}

void Servo::moveClear()
{
  Servo::move(m_clearAngle);
}

void Servo::moveGreen()
{
  Servo::move(m_greenAngle);
}

void Servo::setBrown(float brownAngle)
{
  this->m_brownAngle=brownAngle;
  Servo::moveBrown();
}

void Servo::setClear(float clearAngle)
{
  this->m_clearAngle=clearAngle;
  Servo::moveClear();
}

void Servo::setGreen(float greenAngle)
{
  this->m_greenAngle=greenAngle;
  Servo::moveGreen();
}
