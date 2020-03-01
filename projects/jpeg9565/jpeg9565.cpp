#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main()
{
	//part1
	Mat image1;
	//загружаем картинку в png
	image1 = imread("C:/Users/lada.isakova/Desktop/isakova_l_m/projects/jpeg9565/bob1.png");
	std::vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
	compression_params.push_back(1);
	//уровень качества-95
	compression_params[1] = 95;
	//сохраняем картинку в jpeg-95
	imwrite("C:/Users/lada.isakova/Desktop/isakova_l_m/projects/jpeg9565/bob2.jpeg", image1, compression_params);
	//уровень качества-65
	compression_params[1] = 65;
	//сохраняем картинку в jpeg-65
	imwrite("C:/Users/lada.isakova/Desktop/isakova_l_m/projects/jpeg9565/bob3.jpeg", image1, compression_params);
	//imshow("", image1);
	Mat image2;
	image2 = imread("C:/Users/lada.isakova/Desktop/isakova_l_m/projects/jpeg9565/bob2.jpeg");
	//imshow("", image2);
	Mat image3;
	image3 = imread("C:/Users/lada.isakova/Desktop/isakova_l_m/projects/jpeg9565/bob3.jpeg");
	//imshow("", image3);
	//part2
	//общая картинка
	Mat diffimage(Mat::zeros(328, 600, CV_8UC3));
	for (int i = 0; i < 164; i += 1)
		for (int j = 0; j < 200; j += 1)
		{
			//значения bgr 1 картинки
			int b1 = image1.at<cv::Vec3b>(i, j)[0];
			int g1 = image1.at<cv::Vec3b>(i, j)[1];
			int r1 = image1.at<cv::Vec3b>(i, j)[2];
			//значения bgr 2 картинки
			int b2 = image2.at<cv::Vec3b>(i, j)[0];
			int g2 = image2.at<cv::Vec3b>(i, j)[1];
			int r2 = image2.at<cv::Vec3b>(i, j)[2];
			//значения bgr 3 картинки
			int b3 = image3.at<cv::Vec3b>(i, j)[0];
			int g3 = image3.at<cv::Vec3b>(i, j)[1];
			int r3 = image3.at<cv::Vec3b>(i, j)[2];
			//1 2 b
			diffimage.at<cv::Vec3b>(i, j)[0] = abs(b1 - b2);
			diffimage.at<cv::Vec3b>(i, j)[1] = 0;
			diffimage.at<cv::Vec3b>(i, j)[2] = 0;
			//1 2 g
			diffimage.at<cv::Vec3b>(i, j + 200)[0] = 0;
			diffimage.at<cv::Vec3b>(i, j + 200)[1] = abs(g1 - g2);
			diffimage.at<cv::Vec3b>(i, j + 200)[2] = 0;
			//1 2 r
			diffimage.at<cv::Vec3b>(i, j + 400)[0] = 0;
			diffimage.at<cv::Vec3b>(i, j + 400)[1] = 0;
			diffimage.at<cv::Vec3b>(i, j + 400)[2] = abs(r1 - r2);
			//1 3 b
			diffimage.at<cv::Vec3b>(i + 164, j)[0] = abs(b1 - b2);
			diffimage.at<cv::Vec3b>(i + 164, j)[1] = 0;
			diffimage.at<cv::Vec3b>(i + 164, j)[2] = 0;
			//1 3 g
			diffimage.at<cv::Vec3b>(i + 164, j + 200)[0] = 0;
			diffimage.at<cv::Vec3b>(i + 164, j + 200)[1] = abs(g1 - g2);
			diffimage.at<cv::Vec3b>(i + 164, j + 200)[2] = 0;
			//1 3 r
			diffimage.at<cv::Vec3b>(i + 164, j + 400)[0] = 0;
			diffimage.at<cv::Vec3b>(i + 164, j + 400)[1] = 0;
			diffimage.at<cv::Vec3b>(i + 164, j + 400)[2] = abs(r1 - r2);
		}
	imshow("", diffimage);
	waitKey(0);
	return 0;
}