#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	//part1
	//черный прямоугольник 120*768
	Mat image1(Mat::zeros(120, 768, CV_8UC1));
	int pixel = 5;
	//60*768 ступенчатое изменение пикселей от черного к белому с шагом 10 и градацией серого 30
	for (int i = 0; i < 60; i += 1)
	{
		for (int j = 0; j < 768; j += 30)
		{
			for (int k = 0; k < 30; k += 1)
				if (k + j < 768)
				{
					image1.at<uint8_t>(i, j + k) = pixel;
				}
			pixel += 10;
		}
		pixel = 5;
	}
	//part2
	Mat image2(Mat::zeros(120, 768, CV_8UC1));
	//преобразование 0...255 в 0...1
	image1.convertTo(image2, CV_32FC1, 1.0 / 255);
	//60*768 изображение градиента после гамма-коррекции
	for (int i = 60; i < 120; i += 1)
		for (int j = 0; j < 768; j += 1)
		{
			//гамма-коррекция с коэффициентом 2.2
			image2.at<float_t>(i, j) = pow(image2.at<float_t>(i - 60, j), 2.2);
		}
	//обратное преобразование
	image2.convertTo(image1, CV_8UC1, 255);
	imshow("", image1);
	waitKey(0);
	return 0;
}