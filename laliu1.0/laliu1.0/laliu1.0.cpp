#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

	//VideoCapture capture;
	//capture.open("1.avi"); //����Ƶ�ļ�
	//capture.open("rtmp://101.42.99.28:1935/stream/pupils_trace");

	//����VideoCapture�������һ�ַ�ʽ
	VideoCapture capture("rtmp://101.42.99.28:1935/stream/pupils_trace");

	int frameH = capture.get(4);//�߶�
	int frameW = capture.get(3);//���
	cout << "frameH:" << frameH << "  frameW:" << frameW << endl;

	Mat frame;

	while (1)
	{
		capture >> frame;

		imshow("test", frame);
		if (waitKey(30) >= 0)
			break;
	}

	destroyWindow("test");//����ָ������test
	capture.release();//�����release�ͷţ�������ڴ�й©

	return 0;
}