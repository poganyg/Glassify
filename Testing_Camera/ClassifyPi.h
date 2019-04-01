
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

class AcqClassImages{

public:

  int checkColour(Mat input, int lowH, int highH, int lowS, int highS, int lowV, int highV)
  {
  	cvtColor(input, input, COLOR_RGB2HSV);
  	int counter = 0;

  	for (int r = 0; r < input.rows; r++)
  	{
  		for (int c = 0; c < input.cols; c++)
  		{
  			unsigned char H = input.at<Vec3b>(r, c)[0];
  			unsigned char S = input.at<Vec3b>(r, c)[1];
  			unsigned char V = input.at<Vec3b>(r, c)[2];

  			if (lowH > highH)
  			{
  				if ((H >= lowH || H <= highH) && S >= lowS && S <= highS && V >= lowV && V <= highV)
  				{
  					counter = counter + 1;
  				}
  				else //Set all values of HSV to 0 if pixel in desired range not found
  				{
  					input.at<Vec3b>(r, c)[0] = 0;
  					input.at<Vec3b>(r, c)[1] = 0;
  					input.at<Vec3b>(r, c)[2] = 0;
  				}
  			}
  			if (highH > lowH)
  			{
  				if (H >= lowH && H <= highH && S >= lowS && S <= highS && V >= lowV && V <= highV)
  				{
  					counter = counter + 1;
  				}
  				else //Set all values of HSV to 0 if pixel in desired range not found
  				{
  					input.at<Vec3b>(r, c)[0] = 0;
  					input.at<Vec3b>(r, c)[1] = 0;
  					input.at<Vec3b>(r, c)[2] = 0;
  				}
  			}
  		}
  	}
  	return counter;
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

void captureImage(){
		raspicam::RaspiCam Camera; //Camera object
    Camera.setWidth(512) ;
    Camera.setHeight(512);
    Camera.setFrameRate(20);
    Camera.setShutterSpeed(1000000);
    Camera.setBrightness(50);

    //Open camera
    std::cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}//return -1;}

		//wait a while until camera stabilizes
    Camera.grab();

		int width = Camera.getWidth();
		int height = Camera.getHeight();

    //Initialise Variables
    int gCounter; //green counter
  	int bCounter; //brown counter
  	int cCounter; //clear counter
    int fps = 100;
    //Allocate Memory for Camera Capture
    unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR )];

    //Gather Baseline Data
    Camera.retrieve ( data );//get camera image
    Mat Template(height,width,CV_8UC3,data);
    Mat grayTemplate(height,width,CV_8UC1);
    cvtColor(Template, grayTemplate, COLOR_RGB2GRAY);
    cvtColor(Template,Template,COLOR_RGB2BGR);
    imwrite("TEST.jpg",Template);
    int j = 0;
    while(true)
    {
      j = j+1;
      Camera.grab();
      Camera.retrieve(data);
      Mat Frame(height,width,CV_8UC3,data);

      cCounter = checkMatch(grayTemplate, Frame);
      bCounter = checkColour(Frame, 0, 15, 125, 255, 50, 180); // For Brown
      gCounter = checkColour(Frame, 40, 75, 90, 255, 50, 255); //For Green

      if(j<=20)
      {
        std::cout << "CLEAR: " << cCounter << " BROWN: " << bCounter << " GREEN: " << gCounter << endl;
      }
      else
      {
        std::cout << "CLEAR: " << cCounter << " BROWN: " << bCounter << " GREEN: " << gCounter << " *******" << endl;
        j=0;
      }


      //if (waitKey(1000 / fps) >= 0)
    	//	break;
    }
  }
};
