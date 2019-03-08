#!/bin/bash
g++ libServoSample.cpp -o test -lwiringPi libServo.cpp
./test