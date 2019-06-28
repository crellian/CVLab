#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include"types.h"
#include"imgproc.h"
#include"readimg.h"
using namespace cv;
using namespace std;

int main()
{
	/*Mat img = CVLab::imread("C:\\Users\\Lenovo\\Desktop\\painting\\1.jpg");
	Mat dstImg;
	blur(img, dstImg, Size(100, 100));

	imshow("", dstImg);
	waitKey(6000);*/
	CVLab::Vector v(3);
	cout << v << endl;
	CVLab::Vector v1(10, 2.0);
	signed char a[] = { 1, 2 };
	CVLab::Vector v2(2, a);
	CVLab::Vector v3(v1);
	v = { 1,2,3 };
	CVLab::Vector v4;
	v4 = v;
	cout << (v4 == v);
	cout << (v4 != v);
	cout << v << endl;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << v4 << endl;
}