// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include<vector>


using namespace std;
using namespace cv;

void showImage(const String& winname, InputArray mat)
{
	imshow(winname, mat);
	waitKey(0);

}


int main1()
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

void imhist(Mat image, int histogram[])
{

	// initialize all intensity values to 0
	for (int i = 0; i < 256; i++)
	{
		histogram[i] = 0;
	}

	// calculate the no of pixels for each intensity values
	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			histogram[(int)image.at<uchar>(y, x)]++;
}

void histDisplay(int histogram[], const char* name)
{
	int hist[256];
	for (int i = 0; i < 256; i++)
	{
		hist[i] = histogram[i];
	}
	// draw the histograms
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

	// find the maximum intensity element from histogram
	int max = hist[0];
	for (int i = 1; i < 256; i++) {
		if (max < hist[i]) {
			max = hist[i];
		}
	}

	// normalize the histogram between 0 and histImage.rows
	for (int i = 0; i < 256; i++)
	{
		hist[i] = ((double)hist[i] / max)*histImage.rows;
	}


	// draw the intensity line for histogram
	for (int i = 0; i < 256; i++)
	{
		line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - hist[i]), Scalar(0, 0, 0), 1, 8, 0);
	}

	// display histogram
	namedWindow(name, WINDOW_AUTOSIZE);
	imshow(name, histImage);
}

int main9()
{
	// Load the image
	Mat image = imread("C:\\Users\\arjun\\Desktop\\input.jpg", IMREAD_GRAYSCALE);

	// Generate the histogram
	int histogram[256];
	imhist(image, histogram);

	// Calculate the size of image
	int size = image.rows * image.cols;

	// Calculate the probability of each intensity
	float PrRk[256];
	for (int i = 0; i < 256; i++)
	{
		PrRk[i] = (double)histogram[i] / size;
	}

	// Generate the equalized histogram
	float PsSk[256];
	for (int i = 0; i < 256; i++)
	{
		PsSk[i] = 0;
	}

	for (int i = 0; i < 256; i++)
		for (int j = 0; j <= i; j++)
			PsSk[i] += PrRk[j];

	int final[256];
	for (int i = 0; i < 256; i++)
		final[i] = cvRound(PsSk[i] * 255);

	for (int i = 0; i < 256; i++)
		for (int j = 0; j <= 255; j++)
			if (final[i] == final[j] && i != j)
			{
				final[i] += final[j];
			}

	int final1[256];
	for (int i = 0; i < 256; i++)
	{
		final1[i] = 0;
	}

	for (int i = 0; i < 256; i++)
	{
		final1[cvRound(PsSk[i] * 255)] = cvRound(PrRk[i] * size);
	}

	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			if (final1[i] == final[j] && i != j)
			{
				final1[i] += final1[j];
				cout << "final1[" << i << "]=" << final1[i] << endl;
			}

	// Generate the equlized image
	Mat new_image = image.clone();

	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			new_image.at<uchar>(y, x) = saturate_cast<uchar>(final[image.at<uchar>(y, x)]);

	// Display the original Image
	namedWindow("Original Image");
	imshow("Original Image", image);

	// Display the original Histogram
	histDisplay(histogram, "Original Histogram");

	// Display the equilzed histogram
	histDisplay(final1, "Equilized Histogram");

	// Display equilized image
	namedWindow("Equilized Image");
	imshow("Equilized Image", new_image);

	waitKey(0);
	return 0;
}

int main()
{
	Mat src = imread("F:\\openCV Project\\openCV\\Test\\a.jpg", IMREAD_COLOR);

	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	int histSize = 256;
	float range[] = { 0,256 };
	const float* histRange[] = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);

	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);

	waitKey(0);


}

*/