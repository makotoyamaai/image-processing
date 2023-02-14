/////////////////
// closing.cpp //
/////////////////

// Erosion and Dilation for binary image

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> // for erode, dilate function

using namespace cv;
using namespace std;

Mat src, dst_erode, dst_dilate, elementKernel1, elementKernel2;

int main()
{
	string filename = "../data/image_processing/src1/cosmobio_gray1-unsharp-mask.jpg";
	src = imread(filename);
	if (src.empty()) {
		cerr << "Can NOT load image.\n" << endl;
		return -1;
	}
	
	elementKernel1 = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	elementKernel2 = getStructuringElement(MORPH_RECT, Size(4, 4), Point(-1, -1));
	
	dilate(src, dst_dilate, elementKernel1, Point(-1, -1), 1);
	erode(dst_dilate, dst_erode, elementKernel2, Point(-1, -1), 1);
	
	imshow("Input", src);
	imshow("Dilated", dst_dilate);
	imshow("Eroded", dst_erode);
	imwrite("../data/image_processing/src1/cosmobio_gray1-unsharp-de.jpg", dst_erode);
	
	waitKey(0);
	return 0;	
}
