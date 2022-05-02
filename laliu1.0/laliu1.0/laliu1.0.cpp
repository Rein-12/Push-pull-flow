#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

	//VideoCapture capture;
	//capture.open("1.avi"); //打开视频文件
	//capture.open("rtmp://101.42.99.28:1935/stream/pupils_trace");

	//创建VideoCapture对象的另一种方式
	VideoCapture capture("rtmp://101.42.99.28:1935/stream/pupils_trace");

	int frameH = capture.get(4);//高度
	int frameW = capture.get(3);//宽度
	cout << "frameH:" << frameH << "  frameW:" << frameW << endl;

	Mat frame;

	while (1)
	{
		capture >> frame;

		imshow("test", frame);
		if (waitKey(30) >= 0)
			break;
	}

	destroyWindow("test");//销毁指定窗口test
	capture.release();//必须加release释放，否则会内存泄漏

	return 0;
}