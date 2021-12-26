//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일
#include <list>

#include "perspective.h"

using namespace cv;
using namespace std;


void Perspective::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	Mat dst;



	//show affine image
	imshow("dst", dst);
	waitKey(0);
	destroyAllWindows;
}


/*
warpPerspective  관전 변환




*/
