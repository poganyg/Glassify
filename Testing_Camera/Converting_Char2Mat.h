//#include <raspicam/raspicam.h>
//#include <opencv2/core/mat.hpp>
using namespace cv;

class ConvertingImages{

public:
  Mat ConvertingChar2Mat(unsigned char* data){ // Function takes the pointer to the data
    raspicam::RaspiCam Camera; // creates an instance of the camera class
const int WIDTH = Camera.getWidth(), HEIGHT = Camera.getHeight(); // creates constant variables WIDTH and HEIGHT

//uchar *data = new uchar[WIDTH * HEIGHT * 3];

for (int i = 0; i < WIDTH*HEIGHT*3;i+=3)
{
  if (i < WIDTH*HEIGHT*3/2)
{
	 data[i + 0] = (uchar)0;
	 data[i + 1] = (uchar)0;
    	 data[i + 2] = (uchar)255;
    	}
    else
    {
         data[i + 0] = (uchar)255;
         data[i + 1] = (uchar)0;
         data[i + 2] = (uchar)0;
    }
}

Mat output = Mat(HEIGHT, WIDTH, CV_8UC3); //creates 3D Mat object HEIGHT x WIDTH x 3 consisting of 8-bit Unsigned Chars
output.data = data;
return output;
}
};
