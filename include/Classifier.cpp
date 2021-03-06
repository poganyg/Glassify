#include "Classifier.h"


Classifier::Classifier(State* _stateptr, Camera* _cameraptr, Servo* _servoptr)
:stateptr(_stateptr),cameraptr(_cameraptr),m_servoptr(_servoptr)
{
  Mat baseFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->tempData);
  Mat baseGrey(cameraptr->m_height,cameraptr->m_width,CV_8UC1);
  Mat rollingFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->tempData);
  Mat rollingGrey(cameraptr->m_height,cameraptr->m_width,CV_8UC1);
}


int Classifier::checkMatch(Mat& baseImage, Mat& rollingImage)
{
  int counter = 0;
  for (int r = 0; r < baseImage.rows; r++)
  {
    for (int c = 0; c < baseImage.cols; c++)
    {
      rollingImage.at<uint8_t>(r, c) = abs(baseImage.at<uint8_t>(r, c) - rollingImage.at<uint8_t>(r, c));
      counter = counter + rollingImage.at<uint8_t>(r, c);
    }
  }
  return counter;
}


int Classifier::classify()
{
    //StableBaseline
    baseFrame = cameraptr->capture();
    cvtColor(baseFrame, baseGrey, COLOR_RGB2GRAY);

    rollingFrame = cameraptr->capture();
    cvtColor(rollingFrame,rollingGrey,COLOR_RGB2GRAY);

    baseClear = checkMatch(baseGrey, rollingGrey);

    //MainLoop
    while(stateptr->getBuffer()!=0 )
    {

      rollingFrame = cameraptr->capture();
      cvtColor(rollingFrame,rollingGrey,COLOR_RGB2GRAY);

      //Updating Clear Threshold
      cCounter = checkMatch(baseGrey, rollingGrey);
      if(loopNumber<=10)
      {
        loopNumber++;
        if (baseClear<cCounter)
        {
          baseClear=cCounter;
        }
      }

      cvtColor(rollingFrame,rollingFrame,COLOR_RGB2HSV);
      inRange(rollingFrame, Scalar(20,90,0), Scalar(80,255,255), greenOut);
      gCounter = cv::sum(greenOut);
      inRange(rollingFrame, Scalar(0,50,0), Scalar(30,255,150), brownOut);
      bCounter = cv::sum(brownOut);

      if((gCounter[0]>=33000 && gCounter[0]>=bCounter[0]) ||(gCounter[0]>=2500 && gCounter[0]>=5*bCounter[0]))
      {
        decisionVector[0]=decisionVector[1];
        decisionVector[1]=decisionVector[2];
        decisionVector[2]=decisionVector[3];
        decisionVector[3]=decisionVector[4];
        decisionVector[4]=1;
      }
      else if((bCounter[0]>=33000 && bCounter[0]>=gCounter[0])||(bCounter[0]>=2500 && bCounter[0]>=5*gCounter[0]))
      {
        decisionVector[0]=decisionVector[1];
        decisionVector[1]=decisionVector[2];
        decisionVector[2]=decisionVector[3];
        decisionVector[3]=decisionVector[4];
        decisionVector[4]=2;
      }
      else if(cCounter>=7.5*baseClear && bCounter[0]<=1000 && gCounter[0]<=1000)
      {
        decisionVector[0]=decisionVector[1];
        decisionVector[1]=decisionVector[2];
        decisionVector[2]=decisionVector[3];
        decisionVector[3]=decisionVector[4];
        decisionVector[4]=3;
      }
      else
      {
        decisionVector[0]=decisionVector[1];
        decisionVector[1]=decisionVector[2];
        decisionVector[2]=decisionVector[3];
        decisionVector[3]=decisionVector[4];
        decisionVector[4]=0;
      }
      cout<< "GREEN: " << gCounter << "BROWN: " << bCounter << "CLEAR: " << cCounter << endl;
      if (decisionVector[4]==decisionVector[0] && decisionVector[3]==decisionVector[0] && decisionVector[2]==decisionVector[0] && decisionVector[1]==decisionVector[0] && decisionVector[2]==decisionVector[1] && decisionVector[0]!=0)
      {
        printf("WritingState %i\n", decisionVector[0]);
        if (decisionVector[0]==1){m_servoptr->moveGreen();}
        if (decisionVector[0]==2){m_servoptr->moveBrown();}
        if (decisionVector[0]==3){m_servoptr->moveClear();}
        stateptr->bufferDown();
        decisionVector[0]=0;
        decisionVector[1]=0;
        decisionVector[2]=0;
        decisionVector[3]=0;
        decisionVector[4]=0;
        if(stateptr->getBuffer()==0)
        {
          return 0;
        }
      }
    }
}
