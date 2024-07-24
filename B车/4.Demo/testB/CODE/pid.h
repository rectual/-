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
//直线PID速度参数0
#define   Straight_PID_P     40//40
#define   Straight_PID_I     0
#define   Straight_PID_D     25//25

#define   Straight_SPEED     7500//7200



//弯道PID速度参数1
#define   Bend_PID_P     80 //97 105
#define   Bend_PID_I     0
#define   Bend_PID_D     40 //40 40


#define   Bend_SPEED     6500//6800





//十字PID速度参数
//直道2
#define   Cross_road_Straight_PID_P     40//50
#define   Cross_road_Straight_PID_I     0
#define   Cross_road_Straight_PID_D     25//25

#define   Cross_road_Straight_SPEED       7500

//弯道3
#define   Cross_road_bend_PID_P     80 //100
#define   Cross_road_bend_PID_I     0   //0
#define   Cross_road_bend_PID_D     37//37

#define   Cross_road_bend_SPEED      6800 //6700

//直角弯4
#define   Straight_road_bend_PID_P     130
#define   Straight_road_bend_PID_I     0
#define   Straight_road_bend_PID_D     55

#define   Straight_road_bend_SPEED     6000

//单边桥5
#define   bridge_PID_P     40
#define   bridge_PID_I     0
#define   bridge_PID_D     0

#define   bridge_SPEED     3000


//直角前6
#define   s_bend_PID_P  105
#define   s_bend_PID_I  0
#define   s_bend_PID_D  40

#define   s_bend_SPEED  6500



//7


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



#define   vision1     85 //90 80
#define   vision2     70 //80 70
#define   vision3     65 //75 65

#define   scale1      0.5 //0.5
#define   scale2      0.3 //0.3
#define   scale3      0.2 //0.2

void error_average();
float Car_PID_ERROR(PID *pid,float error,int flag);
void pid_forward_move(float error,PID *Lpid,PID *Rpid,int flag);
void init_PID();
extern PID L_PID,R_PID;
extern int flag;
Car_param car_mode[7];


#endif /* __PID_H_ */

