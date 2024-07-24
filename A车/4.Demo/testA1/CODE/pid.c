#include "pid.h"

PID L_PID,R_PID;

int flag=0;

static void init_Car_param()
{

car_mode[0].PID_D=Straight_PID_D;
car_mode[0].PID_I=Straight_PID_I;
car_mode[0].PID_P=Straight_PID_P;
car_mode[0].speed=Straight_SPEED;

car_mode[1].PID_D=Bend_PID_D;
car_mode[1].PID_I=Bend_PID_I;
car_mode[1].PID_P=Bend_PID_P;
car_mode[1].speed=Bend_SPEED;


car_mode[2].PID_D=Cross_road_Straight_PID_D;
car_mode[2].PID_I=Cross_road_Straight_PID_I;
car_mode[2].PID_P=Cross_road_Straight_PID_P;
car_mode[2].speed=Cross_road_Straight_SPEED;

car_mode[3].PID_D=Cross_road_bend_PID_D;
car_mode[3].PID_I=Cross_road_bend_PID_I;
car_mode[3].PID_P=Cross_road_bend_PID_P;
car_mode[3].speed=Cross_road_bend_SPEED;

car_mode[4].PID_D=Straight_road_bend_PID_D;
car_mode[4].PID_I=Straight_road_bend_PID_I;
car_mode[4].PID_P=Straight_road_bend_PID_P;
car_mode[4].speed=Straight_road_bend_SPEED;

//
car_mode[5].PID_D=triangle_PID_D;
car_mode[5].PID_I=triangle_PID_I;
car_mode[5].PID_P=triangle_PID_P;
car_mode[5].speed=triangle_SPEED;



}


void init_PID()
{
    init_Car_param();
    L_PID.error=0;
    L_PID.error_last=0;
    L_PID.integral=0;
    L_PID.output_val=0;
    L_PID.target_val=0;

    R_PID.error=0;
    R_PID.error_last=0;
    R_PID.integral=0;
    R_PID.output_val=0;
    R_PID.target_val=0;
}



float Car_PID_ERROR(PID *pid,float error,int flag)
{


    pid->error=error;  //误差
    pid->integral+=pid->error;  //积分总量

    //计算输出速度
    pid->output_val = car_mode[flag].PID_P*pid->error  +   car_mode[flag].PID_D*(pid->error - pid->error_last) +   (car_mode[flag].PID_I*pid->integral  );

//      if(flag==1||flag==3)
//        pid->output_val-=fabsf(error)*bend_control;




    //速度限幅
        if(pid->output_val+car_mode[flag].speed>=10000)
            pid->output_val=10000-car_mode[flag].speed;

        if(pid->output_val<=-car_mode[flag].speed)
            pid->output_val=0;


    //重新赋值error
    pid->error_last=pid->error;


    return pid->output_val;

}


void error_average()
{
    error=(int)((47-Center_line[vision1])*scale1 + (47-Center_line[vision2])*scale2 + (47-Center_line[vision3])*scale3);
}



void pid_forward_move(float error,PID *Lpid,PID *Rpid,int flag)
{


    motor_forward(left,car_mode[flag].speed+Car_PID_ERROR(Lpid,-error,flag));
    motor_forward(right,car_mode[flag].speed+Car_PID_ERROR(Rpid,error,flag));

}






