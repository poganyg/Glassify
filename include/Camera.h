/** @file Camera.h
 * @brief  A class which intitialises the camera and enables it
 * to capture images
 *
*/
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
/**
* @brief Setups camera and enables image capture and retrival
*/
class Camera
{
private:
  raspicam::RaspiCam CameraDevice; //instantiates the camera within the class
  int m_fps; //!< frame rate to be used by the camera
  int m_shutter; //!< shutter speed to capture images at
  int m_brightness; //!< brightness of image captured
  Mat m_testImage;

public:
 /**
 * Contructor that sets up camera by defining necessary parameters
 * @param data unsigned char set up in the size of the expected image to later store it
*/
  Camera();
 /**
 * Function which captures the image and assigns it to the variable data
 */
  void capture();
  int m_width; //!< width of the image being captured in pixels
  int m_height;//!< height of image being captured in pixels
  Mat data; //!< Mat object to which tempData is cast
  unsigned char *tempData; //!< The array to which the camera outputs
};

#endif
