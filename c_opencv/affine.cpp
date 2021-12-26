//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����
#include <opencv2/imgproc.hpp>      //resize()�� ����ϱ� ���� �������
#include <list>

#include "affine.h"

using namespace cv;
using namespace std;


void Affine::start() {
	//�ʹ� �̹��� �ҷ����� 
	Mat img = imread("image/person.jpg", cv::IMREAD_COLOR);
	imshow("img", img);

	Mat dst;

	//���� ����Ʈ ����ü �����
	Point2f img_pts[3] =
	{
		Point2f(0,0),
		Point2f(0, img.cols), 
		Point2f(img.rows, img.cols)
	};

	//������ ����Ʈ ����ü �����
	Point2f dst_pts[3] =
	{
		Point2f(300, 300),
		Point2f(300, img.cols),
		Point2f(img.rows-400, img.cols -200)
	};

	Mat m = getAffineTransform(img_pts, dst_pts);

	warpAffine( img, dst, m, Size(img.cols, img.rows) );

	//show affine image
	imshow("dst", dst);
	waitKey(0);
	destroyAllWindows;
}


/*
�̹��� ��ȯ

1. ��ü ��ȯ - ��Ŭ����� ��ȯ�̶�� �ϰ�, ��ȯ�� ���������� ũ��� ������ �����Ǵ� ��ȯ - ���� �̵� ȸ�� ��
2. ���� ��ȯ - ũ�� ��ȯ���� ���� ��ȯ ��漺, �����̵�, ũ�⺯ȯ
3. ���� ��ȯ - ���� ���������� �̵��� �ǹ� ũ�⺯ȯ(�̹漺�� ���� �� ����), �ݻ�, �����
4. ���� ��ȯ - ���纯ȯ+ ���� ��ȯ �簢���� ����纯������ ��ȯ�ϴ� ��
5. ���� ��ȯ - ���� ��ȯ�� ����������, ������ ���� �� �ʴ´�.
6. �������� ��ȯ - ������� �������� ����� �����ϰų� ���� ��Ҹ� ���� �� �и��� �� �ִ� ������ ����

Ȯ��, ���
pyramid Ȯ��, ��� �� ��������� ���� �� �������� ����� �� ����
resize ������(Ȯ��)�� ���չ�(���)�� ����Ͽ� �̹����� ������ ������ ��� �ټ� �ִ�. - SubMat() aoi �����Ҷ� ����ϴ� �Լ�

��Ī
Mat flip(mat src, mat dst, flipmode)
flipmode
xy - �����¿� ��Ī
x  - ���� ��Ī
y  - �¿� ��Ī

ȸ��
Mat GetrotationMatrix2D(point2f center, double angle, double scale)


�������� ��ȯ
���ɺ�ȯ ����Ʈ A,B,C�������� ������ ����Ʈ A`,B`,C`�� ����(����)�� �����Ѵ�.
���� ��ü ����
Mat m = GetAffineTransform(IEnumerable<Point2f> Pnt_src, IEnumable<Point2f> Pnt_dst)

���ɺ�ȯ �Լ�
WarpAffine(
Mat src,
Mat dst,
Mat M,   --
Size dsize,
interpolationFlags(������),
BorderTypes borderMode (�׵θ��ܻ��),
BorderValue (�����ϰ� ���� ���� �� ����))


opencv c++ affine �� ȸ���� ���� ������ 
https://boysboy3.tistory.com/63 ����
*/
