/*
 * PLC.c
 *
 *  Created on: 2023年3月25日
 *  Author: heavywood
 */
#include "PLC.h"


//uart_init(UART_3,115200,UART3_TX_B10,UART3_RX_B11);
//使用前初始化uart3
void Daimxa_Pc_Display188x120(void)
{
    //unsigned char y;
    int i=0;
    int j=0;
    uart_send_char(UART_3,0x00); //发送帧头，函数、UART改成自己的
    uart_send_char(UART_3,0xff);//发送帧头
    uart_send_char(UART_3,0x01);//发送帧头
    uart_send_char(UART_3,0x01);//发送帧头
    for(i=0;i<120;i++)//发送图像，像素为188X120
    {
        for(j=0;j<188;j++)
            uart_send_char(UART_3,Pixel[i][j]);//灰度，二值化均可
    }
//--------------------若只发图像，则下面六行代码可以删除--------------------
//    for(y = 0; y<120; y++)//发送左边线
//        uart_send_char(UART_3,Left_line[y]);//第二个参数均为长度120字节边线数组
//    for(y = 0; y<120; y++)//发送右边线
//        uart_send_char(UART_3,Right_line[y]);
//    for(y = 0; y<120; y++)//发送中线
//        uart_send_char(UART_3,Center_line[y]);
}

