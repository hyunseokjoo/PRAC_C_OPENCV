#include <opencv2/core.hpp>      
#include <opencv2/highgui.hpp>	
#include <opencv2/imgproc.hpp>   

#include "adaptThreshold.h"


using namespace cv;
using namespace std;

void AdaptThreshold::start() {
	//�����̹��� �ҷ�����
	Mat src = imread("image/person.jpg");
	//8��Ʈ 1ä�� mat ��ü ����
	Mat gray = Mat(src.size(), CV_8UC1);
	Mat binary = Mat(src.size(), CV_8UC1);
	Mat binary_1 = Mat(src.size(), CV_8UC1);
	Mat binary_2 = Mat(src.size(), CV_8UC1);
	Mat binary2 = Mat(src.size(), CV_8UC1);
	Mat binary2_1 = Mat(src.size(), CV_8UC1);
	Mat binary2_2 = Mat(src.size(), CV_8UC1);

	//���� �̹��� -> �׷��̽����Ϸ� ����
	cvtColor(src, gray, COLOR_BGR2GRAY);
	//������ ����ȭ �˰���(����þ� ���)
	//blocksize 25x25 ũ�� ���� ������ �м��� ������ �Ӱ찪�� �˾Ƽ� �����Ͽ� ����ϰ� �ȴ�.
	//blocksize�� �ʹ� ũ�� ��귮�� ���� �ӵ��� ��������.
	//��� c���� ���� ���� ���� 5�� ���� �̰��� ������ ���� �� ��� ��ü ������ ��ο�����. �ݴ�� 5���� ũ�� �������.
	adaptiveThreshold(gray, binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 25, 5);
	adaptiveThreshold(gray, binary_1, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 33, 5);
	adaptiveThreshold(gray, binary_2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 5);
	adaptiveThreshold(gray, binary2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 25, -5);
	adaptiveThreshold(gray, binary2_1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 33, -5);
	adaptiveThreshold(gray, binary2_2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, -5);

	imshow("gray", gray);
	imshow("binary", binary);	
	imshow("binary_1", binary_1);
	imshow("binary_2", binary_2);
	imshow("binary2", binary2);
	imshow("binary2_1", binary2_1);
	imshow("binary2_2", binary2_2);

	waitKey(0);
	destroyAllWindows;

}


/*
������ ����ȭ �˰���
- �Է� �̹����� ���� �Ӱ찪�� ������ �ٸ� ���� �Ҵ��� �� �ֵ��� ������ ����ȭ �˰����̴�.
�̹����� ���� ��� �Ӱ찪�� �ִ��� ����ȭ ó���� ����� �̹����� �����ϴµ�
(ex ������ ��ȭ�� �ݻ簡 ���� ��� �̹��� ���� ��� ������ �޶� ���������� �Ӱ찪�� �����ؾ� ���ϴ� ����� ���� ���ִ�.)
�̷��� ��� ������ ����ȭ �˰����� �����Ѵ�.


---------------------- ������ ����ȭ �˰����� ����ϴ� ����--------------------------
Otsu�� ���� ����ȭ�� ���� ����� ��� �̹�������, Ư�� �̹����� ���� �ٸ��������� 
�ٸ� ��Ⱚ�� ���� �� �� ������� �ʴ´�.(������ ���� �޾� ��� ������ �׸������� ������ �׸����� �� �ȵ�)
�̷��� ��� ������ ����ȭ�� ������ �� �ִ�.

������ ����ȭ�� �̹����� �� �ȼ��� ���� ���������� �Ӱ谪�� �����ϴ� �������, 
��� �ȼ��� �ֺ� �ȼ����� ������� �����ȴ�. ���� �̹����� �ٸ� ������ ���� ���� 
�ٸ� �Ӱ谪�� �����ϹǷ� ����� ��Ⱑ �پ��� �̹������� �� �����ϰ� �ȴ�.
---------------------------------------------------------------------------------------


AdaptiveThreshold->������ ����ȭ �˰���

AdaptiveThreshold(�����̹���, �����̹���, maxValue, adaptivemethod, threshold type, blocksize, ��� c)

�ȼ����� ������ �Ӱ찪 x, y�� ������ ������ �̿��Ѵ�.
blocksize�� �߽����� ������ �� �ְ� Ȧ���� ��밡���ϴ�.
����� blocksize�� blocksize������ ���� ���� ����� ��� - c(���) �� �Ѵ�.

type
ADAPTIVE_THRESH_MEAN_C     blocksize      �����Ǹ�� �ȼ��� ��հ���ġ�� ����
ADAPTIVE_THRESH_GAUSSIAN_C blocksize  ������ ��� �ȼ��� �߽������κ����� �Ÿ��� ���� ����þ� ����ġ�� ����
*/

