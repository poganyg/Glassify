#include <chrono>
#include <thread>
#include <math.h>
#include <cmath>
#include <wiringPi.h>
#include "libServo.h"
#include <iostream>
#include <fstream>
using namespace std;

Servo::Servo(int pin)
  :m_pin(pin),m_brownAngle(45),m_clearAngle(90),m_greenAngle(135)
//{   int RestPos;
    //this->pin=pin;
{   wiringPiSetupGpio();
    pinMode(m_pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);
    pwmSetRange(1000);
    Servo::init(90);

    string line;
    ifstream calibFile ("calibration_values");
    getline (calibFile,line);
    m_clearAngle = std::stoi( line );
    getline (calibFile,line);
    m_HaltTime = std::stoi( line );
    getline (calibFile,line);
    m_SepAngle = std::stoi( line );
    calibFile.close();
    cout << m_clearAngle << endl;
    cout << m_HaltTime << endl;
    cout << m_SepAngle << endl;
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

    std::this_thread::sleep_for(std::chrono::milliseconds(m_HaltTime));
}

void Servo::moveCalib(float degree)
{
float t=degree*100/180+25;
pwmWrite(this->m_pin, t);
m_lastDegree=degree;
}

void Servo::moveBrown()
{
m_brownAngle=m_clearAngle+m_SepAngle;
  Servo::move(m_brownAngle);
}

void Servo::moveClear()
{
  Servo::move(m_clearAngle);
}

void Servo::moveClearCalib()
{
Servo::moveCalib(m_clearAngle);
}

void Servo::moveGreen()
{
m_greenAngle=m_clearAngle+m_SepAngle;
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
  Servo::moveClearCalib();
}

void Servo::setGreen(float greenAngle)
{
  this->m_greenAngle=greenAngle;
  Servo::moveGreen();
}

int Servo::getRestPosition()
{
return this->m_clearAngle;
}

void Servo::setHaltTime(int Htime)
{
this->m_HaltTime=Htime;
}

int Servo::getHaltTime()
{
return this->m_HaltTime;
}

void Servo::setSepAngle(float SepAngle)
{
this->m_SepAngle=SepAngle;
Servo::saveCalibValues();
}

int Servo::getSepAngle()
{
return this->m_SepAngle;
}

void Servo::saveCalibValues()
{
  ofstream calibFile;
  calibFile.open ("calibration_values");
  calibFile << this->m_clearAngle << endl;
  calibFile << this->m_HaltTime << endl;
  calibFile << this->m_SepAngle;
  calibFile.close();
}
