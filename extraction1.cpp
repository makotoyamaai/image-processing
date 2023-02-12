/////////////////////
// extraction1.cpp //
/////////////////////

// Extract color from ``Grayscale'' Data
// Choose Min, Max value for brightness value by trackbar

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat src_gray, mask_image, dst_gray;

///////////////////////////////////
// Initial position of Trackbars //
///////////////////////////////////
int Th_MIN = 0;
int Th_MAX = 255;

int main()
{
	////////////////////////////
	// Setting of input image //
	////////////////////////////
	// Path of image
	string filename = "../data/image_processing/src1/cosmobio_gray1-unsharp.jpg";
	// Load image
	Mat src_gray = imread(filename, IMREAD_GRAYSCALE);
	if (src_gray.empty())
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
	createTrackbar("Threshold Min", "Trackbars", &Th_MIN, 256);
	createTrackbar("Threshold Max", "Trackbars", &Th_MAX, 256);
	
	// Filtering input RGB image by mask image
	src_gray.copyTo(dst_gray, mask_image);
	
	while (true)
	{
		//////////////////////////////////////////
		// Detect by BGR value (Using Trackbar) //
		//////////////////////////////////////////
		// Set Min, Max value of each BGR value
		Scalar s_min = Scalar(Th_MIN);
		Scalar s_max = Scalar(Th_MAX);
		inRange(src_gray, s_min, s_max, mask_image);
		
		
		/////////////////
		// Show images //
		/////////////////
		// Show input image
		namedWindow("Input image");
		imshow("Input image", src_gray);
		// Show binary mask image
		namedWindow("Mask image Binary");
		imshow("Mask image Binary", mask_image);
		imwrite("../data/image_processing/src1/cosmobio_gray1-unsharp-mask.jpg", mask_image);
		
		// Show RGB mask image
		//namedWindow("Mask image RGB");
		//imshow("Mask image RGB", dst_gray);
		//imwrite("./images/cosmobio3-unsharp_mask_gray.jpg", dst_gray);
		
		waitKey(1);
	}
	
	return 0;
}
