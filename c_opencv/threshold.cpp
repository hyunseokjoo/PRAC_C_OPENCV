#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "threshold.h"


using namespace cv;
using namespace std;

void Threshold::start() {
	//�����̹��� �ҷ�����
	Mat src = imread("image/person.jpg");
	//8��Ʈ 1ä�� mat ��ü ����
	Mat gray = Mat(src.size(), CV_8UC1);
	Mat otsu = Mat(src.size(), CV_8UC1);
	Mat binary = Mat(src.size(), CV_8UC1);

	//���� �̹��� -> �׷��̽����Ϸ� ����
	cvtColor(src, gray, COLOR_BGR2GRAY);
	//�׷��̽����� �̹���-> ����ȭ �̹���(���� Ÿ��)�� ����
	threshold(gray, binary, 127, 255, THRESH_BINARY);
	threshold(gray, otsu, 127, 255, THRESH_OTSU);
	//threshold(gray, otsu, 127, 255, THRESH_BINARY_INV);
	//threshold(gray, otsu, 127, 255, THRESH_TRUNC);
	//threshold(gray, otsu, 127, 255, THRESH_TOZERO);
	//threshold(gray, otsu, 127, 255, THRESH_TOZERO_INV);
	//threshold(gray, otsu, 127, 255, THRESH_MASK);
	//threshold(gray, otsu, 127, 255, THRESH_TRIANGLE);

	imshow("gray", gray);
	imshow("binary", binary);
	imshow("otsu", otsu);

	waitKey(0);
	destroyAllWindows;

}

/*
threshold �� ����ȭ �Լ��̴�.

thresh�� �Ӱ찪�̶� �ϸ� 
�Ӱ찪�̶� ����ȭ(0�ƴϸ� 1)���� 0 �ƴϸ� 1�� �Ǿ���ϴ� ���ذ��� �ȴ�.
�Ӱ찪���� �Ʒ��� ���̶�� �ϸ� 0 �̵Ǹ� 
�Ӱ찪���� ���� ���̶�� �ϸ� 1�� �ȴ�.
�̷� ������ thresh(����ȭ)�� ����ǰ� �ȴ�.

threshold�Լ��� 
threshold(�����̹�������, �����̹�������, �Ӱ찪, �ִ밪, �Ӱ찪ǥ��Ÿ��)���� �̷���� �ִ�.
threshold(gray, binary, 127, 255, THRESH_OTSU);������  �Ӱ찪�� 127 ,�ִ밪�� 255,  Ÿ���� ����Ÿ�� ���� ���� �Ǿ��ִ�.


THRESH_type ���� (INV -> INVERSE�� ���ڴ�) (THRES�� �Ӱ찪�̶�� ��)
THRESH_BINARY       �Ӱ찪���� ���� �� -> MAX       , �ƴ� �� -> 0
THRESH_BINARY_INV	�Ӱ찪���� ���� �� -> 0         , �ƴ� �� -> MAX 
THRESH_TRUNC		�Ӱ찪���� ���� �� -> THRESH    , �ƴ� �� -> ���� ���� 
THRESH_TOZERO       �Ӱ찪���� ���� �� -> ���� ���� , �ƴ� �� -> 0
THRESH_TOZERO_INV   �Ӱ찪���� ���� �� -> 0		    , �ƴ� �� -> ���� ����
THRESH_MASK			�������̹����� ����
THRESH_OTSU			�����˰��� ����(����ä�ο��� ����)
THRESH_TRIANGLE		Ʈ���̾ޱ� �˰��� ����(����ä�ο��� ����)


���� �˰��� 
- �Էµ� �̹����ǹ�����(������׷�)�� ���������� �Ӱ찪��ã�� ����ȭ�� �����ϴ� �˰���
������ ��� �Ӱ찪�� ����ؼ� �̹��� ���� �ȼ����� �ΰ��� Ŭ������ �з����� �� 
Ŭ���� ���� �л��� �ּ�ȭ�ϰų� ���̸� �ִ�ȭ�ϴ� �Ӱ찪�� ã�´�

Ʈ���̾ޱ� �˰���
- ���� �˰���� �����ϰ� �Էµ� �̹����� ��� ����(������׷�)�� ���� ������ �Ӱ찪��
ã�� ����ȭ�� �����ϴ� �˰���, �������� ��� �Ӱ찪�� ���������� �ʰ� ������׷����� �ִ�Ÿ���
�����ϴ� �Ӱ찪�� ã�� ���� �˰����� �����Ѵ�.


*/