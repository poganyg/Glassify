#include <math.h>
#include <cmath>
#include <wiringPi.h>
#include "libServo.h"
#include <thread>

Servo::Servo(int pin,float brownAngle,float clearAngle,float greenAngle)
  :m_pin(pin),m_brownAngle(brownAngle),m_clearAngle(clearAngle),m_greenAngle(greenAngle)
{
    wiringPiSetup();
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
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
