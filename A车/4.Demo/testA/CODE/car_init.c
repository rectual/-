/*********************************************************************************************************************
* @file            car_init.c
* @author          Andreas HF
* @Target core     CH32V307VCT6
* @revisions       2022.09.07, V1.0
* @modify          none
********************************************************************************************************************/

#include "car_init.h"
#include "headfile.h"
#include <stdlib.h>

//-------------------------------------------------------------------------------------------------------------------
// @brief        ������pwm��ʼ��
// @param        void
// @return       void
// Sample usage:        car_init();
                        //���ܳ���ʼ��
//-------------------------------------------------------------------------------------------------------------------

void car_init()
{
//    DisableGlobalIRQ();                                         //Ĭ�Ϲ������ж�
    board_init();
        Delay_Init();

        /* ��ʼ����� */
        motor_init(left);
        motor_init(right);

        /* ��ʼ������ */
        key_init(K1);
        key_init(K2);
        key_init(K3);
        key_init(K4);
        key_init(K5);
        key_init(K6);

        adc_init(ADC_IN2_A2);
        adc_init(ADC_IN3_A3);
        adc_init(ADC_IN4_A4);
        adc_init(ADC_IN5_A5);
        adc_init(ADC_IN6_A6);

        /* ��ʼ������LED */
        board_led_init(LED1);
        board_led_init(LED2);
    //
    //    /* ��ʼ��RGB���� */
        ws2812b_init();

        /* ��ʼ���ɻɹ� */
        reed_init();

        /* ��ʼ���ж� */
        int_init();
        interrupt_global_enable();

    int n = 8,m = 8;        //�ֱ�Ϊ���ƺ���Ƶĳ���֡��
    flagLED = 0;

    arrays = (int*) malloc (sizeof(int) * (n + m) * 3 - m + 1 + 1 + 1);        //����+1�ֱ�Ϊ��һ֡�����֡����֡
    for ( int i = 0; i < (n + m) * 3 - m + 1 + 1; i++ ){
        arrays[i] = 0;
    }
            arrays[n * 0 + m * 0] = 4;
            arrays[(n + m) * 3 - m + 1 + 1] = 3;
            arrays[n * 0 + m * 0 + 1] = 1;
            arrays[n * 1 + m * 0 + 1] = 2;
            arrays[n * 1 + m * 1 + 1] = 1;
            arrays[n * 2 + m * 1 + 1] = 2;
            arrays[n * 2 + m * 2 + 1] = 1;
            arrays[n * 3 + m * 2 + 1] = 2;


            TIM_init();

}

//-------------------------------------------------------------------------------------------------------------------
// @brief        �жϳ�ʼ��
// @param        void
// @return       void
// Sample usage:        int_init();//�жϳ�ʼ��
//-------------------------------------------------------------------------------------------------------------------
void int_init(void)
{
    ;
}


void TIM_init(void)
{
    //��ʱ����ʼ��
    //TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);  //����TIM1�ﵽarr���Զ�װ��ֵ��ʱ�����ж�

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);        //����TIM1ʱ��

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //  ѡ����ȷ���ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    //TIM1������APB1Ƶ��Ϊ144MHz//503
    TIM_TimeBaseStructure.TIM_Period =797- 1;            //�Զ�װ��ֵ������ֵ�Ǽ�ʱ����0���������ж�
    //144MHz / 144 = 1MHz ÿ����������800�²Ŷ�
    TIM_TimeBaseStructure.TIM_Prescaler = 144 - 1;                //Ԥ��Ƶֵ�����ȷ�ƵΪCK_PSC
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // ����Ϊ���ϼ���ģʽ
    TIM_TimeBaseStructure.TIM_RepetitionCounter=0;              //��������������ж�
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // ʱ�ӷ�Ƶ���ã�������Ϊ����Ƶ����CK_PSC��ΪCK_INT
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
    /* �˴���д�������еĴ���(���磺��ʼ�������) */

    TIM_Cmd(TIM1, DISABLE);                 //�ر�TIM1ʱ��

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);        //����TIM8ʱ��

    NVIC_InitTypeDef NVIC_InitStructure1;
    NVIC_InitStructure1.NVIC_IRQChannel = TIM8_UP_IRQn;  //  ѡ����ȷ���ж�ͨ��
    NVIC_InitStructure1.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure1.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure1.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure1);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure1;
    //TIM1������APB1Ƶ��Ϊ144MHz
    TIM_TimeBaseStructure1.TIM_Period = 10000 - 1;            //�Զ�װ��ֵ������ֵ�Ǽ�ʱ����0���������ж�
    //144MHz / 144 = 1MHz ÿ����������800�²Ŷ�
    TIM_TimeBaseStructure1.TIM_Prescaler = 1440 - 1;                //Ԥ��Ƶֵ�����ȷ�ƵΪCK_PSC
    TIM_TimeBaseStructure1.TIM_CounterMode = TIM_CounterMode_Up; // ����Ϊ���ϼ���ģʽ
    TIM_TimeBaseStructure1.TIM_RepetitionCounter=0;              //��������������ж�
    TIM_TimeBaseStructure1.TIM_ClockDivision = TIM_CKD_DIV1; // ʱ�ӷ�Ƶ���ã�������Ϊ����Ƶ����CK_PSC��ΪCK_INT
    TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure1);
    TIM_ITConfig(TIM8, TIM_IT_Update, ENABLE);
    /* �˴���д�������еĴ���(���磺��ʼ�������) */

    TIM_Cmd(TIM8, DISABLE);                 //�ر�TIM8ʱ��
    car_both_rgb_off();
}



