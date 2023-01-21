////////////
// ed.cpp //
////////////

// Erosion and Dilation for binary image

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> // for erode, dilate function

using namespace cv;

int main()
{
	Mat img = imread("./images/cosmobio3-unsharp_mask_binary.jpg");
	
	Mat erode_dst, dilate_dst;
	
	Mat elementKernel1 = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	Mat elementKernel2 = getStructuringElement(MORPH_RECT, Size(4, 4), Point(-1, -1));
	

	dilate(img, dilate_dst, elementKernel1, Point(-1, -1), 1);
	erode(dilate_dst, erode_dst, elementKernel2, Point(-1, -1), 1);
	
	imshow("Input", img);
	imshow("Dilated", dilate_dst);
	imshow("Eroded", erode_dst);
	imwrite("./images/cosmobio3-unsharp_mask_binary_ed.jpg", erode_dst);
	
	waitKey(0);
	return 0;	
}
