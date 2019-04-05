#include "ClassifyingThread.h"
#include "FunctioningCamera.h"

int ClassifyingThread::run(){
  AcqClassImages cam;
      do{
        *Output=cam.Classify();
      }while(*Output==0)
}
