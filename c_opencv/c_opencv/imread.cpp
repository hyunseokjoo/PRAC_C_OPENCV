//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/videoio.hpp>		//������ �а� ���� ����� �������
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����

#include "imread.h"

using namespace std;
using namespace cv;

void Imread::start() {
	Mat img = imread("image/person.jpg", IMREAD_GRAYSCALE);

	imshow("img", img);
	waitKey(0);
}


/*
Mat img = imread("���", ImreadModes.~~)

imread �Լ��� �̹��� ������ ��� �ҷ� ���� ���ϴ� �Լ� �Դϴ�.

imread�Լ��� �Ķ���ʹ� ��� , ���� ������ �Ǿ��ִµ� ��θ� �ۼ��� ��� 
CV_8UC3���� �ٷ� ���� �ǰ� �˴ϴ�.

mode�� ������ 
Imread_Unchanged                - ���� ä���� �����ؼ� �̹��� ��ȯ						= -1
Imread_GrayScale				- ���� ä�� �׷��̽����Ϸ� ��ȯ							= 0
Imread_Color					- ���� ä�� ���� �̹��� ��ȯ							= 1
Imread_AnyDepth					- ���е��� ������ ��� 16/312��Ʈ �̹����� ��ȯ			= 2
Imread_ReducedGrayscale2		- ũ�⸦ 1/2�� ���� �� �׷��̽����� ��ȯ				= 16
Imread_ReducedGrayscale4		- ũ�⸦ 1/4�� ���� �� �׷��̽����� ��ȯ				= 32
Imread_ReducedColor2			- ũ�⸦ 1/2�� ���� �� ���� ä�� ���� �̹����� ��ȯ     = 17
Imread_ReducedColor4			- ũ�⸦ 1/4�� ���� �� ���� ä�� ���� �̹����� ��ȯ		= 33
Imread_IgnoreOrientation		- exif�� ���� �÷��׿� ���� �̹����� ȸ������ ����		= 128

*/