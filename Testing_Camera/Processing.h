
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
/*


  void checkColourDown(Mat input, Mat& outputImg, int& output, int limH, int limS, int limV, int angle)
  {
    int counter = 0;
    Mat temp = input;
    outputImg = input;
    Mat splitChannels[3]; //declares an array of Mat objects which will store each of the channels
    split(temp, splitChannels);
    int H;
    int S;
    int V;

    for (int r = 0; r < splitChannels[0].rows; r++)
    {
      for (int c = 0; c < splitChannels[0].cols; c++)
      {
        //double H = splitChannels[0].at<double>(r, c);
        //double S = splitChannels[1].at<double>(r, c);
        //double V = splitChannels[2].at<double>(r, c);
        H = temp.at<Vec3b>(r, c)[0];
        S = temp.at<Vec3b>(r, c)[1];
        V = temp.at<Vec3b>(r, c)[2];

        if (H >= limH && H <= (limH + angle) && S >= limS && V <= limV)
          counter = counter + 1;
        else //Set all values of HSV to 0 if pixel in desired range not found
        outputImg.at<Vec3b>(r, c)[0] = 0;
        outputImg.at<Vec3b>(r, c)[1] = 0;
        outputImg.at<Vec3b>(r, c)[2] = 0;
      }
    }
    //cvtColor(outputImg, outputImg, COLOR_HSV2BGR);
    output = counter;
  }

  void checkMatch(Mat templateImg, Mat currentImg, Mat& outputImg, int& output)
  {
    int counter = 0;
    outputImg =	Mat::zeros(templateImg.size(), CV_8UC1);

    for (int r = 0; r < templateImg.rows; r++)
    {
      for (int c = 0; c < templateImg.cols; c++)
      {
        outputImg.at<uint8_t>(r, c) = abs(templateImg.at<uint8_t>(r, c) - currentImg.at<uint8_t>(r, c));
        counter = counter + outputImg.at<uint8_t>(r, c);
      }
    }
    output = counter;
  }

  void SetupCamera(){
        raspicam::RaspiCam Camera;
        cout<<"Opening Camera..."<<endl;
        if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}//return -1;}
        sleep(2);
        Camera.setWidth(640) ;
        Camera.setHeight(480);
        Camera.setFrameRate(20);
        Camera.setShutterSpeed(100);
            }

struct outs
{
  Mat output;
  int counter;
};
*/


Mat checkColour(Mat input, Mat output, int lowH, int highH, int lowS, int highS, int lowV, int highV)
{
  cvtColor(input, input, COLOR_BGR2HSV);
  int counter = 0;
    output = input;
  Mat temp = input;
  Mat splitChannels[3];//declares an array of Mat objects which will store each of the channels
  split(temp, splitChannels);

  for (int r = 0; r < splitChannels[0].rows; r++)
  {
    for (int c = 0; c < splitChannels[0].cols; c++)
    {
      int H = temp.at<Vec3b>(r, c)[0];
      int S = temp.at<Vec3b>(r, c)[1];
      int V = temp.at<Vec3b>(r, c)[2];

      if (lowH > highH)
          {
            if((H >= lowH || H <= highH) && S >= lowS && S <= highS && V >= lowV && V <= highV)
            counter = counter + 1;
          }
      else //Set all values of HSV to 0 if pixel in desired range not found
      output.at<Vec3b>(r, c)[0] = 0;
      output.at<Vec3b>(r, c)[1] = 0;
      output.at<Vec3b>(r, c)[2] = 0;

      if (highH > lowH)
          {
            if (H >= lowH && H <= highH && S >= lowS && S <= highS && V >= lowV && V <= highV)
              counter = counter + 1;
          }
      else //Set all values of HSV to 0 if pixel in desired range not found
      output.at<Vec3b>(r, c)[0] = 0;
      output.at<Vec3b>(r, c)[1] = 0;
      output.at<Vec3b>(r, c)[2] = 0;
      //
    }
  }
  cvtColor(output,output,COLOR_HSV2BGR);
  return output;
}

void captureImage(){
		raspicam::RaspiCam Camera; //Camera object
    Camera.setWidth(1280) ;
    Camera.setHeight(960);
    Camera.setFrameRate(20);
    Camera.setShutterSpeed(1000000);
    Camera.setBrightness(50);
//Open camera
               	cout<<"Opening Camera..."<<endl;
               	if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}//return -1;}
		//wait a while until camera stabilizes
               	Camera.grab();
               	//allocate memory
               	unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR )];

               	Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_BGR );//get camera image

		int width = Camera.getWidth();
		int height = Camera.getHeight();
		Mat frame(height,width, CV_8UC3, data); // should be height THEN width
    Mat outFrame(height,width,CV_8UC3);
    checkColour(frame,outFrame,100,125,90,255,50,255);

    //Mat gray(height,width,CV_8UC1);
    //cvtColor(frame, gray, COLOR_BGR2GRAY);
		imwrite("baseImage.jpg",frame);
    //imwrite("outImage.jpg", outFrame);
		}
};
