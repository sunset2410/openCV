//#include <opencv2/imgproc.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <iostream>
//#include<vector>
//
////
//#include <opencv2/core/types_c.h>
//#include "opencv2/video.hpp"
//#include "opencv2/videoio.hpp"
//
//
//using namespace std;
//using namespace cv;
//
//void showImage(const String& winname, InputArray mat)
//{
//	imshow(winname, mat);
//	waitKey(0);
//
//}
//
//
//void imhist(Mat image, int histogram[])
//{
//
//	// initialize all intensity values to 0
//	for (int i = 0; i < 256; i++)
//	{
//		histogram[i] = 0;
//	}
//
//	// calculate the no of pixels for each intensity values
//	for (int y = 0; y < image.rows; y++)
//		for (int x = 0; x < image.cols; x++)
//			histogram[(int)image.at<uchar>(y, x)]++;
//}
//
//void histDisplay(int histogram[], const char* name)
//{
//	int hist[256];
//	for (int i = 0; i < 256; i++)
//	{
//		hist[i] = histogram[i];
//	}
//	// draw the histograms
//	int hist_w = 512; int hist_h = 400;
//	int bin_w = cvRound((double)hist_w / 256);
//
//	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));
//
//	// find the maximum intensity element from histogram
//	int max = hist[0];
//	for (int i = 1; i < 256; i++) {
//		if (max < hist[i]) {
//			max = hist[i];
//		}
//	}
//
//	// normalize the histogram between 0 and histImage.rows
//	for (int i = 0; i < 256; i++)
//	{
//		hist[i] = ((double)hist[i] / max)*histImage.rows;
//	}
//
//
//	// draw the intensity line for histogram
//	for (int i = 0; i < 256; i++)
//	{
//		line(histImage, Point(bin_w*(i), hist_h), Point(bin_w*(i), hist_h - hist[i]), Scalar(0, 0, 0), 1, 8, 0);
//	}
//
//	// display histogram
//	namedWindow(name, WINDOW_AUTOSIZE);
//	imshow(name, histImage);
//}
//
//
//void imhist2(Mat image, int histogram[], int &type)
//{
//	int  region[3];
//	for (int i = 0; i <= 2; i++)
//	{
//		region[i] = 0;
//	}
//
//	// initialize all intensity values to 0
//	for (int i = 0; i < 256; i++)
//	{
//		histogram[i] = 0;
//	}
//
//	// calculate the no of pixels for each intensity values
//	for (int y = 0; y < image.rows; y++)
//		for (int x = 0; x < image.cols; x++)
//		{
//			histogram[(int)image.at<uchar>(y, x)]++;
//			if((int)image.at<uchar>(y, x) <= 85)
//			{
//				region[0]++;
//			}
//			else if ((int)image.at<uchar>(y, x) > 85 && (int)image.at<uchar>(y, x) <= 170)
//			{
//				region[1]++;
//			}
//			else
//			{
//				region[2]++;
//			}
//		}
//			
//
//	if (region[0] < 0.2*image.rows*image.cols*0.3 || region[2] < 0.2*image.rows*image.cols*0.3)
//	{
//		type = 1;
//	}
//	else
//	{
//		type = 2;
//	}
//}
//
//
//int main1()
//{
//	Mat src = imread("F:\\openCV Project\\openCV\\Test\\b.jpg", IMREAD_COLOR);
//
//	vector<Mat> bgr_planes;
//	split(src, bgr_planes);
//
//	int histSize = 256;
//	float range[] = { 0,256 };
//	const float* histRange[] = { range };
//	bool uniform = true, accumulate = false;
//	Mat b_hist, g_hist, r_hist;
//
//	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
//	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
//	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);
//
//	int hist_w = 512;
//	int hist_h = 400;
//	int bin_w = cvRound((double)hist_w / histSize);
//
//	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
//	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	/*normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());*/
//
//	for (int i = 1; i < histSize; i++)
//	{
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
//			Scalar(255, 0, 0), 2, 8, 0);
//		/*line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
//			Scalar(0, 255, 0), 2, 8, 0);
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
//			Scalar(0, 0, 255), 2, 8, 0);*/
//	}
//
//	namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
//	imshow("calcHist Demo", histImage);
//
//
//	waitKey(0);
//
//	return 0;
//}
//
//
//int histogram_gray_image()
//{
//	Mat src = imread("F:\\openCV Project\\openCV\\Test\\aa.PNG", IMREAD_GRAYSCALE);
//
//	//vector<Mat> bgr_planes;
//	//split(src, bgr_planes);
//
//	int histSize = 256;
//	float range[] = { 0,256 };
//	const float* histRange[] = { range };
//	bool uniform = true, accumulate = false;
//	Mat hist;
//
//	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, histRange, uniform, accumulate);
//	
//
//	int hist_w = 512;
//	int hist_h = 400;
//	int bin_w = cvRound((double)hist_w / histSize);
//
//	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
//	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//
//
//	/*normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());*/
//
//	for (int i = 1; i < histSize; i++)
//	{
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))),
//			Scalar(255, 0, 0), 2, 8, 0);
//
//		/*line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
//			Scalar(0, 255, 0), 2, 8, 0);
//		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
//			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
//			Scalar(0, 0, 255), 2, 8, 0);*/
//	}
//
//	namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
//	imshow("calcHist Demo", histImage);
//
//
//
//	//--------- Generate the histogram c2-----------------------------------//
//	int histogram[256];
//	int type = 0;
//	imhist2(src, histogram, type);
//	// Display the original Histogram
//	histDisplay(histogram, "Original Histogram");
//
//	waitKey(0);
//
//	return 0;
//}
//
//
//void extract_frames(const string &videoFilePath, vector<Mat>& frames) {
//
//	try {
//
//		/*
//		//open the video file
//		VideoCapture cap(videoFilePath); // open the video file
//		if (!cap.isOpened())
//		{
//			// check if we succeeded
//			CV_Error(CV_StsError, "Can not open Video file");
//		}
//		*/
//		VideoCapture cap(videoFilePath);
//		cap.open(0);
//
//		if (!cap.isOpened())
//		{
//			CV_Error(CV_StsError, "Can not open Video file");
//		}
//
//		//cap.get(CV_CAP_PROP_FRAME_COUNT) contains the number of frames in the video;
//		for (int frameNum = 0; frameNum < cap.get(CAP_PROP_POS_FRAMES); frameNum++)
//		{
//			Mat frame;
//			cap >> frame; // get the next frame from video
//			frames.push_back(frame);
//		}
//	}
//	catch (cv::Exception& e) {
//		cerr << e.msg << endl;
//		exit(1);
//	}
//
//}
//
///*
//It saves a vector of frames into jpg images into the outputDir as 1.jpg,2.jpg etc where 1,2 etc represents the frame number
//*/
//void save_frames(vector<Mat>& frames, const string& outputDir) {
//	vector<int> compression_params;
//	compression_params.push_back(IMWRITE_JPEG_QUALITY);
//	compression_params.push_back(100);
//
//	/*for (std::vector<Mat>::iterator frame = frames.begin(), frameNumber = 0; frame != frame.end(); ++frame) {
//		string filePath = outputDir + to_string(static_cast<long long>(frameNumber)) + ".jpg";
//		imwrite(filePath, *frame, compression_params);
//	}*/
//
//	int frameNumber = 0;
//	for (std::vector<Mat>::iterator frame = frames.begin(); frame != frames.end(); ++frame) {
//		string filePath = outputDir + to_string(static_cast<long long>(frameNumber)) + ".jpg";
//		imwrite(filePath, *frame, compression_params);
//	}
//
//}
//
//
//int main()
//{
//	//histogram_gray_image();
//
//	//to extract
//	vector<Mat> frames;
//	extract_frames("a.mp4", frames);
//	//to save
//	save_frames(frames, "D:\\myvideo_frames\\");
//
//}