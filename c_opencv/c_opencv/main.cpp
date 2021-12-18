//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/videoio.hpp>		//������ �а� ���� ����� �������
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����

#include <iostream>					//����� ���� ������ �������(stream input output)
#include <stdio.h>                  //standard input output �� ���ڷ� h�� ����� ���ڴ� ǥ�� ����¿� ���õ� ������ ������� (���������, �ܼ�ȭ�� ���)

using namespace cv;
using namespace std;

int main(int ac, char** av) {
	Mat img = imread("image/person.jpg");

	imshow("img", img);
	waitKey(0);

	return 0;
}   