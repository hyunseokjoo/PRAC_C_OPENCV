//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일

#include "Blur.h"

using namespace cv;
using namespace std;


void Blur::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);

	//단순 블러 효과
	Mat dst;
	cv::blur(img, dst, Size(5, 5), Point(3, 3), BORDER_REFLECT101);
	imshow("dst", dst);

	//중간값 블러 효과 
	Mat median;
	medianBlur(img, median, 5);
	imshow("median", median);

	//가우시안 블러 효과
	Mat gaussian;
	GaussianBlur(img, gaussian, Size(5, 5), 3, 3);
	imshow("gaussian", gaussian);

	//양방향 블러 효과 지름 100(픽셀범위 직경) , 시그마 생상 33 ,  시그마 공간 11 -이미지 내의 서로 영향을 받을 픽셀 범위 
	//-값이 클 수록 멀리 있는 픽셀의 영향도 커져 이미지 블러링의 효과를 높이게 된다.
	Mat bilateral;
	bilateralFilter(img, bilateral, 100, 33, 11);
	imshow("bilateral", bilateral);

	waitKey(0);
	destroyAllWindows;

}


/*
흐림 효과 (Blur) - 블러링 또는 스무딩이라고 불린다.
흐림 효과는 단순히 흐리게 만드는것이 아니라 노이즈를 제거해서 연산 시 계산을 빠르게 만든다.
(이미지 변환시에 1차 미분과 2차미분을 하는데 사용하는 것과 비슷하다고 보면된다)

블러링 이미지에서 사용하는 주요 용어
커널     - 이미지에서 (x,y)의 픽셀과 해당 픽셀 주변을 포함한 작은 크기의 공간을 의미한다.
컨벌루션 - 새로운 픽셀을 만들어 내기 위해 커널 크기의 화소 값을 이용해 어떤 시스템을 통과 해 계산하는 것
고정점   - 커널을 통해 컨벌루션된 값을 할당하는 지점

테두리 외삽법
컨벌루션을 적용할 때 이미지의 가장자리 부분은 계산이 불가능 하다. 여기서 필요한 것이 테두리 외삽법이다.
(ex 커널이 50x50 이면 고정점이 (0.0)에 도달했다고 치면 커널의 가장자리 포인트는 (-50,-50)이 되기 때문에 계산이 불가능하다.)

BORDER_CONSTANT    - 고정값으로 픽셀을 확장
BORDER_RELPICATE   - 테두리 픽셀을 복사해서 확장
BORDER_REFLECT     - 픽셀을 반사해서 확장
BORDER_WRAP        - 반대쪽 픽셀을 복사해서 확장
BORDER_REFLECT101  - 이중 픽셀을 만들지 않고 반사해서 확장
BORDER_DEFAULT     - Reflect101 방식을 사용
BORDER_TRANSPARENT - 픽셀을 투명하게 해서 확장
BORDER_ISOLATED    - 관심 영역밖은 고려하지 않음


단순 흐림
blur(Mat src, Mat dst, Size ksize, Point? anchor=null, BorderTypes borderType = BorderTypes.Reflect101)
blur(입력이미지, 적용이미지, 커널의크기, 고정점, 테두리 외삽법)
진짜 단순하게 흐려지기만 하는 효과


박스 필터 흐림
boxFilter(Mat src, Mat dst, MatType ddepth, size ksize, Point? anchor = null, bool normalize = true, BorderTypes borderType = BorderType.Reflect101)
boxFilter(입력이미지, 적용이미지, 출력이미지정밀도, 고정점, 정규화 여부, 테두리 외삽법)
박스 안에 필터를 설정하여 흐려지게 만드는 효과

중간값 흐림 효과
medianBlur(Mat src, Mat dst, Size ksize)
medianBlur(입력이미지, 적용이미지, 커널)
사각형 크기의 이웃한 픽셀들의 중간값을 사용하여 흐려지게 하는 효과
무작위 노이즈 제거에 효과적 엣지이미지는 엣지가 사라질수 있어 주의 해야한다.

가우시안 흐림 효과
gaussianBlur(Mat src, Mat dst, Size ksize, double sigmX, double sigmaY, BorderTypes borderType = BorderTypes.Reflect101)
gaussianBlue(입력이미지,적용이미지, 커널, x축가우스표준편차설정, y축가우스표준편차설정, 테두리 외삽법)
가우시암 흐림 효과는 다양한 커널에 대해 높은 성능을 내도록 최적화 돼 있으며
3x3, 5x5, 7x7 크기의 커널에 대한 우수한 성능을 보여준다.

양방향 필터 흐림 효과 
bilateralFilter(Mat src, Mat dst, int d, double sigmaColor, double sigmaSpace, BorderTypes borderType = BorderTypes.Reflect101)
bilateralFilter(입력이미지, 적용이미지, 지름, 시그마 색상, 시그마 공간,테두리 외삽법)
가장자리를 선명하게 보존하면서 노이즈를 우수하게 제거 하는 흐림효과 함수다.
엣지만 잘보이고 나머지는 블러처리하는 곳에서 사용 한다 
계산량이 많아 속도가 많이 걸린다.



*/
