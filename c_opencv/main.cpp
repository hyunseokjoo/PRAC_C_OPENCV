#include <iostream>					//입출력 관련 내용이 들어있음(stream input output)
#include <stdio.h>                  //standard input output 의 약자로 h는 헤더의 약자다 표준 입출력에 관련된 내용이 들어있음 (파일입출력, 콘솔화면 등등)
#include "imread.h"
#include "Capture.h"
#include "resize.h"
#include "concat.h"
#include "cvtColor.h"
#include "threshold.h"
#include "adaptThreshold.h"
#include "blur.h"
#include "affine.h"
#include "dilate.h"
#include "erode.h"
#include "contour.h"

using namespace std;

int main(int ac, char** av) {
	//Imread ir;
	//ir.start();

	//Capture cap;
	//cap.start();

	//Resize rs;
	//rs.start();

	//Concat cc;
	//cc.start();

	//CvtColor cvtc;
	//cvtc.start();

	//Threshold th;
	//th.start();

	//AdaptThreshold ath;
	//ath.start();

	//Blur br;
	//br.start();

	//Affine af;
	//af.start();

	//Dilate dl;
	//dl.start();

	//Erode ed;
	//ed.start();

	Contour ct;
	ct.start();

	return 0;
}   
