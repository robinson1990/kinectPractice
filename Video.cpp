#include "video.h"

Video::Video(int w, int h){
	this->width = w, this->height = h;

	initCapture();
	initMemory();
}

Video::~Video(void){
	context.Release();
	image.Release();
	depth.Release();

	delete dptMap;
}

void Video::initMemory(void){
	rgb_img = cv::Mat::zeros(height, width, CV_8UC3);
	dpt_img = cv::Mat::zeros(height, width, CV_8UC1);
	dptMap = new float[width*height];
	return;
}

void Video::initCapture(void){
	try {
		//initial context
		nRetVal = context.InitFromXmlFile(CONFIG_XML_PATH);
		if(nRetVal != XN_STATUS_OK) {
			throw std::runtime_error(xnGetStatusString(nRetVal));
		}
		//depth generator
		nRetVal = context.FindExistingNode(XN_NODE_TYPE_DEPTH, depth);
		if(nRetVal != XN_STATUS_OK) {
			throw std::runtime_error(xnGetStatusString(nRetVal));
		}
		//image generator
		nRetVal = context.FindExistingNode(XN_NODE_TYPE_IMAGE, image);
		if(nRetVal != XN_STATUS_OK) {
			throw std::runtime_error(xnGetStatusString(nRetVal));
		}
		nRetVal = context.StartGeneratingAll();
	} catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
		exit(1);
	}

	//convert viewPoint depth from color
	depth.GetAlternativeViewPointCap().SetViewPoint(image);
	return;
}

void Video::GetRGB_D(void){
	context.WaitAnyUpdateAll();
	return;
}

void Video::createImg(void){
	image.GetMetaData(imageMD);
	depth.GetMetaData(depthMD);

	createRGBImg();
	createDPTImg();
	return;
}

void Video::createRGBImg(void){
	//Image
	memcpy(rgb_img.data,imageMD.Data(), rgb_img.step * rgb_img.rows);
	cv::cvtColor(rgb_img, rgb_img, CV_RGB2BGR);
	return;
}

void Video::createDPTImg(void){
	const XnDepthPixel* pDepth = depthMD.Data();

	for(unsigned int y = 0; y < height; y++){
		for(unsigned int x = 0; x < width; x++){
			int acs = y*width+x;
			dpt_img.data[acs] = (unsigned char)(*pDepth * 255/4096.0);
			dptMap[acs] = ((unsigned short)*pDepth);
			pDepth++;
		}
	}
	return;
}

float* Video::getDPTMap(void){
	return dptMap;
}

cv::Mat Video::getRGBImg(void){
	return rgb_img;
}

cv::Mat Video::getDPTImg(void){
	return dpt_img;
}

void Video::saveRGBImg(char* str){
	char filename[30];
	sprintf(filename,"%s.bmp", str);
	cv::imwrite(filename, rgb_img);
	return;
}

void Video::saveDPTImg(char* str){
	char filename[30];
	sprintf(filename,"%s.bmp", str);
	cv::imwrite(filename, dpt_img);
	return;
}

