#include <iostream>
#include "rpiServo.h"
using namespace std;
int unsigned const delayUs = 2000000;

int main(void){

    rpiServo servo;
// Increase angle by 18 deg every 'delayUs' microseconds from 90 to 180
    servo.setAngle(90); // set servo to centre
    usleep(delayUs);
    cout<<"we working"<<endl;
    servo.setAngle(108);
    usleep(delayUs);
    servo.setAngle(126);
   return 0;
}
