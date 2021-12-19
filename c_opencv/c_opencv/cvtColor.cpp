#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "cvtColor.h"

using namespace cv;
using namespace std;

void CvtColor::start()
{
	Mat src = imread("image/person.jpg");

	//bgr �÷� �̹����� grayscale�� ����
	Mat dst;
	cv::cvtColor(src, dst, COLOR_BGR2GRAY);

	imshow("dst", dst);

	//bgr�÷� �̹����� hsv�� ����
	Mat dst_hsv;
	cv::cvtColor(src, dst_hsv, COLOR_BGR2HSV);

	imshow("dst_hsv", dst_hsv);

	//bgr�÷� �̹����� luv �� ����
	Mat dst_luv;
	cv::cvtColor(src, dst_luv, COLOR_BGR2Luv);

	imshow("dst_luv", dst_luv);

	waitKey(0);
	destroyAllWindows;
}

/*
��ó�� �۾��� �ʿ��� ���� 
- �÷� �̹����� �ַ� �̷�� ���µ� �÷��̹����� rgb�� �̷�� ���־� 
binary �̹��� ���� 3�� �� ������ó���� �� �ʿ� �ϴ� �׷��� �׷��̽������̳� 
�ٸ� ���·� ������ �Ͽ� �̹����� ����ϰ� �Ǵµ� ������ �۾��� �ϱ� �� 
�̹��� ������ �ϴ°��� ��ó�� �۾��̴�. ��, ���ϴ� ������� �������
ó���ϴ� �ӵ��� �����ϱ� ���� ��ó���� �Ѵ�.

CvtColor �Լ��� ���� ��ȯ �Լ��̴�. 
cvtcolor(�����̹���, �����ؼ� ���� mat����, �����һ�������)�� ���� �Ǿ��ִ�.

������ type 
//BGR�� RGB���� ���� ��ȣ ��Ȳ
BGR2RGB
RGB2BGR
BGRA2RGBA
RGBA2BGRA

//BGR�̳� RGB���� ������ ���� ä�� �߰�
BGR2BGRA
BGR2RGBA
RGB2GBRA
RGB2RGBA

//BGRA�̳� RGBA��������� ����ä�� ����
BGRA2BGR
BGRA2RGB
RGBA2BGR
RGBA2RGB

//BGR�� RGB ���� ������ �׷��̽����Ϸκ�ȯ
BGR2GRAY
BGRA2GRAY
RGBA2GRAY

//�׷��̽����� ��������� BGR�̳� RGB�� ��ȯ
GRAY2BGR
GRAY2BGRA
GRAY2RGB
GRAY2RGBA

//HSV�� ��ȯ, RGB�� BGR�� ��ȯ
BGR2HSV
RGB2HSV
HSV2BGR
HSV2RGB

//CIE LAB ���� ��ȣ ��ȯ
BGR2LAB
RGB2LAB
LAB2BGR
LAB2RGB

//LUV�� ��ȣ ��ȯ
RGB2LUV
BGR2LUV
LUV2BGR
LUV2RGB

//BGR�̳� RGB �� YCC(ũ�θ�)FH TKDGH QUSGHKS(YCC= Y, CR, CB)
BGR2YCRCB
RGB2YCRCB
YCRCB2BGR
YCRCB2RGB


BGR565
RGB565�� �������� �ʿ��� ��� ã�ƺ��鼭 �ϸ� �ȴ�.





*/