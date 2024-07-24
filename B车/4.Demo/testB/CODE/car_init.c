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
    interrupt_global_disable();
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

    /* ��ʼ��RGB���� */
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



