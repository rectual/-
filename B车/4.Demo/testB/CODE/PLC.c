/*
 * PLC.c
 *
 *  Created on: 2023��3��25��
 *  Author: heavywood
 */
#include "PLC.h"


//uart_init(UART_3,115200,UART3_TX_B10,UART3_RX_B11);
//ʹ��ǰ��ʼ��uart3
void Daimxa_Pc_Display188x120(void)
{
    //unsigned char y;
    int i=0;
    int j=0;
    uart_send_char(UART_3,0x00); //����֡ͷ��������UART�ĳ��Լ���
    uart_send_char(UART_3,0xff);//����֡ͷ
    uart_send_char(UART_3,0x01);//����֡ͷ
    uart_send_char(UART_3,0x01);//����֡ͷ
    for(i=0;i<120;i++)//����ͼ������Ϊ188X120
    {
        for(j=0;j<188;j++)
            uart_send_char(UART_3,Pixel[i][j]);//�Ҷȣ���ֵ������
    }
//--------------------��ֻ��ͼ�����������д������ɾ��--------------------
//    for(y = 0; y<120; y++)//���������
//        uart_send_char(UART_3,Left_line[y]);//�ڶ���������Ϊ����120�ֽڱ�������
//    for(y = 0; y<120; y++)//�����ұ���
//        uart_send_char(UART_3,Right_line[y]);
//    for(y = 0; y<120; y++)//��������
//        uart_send_char(UART_3,Center_line[y]);
}

