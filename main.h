#ifndef INCLUDED_MAIN_H
#define INCLUDED_MAIN_H

//include
#include "OpenCV.h"
#include "OpenNI.h"

#include "Video.h"
#include "process.h"

//prototype
void keyCheck(int key);

//class instance
Video v(640, 480);
process pro(640, 480);

#endif