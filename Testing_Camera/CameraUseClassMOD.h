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
        //        ConvertingImages convertNow;
//Open camera
               	cout<<"Opening Camera..."<<endl;
               	if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}//return -1;}
//               	sleep(3);
		//wait a while until camera stabilizes
               	Camera.grab();
               	//allocate memory
               	unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR )];
		int Dims;
		Dims = Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_BGR);
		cout << "The image dimensions are : " << Dims << ". I.e. Height X Width X 3" << endl;
		//convertNow.ConvertingChar2Mat(data);
		//cout<<data[0]<<endl;
               	//extract the image in rgb format
               	Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_BGR );//get camera image
		//std::ofstream outFile("howdatais2.ppm", std::ios::binary );
		//outFile<<"P6\n"<<Camera.getWidth()<<" "<<Camera.getHeight()<<" 255/n";
		//outFile.write(( char* ) data,Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR ));
		//cout<<"Image saved as howdatais2.ppm"<<endl;
		/*for (int i=0; i<Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_BGR); i+=1000)
		{
			cout << "Pixel Data is:" << data[i] << endl;
		}		
cout<<sizeof(data)<<endl;
//		cout<<Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)<<endl;
		cout<<"Camera image width = " << Camera.getWidth()<<endl;
		cout<<"Camera image height = " << Camera.getHeight()<<endl;
		int width = Camera.getWidth();
		int height = Camera.getHeight();
	 //	Mat frame(cv::Size(Camera.getWidth(),Camera.getHeight()),CV_8UC3, Scalar::all(0));
		//(cv::Size(Camera.getHeight(),Camera.getWidth()),CV_8UC3);
//		cout<<frame.data<<endl;
		//frame = output;
//		frame=convertNow.ConvertingChar2Mat(data);
		*/
		Mat frame = Mat(Camera.getHeight(),Camera.getWidth(), CV_8UC3); // should be height THEN width
		cout << "is Mat object, 'frame' empty?" << frame.empty() << endl;

		//cout << "The number of nonzero elements in 'frame' is : " << countNonZero(frame);
 //		frame = data;
		cout<<"Output from 'frame.data': " << frame.data <<endl;
		cout<<"Output from 'frame.size': " << frame.size() <<endl;
//		imwrite("MatconvertedImage.ppm",frame);
		cout<<"Got Past char2Mat"<<endl;
		//cvtColor(frame, modFrame, COLOR_RGB2HSV);
		cout<<"Got Past BGR2HSV"<<endl;
		int j = 0;
		for (int r = 0; r < frame.rows; r++)
		  {
			for (int c = 0; c < frame.cols; c++)
			{
				for (int v = 0; v < 3; v++)
				{
					frame.at<Vec3b>(r,c)[v] = data[j];					
					j = j + 1;
					
					//std::cout << "pixel value is: ";
					//printf("%u", frame.at<Vec3b>(r, c)[v]);
					//std::cout << endl;

					//cout<<"pixel value = " << frame.at<Vec3b>(r, c)[v]<< endl;		//instead of RGB, images are BGR in opencv; Vec3b specified that each pixel is a 3 component vector
					// replace Vec3b with Vec3f to work with floats (not 0:255) instead of bytes (0:255)
				}
			}
		}
		std::cout << "The final value of j was: " << j << endl;		
		std::cout << endl;
		std::cout << "FIRST pixel values are: ";
		printf("%u", frame.at<Vec3b>(0,0)[0]);
		std::cout << endl;
		printf("%u", frame.at<Vec3b>(0,0)[1]);
		std::cout << endl;
		printf("%u", frame.at<Vec3b>(0,0)[2]);
		std::cout << endl;
		printf("%u", frame.at<Vec3b>(1,1)[0]);
                std::cout << endl;
                printf("%u", frame.at<Vec3b>(1,1)[1]);
                std::cout << endl;
                printf("%u", frame.at<Vec3b>(1,1)[2]);
                std::cout << endl;
		

		std::cout << "FINAL pixel value is: ";
		printf("%u", frame.at<Vec3b>(959,1279)[1]); 
		std::cout << endl;
                printf("%u", frame.at<Vec3b>(959,1279)[2]);
                std::cout << endl;
                printf("%u", frame.at<Vec3b>(960,1280)[1]);
                std::cout << endl;
                printf("%u", frame.at<Vec3b>(960,1280)[2]);
                std::cout << endl;
		/*
                printf("%u", frame.at<Vec3b>(1279,959)[1]);
                std::cout << endl;
                printf("%u", frame.at<Vec3b>(1279,959)[2]);
                std::cout << endl;
                printf("%u", frame.at<Vec3b>(1280,960)[1]);
                std::cout << endl;
		printf("%u", frame.at<Vec3b>(1280,960)[2]);
		*/
		std::cout << endl;
				

		std::cout << "The number of non-zero elements in the frame is: " << countNonZero(frame) << endl;


		imwrite("ClassifiableImage.jpg",frame);
		//save
          //     	std::ofstream outFile ( "ClassifiableImage.xml",std::ios::binary );
        //       	outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
          //	outFile.write ( ( Mat ) frame, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_BGR ) );
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
