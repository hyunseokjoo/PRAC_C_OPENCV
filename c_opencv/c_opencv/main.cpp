//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/videoio.hpp>		//파일을 읽고 쓰는 기능이 들어있음
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음

#include <iostream>					//입출력 관련 내용이 들어있음(stream input output)
#include <stdio.h>                  //standard input output 의 약자로 h는 헤더의 약자다 표준 입출력에 관련된 내용이 들어있음 (파일입출력, 콘솔화면 등등)

using namespace cv;
using namespace std;

int main(int ac, char** av) {
	Mat img = imread("image/person.jpg");

	imshow("img", img);
	waitKey(0);

	return 0;
}   