#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "cvtColor.h"

using namespace cv;
using namespace std;

void CvtColor::start()
{
	Mat src = imread("image/person.jpg");

	//bgr 컬러 이미지를 grayscale로 변경
	Mat dst;
	cv::cvtColor(src, dst, COLOR_BGR2GRAY);

	imshow("dst", dst);

	//bgr컬러 이미지를 hsv로 변경
	Mat dst_hsv;
	cv::cvtColor(src, dst_hsv, COLOR_BGR2HSV);

	imshow("dst_hsv", dst_hsv);

	//bgr컬러 이미지를 luv 로 변경
	Mat dst_luv;
	cv::cvtColor(src, dst_luv, COLOR_BGR2Luv);

	imshow("dst_luv", dst_luv);

	waitKey(0);
	destroyAllWindows;
}

/*
전처리 작업이 필요한 이유 
- 컬러 이미지가 주로 이루어 지는데 컬러이미지는 rgb로 이루어 져있어 
binary 이미지 보다 3배 의 데이터처리가 더 필요 하다 그래서 그레이스케일이나 
다른 형태로 변형을 하여 이미지를 사용하게 되는데 마지막 작업을 하기 전 
이미지 변형을 하는것이 전처리 작업이다. 즉, 원하는 결과값을 얻기위한
처리하는 속도를 개선하기 위해 전처리를 한다.

CvtColor 함수는 색상 변환 함수이다. 
cvtcolor(원본이미지, 변경해서 나올 mat변수, 변경할색상종류)로 구성 되어있다.

변경할 type 
//BGR과 RGB색상 공간 상호 변황
BGR2RGB
RGB2BGR
BGRA2RGBA
RGBA2BGRA

//BGR이나 RGB색상 공간에 알파 채널 추가
BGR2BGRA
BGR2RGBA
RGB2GBRA
RGB2RGBA

//BGRA이나 RGBA색상공간에 알파채널 제거
BGRA2BGR
BGRA2RGB
RGBA2BGR
RGBA2RGB

//BGR나 RGB 색상 공간을 그레이스케일로변환
BGR2GRAY
BGRA2GRAY
RGBA2GRAY

//그레이스케일 색상공간을 BGR이나 RGB로 변환
GRAY2BGR
GRAY2BGRA
GRAY2RGB
GRAY2RGBA

//HSV로 변환, RGB나 BGR로 변환
BGR2HSV
RGB2HSV
HSV2BGR
HSV2RGB

//CIE LAB 으로 상호 변환
BGR2LAB
RGB2LAB
LAB2BGR
LAB2RGB

//LUV로 상호 변환
RGB2LUV
BGR2LUV
LUV2BGR
LUV2RGB

//BGR이나 RGB 을 YCC(크로마)FH TKDGH QUSGHKS(YCC= Y, CR, CB)
BGR2YCRCB
RGB2YCRCB
YCRCB2BGR
YCRCB2RGB


BGR565
RGB565등 나머지는 필요할 경우 찾아보면서 하면 된다.





*/