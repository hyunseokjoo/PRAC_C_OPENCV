#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "threshold.h"


using namespace cv;
using namespace std;

void Threshold::start() {
	//원본이미지 불러오기
	Mat src = imread("image/person.jpg");
	//8비트 1채널 mat 객체 생성
	Mat gray = Mat(src.size(), CV_8UC1);
	Mat otsu = Mat(src.size(), CV_8UC1);
	Mat binary = Mat(src.size(), CV_8UC1);

	//원본 이미지 -> 그레이스케일로 변경
	cvtColor(src, gray, COLOR_BGR2GRAY);
	//그레이스케일 이미지-> 이진화 이미지(오츠 타입)로 변경
	threshold(gray, binary, 127, 255, THRESH_BINARY);
	threshold(gray, otsu, 127, 255, THRESH_OTSU);
	//threshold(gray, otsu, 127, 255, THRESH_BINARY_INV);
	//threshold(gray, otsu, 127, 255, THRESH_TRUNC);
	//threshold(gray, otsu, 127, 255, THRESH_TOZERO);
	//threshold(gray, otsu, 127, 255, THRESH_TOZERO_INV);
	//threshold(gray, otsu, 127, 255, THRESH_MASK);
	//threshold(gray, otsu, 127, 255, THRESH_TRIANGLE);

	imshow("gray", gray);
	imshow("binary", binary);
	imshow("otsu", otsu);

	waitKey(0);
	destroyAllWindows;

}

/*
threshold 는 이진화 함수이다.

thresh는 임곗값이라 하며 
임곗값이란 이진화(0아니면 1)에서 0 아니면 1이 되어야하는 기준값이 된다.
임곗값보다 아래의 값이라고 하면 0 이되며 
임곗값보다 위의 값이라고 하면 1이 된다.
이런 원리로 thresh(이진화)가 진행되게 된다.

threshold함수는 
threshold(원본이미지변수, 변경이미지변수, 임곗값, 최대값, 임곗값표시타입)으로 이루어져 있다.
threshold(gray, binary, 127, 255, THRESH_OTSU);에서는  임곗값은 127 ,최대값은 255,  타입은 오츠타입 으로 설정 되어있다.


THRESH_type 종류 (INV -> INVERSE의 약자다) (THRES는 임곗값이라는 뜻)
THRESH_BINARY       임곗값보다 높을 때 -> MAX       , 아닐 때 -> 0
THRESH_BINARY_INV	임곗값보다 높을 때 -> 0         , 아닐 때 -> MAX 
THRESH_TRUNC		임곗값보다 높을 때 -> THRESH    , 아닐 때 -> 변경 없음 
THRESH_TOZERO       임곗값보다 높을 때 -> 변경 없음 , 아닐 때 -> 0
THRESH_TOZERO_INV   임곗값보다 높을 때 -> 0		    , 아닐 때 -> 변경 없음
THRESH_MASK			검은색이미지로 변경
THRESH_OTSU			오츠알고리즘 적용(단일채널에만 가능)
THRESH_TRIANGLE		트라이앵글 알고리즘 적용(단일채널에만 가능)


오츠 알고리즘 
- 입력된 이미지의밝기분포(히스토그램)을 통해최적의 임곗값을찾아 이진화를 적용하는 알고리즘
가능한 모든 임곗값을 고려해서 이미지 내의 픽셀들을 두개의 클래스로 분류했을 때 
클래스 간의 분산을 최소화하거나 차이를 최대화하는 임곗값을 찾는다

트라이앵글 알고리즘
- 오츠 알고리즘과 동일하게 입력된 이미지의 밝기 분포(히스토그램)을 통해 최적의 임곗값을
찾아 이진화를 적용하는 알고리즘, 차이점은 모든 임곗값을 대입하지는 않고 히스토그램에서 최대거리를
구성하는 임곗값을 찾아 오츠 알고리즘을 진행한다.


*/