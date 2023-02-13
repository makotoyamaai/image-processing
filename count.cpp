///////////////
// count.cpp //
///////////////

// Count cell on your binary image

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("./images/cosmobio2-unsharp_mask_binary.jpg", IMREAD_UNCHANGED);
	
	//Mat element = Mat::ones(1, 1, CV_8UC1); 
	//erode(img, img, element, Point(-1, -1), 4); 

	vector<vector<Point> > contours;
	findContours(img, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	for(int i=0; i<contours.size(); i++)
	{
		int count=contours.at(i).size();
		double x=0; double y=0;
		for(int j=0;j<count;j++)
		{
			x+=contours.at(i).at(j).x;
			y+=contours.at(i).at(j).y;
		}
		x /= count;
		y /= count;
		circle(img, Point(x, y), 5, Scalar(0, 0, 255), 2, 4);
	}
	
	cout << contours.size() << " cells" << endl;

	imshow("IMAGE", img);
	imwrite("./images/cosmobio2-unsharp_mask_binary_count.jpg", img);
	
	waitKey(); 
	return 0; 
}
