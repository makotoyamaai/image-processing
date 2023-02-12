/////////////////
// unsharp.cpp //
/////////////////

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	for (int i=1; i<=100; i++){
		Mat dst;
			
		/////////////////
		// Load images //
		/////////////////
		// As usual we load our source image "src":
		string filename = "../data/image_processing/src2/cosmobio_rgb" + to_string(i) + ".jpg";
		Mat src = imread(filename, IMREAD_COLOR);
		
		///////////////////
		// Create cernel //
		///////////////////
		// In this case, 3x3 mask
		Mat kernel = (Mat_<float>(3, 3) <<
			           ////////////////////////////
			0, -1, 0,  //           / 0, -1,  0\ //
			-1, 5, -1, // cernel is |-1,  5, -1| //
			0, -1, 0); //           \ 0, -1,  0/ //
			           ////////////////////////////
		filter2D(
			src,
			dst,
			-1,
			kernel,
			Point(-1, -1),
			0,
			BORDER_DEFAULT
		);
		
		///////////////////////////
		// Save unsharped images //
		///////////////////////////
		string filename_output = "../data/image_processing/src2/cosmobio_rgb" + to_string(i) + "-unsharp.jpg";
		imwrite(filename_output, dst);
		
		waitKey(0);
	}
	return 0;
}
