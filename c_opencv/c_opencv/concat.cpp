#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "concat.h"

using namespace cv;
using namespace std;

void Concat::start() 
{
	Mat img_color = imread("image/person.jpg", IMREAD_COLOR);
	Mat img_gray = imread("image/person.jpg", IMREAD_GRAYSCALE);

	/*Mat img_left, img_right, img_bottom, img_top;
	resize(img, img_left, cv::Size(), 0.25, 0.25, INTER_LINEAR);
	resize(img, img_right, cv::Size(), 0.35, 0.35, INTER_LINEAR);
	resize(img, img_bottom, cv::Size(), 0.45, 0.45, INTER_LINEAR);
	resize(img, img_top, cv::Size(), 0.55, 0.55, INTER_LINEAR);*/

	Mat dst;

	/*cv::vconcat(img_left, img_right, left);
	cv::vconcat(img_bottom, img_top, right);
	cv::hconcat(left, right, dst);*/
	Mat matArray[] = { img_color, img_gray };
	cv::hconcat(matArray , 2, dst);

	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}

