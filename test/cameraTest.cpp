#include "Camera.h"

using namespace std;
using namespace cv;

/** This test assesses the functionality of the Camera class.*/

int main (int, char**)
{
  Camera camera();
  if ( camera.m_width > 64){assert_print("Image width too large. Consider lowering to reducing processing burden.")}
  if ( camera.m_height > 64){assert_print("Image height too large. Consider lowering to reducing processing burden.")}
  if ( camera.m_fps < 60){assert_print("Frames per second too low. Consider increasing for better classifier performance.")}
  if ( camera.m_brightness > 75){assert_print("Image brightness too high. Consider reducing for more reliable image analysis.")}
  if ( (sizeof(camera.data)/sizeof(camera.*data)) == 0){assert_print("Creation of data variable on heap for camera image data storage failed.")}
  if ( !camera.CameraDevice.open()) {assert_print("Camera failed to open. This may be because you do not not have camera functionality enabled on your Raspberry Pi OR the ribbon connection between the Pi and the camera is not secure.")}

  camera.capture();
  if camera.data //CHECK THE SIZE OF THE DATA. IF THE MAX VALUE ==0 or MIN VALUE ==255 THERE IS A PROBLEM WITH CAPTURE.
}
