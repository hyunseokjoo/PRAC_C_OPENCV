//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일

#include "Resize.h"

using namespace cv;
using namespace std;


void Resize::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	//resize할 이미지 객체 만들어 보여주기
	Mat img_basic;
	//cv::resize(img, img_basic, cv::Size(1000, 1000)); //기본값 선형 보간법 사용
	cv::resize(img, img_basic, cv::Size(1000, 1000), cv::INTER_LINEAR); //기본값 선형 보간법 사용 가장 많이 쓰는 방법
	imshow("img_basic", img_basic);

	//인접 보간법
	Mat img_NEAR;
	cv::resize(img, img_NEAR, cv::Size(1000, 1000), cv::INTER_NEAREST);
	imshow("img_NEAR", img_NEAR);
	
	//큐빅스플라인 보간
	Mat img_CUBIC;
	cv::resize(img, img_CUBIC, cv::Size(1000, 1000), cv::INTER_CUBIC);
	imshow("img_CUBIC", img_CUBIC);


	//큐빅스플라인 보간
	Mat img_RATIO;
	cv::resize(img, img_RATIO, cv::Size(), 0.25, 0.25, cv::INTER_CUBIC); //1/4비율로 축수 
	imshow("img_RATIO", img_RATIO);


	waitKey(0);

}


/*
이미지 축소를 하기 위해선 c++ 헤더 파일을 입력을 해주어야한다.
필수 - #include <opencv2/imgproc.hpp>

이미지 확대하는 경우 - 픽셀에 대한 보간법을 사용 (보간법이란 기존의 사실들로 하여금 추정하는것- 이중에서도 선형 보간법을 사용)
이미지 축소하는 경우 - 픽셀에 대한 병합법을 사용 

이미지를 변경하는 방법
1. 사용자가 지정한 절대크기로 변경
2. 비율에 맞게 변경 상대크기로 변경

절대크기 - 튜플 형식 (너비, 높이)로 값 할당
상대크기 - 비율에 맞게 값을 나눠 할당

OpenCV 에서는 기본값으로 선형보간(=INTER_LINEAR)을 사용한다 
INTER_LINEAR = 양선형 보간법
INTER_NEAREST = 인접 보간법
INTER_CUBIC = 3차회선 보간법 (4x4 이웃 픽셀 참조)
INTER_AREA = 영상 축소시 효과적


*/
