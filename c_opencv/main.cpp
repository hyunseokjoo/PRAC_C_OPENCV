#include <iostream>					//����� ���� ������ �������(stream input output)
#include <stdio.h>                  //standard input output �� ���ڷ� h�� ����� ���ڴ� ǥ�� ����¿� ���õ� ������ ������� (���������, �ܼ�ȭ�� ���)
#include "imread.h"
#include "Capture.h"
#include "resize.h"
#include "concat.h"
#include "cvtColor.h"
#include "threshold.h"
#include "adaptThreshold.h"
#include "blur.h"
#include "affine.h"

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

	Affine af;
	af.start();

	return 0;
}   
