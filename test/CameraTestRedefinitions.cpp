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
}

Mat Camera::capture()
{
  return data;
}
