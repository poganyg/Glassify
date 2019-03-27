
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
  void SetupCamera(){
        raspicam::RaspiCam Camera;
        cout<<"Opening Camera..."<<endl;
        if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}//return -1;}
        sleep(2);
        Camera.setWidth(640) ;
        Camera.setHeight(480);
        Camera.setFrameRate(60);
      }
      void captureImage(){
		raspicam::RaspiCam Camera; //Camera object
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
		imwrite("MatconvertedImage.ppm",frame);
		}
};
