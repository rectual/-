#ifndef __PID_H_
#define __PID_H_

#include "headfile.h"

typedef struct
{
    float target_val;   //目标值
    float error;          //偏差值
    float error_last;     //上一个偏差值
    float integral;     //积分值
    float output_val;   //输出值
}PID;


typedef struct
{
    int PID_P;
    int PID_I;
    int PID_D;

    int speed;
}Car_param;


//#define bend_control    30

int error;//偏差



//普通pid
//直线PID速度参数
#define   Straight_PID_P     25
#define   Straight_PID_I     0
#define   Straight_PID_D     50 //30

#define   Straight_SPEED     8000



//弯道PID速度参数
#define   Bend_PID_P     150 //150
#define   Bend_PID_I     0
#define   Bend_PID_D     0 //100压内线 120压内线 80压内线 50怪不过来 60怪不过


#define   Bend_SPEED     7000





//十字PID速度参数
//直道
#define   Cross_road_Straight_PID_P     30
#define   Cross_road_Straight_PID_I     0
#define   Cross_road_Straight_PID_D     20

#define   Cross_road_Straight_SPEED       8500

//弯道
#define   Cross_road_bend_PID_P     80
#define   Cross_road_bend_PID_I     0
#define   Cross_road_bend_PID_D     50

#define   Cross_road_bend_SPEED      8500

//直角弯
#define   Straight_road_bend_PID_P     75
#define   Straight_road_bend_PID_I     0
#define   Straight_road_bend_PID_D     50

#define   Straight_road_bend_SPEED     8000


#define   triangle_PID_P     180
#define   triangle_PID_I     0
#define   triangle_PID_D     0

#define   triangle_SPEED     6000
////环岛PID直线速度参数
//#define   Round_Straight_PID_P     45
//#define   Round_Straight_PID_I     0
//#define   Round_Straight_PID_D     35
//
//#define   Round_Straight_SPEED     7000
//
////环岛PID弯道速度参数
//#define   Round_bend_PID_P    80
//#define   Round_bend_PID_I     0
//#define   Round_bend_PID_D    40
//
//#define   Round_bend_SPEED    7500


#define   vision    45



#define   vision1     45
#define   vision2     40
#define   vision3     35

#define   scale1      1
#define   scale2      0.6
#define   scale3      0.4

void error_average();
float Car_PID_ERROR(PID *pid,float error,int flag);
void pid_forward_move(float error,PID *Lpid,PID *Rpid,int flag);
void init_PID();
extern PID L_PID,R_PID;
extern int flag;
Car_param car_mode[6];


#endif /* __PID_H_ */

