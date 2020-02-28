#include<iostream>
#include<opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("test.jpg", 0);
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}