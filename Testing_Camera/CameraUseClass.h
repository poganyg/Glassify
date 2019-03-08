#include <ctime>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
using namespace std;

class AcquiringImages{

  public;

 void captureImage{}{
          raspicam::RaspiCam Camera; //Camera object
          //Open camera
          cout<<"Opening Camera..."<<endl;
          if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
          //wait a while until camera stabilizes
          Camera.grab();
          //allocate memory
          unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB )];
          //extract the image in rgb format
          Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_RGB );//get camera image
          //save
          std::ofstream outFile ( "Bottle_image.ppm",std::ios::binary );
          outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
          outFile.write ( ( char* ) data, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB ) );
          cout<<"Image saved as Bottle_image.ppm"<<endl;
        }
};
//to use say #include "AcquiringImages"  first
// then in main say AcquiringImages to bring in class then name your instance of it
//then put this name.captureImage
//e.g in main  AcquiringImages AcquireImageNow
//AcquiringImageNow.captureImage
