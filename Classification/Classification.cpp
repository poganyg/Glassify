#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

Mat checkMatch(Mat templateImg, Mat currentImg)
{
	int counter = 0;
	Mat outputImg = Mat::zeros(templateImg.size(), CV_8UC1);

	for (int r = 0; r < templateImg.rows; r++)
	{
		for (int c = 0; c < templateImg.cols; c++)
		{
			outputImg.at<uint8_t>(r, c) = abs(templateImg.at<uint8_t>(r, c) - currentImg.at<uint8_t>(r, c));
			counter = counter + outputImg.at<uint8_t>(r, c);
		}
	}
	return outputImg;
}

int main(int argv, char** argc)
{
	int fps = 20;

	//To Initialise
	Mat Template;
	Mat grayTemplate;

	//Looped Classification
	Mat Frame;
	Mat Frame2;
	Mat grayFrame;
	Mat brownOut;
	Mat greenOut;
	Mat grayOut;

	VideoCapture vid(0);

	if (!vid.isOpened())
	{
		return -1;
	}

	vid.read(Template);
	cvtColor(Template, grayTemplate, COLOR_BGR2GRAY);
	int counter = 0;
	while (vid.read(Frame))
	{

		cvtColor(Frame, grayFrame, COLOR_BGR2GRAY);
		cvtColor(Frame, Frame, COLOR_BGR2HSV);
		//grayOut = checkMatch(grayTemplate, grayFrame);
		inRange(Frame, Scalar(35, 90, 0), Scalar(80, 255, 255), greenOut);
		inRange(Frame, Scalar(0, 50, 0), Scalar(30, 255, 150), brownOut);

		imshow("green", greenOut);
		imshow("brown", brownOut);

		cv::moveWindow("green", 0, 100);
		cv::moveWindow("brown", 600, 100);

		if (waitKey(1000 / fps) >= 0)
			break;
	}
	return 1;
}
