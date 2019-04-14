#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <opencv2/core.hpp>
#include "assert_print.h"

using namespace std;
using namespace cv;


int main (int, char**)
{
  //Initialising Camera Object, setting parameters
  raspicam::RaspiCam Camera;
  Camera.setWidth(512) ;
  Camera.setHeight(512);
  Camera.setFrameRate(20);
  Camera.setShutterSpeed(1000000);
  Camera.setBrightness(50);

  //wait a while until camera stabilizes
  Camera.grab();
  int width = Camera.getWidth();
  int height = Camera.getHeight();

  //Allocate Memory for Camera Capture
  unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR )];
  Camera.retrieve ( data );//get camera image
  cv::Mat Template(height,width,CV_8UC3,data);

  //Initialize Min/Max Test
  double minVal;
  double maxVal;
  Point minLoc;
  Point maxLoc;

  cv::minMaxLoc( Template, &minVal, &maxVal, &minLoc, &maxLoc );

  if(maxVal==0.0)
  {
    assert_print("Mat object resulting from camera capture empty!");
  }
  //*/
  return 0;
}
