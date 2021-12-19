//#include <opencv2/opencv.hpp>     //opencv���� �����ϴ� ��� ����� ���� ���������� ����Ҷ��� ����ã�� include���Ŀ� �����
#include <opencv2/core.hpp>         //Mat class�� ������ �⺻ c++ data structure�� ��� ��ƾ�� ����
#include <opencv2/videoio.hpp>		//������ �а� ���� ����� �������
#include <opencv2/highgui.hpp>		//������ ȭ��, uió��(�����̴�,��ư��) �� ���콺�� ������ �� ����

#include <iostream>
#include "Capture.h"

using namespace cv;
using namespace std;


void Capture::start() {
	//opencv videocapture class
	//������, ��ķ ������ �ҷ� �� �� �ִ�.
	cv::VideoCapture capture("video/blueberry.mp4");
	//capture.open(0); ī�޶� ����

	//opencv mat class ��ü ����
	cv::Mat videoFrame;

	float videoFPS = capture.get(cv::CAP_PROP_FPS);
	int videoWidth = capture.get(cv::CAP_PROP_FRAME_WIDTH);
	int videoHeight = capture.get(cv::CAP_PROP_FRAME_HEIGHT);

	int fps = (int)capture.get(CAP_PROP_FPS);
	
	//���� ��� ����
	while (true)
	{
		//videocapture �� ���� �������� �޾ƿ�
		capture >> videoFrame;

		//�Ǹ������� �Ҵ��� ������Ƿ� ��� ��
		if (videoFrame.empty())
		{
			break;
		}

		//capture.read�Լ��� �������� �а� ���� �������� ������ true��ȯ
		if (!capture.read(videoFrame))
		{
			break;
		}

		imshow("Video", videoFrame);
		//fps�� �̿��Ͽ� ����ӵ��� ���� �� �� ���� 
		if (cv::waitKey(1000 / videoFPS) == 27) break;
	}
	
	capture.release();
	destroyAllWindows();
}


/*

*/