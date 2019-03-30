#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

Mat checkColour(Mat input, int lowH, int highH, int lowS, int highS, int lowV, int highV)
{
	cvtColor(input, input, COLOR_BGR2HSV);
	int counter = 0;

	for (int r = 0; r < input.rows; r++)
	{
		for (int c = 0; c < input.cols; c++)
		{
			unsigned char H = input.at<Vec3b>(r, c)[0];
			unsigned char S = input.at<Vec3b>(r, c)[1];
			unsigned char V = input.at<Vec3b>(r, c)[2];

			if (lowH > highH)
			{
				if ((H >= lowH || H <= highH) && S >= lowS && S <= highS && V >= lowV && V <= highV)
				{
					counter = counter + 1;
				}
				else //Set all values of HSV to 0 if pixel in desired range not found
				{
					input.at<Vec3b>(r, c)[0] = 0;
					input.at<Vec3b>(r, c)[1] = 0;
					input.at<Vec3b>(r, c)[2] = 0;
				}
			}
			if (highH > lowH)
			{
				if (H >= lowH && H <= highH && S >= lowS && S <= highS && V >= lowV && V <= highV)
				{
					counter = counter + 1;
				}
				else //Set all values of HSV to 0 if pixel in desired range not found
				{
					input.at<Vec3b>(r, c)[0] = 0;
					input.at<Vec3b>(r, c)[1] = 0;
					input.at<Vec3b>(r, c)[2] = 0;
				}
			}
		}
	}

	cvtColor(input, input, COLOR_HSV2BGR);
	return input;
}

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
		grayOut = checkMatch(grayTemplate, grayFrame);
		greenOut = checkColour(Frame, 40, 75, 90, 255, 50, 255);
		if (waitKey(1000 / fps) >= 0)
			break;
	}
	return 1;
}
