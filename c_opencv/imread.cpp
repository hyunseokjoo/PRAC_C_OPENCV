//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/videoio.hpp>		//파일을 읽고 쓰는 기능이 들어있음
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음

#include "imread.h"

using namespace std;
using namespace cv;

void Imread::start() {
	Mat img = imread("image/person.jpg", IMREAD_GRAYSCALE);

	imshow("img", img);
	waitKey(0);
}


/*
Mat img = imread("경로", ImreadModes.~~)

imread 함수는 이미지 파일을 어떻게 불러 올지 정하는 함수 입니다.

imread함수의 파라미터는 경로 , 모드로 구성이 되어있는데 경로만 작성할 경우 
CV_8UC3으로 바로 적용 되게 됩니다.

mode의 종류는 
Imread_Unchanged                - 알파 채널을 포함해서 이미지 변환						= -1
Imread_GrayScale				- 단일 채널 그레이스케일로 변환							= 0
Imread_Color					- 다중 채널 색상 이미지 변환							= 1
Imread_AnyDepth					- 정밀도가 존재할 경우 16/312비트 이미지로 반환			= 2
Imread_ReducedGrayscale2		- 크기를 1/2로 줄인 후 그레이스케일 반환				= 16
Imread_ReducedGrayscale4		- 크기를 1/4로 줄인 후 그레이스케일 반환				= 32
Imread_ReducedColor2			- 크기를 1/2로 줄인 후 다중 채널 색상 이미지로 반환     = 17
Imread_ReducedColor4			- 크기를 1/4로 줄인 후 다중 채널 색상 이미지로 반환		= 33
Imread_IgnoreOrientation		- exif의 방향 플래그에 따라 이미지를 회전하지 않음		= 128

*/