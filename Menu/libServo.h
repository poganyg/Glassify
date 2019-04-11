#ifndef DEF_SERVO
#define DEF_SERVO

class Servo
{
  public:
    Servo(int pin);
    void init(float degree);
    void move(float degree);
    void moveBrown();
    void moveClear();
    void moveGreen();
    void setBrown(float brownAngle);
    void setClear(float clearAngle);
    void setGreen(float greenAngle);
    void setHaltTime(float Htime);
    void setSepAngle(float SepAngle);
    int getRestPosition();
    int getHaltTime();
    int getSepAngle();

  private:
    int m_pin;
    float m_greenAngle;
    float m_brownAngle;
    float m_clearAngle;
    float m_lastDegree;
    float m_HaltTime;
    float m_SepAngle;
};

#endif
