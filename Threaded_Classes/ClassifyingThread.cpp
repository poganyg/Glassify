#include "ClassifyingThread.h"
#include "Provisional0.h"

void ClassifyingThread::run(){
  acquireImage cam = acquireImage(stateptr);
      do{
        cam.classify();
      }while(true);
}
