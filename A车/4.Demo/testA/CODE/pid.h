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
#define   Straight_PID_P     45//45
#define   Straight_PID_I     0//0
#define   Straight_PID_D     30 //30

#define   Straight_SPEED     8000//7300

//弯道PID速度参数
#define   Bend_PID_P     85//70
#define   Bend_PID_I     0//
#define   Bend_PID_D     120//60


#define   Bend_SPEED     7000//6750

//S弯
#define   S_PID_P     80
#define   S_PID_I     0
#define   S_PID_D     240 //30

#define   S_SPEED     7400

//测距弯道
#define   distance_PID_PF     80
#define   distance_PID_IF     0
#define   distance_PID_DF     180 //30

#define   distance_SPEEDF     4000

//测距直道
#define   distance_PID_PI     40
#define   distance_PID_II     0
#define   distance_PID_DI     20 //30

#define   distance_SPEEDI     4000


//十字PID速度参数
//直道
#define   Cross_road_Straight_PID_P     65
#define   Cross_road_Straight_PID_I     0
#define   Cross_road_Straight_PID_D     30

#define   Cross_road_Straight_SPEED     6000

//十字弯道
#define   Cross_road_bend_PID_P     80//75
#define   Cross_road_bend_PID_I     0
#define   Cross_road_bend_PID_D     180//100

#define   Cross_road_bend_SPEED      7500
//直角弯
#define   Straight_road_bend_PID_P     75
#define   Straight_road_bend_PID_I     0
#define   Straight_road_bend_PID_D     0

#define   Straight_road_bend_SPEED     5500

//三角弯道
//#define   triangle_PID_P     180
//#define   triangle_PID_I     0
//#define   triangle_PID_D     0
//
//#define   triangle_SPEED     6000
#define   triangle_PID_P     135 //150
#define   triangle_PID_I     0
#define   triangle_PID_D     0 //100压内线 120压内线 80压内线 50怪不过来 60怪不过


#define   triangle_SPEED     4750
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


#define   vision    90



#define   vision1     90//100
#define   vision2     70//90
#define   vision3     65//85

#define   scale1      0.5
#define   scale2      0.3
#define   scale3      0.2

void error_average();
float Car_PID_ERROR(PID *pid,float error,int flag);
void pid_forward_move(float error,PID *Lpid,PID *Rpid,int flag);
void init_PID();
extern PID L_PID,R_PID;
extern int flag;
Car_param car_mode[20];


#endif /* __PID_H_ */

