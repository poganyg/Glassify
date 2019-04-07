//#include "CameraUseClass.h"
//#include <opencv2/opencv.hpp>
//#include "FunctioningCamera.h"
//#include "Processing.h"
//#include "CameraUseClassMOD.h"
#include "Provisional.h"
int state = 0;
int* stateptr = &state;

int main(){
acquireImage Classifier(stateptr);
Classifier.classify();
return 0;
}
