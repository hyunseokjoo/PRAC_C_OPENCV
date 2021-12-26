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
	//blocksize 25x25 크기 내의 영역을 분석해 적절한 임곗값을 알아서 설정하여 계산하게 된다.
	//blocksize가 너무 크면 계산량이 많아 속도가 느려진다.
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


---------------------- 적응형 이진화 알고리즘을 사용하는 이유--------------------------
Otsu나 지역 이진화를 통한 방법은 모든 이미지에서, 특히 이미지가 서로 다른영역에서 
다른 밝기값을 가질 때 잘 수행되지 않는다.(한쪽은 빛을 받아 밝고 한쫏은 그림자지는 형태의 그림에서 잘 안됨)
이러한 경우 적응형 이진화를 진행할 수 있다.

적응형 이진화란 이미지의 각 픽셀에 대해 개별적으로 임계값을 설정하는 방법으로, 
대상 픽셀의 주변 픽셀들을 기반으로 결정된다. 따라서 이미지의 다른 영역에 대해 서로 
다른 임계값을 적용하므로 배경의 밝기가 다양한 이미지에서 잘 동작하게 된다.
---------------------------------------------------------------------------------------


AdaptiveThreshold->적응형 이진화 알고리즘

AdaptiveThreshold(원본이미지, 추출이미지, maxValue, adaptivemethod, threshold type, blocksize, 상수 c)

픽셀마다 적응형 임곗값 x, y를 설정해 계산식을 이용한다.
blocksize를 중심점이 존재할 수 있게 홀수만 사용가능하다.
계산은 blocksizeㅌ blocksize영역에 대한 가중 평균을 계산 - c(상수) 를 한다.

type
ADAPTIVE_THRESH_MEAN_C     blocksize      영역의모든 픽셀에 평균가중치를 적용
ADAPTIVE_THRESH_GAUSSIAN_C blocksize  영역의 모든 픽셀에 중심점으로부터의 거리에 대한 가우시안 가중치를 적용
*/

