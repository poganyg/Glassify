#include "Classifier.h"

using namespace std;
using namespace cv;

/** This test assesses the functionality of the Classifier class.*/

int main (int, char**)
{
  wiringPiSetup();
  Camera camera;
  Camera* cameraptr = &camera;
  State state;
  State* stateptr = &state;
  Servo servo(1);
  Servo* servoptr = &servo;
  Classifier classifier(stateptr,cameraptr,servoptr);

  Mat whiteImg(64,64, CV_8UC1, Scalar(255));
  Mat blackImg(64,64, CV_8UC1, Scalar(0));
  int checkMatchTestCounter=classifier.checkMatch(whiteImg,blackImg);
  if(checkMatchTestCounter!=(64*64*255)){assert_print("checkMatch not functioning as intented. Please review.")}

  Mat greenImg(64,64, CV_8UC3, Scalar(40,150,150));
  Mat brownImg(64,64, CV_8UC3, Scalar(15,150,100));

  camera.data=greenImg;
  stateptr->bufferUp();
  stateptr->bufferUp();
  classifier.classify();
  if(state.getState()!=1){assert_print("Classifier is failing to detect Green.")}
  if(state.getBuffer()!=0){assert_print("Classifier is failing to empty buffer on Green.")}


  camera.data=brownImg;
  stateptr->bufferUp();
  stateptr->bufferUp();
  classifier.classify();
  if(state.getState()!=2){assert_print("Classifier is failing to detect Brown.")}
  if(state.getBuffer()!=0){assert_print("Classifier is failing to empty buffer on Brown.")}
}
