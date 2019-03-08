#include <wiringPi.h> // don't forget
#include <cstdlib>
#include <iostream>
#include "libServo.h"

using namespace std;

int sec = 1000;
int pin=19;
int main()

{
   wiringPiSetupGpio();
   if (wiringPiSetup() == -1)
      exit(1);
  Servo servo(pin);


  cout << "Initialising the servo" << endl;
  servo.init(90);
  delay(2 * sec);

  for(i=90;i<181;++i) {
    //cout << "Angle +60 degrees" << endl;
    servo.move(i);
    delay(0.1*sec);
    //cout << "Angle -60 degrees" << endl;
  }

return 0;
}
