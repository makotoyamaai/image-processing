///////////////////////
// extraction2-1.cpp //
///////////////////////

// For making mask image on unsharp BGR image

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

// Min, Max value of RGB
#define B_MAX 255
#define B_MIN 180
#define G_MAX 255
#define G_MIN 0
#define R_MAX 100
#define R_MIN 0

int main(void)
{
	string input_filename = "./images/yourimage-unsharp.jpg";

	// Load image file as 3 channel (BGR)
	Mat input_image_rgb = imread(input_filename, IMREAD_COLOR);
	if (input_image_rgb.empty()) {
		cerr << "Cannot road Images. There are no specified Images." << endl;
		return -1;
	}

	namedWindow("input_RGB");
	imshow("input_RGB", input_image_rgb);

	Mat mask_image, output_image_rgb;

	// Filtering by using inRange
	Scalar s_min = Scalar(B_MIN, G_MIN, R_MIN);
	Scalar s_max = Scalar(B_MAX, G_MAX, R_MAX);
	inRange(input_image_rgb, s_min, s_max, mask_image);

	// Show mask image
	namedWindow("mask");
	imshow("mask", mask_image);
	//imwrite("./images/example1_mask.jpg", mask_image);

	// Filtering by mask image
	input_image_rgb.copyTo(output_image_rgb, mask_image);

	// Show result
	namedWindow("output");
	imshow("output", output_image_rgb);
	imwrite("./images/yourimage-unsharp-mask-rgb.jpg", output_image_rgb);
	waitKey(0);

	return 0;
}
