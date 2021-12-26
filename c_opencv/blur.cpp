//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������

#include "Blur.h"

using namespace cv;
using namespace std;


void Blur::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);

	//�ܼ� �� ȿ��
	Mat dst;
	cv::blur(img, dst, Size(5, 5), Point(3, 3), BORDER_REFLECT101);
	imshow("dst", dst);

	//�߰��� �� ȿ�� 
	Mat median;
	medianBlur(img, median, 5);
	imshow("median", median);

	//����þ� �� ȿ��
	Mat gaussian;
	GaussianBlur(img, gaussian, Size(5, 5), 3, 3);
	imshow("gaussian", gaussian);

	//����� �� ȿ�� ���� 100(�ȼ����� ����) , �ñ׸� ���� 33 ,  �ñ׸� ���� 11 -�̹��� ���� ���� ������ ���� �ȼ� ���� 
	//-���� Ŭ ���� �ָ� �ִ� �ȼ��� ���⵵ Ŀ�� �̹��� ������ ȿ���� ���̰� �ȴ�.
	Mat bilateral;
	bilateralFilter(img, bilateral, 100, 33, 11);
	imshow("bilateral", bilateral);

	waitKey(0);
	destroyAllWindows;

}


/*
�帲 ȿ�� (Blur) - ���� �Ǵ� �������̶�� �Ҹ���.
�帲 ȿ���� �ܼ��� �帮�� ����°��� �ƴ϶� ����� �����ؼ� ���� �� ����� ������ �����.
(�̹��� ��ȯ�ÿ� 1�� �̺а� 2���̺��� �ϴµ� ����ϴ� �Ͱ� ����ϴٰ� ����ȴ�)

���� �̹������� ����ϴ� �ֿ� ���
Ŀ��     - �̹������� (x,y)�� �ȼ��� �ش� �ȼ� �ֺ��� ������ ���� ũ���� ������ �ǹ��Ѵ�.
������� - ���ο� �ȼ��� ����� ���� ���� Ŀ�� ũ���� ȭ�� ���� �̿��� � �ý����� ��� �� ����ϴ� ��
������   - Ŀ���� ���� ������ǵ� ���� �Ҵ��ϴ� ����

�׵θ� �ܻ��
��������� ������ �� �̹����� �����ڸ� �κ��� ����� �Ұ��� �ϴ�. ���⼭ �ʿ��� ���� �׵θ� �ܻ���̴�.
(ex Ŀ���� 50x50 �̸� �������� (0.0)�� �����ߴٰ� ġ�� Ŀ���� �����ڸ� ����Ʈ�� (-50,-50)�� �Ǳ� ������ ����� �Ұ����ϴ�.)

BORDER_CONSTANT    - ���������� �ȼ��� Ȯ��
BORDER_RELPICATE   - �׵θ� �ȼ��� �����ؼ� Ȯ��
BORDER_REFLECT     - �ȼ��� �ݻ��ؼ� Ȯ��
BORDER_WRAP        - �ݴ��� �ȼ��� �����ؼ� Ȯ��
BORDER_REFLECT101  - ���� �ȼ��� ������ �ʰ� �ݻ��ؼ� Ȯ��
BORDER_DEFAULT     - Reflect101 ����� ���
BORDER_TRANSPARENT - �ȼ��� �����ϰ� �ؼ� Ȯ��
BORDER_ISOLATED    - ���� �������� ������� ����


�ܼ� �帲
blur(Mat src, Mat dst, Size ksize, Point? anchor=null, BorderTypes borderType = BorderTypes.Reflect101)
blur(�Է��̹���, �����̹���, Ŀ����ũ��, ������, �׵θ� �ܻ��)
��¥ �ܼ��ϰ� ������⸸ �ϴ� ȿ��


�ڽ� ���� �帲
boxFilter(Mat src, Mat dst, MatType ddepth, size ksize, Point? anchor = null, bool normalize = true, BorderTypes borderType = BorderType.Reflect101)
boxFilter(�Է��̹���, �����̹���, ����̹������е�, ������, ����ȭ ����, �׵θ� �ܻ��)
�ڽ� �ȿ� ���͸� �����Ͽ� ������� ����� ȿ��

�߰��� �帲 ȿ��
medianBlur(Mat src, Mat dst, Size ksize)
medianBlur(�Է��̹���, �����̹���, Ŀ��)
�簢�� ũ���� �̿��� �ȼ����� �߰����� ����Ͽ� ������� �ϴ� ȿ��
������ ������ ���ſ� ȿ���� �����̹����� ������ ������� �־� ���� �ؾ��Ѵ�.

����þ� �帲 ȿ��
gaussianBlur(Mat src, Mat dst, Size ksize, double sigmX, double sigmaY, BorderTypes borderType = BorderTypes.Reflect101)
gaussianBlue(�Է��̹���,�����̹���, Ŀ��, x�డ�콺ǥ����������, y�డ�콺ǥ����������, �׵θ� �ܻ��)
����þ� �帲 ȿ���� �پ��� Ŀ�ο� ���� ���� ������ ������ ����ȭ �� ������
3x3, 5x5, 7x7 ũ���� Ŀ�ο� ���� ����� ������ �����ش�.

����� ���� �帲 ȿ�� 
bilateralFilter(Mat src, Mat dst, int d, double sigmaColor, double sigmaSpace, BorderTypes borderType = BorderTypes.Reflect101)
bilateralFilter(�Է��̹���, �����̹���, ����, �ñ׸� ����, �ñ׸� ����,�׵θ� �ܻ��)
�����ڸ��� �����ϰ� �����ϸ鼭 ����� ����ϰ� ���� �ϴ� �帲ȿ�� �Լ���.
������ �ߺ��̰� �������� ��ó���ϴ� ������ ��� �Ѵ� 
��귮�� ���� �ӵ��� ���� �ɸ���.



*/
