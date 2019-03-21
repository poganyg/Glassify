#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <opencv2/opencv.hpp>
#include <stdint.h>
//#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include "Converting_Char2Mat.h"

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
                ConvertingImages convertNow;
//Open camera
               	cout<<"Opening Camera..."<<endl;
               	if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}//return -1;}
               	//wait a while until camera stabilizes
               	Camera.grab();
               	//allocate memory
               	unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR )];
		//convertNow.ConvertingChar2Mat(data);
		//cout<<data[0]<<endl;
               	//extract the image in rgb format
               	Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_BGR );//get camera image
		cout<<Camera.getWidth()<<endl;
		cout<<Camera.getHeight()<<endl;
	 	Mat frame(cv::Size(Camera.getWidth(),Camera.getHeight()),CV_8UC3, Scalar::all(0));
		Mat modFrame(cv::Size(Camera.getWidth(),Camera.getHeight()),CV_8UC3);
		cout<<frame.data<<endl;
		//frame = output;
		frame=convertNow.ConvertingChar2Mat(data);
	 //	frame = data;
		cout<<frame.data<<endl;
		cout<<"Got Past char2Mat"<<endl;
		cvtColor(frame, modFrame, COLOR_BGR2HSV);
		cout<<"Got Past BGR2HSV"<<endl;
		imwrite("ClassifiableImage.ppm",modFrame);
		//save
        //       	std::ofstream outFile ( "ClassifiableImage.xml",std::ios::binary );
          //     	outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
            //  	outFile.write ( ( Mat ) modFrame, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR ) );
	//	cout<<"Image saved as Bottle_image.ppm"<<endl; 
		}

/*


     void captureBurst(){
        raspicam::RaspiCam Camera;
        std::clock_t start;
        double duration;
        start = std::clock();
            for (int i=0; i<50; i++) {
              Camera.grab();
              unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR )];
              Camera.retrieve( data,raspicam::RASPICAM_FORMAT_BGR  );
		std::string oo;
		std::stringstream name;
		name <<i<<".ppm";
              std::ofstream outFile ( name.str() ,std::ios::binary );
              outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
              outFile.write ( ( char* ) data, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR ) );
            }
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            std::cout<<"printf: "<< duration <<'\n';
     }
*/
};
