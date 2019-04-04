#include <wiringPi.h>
#include <cstdlib>
#include <iostream>
#include "libServo.h"
#include "libServo.cpp"

int main(){
int sec=1000;
int pin=18;
wiringPiSetupGpio();
Servo servo(18);
servo.init(90);
delay(sec);
servo.move(45);
delay(0.2*sec);
servo.move(135);
}
