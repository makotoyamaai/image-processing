/////////////////
// region2.cpp //
/////////////////
// Clipping image

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

Mat src, dst;

int main()
{
	////////////////////
	// src image name //
	////////////////////
	string filename = "../data/image_processing/src2/cosmobio_rgb1-unsharp.jpg";
	
	///////////////////////////////////
	// Load image as BGR (3 channel) //
	///////////////////////////////////
	src = imread(filename, IMREAD_COLOR);
	if (src.empty())
	{
		cerr << "Can NOT load image.\n" << endl;
		return -1;
	}
	
	////////////////////
	// Clipping image //
	////////////////////
	dst = Mat(src, Rect(144, 68, 50, 50));	
	
	namedWindow("ROI");
	imshow("ROI", dst);
	imwrite("../data/image_processing/src2/cosmobio_rgb1-unsharp-region.jpg", dst);
	
	waitKey(0);
	
	return 0;
}
