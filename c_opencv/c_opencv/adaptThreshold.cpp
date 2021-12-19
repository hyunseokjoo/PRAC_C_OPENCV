#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "adaptThreshold.h"


using namespace cv;
using namespace std;

void AdaptThreshold::start() {
	//원본이미지 불러오기
	Mat src = imread("image/person.jpg");
	//8비트 1채널 mat 객체 생성
	Mat gray = Mat(src.size(), CV_8UC1);
	Mat binary = Mat(src.size(), CV_8UC1);
	Mat binary_1 = Mat(src.size(), CV_8UC1);
	Mat binary_2 = Mat(src.size(), CV_8UC1);
	Mat binary2 = Mat(src.size(), CV_8UC1);
	Mat binary2_1 = Mat(src.size(), CV_8UC1);
	Mat binary2_2 = Mat(src.size(), CV_8UC1);

	//원본 이미지 -> 그레이스케일로 변경
	cvtColor(src, gray, COLOR_BGR2GRAY);
	//적응형 이진화 알고리즘(가우시안 방법)
	//blocksize 25x25 크기 내의 영역을 분석해 적절한 임곗값을 설정
	//상수 c에는 비교적 낮은 값인 5를 지정 이값을 음수로 지정 할 경우 전체 영역이 어두워진다. 반대로 5보다 크면 밝아진다.
	adaptiveThreshold(gray, binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 25, 5);
	adaptiveThreshold(gray, binary_1, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 33, 5);
	adaptiveThreshold(gray, binary_2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 5);
	adaptiveThreshold(gray, binary2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 25, -5);
	adaptiveThreshold(gray, binary2_1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 33, -5);
	adaptiveThreshold(gray, binary2_2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, -5);

	imshow("gray", gray);
	imshow("binary", binary);	
	imshow("binary_1", binary_1);
	imshow("binary_2", binary_2);
	imshow("binary2", binary2);
	imshow("binary2_1", binary2_1);
	imshow("binary2_2", binary2_2);

	waitKey(0);
	destroyAllWindows;

}


/*
적응형 이진화 알고리즘
- 입력 이미지에 따라 임곗값이 스스로 다른 값을 할당할 수 있도록 구성된 이진화 알고리즘이다.
이미지에 따라 어떠한 임곗값을 주더라도 이진화 처리가 어려운 이미지가 존재하는데
(ex 조명의 변화나 반사가 심한 경우 이미지 내의 밝기 분포가 달라 국소적으로 임곗값을 적용해야 원하는 결과를 얻을 수있다.)
이러한 경우 적응형 이진화 알고리즘을 적용한다.

AdaptiveThreshold->적응형 이진화 알고리즘

AdaptiveThreshold(원본이미지, 추출이미지, maxValue, adaptivemethod, threshold type, blocksize, 상수 c)

픽셀마다 적응형 임곗값 x, y를 설정해 계산식을 이용한다.
blocksize를 중심점이 존재할 수 있게 홀수만 사용가능하다.
계산은 blocksizeㅌ blocksize영역에 대한 가중 평균을 계산 - c(상수) 를 한다.

type
ADAPTIVE_THRESH_MEAN_C     blocksize      영역의모든 픽셀에 평균가중치를 적용
ADAPTIVE_THRESH_GAUSSIAN_C blocksize  영역의 모든 픽셀에 중심점으로부터의 거리에 대한 가우시안 가중치를 적용
*/

