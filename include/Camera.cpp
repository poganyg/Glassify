#include "Camera.h"

Camera::Camera()
:m_width(32),m_height(32),m_fps(120),m_shutter(100000),m_brightness(50)//default parameters for camera
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

  cout<<"Opening Camera..."<<endl;
  if ( !CameraDevice.open()) {cerr<<"Error opening camera"<<endl;}
}

Mat Camera::capture()
{
  CameraDevice.grab();
  CameraDevice.retrieve(tempData);
  Mat data(m_height,m_width,CV_8UC3,tempData);
  imwrite("data.jpg",data);
  return data;
}
