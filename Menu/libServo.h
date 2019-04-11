#ifndef DEF_SERVO
#define DEF_SERVO

class Servo
{
  public:
    Servo(int pin);
    void init(float degree);
    void move(float degree);
    void moveCalib(float degree);
    void moveBrown();
    void moveClear();
    void moveClearCalib();
    void moveGreen();
    void setBrown(float brownAngle);
    void setClear(float clearAngle);
    void setGreen(float greenAngle);
    void setHaltTime(int Htime);
    void setSepAngle(float SepAngle);
    int getRestPosition();
    int getHaltTime();
    int getSepAngle();
    void saveCalibValues();

  private:
    int m_pin;
    float m_greenAngle;
    float m_brownAngle;
    float m_clearAngle;
    float m_lastDegree;
    int m_HaltTime;
    float m_SepAngle;
};

#endif
