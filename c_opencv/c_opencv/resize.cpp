//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/videoio.hpp>		//������ �а� ���� ����� �������
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����

#include "Resize.h"

using namespace std;
using namespace cv;

void Resize::start() {
	cv::Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);

	imshow("img", img);
	waitKey(0);
}


/*
�̹��� Ȯ���ϴ� ��� - �ȼ��� ���� �������� ��� (Ȯ�븦 �ϸ� ȭ���� ������ ���� �ʱ⶧���� �������� �̿��� ȭ���� ���� �ؾ��Ѵ�.)
�̹��� ����ϴ� ��� - �ȼ��� ���� ���չ��� ��� 

�̹����� �����ϴ� ���
1. ����ڰ� ������ ����ũ��� ����
2. ������ �°� ����


*/