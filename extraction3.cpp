///////////////////////
// extraction3.cpp //
///////////////////////

// For making mask image on unsharp BGR image

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

Mat src_rgb, mask_image, dst_rgb;

// Min, Max value of RGB
#define B_MAX 160
#define B_MIN 0
#define G_MAX 255
#define G_MIN 100
#define R_MAX 130
#define R_MIN 0

int main(void)
{
	string filename = "../data/image_processing/src2/cosmobio_rgb1-unsharp.jpg";

	// Load image file as 3 channel (BGR)
	src_rgb = imread(filename, IMREAD_COLOR);
	if (src_rgb.empty()) {
		cerr << "Can NOT load image.\n" << endl;
		return -1;
	}

	namedWindow("input_RGB");
	imshow("input_RGB", src_rgb);

	// Filtering by using inRange
	Scalar s_min = Scalar(B_MIN, G_MIN, R_MIN);
	Scalar s_max = Scalar(B_MAX, G_MAX, R_MAX);
	inRange(src_rgb, s_min, s_max, mask_image);

	// Show mask image
	namedWindow("mask");
	imshow("mask", mask_image);
	//imwrite("./images/example1_mask.jpg", mask_image);

	// Filtering by mask image
	src_rgb.copyTo(dst_rgb, mask_image);

	// Show result
	namedWindow("output");
	imshow("output", dst_rgb);
	imwrite("../data/image_processing/src2/cosmobio_rgb1-unsharp-mask2-filtering.jpg", dst_rgb);
	waitKey(0);

	return 0;
}
