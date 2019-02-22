#include<iostream>
#include<wiringPi.h>
#include <softPwm.h>

using namespace std;

#define  MotorPin1 7
#define  MotorPin2 6
#define  MotorEnableDC1 2

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


softPwmCreate(MotorPin1,0,50);

while(1)
{
    softPwmWrite(MotorPin1,50);
    delay(5000);
    softPwmWrite(MotorPin1,0);
}
return 0;
}
