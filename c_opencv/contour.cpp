//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������

#include "contour.h"

using namespace cv;
using namespace std;


void Contour::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	Mat gray, thres;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	
	Mat sb;
	Sobel(gray, sb, CV_8UC1, 1, 0, 3, 1, 0, BORDER_REFLECT101); //�̺� ����x�� 1 y�� 0 
	imshow("gray", sb);

	Mat cn; // ĳ�� ������ �ַ� ���� ����Ѵ� 2���̺��� ����Ͽ� ������ ���Ű� ���� ����ȭ threshold�� �����Ͽ� ������ �׵θ��� �ּҰ��� ���� �ִ밪�� ���� �� �� �ֱ� �����̴�.
	Canny(img, cn, 50, 100, 3, true); //threshold1 50���� ���� 50 �̸��� ��� ����, threshold2 200���� ���� 200�̻��� ���� ����� ��� �ȼ��� ����

	imshow("Canny", cn);

	waitKey(0);
	destroyAllWindows;
}


/*
�����ڸ�, ������, ���� �� ���� ����

�����ڸ� ����
�����ڸ��� ���� �ٱ� �κ��� �ѷ��� �ǹ�, ��ü�� �׵θ��� �� �� �ִ�.
�����ڸ� ������ ����� ����� �����ϴ� ���� �ľ��Ѵ�
����� ������� ������ �� �ް��ϰ� ��ȭ�ϴ� ���� ã�� �����ڸ��� ã�´�
�̰��� Ȯ���ϴ� ����� �ȼ��� ��⸦ �̿��� ��ȭ���� �����Ѵ�.
��ȭ���� �����ϱ� ���� �̺��� ����Ͽ� ������ ��ȭ�� ã�Ƴ���.

�̺� ������ �����ڸ� ������
step, line, ramp, roof�� �ִ�.

step�� ���� �ٷ� 0-1���� ��ȭ�ϴ� ����
line�� ���� �ް��ϰ� ���ߴٰ� �ٽ� ���ڸ��� ���ƿ��� ����
ramp�� step���� ������ ������ ��
roof�� line���� ������ ������ ��


�����ڸ� ���� ���
�Һ� �̺�, ���� ����, ���ö�þ�, ĳ�� ����

sobel(
 Mat src,			- ���� �̹���
 Mat dst,			- ��� �̹���
 MatType ddepth,	- ��� �̹��� ���е� 
 int xorder,		- x �̺� ����
 int yorder,		- y �̺� ����
 int ksize = 3,		- Ŀ���� ũ��
 double scale = 1,	- ���� 
 double delta = 0,	- ������
 BorderTypes borderType = borderTypes.Reflect101
)

�Һ��� �̺��� �ϴ� ���� ������ �̺й�
Ŀ���� ����ϰ� ũ�Ⱑ 3~31 ���� �����ϴ�
Ŀ�� ���� ������ ���� ���� 0�� �Ǿ���Ѵ�


���� ����
�Һ� �̺��� ������ ����
3x3�� ���͸� ����Ѵٸ� ���� ���͸� Ȱ���ϴ°� ����

Scharr(
 Mat src,
 Mat dst,
 MatType ddepth,
 int xorder,
 int yorderm
 double scale = 1,
 double delta = 0,
 BorderTypes borderType = BorderTypes.Reflect101
)

������ 3x3Ŀ�λ���� �����ؼ� Ŀ���� ũ��� ������� �ʴ´�



���ö�þ�
�Һ� ������ ����� ��
2���̺��� ����
x��� y���� ���� 2�� �̺��� ���� �ǹ��Ѵ�.
Ŀ���� ũ�Ⱑ 1�� �� Ư���ϰ� ����Ǵ� ���ö�þ� ������ ���¸� �����ش�





ĳ�� ����
���� ���� ����ϴ� �����ڸ� ���� ���, �Һ������� ����� ��
������ ���Ÿ� ���� ����þ� ���͸� ����� �帲 ȿ���� ����
���� ���� ���� ������ ����
�ִ��� �ƴ� �ȼ��� ���� 0���� ����
�����׸��ý� �Ӱ찪 ����

���� �Ӱ찪�� ���� �Ӱ찪�� ����� ��츸 �����ڸ� �ȼ��� ����
���� �Ӱ찪 200, ���� �Ӱ찪 100�̸�
100���ϴ� ��� ���� 200�̻��� �ȼ��� �ϳ��� ������
100�̻��� �ȼ��� ��� �����ڸ��� �����Ѵ�.

canny(
 Mat src,
 Mat dst,
 double threshold1,
 double threshold2,
 int aperturesize = 3, - �Һ����� ����ũ ������
 bool L2gradient = false - L2norm �������� �ӵ����� �ɷ��� ��Ȯ�ϰ� ������� , �ӵ� ������ ���� ������� ����
)





*/
