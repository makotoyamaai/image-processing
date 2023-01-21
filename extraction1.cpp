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

Mat input_image_gray, mask_image, output_image_gray;

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
	string path = "./images/cosmobio3-unsharp.jpg";
	// Load image
	Mat input_image_gray = imread(path, IMREAD_GRAYSCALE);
	if (input_image_gray.empty())
	{
		cerr << "Cannot road Images. There are no specified Images." << endl;
		return -1;
	}
	
	//////////////////////////
	// Setting of Trackbars //
	//////////////////////////
	// Create trackbar's window 
	namedWindow("Trackbars", WINDOW_AUTOSIZE); 
	// Create trackbars
	createTrackbar("Threshold Min", "Trackbars", &Th_MIN, 255);
	createTrackbar("Threshold Max", "Trackbars", &Th_MAX, 255);
	
	// Filtering input RGB image by mask image
	input_image_gray.copyTo(output_image_gray, mask_image);
	
	while (true)
	{
		//////////////////////////////////////////
		// Detect by BGR value (Using Trackbar) //
		//////////////////////////////////////////
		// Set Min, Max value of each BGR value
		Scalar s_min = Scalar(Th_MIN);
		Scalar s_max = Scalar(Th_MAX);
		inRange(input_image_gray, s_min, s_max, mask_image);
		
		
		/////////////////
		// Show images //
		/////////////////
		// Show input image
		namedWindow("Input image");
		imshow("Input image", input_image_gray);
		// Show binary mask image
		namedWindow("Mask image Binary");
		imshow("Mask image Binary", mask_image);
		//imwrite("./images/cosmobio3-unsharp_mask_binary.jpg", mask_image);
		
		// Show RGB mask image
		namedWindow("Mask image RGB");
		imshow("Mask image RGB", output_image_gray);
		//imwrite("./images/cosmobio3-unsharp_mask_gray.jpg", output_image_gray);
		
		waitKey(1);
	}
	
	return 0;
}
