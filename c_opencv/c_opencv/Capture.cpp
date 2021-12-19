//#include <opencv2/opencv.hpp>     //opencv에서 지원하는 모든 기능을 포함 실질적으로 사용할때는 직업찾아 include한후에 사용함
#include <opencv2/core.hpp>         //Mat class를 포함한 기본 c++ data structure와 산술 루틴을 포함
#include <opencv2/videoio.hpp>		//파일을 읽고 쓰는 기능이 들어있음
#include <opencv2/highgui.hpp>		//윈도우 화면, ui처리(슬라이더,버튼등) 및 마우스를 제어할 수 있음

#include <iostream>
#include "Capture.h"

using namespace cv;
using namespace std;


void Capture::start() {
	//opencv videocapture class
	//동영상, 웹캠 영상을 불러 올 수 있다.
	cv::VideoCapture capture("video/blueberry.mp4");
	//capture.open(0); 카메라 설정

	//opencv mat class 객체 생성
	cv::Mat videoFrame;

	float videoFPS = capture.get(cv::CAP_PROP_FPS);
	int videoWidth = capture.get(cv::CAP_PROP_FRAME_WIDTH);
	int videoHeight = capture.get(cv::CAP_PROP_FRAME_HEIGHT);

	int fps = (int)capture.get(CAP_PROP_FPS);
	
	//비디오 재생 시작
	while (true)
	{
		//videocapture 로 부터 프레임을 받아옴
		capture >> videoFrame;

		//맨마지막은 할당이 비었으므로 재생 끝
		if (videoFrame.empty())
		{
			break;
		}

		//capture.read함수는 프레인을 읽고 나서 프레임이 있으면 true반환
		if (!capture.read(videoFrame))
		{
			break;
		}

		imshow("Video", videoFrame);
		//fps를 이용하여 재생속도를 조절 할 수 있음 
		if (cv::waitKey(1000 / videoFPS) == 27) break;
	}
	
	capture.release();
	destroyAllWindows();
}


/*

*/