#include<iostream>
#include<opencv.hpp>
#include <fstream>
#include<string>
using namespace cv;
using namespace std;
int main()
{
	int c[256] = { 0 };
	float d[256] = { 0 };
	ofstream outfile("out1.txt", ios::trunc);
	cv::Mat srcMat = imread("test.jpg", 0);
	imshow("src", srcMat);
	int height = srcMat.rows;
	int width = srcMat.cols;
	int sum = height*width;
	int sum_test = 0;
	for (int i = 0; i < 256; i++) {
		c[i] = i;
	}
	for (int j = 0; j < height; j++) {
		//���д������
		for (int i = 0; i < width; i++) {
			//------��ʼ����ÿ������------------
			int getScr = srcMat.at<uchar>(j, i);
			d[getScr] = d[getScr] + 1;
			//-----����ÿ�����صĴ���-----------
		}
	}
		for (int i = 0; i < 256; i++) {
			sum_test = sum_test + d[i];
			d[i] = d[i] / sum;
		}
		if (sum_test == sum) {
			cout << "Match!"  << endl;
		};
		waitKey(0);
		system("pause");
		return 0;
	}