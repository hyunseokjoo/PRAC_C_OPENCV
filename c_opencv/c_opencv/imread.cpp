//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/videoio.hpp>		//파일을 읽고 쓰는 기능이 들어있음
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음

#include "imread.h"

using namespace std;
using namespace cv;

void Imread::start() {
	Mat img = imread("image/person.jpg");

	imshow("img", img);
	waitKey(0);
}