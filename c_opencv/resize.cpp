//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������

#include "Resize.h"

using namespace cv;
using namespace std;


void Resize::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	//resize�� �̹��� ��ü ����� �����ֱ�
	Mat img_basic;
	//cv::resize(img, img_basic, cv::Size(1000, 1000)); //�⺻�� ���� ������ ���
	cv::resize(img, img_basic, cv::Size(1000, 1000), cv::INTER_LINEAR); //�⺻�� ���� ������ ��� ���� ���� ���� ���
	imshow("img_basic", img_basic);

	//���� ������
	Mat img_NEAR;
	cv::resize(img, img_NEAR, cv::Size(1000, 1000), cv::INTER_NEAREST);
	imshow("img_NEAR", img_NEAR);
	
	//ť���ö��� ����
	Mat img_CUBIC;
	cv::resize(img, img_CUBIC, cv::Size(1000, 1000), cv::INTER_CUBIC);
	imshow("img_CUBIC", img_CUBIC);


	//ť���ö��� ����
	Mat img_RATIO;
	cv::resize(img, img_RATIO, cv::Size(), 0.25, 0.25, cv::INTER_CUBIC); //1/4������ ��� 
	imshow("img_RATIO", img_RATIO);


	waitKey(0);

}


/*
�̹��� ��Ҹ� �ϱ� ���ؼ� c++ ��� ������ �Է��� ���־���Ѵ�.
�ʼ� - #include <opencv2/imgproc.hpp>

�̹��� Ȯ���ϴ� ��� - �ȼ��� ���� �������� ��� (�������̶� ������ ��ǵ�� �Ͽ��� �����ϴ°�- ���߿����� ���� �������� ���)
�̹��� ����ϴ� ��� - �ȼ��� ���� ���չ��� ��� 

�̹����� �����ϴ� ���
1. ����ڰ� ������ ����ũ��� ����
2. ������ �°� ���� ���ũ��� ����

����ũ�� - Ʃ�� ���� (�ʺ�, ����)�� �� �Ҵ�
���ũ�� - ������ �°� ���� ���� �Ҵ�

OpenCV ������ �⺻������ ��������(=INTER_LINEAR)�� ����Ѵ� 
INTER_LINEAR = �缱�� ������
INTER_NEAREST = ���� ������
INTER_CUBIC = 3��ȸ�� ������ (4x4 �̿� �ȼ� ����)
INTER_AREA = ���� ��ҽ� ȿ����


*/
