#include "Classifier.h"


Classifier::Classifier(State* _stateptr, Camera* _cameraptr)
  :stateptr(_stateptr),cameraptr(_cameraptr),bufferOn(false),loopNumber(0)
{
  Mat baseFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->data);
  Mat baseGrey(cameraptr->m_height,cameraptr->m_width,CV_8UC1);
  Mat rollingFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->data);
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


void Classifier::classify()
{
  while(stateptr->getBuffer()!=0)
  {
    //StableBaseline
    cameraptr->capture();
    Mat baseFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->data);
    cvtColor(baseFrame, baseGrey, COLOR_RGB2GRAY);

    cameraptr->capture();
    Mat rollingFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->data);
    cvtColor(rollingFrame,rollingGrey,COLOR_RGB2GRAY);

    baseClear = checkMatch(baseGrey, rollingGrey);

    //MainLoop
    while(stateptr->getBuffer()!=0)
    {
      cameraptr->capture();
      Mat rollingFrame(cameraptr->m_height,cameraptr->m_width,CV_8UC3,cameraptr->data);
      cvtColor(rollingFrame,rollingGrey,COLOR_RGB2GRAY);

      //Updating Clear Threshold
      cCounter = checkMatch(baseGrey, rollingGrey);
      if(loopNumber<=25)
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
        if((stateptr->getBuffer()-1)!=0)
        {
          if (bufferOn == true)
          {
            end = chrono::steady_clock::now();
            stateptr->addState(decisionVector[0],abs(end-start))
            start = chrono::steady_clock::now();
          }
          else
          {
            stateptr->addState(decisionVector[0],0)
            start = chrono::steady_clock::now();
            bufferOn = true;
          }
          softReset();
        }
        else
        {
          if (bufferOn == true)
          {
            bufferOn = false;
            end = chrono::steady_clock::now();
            stateptr->addState(decisionVector[0],0)
          }
          else
          {
            stateptr->addState(decisionVector[0],0);
          }
          reset(); //Resets loopNumber and decisionVector variables for next classification loop
          }
        }
      }
      stateptr->bufferDown();
    }
  }

  void Classifier::reset()
  {
    loopNumber = 0;
    decisionVector[0]=0;
    decisionVector[1]=0;
    decisionVector[2]=0;
  }

  void Classifier::softReset()
  {
    decisionVector[0]=0;
    decisionVector[1]=0;
    decisionVector[2]=0;
  }
