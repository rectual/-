#include "pid.h"

PID L_PID,R_PID;

int flag=0;
int distance_speedL;
int distance_speedR;

#define test_speed 4000

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

car_mode[6].PID_D=distance_PID_DF;
car_mode[6].PID_I=distance_PID_IF;
car_mode[6].PID_P=distance_PID_PF;
car_mode[6].speed=distance_SPEEDF;

car_mode[7].PID_D=distance_PID_DI;
car_mode[7].PID_I=distance_PID_II;
car_mode[7].PID_P=distance_PID_PI;
car_mode[7].speed=distance_SPEEDI;

car_mode[8].PID_D=S_PID_D;
car_mode[8].PID_I=S_PID_I;
car_mode[8].PID_P=S_PID_P;
car_mode[8].speed=S_SPEED;

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
    pid->output_val = car_mode[flag].PID_P*pid->error  +   car_mode[flag].PID_D*(pid->error - pid->error_last) +   (car_mode[flag].PID_I*pid->integral / 50  );

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
    error=(int)((94-Center_line[vision1])*scale1 + (94-Center_line[vision2])*scale2 + (94-Center_line[vision3])*scale3);
}



void pid_forward_move(float error,PID *Lpid,PID *Rpid,int flag)
{
//    if(flag == 2){
//        motor_forward(left, 5000);
//                motor_forward(right, 4500);
//                Delay_Ms(500);
//                return;
//    }
    if(flag==9)
    {
        motor_forward(left, 4900);
        motor_forward(right, 4500);
    }
    else if(flag == 1 && speedLow && flagAllow == 0){
        flag = 8;
        motor_forward(left,car_mode[flag].speed  + Car_PID_ERROR(Lpid,-error,flag));
        motor_forward(right,car_mode[flag].speed  + Car_PID_ERROR(Rpid,error,flag));
    }
    else if(count_tri != 1){

        motor_forward(left,car_mode[flag].speed  - 0 * (triangle_flag == 1) - 0 * (finalLow >= 10) - 0 * (finalLow >= 10 && flag == 0) - 1300 * (count_tri >= 2 && flag != 5) - 1350 * (rightangle_flag && count_tri < 2) + Car_PID_ERROR(Lpid,-error,flag));
        motor_forward(right,car_mode[flag].speed - 0 * (triangle_flag == 1) - 0 * (finalLow >= 10) - 0 * (finalLow >= 10 && flag == 0) - 1300 * (count_tri >= 2  && flag != 5) - 1250 * (rightangle_flag && count_tri < 2) + Car_PID_ERROR(Rpid,error,flag));

    }

    else if(flag != 5 ){
        flag = 6;
//        distance_speedL = car_mode[flag].speed - 500 * ( isTOF ) +Car_PID_ERROR(Lpid,-error,flag);
        distance_speedL = 6500;
        distance_speedR = car_mode[flag].speed  + Car_PID_ERROR(Rpid,error,flag);
        motor_forward(left, distance_speedL);
        motor_forward(right, distance_speedR);
//        ips114_show_int(200,60,count_tri,6);
//        pwm_duty(L_PWM_F, 0);
//                pwm_duty(R_PWM_F,0);
    }
    else{
        motor_forward(left,car_mode[flag].speed + Car_PID_ERROR(Lpid,-error,flag));
        motor_forward(right,car_mode[flag].speed + Car_PID_ERROR(Rpid,error,flag));
    }

}






