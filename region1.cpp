/////////////////
// region1.cpp //
/////////////////

// Show Detected box's axis

#include <stdio.h>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

////////////////////////////////////////////
// Define Point that contain detected box //
////////////////////////////////////////////
Point top_left_corner, bottom_right_corner;

////////////////////
// Define Mat src //
////////////////////
Mat src;

///////////////////////////////////////////
// Function for calling input from mouse //
///////////////////////////////////////////
void drawRectangle(int event, int x, int y, int flags, void *userdata)
{
	//////////////////////////////////////////////////////////////////////////////
	// If you click mouse left button, then draw detected box's top left corner //
	//////////////////////////////////////////////////////////////////////////////
	if (event == EVENT_LBUTTONDOWN)
	{
		top_left_corner = Point(x, y);
	}
	////////////////////////////////////////////////////////////////////////////////////
	// If you release mouse left button, then draw detected box's bottom right corner //
	////////////////////////////////////////////////////////////////////////////////////
	else if (event == EVENT_LBUTTONUP)
	{
		bottom_right_corner = Point(x, y);
		////////////////////
		// Draw rectangle //
		////////////////////
		rectangle(src, top_left_corner, bottom_right_corner, Scalar(0,255,0), 1, 8);
		
		imshow("Window", src);
		//////////////////////////////////////////////////////
		// Show (top_left_corner, bottom_right_corner) axis //
		//////////////////////////////////////////////////////
		cout << top_left_corner << ", " << bottom_right_corner << "\n" << endl;
		///////////////////////////////////
		// Show rectangle's 4 point axis //
		///////////////////////////////////
		//cout << Point(x, y) << "\n" << endl;
	}
	
}

int main(int argc, char** argv)
{
	///////////////////
	// src file name //
	///////////////////
	string input_filename = "images/cosmobio3.jpg";
	
	///////////////////////////////////
	// Read image as BGR (3 channel) //
	///////////////////////////////////
	src = imread(input_filename, IMREAD_COLOR);
	if (src.empty())
	{
		cerr << "Can NOT input image.\n" << endl;
		return -1;
	}
	///////////////////////////////////////////////
	// This image uses for clearing detected box // 
	///////////////////////////////////////////////
	Mat temp = src.clone();
	
	///////////////////
	// Create window //
	///////////////////
	namedWindow("Window", WINDOW_AUTOSIZE);
	///////////////////////////////////////////////
	// highgui function                          //
	// It is calling when mouse event was happen //
	///////////////////////////////////////////////
	setMouseCallback("Window", drawRectangle, NULL);
	
	int k = 0;
	///////////////////////////////////////
	// Loop while ``q'' button is pushed //
	///////////////////////////////////////
	while(k != 123)
	{
		imshow("Window", src);
		k = waitKey(0);
		/////////////////////////////////////////////////////////////////////////
		// If the ``c'' key is clicked, then use dummy image and delete window //
		// In otherword, overwriting                                           //
		/////////////////////////////////////////////////////////////////////////
		if (k == 99)
		{
			temp.copyTo(src);
		}
		//imwrite("images/cosmobio2-unsharp_region.jpg", src);
	}
	destroyAllWindows();
	
	return 0;
}