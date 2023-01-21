/////////////////////
// extraction2.cpp //
/////////////////////

// Extract color from ``BGR'' Data
// Choose Min, Max value for each BGR value by using trackbar


#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat input_image_rgb, mask_image, output_image_rgb;

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
	string path = "./images/cosmobio2-unsharp.jpg";
	// Load image
	Mat input_image_rgb = imread(path);
	if (input_image_rgb.empty())
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
		inRange(input_image_rgb, s_min, s_max, mask_image);
		
		
		/////////////////
		// Show images //
		/////////////////
		// Show input image
		namedWindow("Input image");
		imshow("Input image", input_image_rgb);
		// Show binary mask image
		namedWindow("Mask image Binary");
		imshow("Mask image Binary", mask_image);
		imwrite("./images/cosmobio2-unsharp_mask_binary2.jpg", mask_image);
		
		
		// Filtering input RGB image by mask image
		input_image_rgb.copyTo(output_image_rgb, mask_image);
		// Show RGB mask image
		namedWindow("Mask image RGB");
		imshow("Mask image RGB", output_image_rgb);
		//imwrite("./images/cosmobio2-unsharp_mask_rgb.jpg", output_image_rgb);
			
		waitKey(1);
	}

	return 0;
}
