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
  int state;
  int m_width; //width of image
  int m_height;
  int m_fps;
  int m_shutter;
  int m_brightness;
  raspicam::RaspiCam Camera; //instantiates the camera within the class
  unsigned char *data;

  //Initialise Variables
  cv::Scalar gCounter; //green counter
  cv::Scalar bCounter; //brown counter
  int cCounter; //clear counter
  Mat greenOut;
  Mat brownOut;

  int setup = 0;
  int baseClear;

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
    data=new unsigned char[Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)]; //Allocates uchar data for __DEFAULT__ raspicam::format, i.e. RGB
    //IDEALLY, FIND OUT HOW TO RECAST UCHAR TO MAT AND DEFINE MAT HERE

    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}
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
    data=new unsigned char[Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)]; //Allocates uchar data for __DEFAULT__ raspicam::format, i.e. RGB
    //IDEALLY, FIND OUT HOW TO RECAST UCHAR TO MAT AND DEFINE MAT HERE

    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}
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
//    state=0;
		//wait a while until camera stabilizes
    Camera.grab();
    //Gather Baseline Data
    Camera.retrieve ( data );//get camera image
    Mat Template(m_height,m_width,CV_8UC3,data);
    Mat grayTemplate(m_height,m_width,CV_8UC1);
    cvtColor(Template, grayTemplate, COLOR_RGB2GRAY);
    Camera.grab();
    //Gather Baseline Data
    Camera.retrieve ( data );//get camera image
    Mat Frame(m_height,m_width,CV_8UC3,data);
    baseClear = checkMatch(grayTemplate, Frame);
    while(state==0)
    {

      Camera.grab();
      Camera.retrieve(data);
      Mat Frame(m_height,m_width,CV_8UC3,data);
      cvtColor(Frame,Frame,COLOR_RGB2HSV);
      cCounter = checkMatch(grayTemplate, Frame);

      inRange(Frame, Scalar(20,90,0), Scalar(80,255,255), greenOut);
      gCounter = cv::sum(greenOut);
      inRange(Frame, Scalar(0,50,0), Scalar(30,255,150), brownOut);
      bCounter = cv::sum(brownOut);



      if(cCounter>=baseClear*4){
        if((gCounter[0]>=100000 && gCounter[0]>=bCounter[0]) ||(gCounter[0]>=10000 && gCounter[0]>=5*bCounter[0]))
        {
          state = 1;
        }
        else if((bCounter[0]>=100000 && bCounter[0]>=gCounter[0])||(bCounter[0]>=10000 && bCounter[0]>=5*gCounter[0]))
        {
          state = 2;
        }
        else
        {
          state = 3;
        }
      }
      std::cout << "CLEAR: " << cCounter << " BROWN: " << bCounter[0] << " GREEN: " << gCounter[0] << "                    STATE: " << state << endl;
      state = 0;

    }
    return 0;
  }
};
