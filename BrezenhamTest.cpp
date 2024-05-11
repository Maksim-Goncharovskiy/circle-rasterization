#include <BrezenhamLib/include/Brezenham/Brezenham.hpp>

int main() {
	cv::Mat img(500, 500, CV_8UC3, cv::Scalar(0, 0, 0));
	BrezenhamCircle var(cv::Point(250, 250), 100, cv::Scalar(255, 0, 0));
	var.GetArc(img, 18, 234, true);
}