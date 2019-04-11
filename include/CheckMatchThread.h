#ifndef CHECK_MATCH_THREAD
#define CHECK_MATCH_THREAD
//#include "libServo.cpp"
#include "CppThread.h"
#include "Camera.h"
#include "libServo.h"
//#include <wiringPi.h>
class CheckMatchThread : public CppThread {

public:
  CheckMatchThread(acquireImage* _cameraptr)
    :cameraptr(_cameraptr)
    {
    }

private:
  void run();

private:
acquireImage* cameraptr;
//Variables
};
#endif
