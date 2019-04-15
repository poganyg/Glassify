#include "libServo.h"
using namespace std;

Servo::Servo(int pin)
:m_pin(pin),pwmClock(384),pwmRange(1000)
{
  pinMode(m_pin, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(pwmClock);
  pwmSetRange(pwmRange);

  string line;
  ifstream calibFile ("../include/calibration_values");

  getline (calibFile,line);
  m_clearAngle = std::stoi( line );
  getline (calibFile,line);
  m_HaltTime = std::stoi( line );
  getline (calibFile,line);
  m_SepAngle = std::stoi( line );

  calibFile.close();
  m_brownAngle=m_clearAngle - m_SepAngle;
  m_greenAngle=m_clearAngle + m_SepAngle;

  cout << m_clearAngle << endl;
  cout << m_HaltTime << endl;
  cout << m_SepAngle << endl;

  Servo::init();
}

void Servo::init()
{
  float t=m_clearAngle*100/180+25;
  pwmWrite(this->m_pin, t);
  m_lastDegree=m_clearAngle;
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
  Servo::move(m_greenAngle);
}

void Servo::setRestPosition(float clearAngle)
{
  this->m_clearAngle=clearAngle;
  Servo::moveClearCalib();
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
  m_brownAngle=m_clearAngle - m_SepAngle;
  m_greenAngle=m_clearAngle + m_SepAngle;
}

int Servo::getSepAngle()
{
  return this->m_SepAngle;
}

void Servo::saveCalibValues()
{
  ofstream calibFile;
  calibFile.open ("../include/calibration_values");
  calibFile << this->m_clearAngle <<endl;
  calibFile << this->m_HaltTime<<endl;
  calibFile << this->m_SepAngle;
  calibFile.close();
}
