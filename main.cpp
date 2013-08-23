#include "main.h"

int main(int argc,char** argv)
{

	while(1){
		v.GetRGB_D();
		v.createImg();

		pro.CannyProcess(v.getRGBImg());

		cv::imshow("color", v.getRGBImg());
		//cv::imshow("depth", v.getDPTImg());

		//cv::imshow("gray", pro.getGray());
		cv::imshow("canny", pro.getCanny());
		
		int key = cv::waitKey(1);

		keyCheck(key);
	}

	return 0;

}

void keyCheck(int key){
	switch(key){
	case 'q':
		exit(0);
		break;
	case '\033':
		exit(0);
		break;
	case 's':
		v.saveRGBImg("./color");
		v.saveDPTImg("./depth");
		pro.saveGray("./gray");
		pro.saveCanny("./canny");
		break;
	case 'd':
		std::cout<<v.getDPTImg()<<std::endl;

	}
}
