# Raspberry-PI-Servo
The simplest way to use servo motors on a Raspberry PI

HOW TO
======

First you will need to download WiringPI library from [Gordon](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) :

    git clone git://git.drogon.net/wiringPi
    cd wiringPi
    git pull origin
    cd wiringPi
    ./build

Once it is done, download the servo library from this git. Then it is as simple as this : 

    #include <wiringPi.h> // don't forget
    #include <cstdlib>
    #include "libServo.h"

    using namespace std;

    int pin=24;

    int main()
    {
        if (wiringPiSetup() == -1)
            exit(1);

        Servo servo(pin);    // set a pin.
        servo.init(90);      // initialize the servo to an angle. Need to be called only once.

        servo.move(180);     // Then move the servo to any angle.
        servo.move(0);
    }
