#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "OpenCV.h"

class process{

public:
	process(int w, int h);
	~process();

	void CannyProcess(cv::Mat color);

	cv::Mat getCanny(void);
	cv::Mat getGray(void);

	//save image
	void saveCanny(char* str);
	void saveGray(char* str);

private:
	int width, height;

	void initMemory(void);

	cv::Mat canny;
	cv::Mat gray;

};


#endif