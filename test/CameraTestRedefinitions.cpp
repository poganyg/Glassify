#include "Camera.h"

Camera::Camera()
  :m_width(64),m_height(64),m_fps(120),m_shutter(10000),m_brightness(50)//default parameters for camera
{
  //Setting up Camera
  CameraDevice.setWidth(m_width);
  CameraDevice.setHeight(m_height);
  CameraDevice.setFrameRate(m_fps);
  CameraDevice.setShutterSpeed(m_shutter);
  CameraDevice.setBrightness(m_brightness);

  //Allocate Memory
  tempData=new unsigned char[CameraDevice.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)]; //Allocates uchar data for __DEFAULT__ raspicam::format, i.e. RGB
  Mat data(m_height,m_width,CV_8UC3,tempData);//IDEALLY, FIND OUT HOW TO RECAST UCHAR TO MAT AND DEFINE MAT HERE
}

Mat Camera::capture()
{
  if (tempData[0]==1)
  {
    Mat greenImg(64,64, CV_8UC3, Scalar(40,150,150));
    cvtColor(greenImg,greenImg,COLOR_HSV2RGB);
    return greenImg;
  }
  else if (tempData[0]==2)
  {
    Mat brownImg(64,64, CV_8UC3, Scalar(15,150,100));
    cvtColor(brownImg,brownImg,COLOR_HSV2RGB);
    return brownImg;
  }
}
