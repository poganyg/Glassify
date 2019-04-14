/**
 * @file Classifier.h
 * @brief Class which defines all functions required to classify
 * green, brown or clear bottles based on the camera output
*/

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
#include "./Camera.h"
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
  //*
   * Constructor which sets up Mat arrays for all frames required for classification
   * @param baseFrame intial frame for comparison to test for changes in order 
   * to identify clear glass
   * @param baseGrey empty Mat array to be filled with greyscale version of baseFrame
   * @param rollingFrame Frame which is constantly updated by images captured by the camera
   * @param rollingGrey Greyscale version of the rolingFrame
   */
  Classifier(State* _stateptr, Camera* _cameraptr,Servo* _servoptr);
  //*
  * Compares the initial image (base image) captured when the switch was pressed
  * with the last picture taken (rolling image) and shows the difference between them
  * in order to detect clear glass
  * @param[in] baseImage Image captured of inner tube when switch is press
  * @param[in] rollingImage Last image cpatured by camera
  * @return counter the magnitude of difference between the two frames
  */
  int checkMatch(Mat& baseImage, Mat& rollingImage);
  //*
   * Classifies images to detect green, brown and clear glass and
   * sets the state to the appropriate result so it can be read by 
   * other threads
   * Captures images, converts them to grayscale and uses the checkMatch to check clear glass.
   * Continuosly captures images and converts them to HSV and thresholds them to determine green and brown presence
   * Decides what colour the glass was and this the current state and sets the state value accordingly
   *  @param greenOut output of image after being thresholded for green 
   *  @param brownOut output of image after being thresholded for brown
   * @param gCounter Number of detected pixels in greenOut
   * @param bCounter Number of detected pixels in brownOut
   * @param loopNumber number of times the classification loop has run, used to set threshold for clear classification after stabilisation
   * @param desicionVector sets state only when 5 outputs of the same value are recieved
   * @param baseClear baseline clear value from setup
   */
  void classify();
};

#endif
