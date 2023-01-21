/////////////////
// region2.cpp //
/////////////////

// Clipping image

#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat src;

int main(int argc, char **argv)
{
	////////////////////
	// src image name //
	////////////////////
	string input_filename = "images/cosmobio3-unsharp.jpg";
	
	///////////////////////////////////
	// Load image as BGR (3 channel) //
	///////////////////////////////////
	src = imread(input_filename, IMREAD_COLOR);
	if (src.empty())
	{
		cerr << "Can NOT input image.\n" << endl;
		return -1;
	}
	
	////////////////////
	// Clipping image //
	////////////////////
	Mat dst;
	dst = Mat(src, Rect(132, 85, 50, 50));	
	
	namedWindow("ROI");
	imshow("ROI", dst);
	imwrite("images/cosmobio3-unsharp-roi.jpg", dst);
	
	waitKey(0);
	
	return 0;
}
