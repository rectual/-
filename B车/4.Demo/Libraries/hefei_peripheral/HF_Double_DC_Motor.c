/*********************************************************************************************************************
* @file            HF_L9110S_2.c
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#include <HF_Double_DC_Motor.h>
#include "headfile.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        PWM初始化
// @param        object            控制对象
// @return       void
// Sample usage:        motor_init(left);
                        //初始化左电机PWM
//-------------------------------------------------------------------------------------------------------------------
void motor_init(left_or_right object)
{
    if(object == left)
    {
        pwm_init(L_PWM_F, 180000, 0, TIM_OCPreload_Enable);
        pwm_init(L_PWM_B, 180000, 0, TIM_OCPreload_Enable);
    }

    else if(object == right)
    {
        pwm_init(R_PWM_F, 180000, 0, TIM_OCPreload_Disable);
        pwm_init(R_PWM_B, 180000, 0, TIM_OCPreload_Disable);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        控制电机正转
// @param        object            控制对象
// @param        value             PWM占空比(0-10000)
// @return       void
// Sample usage:        motor_forward(right, 10000);
                        //右电机满速正转(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void motor_forward(left_or_right object, uint16 value)
{
    if (value >= 9800)
        value = 9800;

    if ( flagLED != 0 ){
              if ( arrays[flagLED - 100] == 1 ){
                  if(triangle_turn==0)
                      car_yellow_left();
                  if(triangle_turn==1)
                      car_yellow_right();
              }
              else if ( arrays[flagLED - 100] == 2 ){
                  car_both_rgb_off();
              }
              else if ( arrays[flagLED - 100] == 3){
                  flagLED = -1;
              }
              flagLED++;
          }

    if(object == left)
    {

        pwm_duty(L_PWM_F, value);
        ips114_show_int(200,100,value,6);
        pwm_duty(L_PWM_B, 0);

    }


    else if(object == right)
    {


//        if(inbridge_flag==2)
//        {
//            pwm_duty(L_PWM_F, 3000);
//            pwm_duty(R_PWM_F, 2500);
//            Delay_Ms(500);
//            inbridge_flag=3;
//        }
        if(delay_flag==1)//单边桥
        {
            inbridge_flag=3;
//            pwm_duty(L_PWM_F, 0);
//            pwm_duty(R_PWM_F,0);
//            Delay_Ms(100);
//            pwm_duty(L_PWM_F, 4000);
//            pwm_duty(R_PWM_F, 0);
//            Delay_Ms(280);
//            pwm_duty(L_PWM_F, 5000);
//            pwm_duty(R_PWM_F, 4850);
//            Delay_Ms(100+bridge_error);
//
//            pwm_duty(L_PWM_F, 0);
//            pwm_duty(R_PWM_F, 3800);
//            Delay_Ms(310);
//
//
//            pwm_duty(L_PWM_F, 5100);
//            pwm_duty(R_PWM_F, 4850);
//            Delay_Ms(1100);


            pwm_duty(L_PWM_F, 0);
            pwm_duty(R_PWM_F,0);
            Delay_Ms(100);
            pwm_duty(L_PWM_F, 5500);
            pwm_duty(R_PWM_F,4000);
            Delay_Ms(300+bridge_error);
            pwm_duty(L_PWM_F, 3000);
            pwm_duty(R_PWM_F,5000);
            Delay_Ms(315);

//            pwm_duty(L_PWM_F, 0);
//            pwm_duty(R_PWM_F,0);
//            Delay_Ms(100);
//            while(1);
            pwm_duty(L_PWM_F, 5160);
            pwm_duty(R_PWM_F,4500);
            Delay_Ms(700);




            delay_flag=0;
        }
        if(flag==4) //直角弯
        {

            pwm_duty(L_PWM_F, 0);
            pwm_duty(R_PWM_F,0);
            //Delay_Ms(100);
            pwm_duty(R_PWM_F, 0);
            pwm_duty(R_PWM_B, 2500);//左轮电机反转
            pwm_duty(L_PWM_F, 2500);
            pwm_duty(L_PWM_B, 0);
            Delay_Ms(650);
            return;
        }

        pwm_duty(R_PWM_F, value);
        ips114_show_int(200,120,value,6);
        pwm_duty(R_PWM_B, 0);


    }


}

//-------------------------------------------------------------------------------------------------------------------
// @brief        控制电机反转
// @param        object            控制对象
// @param        value             PWM占空比(0-10000)
// @return       void
// Sample usage:        motor_back(left, 10000)；
                        //左电机满速反转(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void motor_back(left_or_right object, uint16 value)
{
    if(object == left)
    {
        pwm_duty(L_PWM_F, 0);
        pwm_duty(L_PWM_B, value);
    }

    else if(object == right)
    {
        pwm_duty(R_PWM_F, 0);
        pwm_duty(R_PWM_B, value);
    }
}


