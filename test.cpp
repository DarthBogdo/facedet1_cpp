#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main()
{
	string path = "captain_tatarstan.jpg"; //Put in the image
	Mat img = imread(path);

	CascadeClassifier facedetect;
	facedetect.load("haarcascade_frontalface_default.xml");


	if (facedetect.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;

	facedetect.detectMultiScale(img, faces, 1.3, 5); 

	cout << faces.size() << endl;

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
		rectangle(img, Point(0,0), Point(300, 70), Scalar(50, 50, 255), FILLED);
		putText(img, to_string(faces.size()) + "Face(s) Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
	}

	imshow("Frame", img);
	waitKey(1);
}