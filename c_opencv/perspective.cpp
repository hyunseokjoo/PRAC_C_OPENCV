//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������
#include <list>

#include "perspective.h"

using namespace cv;
using namespace std;


void Perspective::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	Mat dst;



	//show affine image
	imshow("dst", dst);
	waitKey(0);
	destroyAllWindows;
}


/*
warpPerspective  ���� ��ȯ




*/
