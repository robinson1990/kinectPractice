#include "process.h"

process::process(int w, int h){
	this->width = w, this->height = h;
	initMemory();
}
process::~process(){
	canny.release();
	gray.release();

}
void process::initMemory(void){
	canny = cv::Mat::zeros(height, width, CV_8UC1);
	gray = cv::Mat::zeros(height, width, CV_8UC1);
	return;
}

void process::CannyProcess(cv::Mat color){
	cv::cvtColor(color, gray, CV_BGR2GRAY);
	cv::Canny(gray, canny, 30, 80);
	return;
}

cv::Mat process::getCanny(void){
	return canny;
}

cv::Mat process::getGray(void){
	return gray;
}

//save image
void process::saveCanny(char* str){
	char filename[30];
	sprintf(filename,"%s.bmp", str);
	cv::imwrite(filename, canny);
	return;
}

void process::saveGray(char* str){
	char filename[30];
	sprintf(filename,"%s.bmp", str);
	cv::imwrite(filename, gray);

}
