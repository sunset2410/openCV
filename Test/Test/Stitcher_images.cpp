//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 1
//
//// CPP program to Stitch
//// input images (panorama) using OpenCV 
//#include <iostream>
//#include <fstream>
//
//// Include header files from OpenCV directory
//// required to stitch images.
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/stitching.hpp"
//
//using namespace std;
//using namespace cv;
//
//// Define mode for stitching as panoroma 
//// (One out of many functions of Stitcher)
//Stitcher::Mode mode = Stitcher::PANORAMA;
//
//// Array for pictures
//vector<Mat> imgs;
//
//int main()
//{
//	
//	char path[50];
//	sprintf(path, "%s/*.%s", "F:\\openCV Project\\openCV\\Test\\Test\\anh\\test4", "jpg");
//	vector<cv::String> vtFiles;
//	cv::glob(path, vtFiles, false);
//
//	for (int i = 0; i < vtFiles.size(); i++)
//	{
//		std:string strFilepath(vtFiles.at(i).c_str());
//		Mat img = imread(vtFiles.at(i).c_str(), IMREAD_COLOR);
//		imgs.push_back(img);
//
//
//	}
//
//	// Define object to store the stitched image
//	Mat pano;
//
//	// Create a Stitcher class object with mode panoroma
//	Ptr<Stitcher> stitcher = Stitcher::create(mode);
//
//	// Command to stitch all the images present in the image array
//	Stitcher::Status status = stitcher->stitch(imgs, pano);
//
//	if (status != Stitcher::OK)
//	{
//		// Check if images could not be stiched
//		// status is OK if images are stiched successfully
//		cout << "Can't stitch images\n";
//		return -1;
//	}
//
//	// Store a new image stiched from the given 
//	//set of images as "result.jpg"
//	imwrite("F:\\openCV Project\\openCV\\Test\\Test\\anh\\test4\\result.jpg", pano);
//
//	// Show the result
//	imshow("Result", pano);
//
//	waitKey(0);
//	return 0;
//}