#include <opencv/cv.h>
#include <opencv/highgui.h>

//pragma
#ifdef _DEBUG
//Debug mode
#pragma comment(lib, "opencv_imgproc230d.lib")
#pragma comment(lib, "opencv_core230d.lib")
#pragma comment(lib, "opencv_highgui230d.lib")
#else
//Release mode
#pragma comment(lib, "opencv_imgproc230.lib")
#pragma comment(lib, "opencv_core230.lib")
#pragma comment(lib, "opencv_highgui230.lib")
#endif
