#include <wiringPi.h> // don't forget
#include <cstdlib>
#include <iostream>
#include "libServo.h"

using namespace std;

int sec = 1000;
int pin=18;
int main()

{
   wiringPiSetupGpio();
   if (wiringPiSetup() == -1)
      exit(1);
  Servo servo(pin);


  cout << "Initialising the servo newpin" << endl;
  servo.init(90);
  delay(2 * sec);

//  for(int i=90;i<181;++i) {
    //cout << "Angle +60 degrees" << endl;
    servo.move(45);
    cout<<"Turn 1"<<endl;
    delay(0.2*sec);
    servo.move(90);
 cout<<"Turn 2"<<endl;
    delay(0.2*sec);
    servo.move(135);
    //cout << "Angle -60 degrees" << endl;
 // }

return 0;
}
