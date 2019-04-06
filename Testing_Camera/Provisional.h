#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

class acquireImage{
private:
  int m_width; //width of image
  int m_height;
  int m_fps;
  int m_shutter;
  int m_brightness;
  raspicam::Raspicam Camera; //instantiates the camera within the class

public:
  acquireImage()
    :m_width(256),m_height(256),m_fps(20),m_shutter(10000),m_brightness(50) //default parameters for camera
  {
    //Setting up camera
    Camera.setWidth(m_width);
    Camera.setHeight(m_height);
    Camera.setFrameRate(m_fps);
    Camera.setShutterSpeed(m_shutter);
    Camera.setBrightness(m_brightness);

    //Allocate Memory
    unsigned char *data=new unsigned char[Camera.getImageTypeSize()]; //Allocates uchar data for __DEFAULT__ raspicam::format, i.e. RGB
    //IDEALLY, FIND OUT HOW TO RECAST UCHAR TO MAT AND DEFINE MAT HERE
  }

  acquireImage(int width,int height,int fps,int shutter,int brightness)
    :m_width(width),m_height(height),m_fps(fps),m_shutter(shutter),m_brightness(brightness)
  {
    Camera.setWidth(m_width);
    Camera.setHeight(m_height);
    Camera.setFrameRate(m_fps);
    Camera.setShutterSpeed(m_shutter);
    Camera.setBrightness(m_brightness);

    //Allocate Memory
    unsigned char *data=new unsigned char[Camera.getImageTypeSize()]; //Allocates uchar data for __DEFAULT__ raspicam::format, i.e. RGB
    //IDEALLY, FIND OUT HOW TO RECAST UCHAR TO MAT AND DEFINE MAT HERE
  }

  int checkMatch(Mat templateImg, Mat currentImg)
  {
  	int counter = 0;
  	Mat greyImg;
  	cvtColor(currentImg, greyImg, COLOR_RGB2GRAY);

  	for (int r = 0; r < templateImg.rows; r++)
  	{
  		for (int c = 0; c < templateImg.cols; c++)
  		{
  			greyImg.at<uint8_t>(r, c) = abs(templateImg.at<uint8_t>(r, c) - greyImg.at<uint8_t>(r, c));
  			counter = counter + greyImg.at<uint8_t>(r, c);
  		}
  	}
  	return counter;
  }

  int classify()
  {
		//wait a while until camera stabilizes
    Camera.grab();

    //Initialise Variables
    int gCounter; //green counter
  	int bCounter; //brown counter
  	int cCounter; //clear counter
    Mat greenOut;
    Mat brownOut;

    //Gather Baseline Data
    Camera.retrieve ( data );//get camera image
    Mat Template(height,width,CV_8UC3,data);
    Mat grayTemplate(height,width,CV_8UC1);
    cvtColor(Template, grayTemplate, COLOR_RGB2GRAY);
    while(true)
    {
      Camera.grab();
      Camera.retrieve(data);
      Mat Frame(height,width,CV_8UC3,data);

      cCounter = checkMatch(grayTemplate, Frame);
      inRange(Frame, Scalar(35,90,0), Scalar(80,255,255), greenOut);
      gCounter = cv::sum(greenOut);
      inRange(Frame, Scalar(0,50,0), Scalar(30,255,150), brownOut);
      bCounter = cv::sum(brownOut);

      std::cout << "CLEAR: " << cCounter << " BROWN: " << bCounter << " GREEN: " << gCounter << endl;


    }
    return 0;
  }
};
