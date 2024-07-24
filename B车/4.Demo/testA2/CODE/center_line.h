/*
 * PLC.h
 *
 *  Created on: 
 *  Author: heavywood
 */

#ifndef center_line_H_
#define center_line_H_

#include "headfile.h"


uint8 Left_line[120];
uint8 Right_line[120],Center_line[120];
uint8 choose;
uint8 L_U_dot,L_D_dot,R_U_dot,R_D_dot;
uint8 white_line[60];



uint8 round_dot1_row,round_dot1_col;
int num_white,num_L,num_R,num_R_row;
uint8 first1,WtoB_R,first2,WtoB_L,first3;


//十字状态
uint8 Cross_status;
uint8 entered_Cross;

//三岔路口
uint8 triangle_flag;
uint8 triangle_turn;
int A,B; //左右拐点
uint8 CX,CY; //上拐点

//直角弯道
uint8 rightangle_flag;
#define MT9V03X_DVP_H     120
#define MT9V03X_DVP_W     188

//出库
uint8 car_start;
uint8 out_flag;

//检测斑马线，第一次车启动，第二次车停止
uint8 black_white_first;
uint8 black_white_flag;
#define E 1e-10
void CenterLine();
double sqrt(double value);
double Abs(double a,double b);




#endif /* center_line_H_ */
