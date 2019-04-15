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
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
using namespace std;
using namespace cv;

/**
* @brief Setups camera and enables image capture and retrieval
*
*  Class which contains all setup required for the camera such as image hieght 
*  and width which also contains the function required to capture and store an image. 
*/
class Camera
{
//private:

public:
 /**
 * @brief Contructor that sets up camera by defining necessary parameters
 */
  Camera();
 /**
 * @brief Function which captures the image and assigns it to the variable data
 * @return data Mat variable which contains an image captured with the camera
 */
  Mat capture();
  raspicam::RaspiCam CameraDevice; //!<instantiates the camera within the class
  int m_fps; //!< frame rate to be used by the camera
  int m_shutter; //!< shutter speed to capture images at
  int m_brightness; //!< brightness of image captured
  int m_width; //!< width of the image being captured in pixels
  int m_height;//!< height of image being captured in pixels
  Mat data; //!< Mat object to which tempData is cast
  unsigned char *tempData; //!< The array to which the camera outputs
};

#endif
