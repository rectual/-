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
// @brief        左右轮pwm初始化
// @param        void
// @return       void
// Sample usage:        car_init();
                        //智能车初始化
//-------------------------------------------------------------------------------------------------------------------

void car_init()
{
//    DisableGlobalIRQ();                                         //默认关所有中断
    board_init();
        Delay_Init();

        /* 初始化电机 */
        motor_init(left);
        motor_init(right);

        /* 初始化按键 */
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

        /* 初始化板载LED */
        board_led_init(LED1);
        board_led_init(LED2);
    //
    //    /* 初始化RGB引脚 */
        ws2812b_init();

        /* 初始化干簧管 */
        reed_init();

        /* 初始化中断 */
        int_init();
        interrupt_global_enable();

    int n = 8,m = 8;        //分别为亮灯和灭灯的持续帧数
    flagLED = 0;

    arrays = (int*) malloc (sizeof(int) * (n + m) * 3 - m + 1 + 1 + 1);        //三个+1分别为第一帧和清除帧和零帧
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
// @brief        中断初始化
// @param        void
// @return       void
// Sample usage:        int_init();//中断初始化
//-------------------------------------------------------------------------------------------------------------------
void int_init(void)
{
    ;
}


void TIM_init(void)
{
    //定时器初始化
    //TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);  //允许TIM1达到arr（自动装载值）时触发中断

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);        //启用TIM1时钟

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //  选择正确的中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = 20;            //自动装载值，到该值是计时器清0，并触发中断
    TIM_TimeBaseStructure.TIM_Prescaler = 36;                //预分频值，首先分频为CK_PSC，频率我猜是2万hz
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // 设置为向上计数模式
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 时钟分频设置，这里设为不分频，从CK_PSC分为CK_INT
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
    /* 此处编写单次运行的代码(例如：初始化代码等) */

    TIM_Cmd(TIM1, DISABLE);                 //开启TIM1时钟

}



