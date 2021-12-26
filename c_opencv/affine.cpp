//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음
#include <opencv2/imgproc.hpp>      //resize()를 사용하기 위한 헤더파일
#include <list>

#include "affine.h"

using namespace cv;
using namespace std;


void Affine::start() {
	//초반 이미지 불러오기 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	Mat dst;

	//원본 포인트 구조체 만들기
	Point2f img_pts[3] =
	{
		Point2f(0,0),
		Point2f(0, img.cols), 
		Point2f(img.rows, img.cols)
	};

	//변경할 포인트 구조체 만들기
	Point2f dst_pts[3] =
	{
		Point2f(300, 300),
		Point2f(300, img.cols),
		Point2f(img.rows-400, img.cols -200)
	};

	Mat m = getAffineTransform(img_pts, dst_pts);

	warpAffine( img, dst, m, Size(img.cols, img.rows) );

	//show affine image
	imshow("dst", dst);
	waitKey(0);
	destroyAllWindows;
}


/*
이미지 변환

1. 강체 변환 - 유클리디언 변환이라고도 하고, 변환의 기준점으로 크기와 각도가 보존되는 변환 - 평행 이동 회전 등
2. 유사 변환 - 크기 변환까지 허용된 변환 등방성, 평행이동, 크기변환
3. 선형 변환 - 벡터 공간에서의 이동을 의미 크기변환(이방성을 가질 수 있음), 반사, 기울임
4. 아핀 변환 - 유사변환+ 선형 변환 사각형을 평행사변형으로 변환하는 것
5. 원근 변환 - 아핀 변환과 유사하지만, 수평성은 유지 되 않는다.
6. 모폴로지 변환 - 컨벌루션 연산으로 노이즈를 제거하거나 검출 요소를 결합 및 분리할 수 있는 형태학 연산

확대, 축소
pyramid 확대, 축소 잘 사용하지는 않을 듯 보간법을 사용할 수 없음
resize 보간법(확대)과 병합법(축소)을 사용하여 이미지가 깨지는 현상을 잡아 줄수 있다. - SubMat() aoi 설정할때 사용하는 함수

대칭
Mat flip(mat src, mat dst, flipmode)
flipmode
xy - 상하좌우 대칭
x  - 상하 대칭
y  - 좌우 대칭

회전
Mat GetrotationMatrix2D(point2f center, double angle, double scale)


기하학적 변환
아핀변환 포인트 A,B,C기준으로 변형할 포인트 A`,B`,C`로 사진(영상)을 변형한다.
아핀 객체 생성
Mat m = GetAffineTransform(IEnumerable<Point2f> Pnt_src, IEnumable<Point2f> Pnt_dst)

아핀변환 함수
WarpAffine(
Mat src,
Mat dst,
Mat M,   --
Size dsize,
interpolationFlags(보간법),
BorderTypes borderMode (테두리외삽법),
BorderValue (변형하고 남은 곳에 들어갈 색상))


opencv c++ affine 및 회전에 대한 내용은 
https://boysboy3.tistory.com/63 참조
*/
