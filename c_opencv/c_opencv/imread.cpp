//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/videoio.hpp>		//������ �а� ���� ����� �������
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����

#include "imread.h"

using namespace std;
using namespace cv;

void Imread::start() {
	Mat img = imread("image/person.jpg");

	imshow("img", img);
	waitKey(0);
}