#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

int checkColour(Mat input, int lowH, int highH, int lowS, int highS, int lowV, int highV)
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
	return counter;
}

int checkMatch(Mat templateImg, Mat currentImg)
{
	int counter = 0;
	Mat greyImg;
	cvtColor(currentImg, greyImg, COLOR_BGR2GRAY);

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

int main(int argv, char** argc)
{

	//To Initialise
	Mat Template;
	Mat grayTemplate;
	int fps = 20; //sets rate of capture

	//Looped Classification
	Mat Frame;

	int gCounter; //green counter
	int bCounter; //brown counter
	int cCounter; //clear counter

	VideoCapture vid(0);

	if (!vid.isOpened())
	{
		return -1;
	}

	vid.read(Template);
	
	//Not specific to OpenCV camera capture from here down
	cvtColor(Template, grayTemplate, COLOR_BGR2GRAY);
	int counter = 0;
	while (vid.read(Frame))
	{
		cCounter = checkMatch(grayTemplate, Frame);
		bCounter = checkColour(Frame, 170, 25, 50, 150, 0, 65); // For Brown
		gCounter = checkColour(Frame, 40, 75, 90, 255, 50, 255); //For Green

		std::cout << "CLEAR: " << cCounter << " BROWN: " << bCounter << " GREEN: " << gCounter << endl;

		if (waitKey(1000 / fps) >= 0)
			break;
	}
	return 1;
}
