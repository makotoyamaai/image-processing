/////////////////////
// extraction2.cpp //
/////////////////////

// Extract color from ``BGR'' Data
// Choose Min, Max value for each BGR value by trackbar


#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat src_rgb, mask_image, dst_rgb;

///////////////////////////////////
// Initial position of Trackbars //
///////////////////////////////////
int B_MIN = 0;
int G_MIN = 0;
int R_MIN = 0;
int B_MAX = 255;
int G_MAX = 255;
int R_MAX = 255;

int main()
{
	////////////////////////////
	// Setting of input image //
	////////////////////////////
	// Path of image
	string filename = "../data/image_processing/src2/cosmobio_rgb1-unsharp.jpg";
	// Load image
	src_rgb = imread(filename);
	if (src_rgb.empty())
	{
		cerr << "Can NOT load image.\n" << endl;
		return -1;
	}
	
	//////////////////////////
	// Setting of Trackbars //
	//////////////////////////
	// Create trackbar's window 
	namedWindow("Trackbars", WINDOW_AUTOSIZE); 
	// Create trackbars
	createTrackbar("Blue Min", "Trackbars", &B_MIN, 255);
	createTrackbar("Blue Max", "Trackbars", &B_MAX, 255);
	createTrackbar("Green Min", "Trackbars", &G_MIN, 255);
	createTrackbar("Green Max", "Trackbars", &G_MAX, 255);
	createTrackbar("Red Min", "Trackbars", &R_MIN, 255);
	createTrackbar("Red Max", "Trackbars", &R_MAX, 255);
	
	while (true)
	{
		//////////////////////////////////////////
		// Detect by BGR value (Using Trackbar) //
		//////////////////////////////////////////
		// Set Min, Max value of each BGR value
		Scalar s_min = Scalar(B_MIN, G_MIN, R_MIN);
		Scalar s_max = Scalar(B_MAX, G_MAX, R_MAX);
		inRange(src_rgb, s_min, s_max, mask_image);
		
		/////////////////
		// Show images //
		/////////////////
		// Show input image
		namedWindow("Input image");
		imshow("Input image", src_rgb);
		// Show binary mask image
		namedWindow("Mask image Binary");
		imshow("Mask image Binary", mask_image);
		imwrite("../data/image_processing/src2/cosmobio_rgb1-unsharp-mask1.jpg", mask_image);
			
		waitKey(1);
	}

	return 0;
}
