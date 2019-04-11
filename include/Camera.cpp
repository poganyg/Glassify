#include "Camera.h"

acquireImage::acquireImage(State* _stateptr)
  :m_width(64),m_height(64),m_fps(120),m_shutter(10000),m_brightness(50),stateptr(_stateptr) //default parameters for camera
{

  //Setting up Camera
  Camera.setWidth(m_width);
  Camera.setHeight(m_height);
  Camera.setFrameRate(m_fps);
  Camera.setShutterSpeed(m_shutter);
  Camera.setBrightness(m_brightness);

  //Allocate Memory
  data=new unsigned char[Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)]; //Allocates uchar data for __DEFAULT__ raspicam::format, i.e. RGB
  unsigned char* dataptr = &data;
  //IDEALLY, FIND OUT HOW TO RECAST UCHAR TO MAT AND DEFINE MAT HERE

  cout<<"Opening Camera..."<<endl;
  if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;}
}

int acquireImage::checkMatch(Mat templateImg, Mat currentImg)
{
  int counter = 0;
  Mat greyImg;
  cvtColor(currentImg, greyImg, COLOR_RGB2GRAY);

  for (int r = 0; r < templateImg.rows; r++)
  {
    for (int c = 0; c < templateImg.cols; c++)
    {
      greyImg.at<uint8_t>(r, c) = abs(templateImg.at<uint8_t>(r, c) - greyImg.at<uint8_t>(r, c));
      counter = counter + greyImg.at<uint8_t>(r, c);
    }
  }
  return counter;
}

void acquireImage::classify()
//   *stateptr=0;
{
  while(stateptr->getState()==0)
  {
  //wait a while until camera stabilizes
  Camera.grab();
  //Gather Baseline Data
  Camera.retrieve ( data );//get camera image
  Mat Template(m_height,m_width,CV_8UC3,data);
  Mat grayTemplate(m_height,m_width,CV_8UC1);
  cvtColor(Template, grayTemplate, COLOR_RGB2GRAY);
  Camera.grab();
  //Gather Baseline Data
  Camera.retrieve ( data );//get camera image
  Mat Frame(m_height,m_width,CV_8UC3,data);
  baseClear = checkMatch(grayTemplate, Frame);
  while(true)
  {
    Camera.grab();
    Camera.retrieve(data);
    Mat Frame(m_height,m_width,CV_8UC3,data);
    cCounter = checkMatch(grayTemplate, Frame);
    if(loopNumber<=25)
    {
      loopNumber++;
      if (baseClear<cCounter)
      {
        baseClear=cCounter;
      }
    }
    cvtColor(Frame,Frame,COLOR_RGB2HSV);
    inRange(Frame, Scalar(20,90,0), Scalar(80,255,255), greenOut);
    gCounter = cv::sum(greenOut);
    inRange(Frame, Scalar(0,50,0), Scalar(30,255,150), brownOut);
    bCounter = cv::sum(brownOut);
    printf("Classifying\n");
    if((gCounter[0]>=100000 && gCounter[0]>=bCounter[0]) ||(gCounter[0]>=10000 && gCounter[0]>=5*bCounter[0]))
    {
      decisionVector[0]=decisionVector[1];
      decisionVector[1]=decisionVector[2];
      decisionVector[2]=1;
    }
    else if((bCounter[0]>=100000 && bCounter[0]>=gCounter[0])||(bCounter[0]>=10000 && bCounter[0]>=5*gCounter[0]))
    {
     decisionVector[0]=decisionVector[1];
     decisionVector[1]=decisionVector[2];
     decisionVector[2]=2;
    }
    else if(cCounter>=baseClear*2)
    {
     decisionVector[0]=decisionVector[1];
     decisionVector[1]=decisionVector[2];
     decisionVector[2]=3;
    }
    else
    {
      decisionVector[0]=decisionVector[1];
      decisionVector[1]=decisionVector[2];
      decisionVector[2]=0;
    }
    if (decisionVector[1]==decisionVector[0] && decisionVector[2]==decisionVector[1] && decisionVector[0]!=0)
    {
      printf("WritingState %i\n", decisionVector[0]);
      stateptr->writeState(decisionVector[0]);
      return;
    }
  }
}
}
