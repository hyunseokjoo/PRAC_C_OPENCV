//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일

#include "morphologyEx.h"

using namespace cv;
using namespace std;


void MorphologyEx::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat thres;
	threshold(gray, thres, 127, 255, THRESH_BINARY);

	//팽창 연산
	Mat dilate;
	cv::Mat Kernel(5, 5, CV_8U, cv::Scalar(1));
	cv::morphologyEx(thres, dilate, MORPH_DILATE, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0));
	imshow("dilate", dilate);

	//침식 연산
	Mat erode;
	cv::morphologyEx(thres, erode, MORPH_ERODE, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("erode", erode);

	//open(침식 후 팽창) 작은 흰색 점들 없어지는 효과
	Mat open;
	cv::morphologyEx(thres, open, MORPH_OPEN, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("open", open);

	//close(팽창 후 침식) 작은 검정 점들 없어지는 효과
	Mat close;
	cv::morphologyEx(thres, close, MORPH_CLOSE, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("close", close);

	//gradient (dilate - erode) 이진영상에 적용 시 영역의 외곽선만 남기는 효과 
	Mat gradient;
	cv::morphologyEx(thres, gradient, MORPH_GRADIENT, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("gradient", gradient);

	//tophat (origin - open) 흰색 반점들만 남는 효과(작은 흰색 반점을 없애는 것을 뺀것이니깐)
	Mat tophat;
	cv::morphologyEx(thres, tophat, MORPH_TOPHAT, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("tophat", tophat);

	//blackhat (close - origin) 검은 반점들만 남는 효과(작은 검정 반점을 없앤것을 뺀것이니깐)
	Mat blackhat;
	cv::morphologyEx(thres, blackhat, MORPH_BLACKHAT, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("blackhat", blackhat);

	//hitmiss 모서리 검출 
	Mat hitmiss;
	cv::morphologyEx(thres, hitmiss, MORPH_HITMISS, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 은 검은색
	imshow("hitmiss", hitmiss);


	waitKey(0);
	destroyAllWindows;
}


/*
이진화로 만들어서 연산 하는 이유
입력 이미지가 이진화된 이미지라면 팽창과 침식 연산으로도 우수한 결과 없음
모폴로지 연산 및 노이즈 제거에는 그냥 이진화 작업을 한다고 보면 됨.

다중 채널이미지는 더 복잡한 연산이 필요 -> 모폴로지 연산

MorphologyEx(
 Mat src,											- 원본이미지
 Mat dst,											- 출력이미지
 MorphTypes op,										- 연산종류
 Mat kernel,										- 구조요소나 kernel 
 Point? anchor = null,								- 고정점
 int iterations = 1,								- 반복횟수
 BorderTypes borderType = BorderTypes.Constant,		- 테두리 외삽법
 Scalar? bordeValue = null							- 테두리 색상
)


MorphType type
Dilate = 팽창
Erode = 침식
Open = 열림 (dilate(erose(src)))
Close = 닫힘 (erose(dilate(src)))
Gradient = 그라디언트 ( dilate(src) - erode(src) )
TopHat  = 탑햇  ( src - open(src) )
BlackHat = 블랙햇 ( close(src) - src )
HitMiss = 힛트미스


열림 연산
침식으로 인해 밝은 영역 다운 어두운 영역 업
다시 팽창으로 인해 밝은영역을 업 하여 조금 선명하게 반환되도록 한다.

닫힘 연산
팽창으로 인해 밝은 영역 업 어두운 영역 다운
다시 침식으로 인해 어두운 영역 업시킨다.

그라디언트
팽창한 부분에서 침식된 부분을 뺀다.
가장 급격하게 변한 곳에서 가장 차이점을 도출해 낼 수 있다.

탑햇 연산
스펙클이 사라지고 객체의 크기가 보존된 결과를 받을 수 잇다.
원본에서 open연산 된것을 빼는 것이니깐
open연산에서 사라진 반점을 뺀 원본의 객체를 얻을 수 있다.
(입력 이미지의 객체들이 제외되고 국소적으로 밝았던 부분들이 분리됨)

블랙햇 연산
close연산된것에 원본을 뺀 결과
극소적인 어두운 부분을 도출

히트미스 연산
단일 채널에만 사용
이진화 이미지에서 주로 사용
히트미스 컨벌루션 커널은 내부요소의 값이 0 or 1의 값만 갖는다.
히스미스 연산을 모서리(corner)를 검출하는데 활용하기도 한다.

연산 이해를 위한 사이트 
https://m.blog.naver.com/9409290274/221549688872

*/
