//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일

#include "contour.h"

using namespace cv;
using namespace std;


void Contour::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	Mat gray, thres;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	
	Mat sb;
	Sobel(gray, sb, CV_8UC1, 1, 0, 3, 1, 0, BORDER_REFLECT101); //미분 차수x는 1 y는 0 
	imshow("gray", sb);

	Mat cn; // 캐닛 엣지를 주로 많이 사용한다 2차미분을 사용하여 노이즈 제거가 쉽고 이진화 threshold를 지정하여 지정한 테두리의 최소값과 연관 최대값을 지정 할 수 있기 때문이다.
	Canny(img, cn, 50, 100, 3, true); //threshold1 50으로 설정 50 미만은 모두 제거, threshold2 200으로 설정 200이상의 값과 연결된 모든 픽셀을 검출

	imshow("Canny", cn);

	waitKey(0);
	destroyAllWindows;
}


/*
가장자리, 윤곽선, 직선 원 등을 검출

가장자리 검출
가장자리는 가장 바깥 부분의 둘레를 의미, 객체의 테두리로 볼 수 있다.
가장자리 검출은 전경과 배경이 존재하는 것을 파악한다
전경과 배경으로 나눠질 때 급격하게 변화하는 값을 찾아 가장자리를 찾는다
이것을 확인하는 방법은 픽셀의 밝기를 이용한 변화율을 감지한다.
변화율을 감지하기 위해 미분을 사용하여 극적인 변화를 찾아낸다.

미분 형태의 가장자리 유형은
step, line, ramp, roof가 있다.

step은 값이 바로 0-1같이 변화하는 구간
line은 값이 급격하게 변했다가 다시 제자리로 돌아오는 구간
ramp는 step에서 노이즈 제거한 것
roof는 line에서 노이즈 제거한 것


가장자리 검출 방식
소벨 미분, 샤르 필터, 라플라시안, 캐니 엣지

sobel(
 Mat src,			- 원본 이미지
 Mat dst,			- 출력 이미지
 MatType ddepth,	- 출력 이미지 정밀도 
 int xorder,		- x 미분 차수
 int yorder,		- y 미분 차수
 int ksize = 3,		- 커널의 크기
 double scale = 1,	- 비율 
 double delta = 0,	- 오프셋
 BorderTypes borderType = borderTypes.Reflect101
)

소벨은 미분을 하는 가장 간단한 미분법
커널을 사용하고 크기가 3~31 까지 가능하다
커널 내부 원소의 값의 합이 0이 되어야한다


샤르 필터
소벨 미분의 단점을 보완
3x3의 필터를 사용한다면 샤르 필터를 활용하는게 좋다

Scharr(
 Mat src,
 Mat dst,
 MatType ddepth,
 int xorder,
 int yorderm
 double scale = 1,
 double delta = 0,
 BorderTypes borderType = BorderTypes.Reflect101
)

샤르는 3x3커널사이즈만 지원해서 커널의 크기는 사용하지 않는다



라플라시안
소벨 연산의 기반을 둠
2차미분의 형태
x축과 y축을 따라 2차 미분한 합을 의미한다.
커널으 크기가 1일 때 특수하게 적용되는 라플라시안 필터의 형태를 보여준다





캐니 엣지
가장 많이 사용하는 가장자리 검출 방식, 소벨연산의 기반을 둠
노이즈 제거를 위해 가우시안 필터를 사용해 흐림 효과를 적용
기울기 값이 높은 지점을 검출
최댓값이 아닌 픽셀의 값을 0으로 변경
히스테리시스 임곗값 적용

상위 임곗값과 하위 임곗값에 연결된 경우만 가장자리 픽셀로 간주
상위 임곗값 200, 하위 임곗값 100이면
100이하는 모두 제외 200이상인 픽셀이 하나라도 있으면
100이상의 픽셀은 모두 가장자리로 간주한다.

canny(
 Mat src,
 Mat dst,
 double threshold1,
 double threshold2,
 int aperturesize = 3, - 소벨연산 마스크 사이즈
 bool L2gradient = false - L2norm 방향으로 속도많이 걸려도 정확하게 계산할지 , 속도 빠르고 대충 계산할지 정함
)





*/
