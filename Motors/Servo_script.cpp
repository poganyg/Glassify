#include<iostream>
#include<wiringPi.h>
#include <softPwm.h>

using namespace std;

#define  MotorPin1 17
#define  MotorPin2 18
#define  MotorEnableDC1 4

 int main(void)
 {

 if(wiringPiSetupGpio()==-1)
{
    cout<<"Setup wiring pi failed";
    return 1;
}


pinMode(MotorPin1,OUTPUT);
pinMode(MotorPin2,OUTPUT);
pinMode(MotorEnableDC1,OUTPUT);


softPwmCreate(MotorEnableDC1,0,50);

while(1)
{
    softPwmWrite(MotorEnableDC1,50);
    digitalWrite(MotorPin1,HIGH);
    digitalWrite(MotorPin2,LOW);
    delay(5000);
    softPwmWrite(MotorEnableDC1,0);
}
return 0;
}