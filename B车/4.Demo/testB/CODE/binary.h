#ifndef BINARY_H_
#define BINARY_H_

#include "headfile.h"

uint8 HistGram[256];
uint8 Threshold;
uint8 Pixel[MT9V03X_DVP_H][MT9V03X_DVP_W];//数组指针，存放二值化图像数据



void GetHistGram(uint8 Image[120][188]);
uint8_t OSTUThreshold();
void BinaryImage(uint8 Image[120][188]);
void ImageHandle(uint8_t Image[120][188]);

void OSTU2Image(uint8 Image[120][188]);
void Bin_Image_Filter();

#endif/* BINARY_H_ */
