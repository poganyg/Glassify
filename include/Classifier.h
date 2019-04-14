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
/**
* @brief Classifies glass as brown, green or clear and sets state accordingly
*/
class Classifier
{
private: // Classification
  Camera* cameraptr;  //!< Decleration of camera class pointer
  State* stateptr;  //!< Decleration of state class pointer
  Servo* m_servoptr; //!< Decleration of servo class pointer

  //Initialise Variables
  int loopNumber = 0;  //!<   number of times the classification loop has run, used to set threshold for clear classification after stabilisation
  int decisionVector[5];  //!<  sets state only when 5 outputs of the same value are recieved
  bool bufferOn = 0;  //!< States if a buffer of bottles in the tube is present

  Mat baseFrame;  //!< intial frame for comparison to test for changes in order to identify clear glass
  Mat baseGrey;  //!< empty Mat array to be filled with greyscale version of baseFrame
  Mat rollingFrame;  //!< Frame which is constantly updated by images captured by the camera
  Mat rollingGrey;  //!<  Greyscale version of the rolingFrame

  int baseClear; //!< baseline clear value from setup
  int cCounter;  //!< Number of altered pixels between base and rolling image
  cv::Scalar gCounter;  //!< Number of detected pixels in greenOut
  cv::Scalar bCounter;  //!< Number of detected pixels in brownOut
  Mat greenOut; //!< output of image after being thresholded for green
  Mat brownOut; //!< output of image after being thresholded for brown

public:
  /**
   * @brief Constructor which sets up Mat arrays for all frames required for classification
   * @param _stateptr Pointer to state class
   * @param _cameraptr Pointer to camera class
   * @param _servoptr Pointer to Servo class
   */
  Classifier(State* _stateptr, Camera* _cameraptr,Servo* _servoptr);
  /**
  * @brief Compares the initial image (base image) captured when the switch was pressed
  * with the last picture taken (rolling image) and shows the difference between them
  * in order to detect clear glass
  * @param baseImage Image captured of inner tube when switch is press
  * @param rollingImage Last image cpatured by camera
  * @return counter the magnitude of difference between the two frames
  */
  int checkMatch(Mat& baseImage, Mat& rollingImage);
  /**
   * Classifies images to detect green, brown and clear glass and
   * sets the state to the appropriate result so it can be read by
   * other threads
   * Captures images, converts them to grayscale and uses the checkMatch to check clear glass.
   * Continuosly captures images and converts them to HSV and thresholds them to determine green and brown presence
   * Decides what colour the glass was and this the current state and sets the state value accordingly
   */
  void classify();
};

#endif
