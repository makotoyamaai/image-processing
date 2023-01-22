////////////////////
// histogram1.cpp //
////////////////////

// histogram for grayscale image

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat imgA, grayImg;
	imgA = imread("./images/yourimage-unsharp.jpg");
	imshow("img1", imgA);
	cvtColor(imgA, grayImg, COLOR_BGR2GRAY);

	int hbins = 255; 
	int channels[] = {0}; 
	int histSize[] = {hbins};
	float hranges[] = {0, 255};
	const float* ranges[] = {hranges};

	MatND Hist;

	vector<Mat> bgr_planes;
	split(imgA, bgr_planes);

	calcHist(&grayImg, 1, channels, Mat(), Hist, 1, histSize, ranges, true, false);
	normalize(Hist, Hist, 0, 255, NORM_MINMAX);

	int hist_w = 1000; int hist_h = 400;
	int ratio = cvRound((double)hist_w / hbins);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	int x1, y1;
	int x2, y2;
	for (int i = 1; i < hbins; i++)
	{
		x1 = ratio*(i - 1);
		y1 = hist_h - cvRound(Hist.at<float>(i - 1));

		x2 = ratio*(i);
		y2 = hist_h - cvRound(Hist.at<float>(i));

		line(histImage, Point(x1, y1), Point(x2, y2), Scalar(255, 255, 255), 2, 8, 0);
	}

	/// Display
	namedWindow("calcHist Demo", WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);
	imwrite("./images/yourimage-unsharp-hist.jpg", histImage);
	waitKey(0);

	return 0;
}
