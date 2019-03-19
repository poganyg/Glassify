#include "opencv2/opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

void checkColourUp(Mat input, Mat& outputImg, int& output, int limH, int limS, int limV, int angle)
{
	int counter = 0;
	Mat temp = input;
	outputImg = input;
	Mat splitChannels[3];//declares an array of Mat objects which will store each of the channels
	split(temp, splitChannels);
	int H;
	int S;
	int V;

	for (int r = 0; r < splitChannels[0].rows; r++)
	{
		for (int c = 0; c < splitChannels[0].cols; c++)
		{
			//double H = splitChannels[0].at<double>(r, c);
			//double S = splitChannels[1].at<double>(r, c);
			//double V = splitChannels[2].at<double>(r, c);
			H = temp.at<Vec3b>(r, c)[0];
			S = temp.at<Vec3b>(r, c)[1];
			V = temp.at<Vec3b>(r, c)[2];

			if (H >= limH && H <= (limH + angle) && S >= limS && V >= limV)
				counter = counter + 1;
			//
			else //Set all values of HSV to 0 if pixel in desired range not found
				outputImg.at<Vec3b>(r, c)[0] = 0;
				outputImg.at<Vec3b>(r, c)[1] = 0;
				outputImg.at<Vec3b>(r, c)[2] = 0;
			//
		}
	}
	//cvtColor(outputImg, outputImg, COLOR_HSV2BGR);
	imshow("original", input);
	moveWindow("original",100, 100);
	imshow("test", outputImg);
	moveWindow("test", 600, 100);
	output = counter;
	waitKey();
}

void checkColourDown(Mat input, Mat& outputImg, int& output, int limH, int limS, int limV, int angle)
{
	int counter = 0;
	Mat temp = input;
	outputImg = input;
	Mat splitChannels[3]; //declares an array of Mat objects which will store each of the channels
	split(temp, splitChannels);
	int H;
	int S;
	int V;

	for (int r = 0; r < splitChannels[0].rows; r++)
	{
		for (int c = 0; c < splitChannels[0].cols; c++)
		{
			//double H = splitChannels[0].at<double>(r, c);
			//double S = splitChannels[1].at<double>(r, c);
			//double V = splitChannels[2].at<double>(r, c);
			H = temp.at<Vec3b>(r, c)[0];
			S = temp.at<Vec3b>(r, c)[1];
			V = temp.at<Vec3b>(r, c)[2];

			if (H >= limH && H <= (limH + angle) && S >= limS && V <= limV)
				counter = counter + 1;
			else //Set all values of HSV to 0 if pixel in desired range not found
			outputImg.at<Vec3b>(r, c)[0] = 0;
			outputImg.at<Vec3b>(r, c)[1] = 0;
			outputImg.at<Vec3b>(r, c)[2] = 0;
		}
	}
	//cvtColor(outputImg, outputImg, COLOR_HSV2BGR);
	output = counter;
}

void checkMatch(Mat templateImg, Mat currentImg, Mat& outputImg, int& output)
{
	int counter = 0;
	outputImg =	Mat::zeros(templateImg.size(), CV_8UC1);

	for (int r = 0; r < templateImg.rows; r++)
	{
		for (int c = 0; c < templateImg.cols; c++)
		{
			outputImg.at<uint8_t>(r, c) = abs(templateImg.at<uint8_t>(r, c) - currentImg.at<uint8_t>(r, c));
			counter = counter + outputImg.at<uint8_t>(r, c);
		}
	}
	output = counter;
}


int main(int argv, char** argc)
{
	Mat colorFrame;
	Mat grayFrame;
	Mat modFrame;
	Mat Template;
	Mat Out;
	Mat grayOut;
	int gCounter; //green counter
	int bCounter; //brown counter
	int cCounter; //clear counter

	VideoCapture vid(0);

	if (!vid.isOpened())
	{
		return -1;
	}

	vid.read(Template);
	cvtColor(Template, Template, COLOR_BGR2GRAY);
	imshow("Template", Template);
	//waitKey();
	//while (waitKey() < 0)
	//{
		vid.read(colorFrame);
		cvtColor(colorFrame, modFrame, COLOR_BGR2HSV);
		cvtColor(colorFrame, grayFrame, COLOR_BGR2GRAY);

		checkColourUp(modFrame, Out, gCounter, 160, 30, 5, 20);
		imshow("Green", Out);
		Mat Next;
		cvtColor(Out, Next, COLOR_HSV2BGR);
		imshow("Next", Next);

		cout << "Green Pixels " << gCounter << endl;
		moveWindow("Green", 100, 100);
		//waitKey();

		checkColourDown(modFrame, Out, bCounter, 7, 70, 20, 15);
		imshow("Brown", Out);
		cout << "Brown Pixels " << bCounter << endl;
		moveWindow("Brown", 500, 100);
		//waitKey();

		checkMatch(Template, grayFrame, grayOut, cCounter);
		imshow("Match", grayOut);
		cout << "Deviation Magnitude " << cCounter << endl;
		moveWindow("Match", 900, 100);
		waitKey();
		//imshow("Webcam", frame);
		//std::cout << "picture" << std::endl;
	//}

	return 1;
}
