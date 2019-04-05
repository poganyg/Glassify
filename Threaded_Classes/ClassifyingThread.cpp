#include "ClassifyingThread.h"
#include "FunctioningCamera.h"
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>

int ClassifyingThread::run(){
  AcqClassImages cam;
      do{
        Mat frame=cam.captureImage();
        cam.checkColour();
        cam.checkMatch(frame1,frame2);
        return Output;
      }while(Output==0)
}
