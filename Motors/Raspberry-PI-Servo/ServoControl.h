#include <wiringPi.h> // don't forget
#include <cstdlib>
#include <iostream>
#include "libServo.h"

using namespace std;

class motorMove{

public
int sec = 1000;
int pin=18;

void motorSetup(){
   wiringPiSetupGpio();
   if (wiringPiSetup() == -1)
      exit(1);
  Servo servo(pin);
  cout << "Initialising the servo for GPIO pin" << pin << endl;
  servo.init(90);
  delay(2 * sec);
}

void isGreen(){
servo.move(45);
delay(0.2*sec);
}
void isBrown(){
servo.move(90);
delay(0.2*sec);
}
void isWhite(){
servo.move(135);
delay(0.2*sec);
}

}
