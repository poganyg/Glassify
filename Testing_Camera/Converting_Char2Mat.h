//#include <raspicam/raspicam.h>

using namespace cv;

class ConvertingImages{

public:
  Mat ConvertingChar2Mat(uchar data){
    raspicam::RaspiCam Camera;
const int WIDTH = Camera.getWidth(), HEIGHT = Camera.getHeight();

uchar *data = new uchar[WIDTH * HEIGHT * 3];

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

Mat output = Mat(HEIGHT, WIDTH, CV_8UC3);
output.data = data;
return output;
}
};
