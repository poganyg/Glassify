#include <cstdlib>
#include "MotorThread.h"

int main(){
MotorThread motorThread1(1);
motorThread1.start();
motorThread1.join();
motorThread1.~MotorThread();
return 0;}

