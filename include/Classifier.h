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
#include "Camera.h"
#include "libServo.h"

using namespace cv;
using namespace std;

class Classifier
{
private: // Classification
  Camera* cameraptr;
  State* stateptr; // CONSTRUCTOR
  Servo* m_servoptr;

  //Initialise Variables
  int loopNumber = 0;
  int decisionVector[5];
  bool bufferOn = 0;

  Mat baseFrame; //CONSTRUCTOR
  Mat baseGrey; //CONSTRUCTOR
  Mat rollingFrame; //CONSTRUCTOR
  Mat rollingGrey; //CONSTRUCTOR

  int baseClear;
  int cCounter; //clear counter
  cv::Scalar gCounter; //green counter
  cv::Scalar bCounter; //brown counter
  Mat greenOut;
  Mat brownOut;

public:
  Classifier(State* _stateptr, Camera* _cameraptr,Servo* _servoptr);
  int checkMatch(Mat& baseImage, Mat& rollingImage);
  void classify();
};

#endif
