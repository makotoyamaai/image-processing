////////////////////
// histogram2.cpp //
////////////////////

// for grayscale image

#include <stdio.h>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	/////////////////////////////
	// 入力画像名(ファイルパス) //
	/////////////////////////////
	string input_filename = "images/cosmobio2-unsharp.jpg";
	
	///////////////////////////////////
	// Load image as BGR (3 channel) //
	///////////////////////////////////
	Mat src = imread(input_filename, IMREAD_COLOR);
	if (src.empty())
	{
		cerr << "Can NOT input image.\n" << endl;
		return -1;
	}
	
	vector<Mat> bgr_planes;
	split(src, bgr_planes);
	
	int histSize = 256;
	
	float range[] = { 0, 256 }; // the upper boundary is exclusive
	const float* histRange[] = { range };
	
	bool uniform = true, accumulate = false;
	
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);
	
	///////////////////
	// グラフのサイズ //
	///////////////////
	int hist_w = 1000, hist_h = 400;
	int bin_w = cvRound((double) hist_w / histSize);
	
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	
	for (int i = 1; i < histSize; i++)
	{
		///////////////////////////////////////////////////////////////////////
		// line(img, pt1, pt2, color, thickness, lineType, shift)            //
		// pt1: 直線の始点の座標                                              //
		// pt2: 直線の終点の座標                                              //
		// color: 線の色                                                     //
		// thickness: 線の太さ．int型で指定する．0以下ならerror発生            //
		// linetype: 線を描画するアルゴリズムの種類                            //
		// shift: 各座標において小数点以下の桁を表すビット数．int型で指定する． //
		//        デフォルト引数なので，値を渡さなければshift=0                //
		///////////////////////////////////////////////////////////////////////
		line(histImage, Point(bin_w * (i-1), hist_h - cvRound(b_hist.at<float>(i-1))),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i-1), hist_h - cvRound(g_hist.at<float>(i-1))),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i-1), hist_h - cvRound(r_hist.at<float>(i-1))),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
		
		/*
		////////////////////////////////
		// 横軸方向に縦線を引く(5刻み) //
		////////////////////////////////
		if (i%10 == 0)
		{
			line(histImage, Point(10 + i, 100), Point(10 + i, 10),
				Scalar(80, 80, 80), 1, 8, 0);
			line(histImage, Point(5 + i, 200), Point(5 + i, 110),
				Scalar(170, 170, 170), 1, 8, 0);
			line(histImage, Point(5 + i, 300), Point(5 + i, 210),
				Scalar(170, 170, 170), 1, 8, 0);
		
			/////////////////////////////////////
			// 横軸方向に太い縦線を引く(10刻み) //
			/////////////////////////////////////
			if (i%50 == 0)
			{
				line(histImage, Point(10 + i, 100), Point(10 + i, 10),
					Scalar(50, 50, 50), 1, 8, 0);
				line(histImage, Point(10 + i, 200), Point(10 + i, 110),
					Scalar(50, 50, 50), 1, 8, 0);
				line(histImage, Point(10 + i, 300), Point(10 + i, 210),
					Scalar(50, 50, 50), 1, 8, 0);
			}
		}*/
	}
	
	imshow("Source image", src);
	imshow("calcHist", histImage);
	imwrite("./images/cosmobio2-unsharp-hist.jpg", histImage);
	
	waitKey(0);
	
	return EXIT_SUCCESS;
}
