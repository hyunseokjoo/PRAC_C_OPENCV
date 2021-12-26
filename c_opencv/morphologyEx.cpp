//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������

#include "morphologyEx.h"

using namespace cv;
using namespace std;


void MorphologyEx::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat thres;
	threshold(gray, thres, 127, 255, THRESH_BINARY);

	//��â ����
	Mat dilate;
	cv::Mat Kernel(5, 5, CV_8U, cv::Scalar(1));
	cv::morphologyEx(thres, dilate, MORPH_DILATE, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0));
	imshow("dilate", dilate);

	//ħ�� ����
	Mat erode;
	cv::morphologyEx(thres, erode, MORPH_ERODE, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("erode", erode);

	//open(ħ�� �� ��â) ���� ��� ���� �������� ȿ��
	Mat open;
	cv::morphologyEx(thres, open, MORPH_OPEN, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("open", open);

	//close(��â �� ħ��) ���� ���� ���� �������� ȿ��
	Mat close;
	cv::morphologyEx(thres, close, MORPH_CLOSE, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("close", close);

	//gradient (dilate - erode) �������� ���� �� ������ �ܰ����� ����� ȿ�� 
	Mat gradient;
	cv::morphologyEx(thres, gradient, MORPH_GRADIENT, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("gradient", gradient);

	//tophat (origin - open) ��� �����鸸 ���� ȿ��(���� ��� ������ ���ִ� ���� �����̴ϱ�)
	Mat tophat;
	cv::morphologyEx(thres, tophat, MORPH_TOPHAT, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("tophat", tophat);

	//blackhat (close - origin) ���� �����鸸 ���� ȿ��(���� ���� ������ ���ذ��� �����̴ϱ�)
	Mat blackhat;
	cv::morphologyEx(thres, blackhat, MORPH_BLACKHAT, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("blackhat", blackhat);

	//hitmiss �𼭸� ���� 
	Mat hitmiss;
	cv::morphologyEx(thres, hitmiss, MORPH_HITMISS, Kernel, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("hitmiss", hitmiss);


	waitKey(0);
	destroyAllWindows;
}


/*
����ȭ�� ���� ���� �ϴ� ����
�Է� �̹����� ����ȭ�� �̹������ ��â�� ħ�� �������ε� ����� ��� ����
�������� ���� �� ������ ���ſ��� �׳� ����ȭ �۾��� �Ѵٰ� ���� ��.

���� ä���̹����� �� ������ ������ �ʿ� -> �������� ����

MorphologyEx(
 Mat src,											- �����̹���
 Mat dst,											- ����̹���
 MorphTypes op,										- ��������
 Mat kernel,										- ������ҳ� kernel 
 Point? anchor = null,								- ������
 int iterations = 1,								- �ݺ�Ƚ��
 BorderTypes borderType = BorderTypes.Constant,		- �׵θ� �ܻ��
 Scalar? bordeValue = null							- �׵θ� ����
)


MorphType type
Dilate = ��â
Erode = ħ��
Open = ���� (dilate(erose(src)))
Close = ���� (erose(dilate(src)))
Gradient = �׶���Ʈ ( dilate(src) - erode(src) )
TopHat  = ž��  ( src - open(src) )
BlackHat = ���� ( close(src) - src )
HitMiss = ��Ʈ�̽�


���� ����
ħ������ ���� ���� ���� �ٿ� ��ο� ���� ��
�ٽ� ��â���� ���� ���������� �� �Ͽ� ���� �����ϰ� ��ȯ�ǵ��� �Ѵ�.

���� ����
��â���� ���� ���� ���� �� ��ο� ���� �ٿ�
�ٽ� ħ������ ���� ��ο� ���� ����Ų��.

�׶���Ʈ
��â�� �κп��� ħ�ĵ� �κ��� ����.
���� �ް��ϰ� ���� ������ ���� �������� ������ �� �� �ִ�.

ž�� ����
����Ŭ�� ������� ��ü�� ũ�Ⱑ ������ ����� ���� �� �մ�.
�������� open���� �Ȱ��� ���� ���̴ϱ�
open���꿡�� ����� ������ �� ������ ��ü�� ���� �� �ִ�.
(�Է� �̹����� ��ü���� ���ܵǰ� ���������� ��Ҵ� �κе��� �и���)

���� ����
close����ȰͿ� ������ �� ���
�ؼ����� ��ο� �κ��� ����

��Ʈ�̽� ����
���� ä�ο��� ���
����ȭ �̹������� �ַ� ���
��Ʈ�̽� ������� Ŀ���� ���ο���� ���� 0 or 1�� ���� ���´�.
�����̽� ������ �𼭸�(corner)�� �����ϴµ� Ȱ���ϱ⵵ �Ѵ�.

���� ���ظ� ���� ����Ʈ 
https://m.blog.naver.com/9409290274/221549688872

*/
