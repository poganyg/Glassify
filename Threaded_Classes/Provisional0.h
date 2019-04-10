#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <opencv2/core.hpp>
#include "state.h"
#include "wiringPi.h"

using namespace cv;
using namespace std;

class acquireImage{
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
  acquireImage(State* _stateptr)
    :m_width(64),m_height(64),m_fps(120),m_shutter(10000),m_brightness(50),stateptr(_stateptr) //default parameters for camera
  {

    //Setting up Camera
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

  /*
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
  */

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
//   *stateptr=0;
  {while(true){
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
    while(true)
    {
      Camera.grab();
      Camera.retrieve(data);
      Mat Frame(m_height,m_width,CV_8UC3,data);
      cCounter = checkMatch(grayTemplate, Frame);
      if(loopNumber<=15){
          loopNumber++;
          if (baseClear<cCounter){
            baseClear=cCounter;
          }
      }
      cvtColor(Frame,Frame,COLOR_RGB2HSV);
      inRange(Frame, Scalar(20,90,0), Scalar(80,255,255), greenOut);
      gCounter = cv::sum(greenOut);
      inRange(Frame, Scalar(0,50,0), Scalar(30,255,150), brownOut);
      bCounter = cv::sum(brownOut);

      if((gCounter[0]>=100000 && gCounter[0]>=bCounter[0]) ||(gCounter[0]>=10000 && gCounter[0]>=5*bCounter[0]))
      {
       // *stateptr = 1;
        decisionVector[0]=decisionVector[1];
        decisionVector[1]=decisionVector[2];
        decisionVector[2]=1;
      }
      else if((bCounter[0]>=100000 && bCounter[0]>=gCounter[0])||(bCounter[0]>=10000 && bCounter[0]>=5*gCounter[0]))
      {
       // *stateptr = 2;
       decisionVector[0]=decisionVector[1];
       decisionVector[1]=decisionVector[2];
       decisionVector[2]=1;
        //stateptr->writeState(2);
	     }
      else if(cCounter>=baseClear*1.5){
       // *stateptr = 3;
       decisionVector[0]=decisionVector[1];
       decisionVector[1]=decisionVector[2];
       decisionVector[2]=1;
	      //stateptr->writeState(3);
      }
      else  {
        decisionVector[0]=decisionVector[1];
        decisionVector[1]=decisionVector[2];
        decisionVector[2]=1;
        //stateptr->writeState(0);
      }

      if (decisionVector[2]==decisionVector[1] && decisionVector[1]==decisionVector[0]) {
        stateptr->writeState(decisionVector[0]);
      }

      //std::cout << "CLEAR: " << cCounter << " BROWN: " << bCounter[0] << " GREEN: " << gCounter[0] << "                    STATE: " << stateptr->getState() << endl;

      /*
      avg=avg+state;
	    counter=counter+1;
      if (state==0 &&  avg!=0)
      {
        *stateptr=round(avg/counter);
         counter==0;
         avg==0;
      }
      else
      {
        if(state==0)
         {counter==0;
           avg==0;
         } }}
         */
       }

    return 0;
  }
}
};
