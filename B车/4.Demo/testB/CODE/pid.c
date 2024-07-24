#include "pid.h"

PID L_PID,R_PID;

unsigned int get_dis;
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
car_mode[5].PID_D=bridge_PID_D;
car_mode[5].PID_I=bridge_PID_I;
car_mode[5].PID_P=bridge_PID_P;
car_mode[5].speed=bridge_SPEED;

car_mode[6].PID_D=s_bend_PID_P;
car_mode[6].PID_I=s_bend_PID_I;
car_mode[6].PID_P=s_bend_PID_D;
car_mode[6].speed=s_bend_SPEED;

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
    pid->output_val = car_mode[flag].PID_P*pid->error  +   car_mode[flag].PID_D*(pid->error - pid->error_last) +   (car_mode[flag].PID_I*pid->integral/50  );

//      if(flag==1||flag==3)
//        pid->output_val-=fabsf(error)*bend_control;




    //速度限幅
    if(flag!=5)
    {
        if(pid->output_val+car_mode[flag].speed>=10000)
            pid->output_val=10000-car_mode[flag].speed;

        if(pid->output_val<=-car_mode[flag].speed)
            pid->output_val=0;
    }
    else {
        if(pid->output_val+car_mode[flag].speed>=4000)
            pid->output_val=4000-car_mode[flag].speed;

        if(pid->output_val<=-car_mode[flag].speed)
            pid->output_val=0;
    }


    //重新赋值error
    pid->error_last=pid->error;


    return pid->output_val;

}

//20
void error_average()
{
    error=(int)((94-Center_line[vision1])*scale1 + (94-Center_line[vision2])*scale2 + (94-Center_line[vision3])*scale3);
}



void pid_forward_move(float error,PID *Lpid,PID *Rpid,int flag)
{

    int i;
    // 获取TOF400C模块测量距离
    if(obstacle_flag==1)//inbridge_flag==3&&
    {

            pwm_duty(L_PWM_F, 0);//停车
            pwm_duty(R_PWM_F,0);
            Delay_Ms(300);

            pwm_duty(L_PWM_F, 0);//左转角度
            pwm_duty(R_PWM_F,6000);
            Delay_Ms(150);

            pwm_duty(L_PWM_F, 5000);//直行
            pwm_duty(R_PWM_F,5000);
            Delay_Ms(700);

//            pwm_duty(L_PWM_F, 0);//停车
//            pwm_duty(R_PWM_F,0);
//            Delay_Ms(200);

            pwm_duty(L_PWM_F, 6790);//右转角度
            pwm_duty(R_PWM_F,0);
            Delay_Ms(425);
//            pwm_duty(L_PWM_F, 0);//停车
//            pwm_duty(R_PWM_F,0);
//            Delay_Ms(200);

            pwm_duty(L_PWM_F, 5000);//直行
            pwm_duty(R_PWM_F,4850);
            Delay_Ms(500);
            Delay_Ms(550);
//            pwm_duty(L_PWM_F, 0);//停车
//            pwm_duty(R_PWM_F,0);
//            Delay_Ms(200);
            pwm_duty(L_PWM_F, 0);//左转角度
            pwm_duty(R_PWM_F,7770);
            Delay_Ms(335+obstacle_time);
//            pwm_duty(L_PWM_F, 0);//停车
//            pwm_duty(R_PWM_F,0);
//            Delay_Ms(200);
            pwm_duty(L_PWM_F, 5000);//直行
            pwm_duty(R_PWM_F,5000);
            Delay_Ms(600);



            obstacle_flag=2;
    }



    if(flag==9)
    {
        motor_forward(left, 5800);
        motor_forward(right, 5000);
    }

    else
    {
        motor_forward(left,car_mode[flag].speed+Car_PID_ERROR(Lpid,-error,flag)-1500*(inbridge_flag==3));
        motor_forward(right,car_mode[flag].speed+Car_PID_ERROR(Rpid,error,flag)-1500*(inbridge_flag==3));
    }


}






