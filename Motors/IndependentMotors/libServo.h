#ifndef DEF_SERVO
#define DEF_SERVO

class Servo
{
  public:
    Servo(int pin);
    void init(float degree);
    void move(float degree);

  private:
    int pin;
    float lastDegree;
};

#endif
