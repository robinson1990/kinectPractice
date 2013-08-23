#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "OpenCV.h"
#include "OpenNI.h"

#define CONFIG_XML_PATH "SamplesConfig.xml"

class Video{

public:
	Video(int w, int h);
	~Video(void);

	//RGB, Depth image creation
	void GetRGB_D(void);
	void createImg(void);

	float* getDPTMap(void);
	cv::Mat getRGBImg(void);
	cv::Mat getDPTImg(void);

	//save image
	void saveRGBImg(char* str);
	void saveDPTImg(char* str);


private:
	int width, height;

	XnStatus nRetVal;

	//context
	xn::Context context;
	//generator
	xn::ImageGenerator image;
	xn::DepthGenerator depth;

	//MetaData
	xn::ImageMetaData imageMD;
	xn::DepthMetaData depthMD;

	//replay
	xn::Player player;
	xn::NodeInfoList nodeList;
	xn::MapGenerator* generator;

	//mat image
	cv::Mat rgb_img;
	cv::Mat dpt_img;

	//map of rgb and depth
	float* dptMap;

	void initMemory(void);
	void initCapture(void);

	void createRGBImg(void);
	void createDPTImg(void);

};

#endif
