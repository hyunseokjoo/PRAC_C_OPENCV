//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������

#include "erode.h"

using namespace cv;
using namespace std;


void Erode::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	//ħ�� ��ü ����
	Mat erode;
	Mat structure_erode = getStructuringElement(MORPH_ERODE, Size(7, 7));

	cv::erode(img, erode, structure_erode, Point(-1, -1), 3, BORDER_REFLECT101, Scalar(0)); // scalar0 �� ������
	imshow("erode", erode);

	waitKey(0);
	destroyAllWindows;
}

/*
�������� ���꿡�� ���� ��Ҹ� ����Ѵ�.
�������� ������ ������ n x n �ȼ� ������ �ƴ϶�
���� ��ҷ� ���簢��, ���ڰ�, Ÿ���� ������� ����� �ϱ� ������ �ٸ��� ����ϰ� �ȴ�.

���� ��� - Ŀ���� ���¸� ������ ���꿡 ���¸� ���Ѵ�. (���簢��, ���ڰ�, Ÿ���� shape���� ����Ѵ�)
strucElement = GetStructuringElement(MorphShapes shpae, Size ksize, Point anchor);
			   GetStructuringElement(shpae, Ŀ�� ũ��, ������);

���� ��� ��ü ���� �� Shape�� �־� �������� ������ �����Ѵ�.
shape ����
RECT    - ���簢��
CROSS   - ���ڰ�
ELLIPSE - Ÿ��

ħ��
Ŀ�� �ȿ� ���� �ؼҰ����� ��ȯ
��ο� �κ��� Ŀ����, ���� �κ��� �۾�����.
����Ŭ(����)�� �۾�����, ��ü ������ Ȧ(����)�� �����
������ ���ſ� �ַ� ���

Erode(ħ��)

Erode(Mat src   , Mat dst   , Mat shape , Point? anchor = null, int iterations = 1, BorderTypes borderType = BorderTypes.Constant, Scalar? borderValue = null)
Erode(�����̹���, �����̹���, shape     , ������              , �ݺ�Ƚ��          , �׵θ� �ܻ��                                , �׵θ� ����               )


*/
