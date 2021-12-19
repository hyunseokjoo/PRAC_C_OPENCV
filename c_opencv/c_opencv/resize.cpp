//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/videoio.hpp>		//파일을 읽고 쓰는 기능이 들어있음
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음

#include "Resize.h"

using namespace std;
using namespace cv;

void Resize::start() {
	cv::Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);

	imshow("img", img);
	waitKey(0);
}


/*
이미지 확대하는 경우 - 픽셀에 대한 보간법을 사용 (확대를 하면 화질이 선명해 지지 않기때문에 보간법을 이용해 화질을 개선 해야한다.)
이미지 축소하는 경우 - 픽셀에 대한 병합법을 사용 

이미지를 변경하는 방법
1. 사용자가 지정한 절대크기로 변경
2. 비율에 맞게 변경


*/