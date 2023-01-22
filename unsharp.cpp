/////////////////
// unsharp.cpp //
/////////////////

#include <stdio.h>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, const char* argv[])
{
	int hr = -1;
	
	try
	{
		Mat src, dst;
		
		///////////////////
		// Load an image //
		///////////////////
		// As usual we load our source image ``src'':
		const char* imageName = argc >= 2 ? argv[1] : "./images/yourimage.jpg";
		src = imread(samples::findFile(imageName), IMREAD_COLOR); // Load an image
		
		///////////////////
		// Create cernel //
		///////////////////
		// In this case, mask size is 3x3
		Mat kernel = (Mat_<float>(3, 3) <<
		                   ////////////////////////////
			0, -1, 0,  //           / 0, -1,  0\ //
			-1, 6, -1, // cernel is |-1,  5, -1| //
			0, -1, 0); //           \ 0, -1,  0/ //
		                   ////////////////////////////
		
		filter2D(src, dst, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
		
		std::cout << "Successed" << std::endl;
		
		////////////////////////////
		// Show src (input) image //
		////////////////////////////
		namedWindow("Source", 1);
		imshow("Source", src);
		
		//////////////////////////
		// Show unsharped image //
		//////////////////////////
		namedWindow("unsharp", 1);
		imshow("unsharp", dst);
		// save unsharped image
		imwrite("./images/yourimage-unsharp.jpg", dst);
		
		waitKey(0);
		
		hr = 0;
	}
	
	catch (Exception ex)
	{
		std::cout << ex.err << std::endl;
	}
	
	/////////////////////////
	// Destroy all windows //
	/////////////////////////
	destroyAllWindows();
	
	return hr;
}
