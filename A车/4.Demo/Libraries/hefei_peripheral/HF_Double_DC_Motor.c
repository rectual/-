/*********************************************************************************************************************
* @file            HF_L9110S_2.c
* @author
* @version         1.0
* @Target core     CH32V307VCT6
* @date            20220905
********************************************************************************************************************/

#include <HF_Double_DC_Motor.h>
#include "headfile.h"
int count_tri = 0;
int can_turn = 1;
int countAllow = 0;
int finalLow = 0;
int countFlagcross = 0;
//-------------------------------------------------------------------------------------------------------------------
// @brief        PWM��ʼ��
// @param        object            ���ƶ���
// @return       void
// Sample usage:        motor_init(left);
                        //��ʼ������PWM
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
// @brief        ���Ƶ����ת
// @param        object            ���ƶ���
// @param        value             PWMռ�ձ�(0-10000)
// @return       void
// Sample usage:        motor_forward(right, 10000);
                        //�ҵ��������ת(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void motor_forward(left_or_right object, uint16 value)
{
    if(flag != 6 && count_tri != 1 && value > minusSpeed * 250){
        value -= minusSpeed * 250;
    }
    if (value >= 9800)
        value = 9800;

    if(flag == 3){
        countAllow = 1;
    }

    if(countAllow && flag == 0){
        countAllow++;
    }
    else if(countAllow > 1) countAllow--;

    if(countAllow >= 20){
        flagAllow = 1;
    }

    if(flag == 3)   countFlagcross++;
    else if(countFlagcross <= 100 ) countFlagcross = 0;
    else    speedLow = 1;

    if(count_tri == 3){
        finalLow++;
    }

//    if(flag == 5){
//        pwm_duty(L_PWM_F, 0);
//        pwm_duty(R_PWM_F,0);
//        while(1);
//        Delay_Ms(100);
//    }

    if (flag == 5 && ( count_tri == 0 || count_tri == 2) ){
            count_tri++;
            TIM_Cmd(TIM8,ENABLE);
        }
        if(count_tri == 1 ){
            more_count_tri++;
            if( more_count_tri >= 80 && isTOF == 0){ isTOF++; can_turn++; }
        }
        if(flag == 2 && Cross_status != 2 && Cross_status != 3 && crossDelay){
            pwm_duty(L_PWM_F, 4500);
            pwm_duty(R_PWM_F, 4800);
            Delay_Ms(30);
            return;
        }


//    if(flag == 5 && can_turn){
//            pwm_duty(L_PWM_F, 4000);
//            pwm_duty(R_PWM_F, 3600);
//            Delay_Ms(120 - 80 * ( count_tri >= 2 ));
//            pwm_duty(L_PWM_F, 0);
//            pwm_duty(R_PWM_F, 0);
//            Delay_Ms(100);
//            can_turn--;
//            pwm_duty(R_PWM_F, 3100 - 3100 * (triangle_turn == 1));
//            pwm_duty(L_PWM_F, 3500 - 3500 * (triangle_turn == 0));
//            Delay_Ms(120);
//        }

    if(object == left)
    {
        pwm_duty(L_PWM_F, value);
//        ips114_show_int(200,100,value,6);
        pwm_duty(L_PWM_B, 0);
        return;
    }


    else if(object == right)
    {

        if(flag==4) //ֱ����
        {

            pwm_duty(L_PWM_F, 0);
            pwm_duty(R_PWM_F,0);
           // Delay_Ms(100);
            pwm_duty(L_PWM_F, 0);
            pwm_duty(L_PWM_B, 3000);//���ֵ����ת
            pwm_duty(R_PWM_F, 3000);
            pwm_duty(R_PWM_B, 0);//���ֵ����ת
            Delay_Ms(520);


            pwm_duty(L_PWM_B, 0);
            pwm_duty(R_PWM_F,0);


            //while(1);

        }

        pwm_duty(R_PWM_F, value);
//        ips114_show_int(200,120,value,6);
        pwm_duty(R_PWM_B, 0);

    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���Ƶ����ת
// @param        object            ���ƶ���
// @param        value             PWMռ�ձ�(0-10000)
// @return       void
// Sample usage:        motor_back(left, 10000)��
                        //�������ٷ�ת(10000/10000)
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


