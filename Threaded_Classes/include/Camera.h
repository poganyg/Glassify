#ifndef CLASSIFIER
#define CLASSIFIER

#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <opencv2/core.hpp>
#include <wiringPi.h>
#include "state.h"

using namespace cv;
using namespace std;

class acquireImage
{
private:
  int loopNumber = 0;
  int decisionVector[3];
  State* stateptr;
  int m_width; //width of image
  int m_height;
  int m_fps;
  int m_shutter;
  int m_brightness;
  raspicam::RaspiCam Camera; //instantiates the camera within the class
  unsigned char *data;
  int avg;
  int counter;

  //Initialise Variables
  cv::Scalar gCounter; //green counter
  cv::Scalar bCounter; //brown counter
  int cCounter; //clear counter
  Mat greenOut;
  Mat brownOut;

  int setup = 0;
  int baseClear;

public:
  acquireImage(State* _stateptr);
  int checkMatch(Mat templateImg, Mat currentImg);
  int classify();
};

#endif
