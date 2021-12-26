//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일

#include "dilate.h"

using namespace cv;
using namespace std;


void Dilate::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	//팽창 객체 설정
	Mat dilate;
	Mat structure_dilate = getStructuringElement( MORPH_ELLIPSE , Size(7,7)); //고정점 -1,-1 고정점 -1-1의 의미는 중앙에 위치한다는 의미

	cv::dilate(img, dilate, structure_dilate, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("dilate", dilate);

	//침식 객체 설정
	Mat erode;
	Mat structure_erode = getStructuringElement(MORPH_ERODE, Size(7, 7));

	cv::erode(img, erode, structure_erode, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("erode", erode);

	waitKey(0);
	destroyAllWindows;
}


/*
모폴로지 연산에는 구조 요소를 사용한다.
모폴로지 연산은 블러같은 n x n 픽셀 연산이 아니라 
구조 요소로 직사각형, 십자가, 타원의 모양으로 계산을 하기 때문에 다른게 사용하게 된다.

구조 요소 - 커널의 형태를 설정해 연산에 형태를 정한다. (직사각형, 십자가, 타원이 shape으로 사용한다)
strucElement = GetStructuringElement(MorphShapes shpae, Size ksize, Point anchor);
			   GetStructuringElement(shpae, 커널 크기, 고정점);

구조 요소 객체 생성 후 Shape에 넣어 모폴로지 연산을 실행한다.
shape 종류
RECT    - 직사각형
CROSS   - 십자가
ELLIPSE - 타원


Dilate(팽창)
커널(구조 요소(element)) 안에 값을 극댓값으로 변환
어두운 부분이 작아지고, 밝은 부분이 밝아진다.
스펙클(반점)이 커지고, 객체 내부의 홀(구멍)이 사라진다.
노이즈 제거 후 줄어든 크기를 복구하고자 할때 주로 사용


Dilate(Mat src   , Mat dst   , Mat shape , Point? anchor = null, int iterations = 1, BorderTypes borderType = BorderTypes.Constant, Scalar? borderValue = null)
Dilate(원본이미지, 추출이미지, shape     , 고정점              , 반복횟수          , 테두리 외삽법                                , 테두리 색상               )


침식
커널 안에 값을 극소값으로 변환
어두운 부분은 커지고, 밝은 부분이 작아진다.
스펙클(반점)이 작아지고, 객체 내부의 홀(구멍)이 생긴다
노이즈 제거에 주로 사용

Erode(침식)

Erode(Mat src   , Mat dst   , Mat shape , Point? anchor = null, int iterations = 1, BorderTypes borderType = BorderTypes.Constant, Scalar? borderValue = null)
Erode(원본이미지, 추출이미지, shape     , 고정점              , 반복횟수          , 테두리 외삽법                                , 테두리 색상               )


*/
