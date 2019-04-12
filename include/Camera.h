#ifndef CAMERA
#define CAMERA

#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <stdint.h>
#include <wiringPi.h>

using namespace std;

class Camera
{
private:
  raspicam::RaspiCam CameraDevice; //instantiates the camera within the class
  int m_fps; //CONSTRUCTOR
  int m_shutter; //CONSTRUCTOR
  int m_brightness; //CONSTRUCTOR

public:
  Camera();
  void capture();
  int m_width; //CONSTRUCTOR
  int m_height; //CONSTRUCTOR
  unsigned char *data; //CONSTRUCTOR - the array to which the camera will output
};

#endif
