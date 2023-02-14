//////////////////////////
// contour_rect_all.cpp //
//////////////////////////

// Draw boundingRect

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cstdio>

using namespace cv;
using namespace std;

Mat src, src_gray, drawing;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

void thresh_callback(int, void*);

int main()
{
	for (int j=1; j<=100; j++)
	{
		/////////////////
		// Load images //
		/////////////////
		string filename = "../data/image_processing/src1/cosmobio_gray" + to_string(j) + "-unsharp-de.jpg";
		src = imread(filename, IMREAD_COLOR);
		if (src.empty()) 
		{
			cerr << "Can NOT load image.\n" << endl;
			return -1;
		}
		
		cvtColor(src, src_gray, COLOR_BGR2GRAY);
		
		Mat threshold_output;
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		
		//////////////////////////////////////
		// threshold of the grayscale image //
		//////////////////////////////////////
		threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);
		
		///////////////////////////////////////////////////////////////////////////////
		// Find contours and saves them to the vectors ``contour'' and ``hierarchy'' //
		///////////////////////////////////////////////////////////////////////////////
		findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
		
		vector<vector<Point> > contours_poly(contours.size());
		vector<Rect> boundRect(contours.size());
		vector<Point2f>center(contours.size());
		vector<float>radius(contours.size());

		///////////////////////////////////////////////////////////////////////////////////////
		// For every found contour we now apply approximation to polygons with accuracy +-3  //
		// and stating that the curve closed.                                                //
		// After that we find a bounding rect for every polygon and save it to ``boundRect'' //
		///////////////////////////////////////////////////////////////////////////////////////
		for(size_t i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
			boundRect[i] = boundingRect( Mat(contours_poly[i]) );
			//minEnclosingCircle( contours_poly[i], center[i], radius[i] );
		}
		
		drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
		
		//////////////////////////////////////////////////
		// Write axis of boundingRext in ``output.txt'' //
		//////////////////////////////////////////////////
		string result_data = "../data/image_processing/output_rect_all" + to_string(j) + ".txt";
		freopen(result_data.c_str(), "w", stdout);
		
		for(size_t i = 0; i< contours.size(); i++)
		{
			//////////////////////////////////////////
			// Scalar(255, 255, 255) -> White color //
			// Scalar(255, 0, 0)     -> Blue color  //
			// Scalar(0, 255, 0)     -> Green color //
			// Scalar(0, 0, 255)     -> Red color   //
			//////////////////////////////////////////
			Scalar color1 = Scalar(255, 255, 255);
			Scalar color2 = Scalar(255, 0, 0);
			Scalar color3 = Scalar(0, 255, 0);
			Scalar color4 = Scalar(0, 0, 255);
			
			///////////////////////////////
			// Draw contours with color1 //
			///////////////////////////////
			drawContours(drawing, contours_poly, (int)i, color1, 1, 8, vector<Vec4i>(), 0, Point());
			
			/////////////////////////////////
			// Draw rectangles with color2 //
			/////////////////////////////////
			rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color4, 2, 8, 0);
			cout << boundRect[i] << endl;
			//circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
		}
		
		///////////////////////////
		// Save unsharped images //
		///////////////////////////
		string filename_output = "../data/image_processing/src1/cosmobio_gray" + to_string(j) + "-unsharp-de-rect.jpg";
		imwrite(filename_output, drawing);

		waitKey(0);
	}
	return(0);
}
