#include <math.h>
#include <cmath>
#include <wiringPi.h>
#include "libServo.h"

Servo::Servo(int pin)
{
    this->pin=pin;
    pinMode(pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);
    pwmSetRange(1000);
}

void Servo::init(float degree)
{
    float t=degree*100/180+25;
//    pwmWrite(this->pin, t);
    lastDegree=degree;
    //delay(1000);
}

void Servo::move(float degree)
{
    float t=degree*100/180+25;
    float t2=abs(lastDegree-degree)*100/180;
    pwmWrite(this->pin, t);
    lastDegree=degree;
    //delay(t2*5);
}
