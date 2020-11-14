// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

void showImage(const String& winname, InputArray mat)
{
	imshow(winname, mat);
	waitKey(0);

}


int main()
{
    std::cout << "Hello World!\n";

	Mat img = imread("G:\\test.png", IMREAD_COLOR);
	showImage("origin", img);


	cvtColor(img, img, COLOR_BGR2GRAY);

	showImage("test", img);


	Mat a;
	absdiff(img, img, a);


	showImage("a", a);


	waitKey(0);
	return 0;
}

