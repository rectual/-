/*********************************************************************************************************************
* @file            main.c
* @brief           摄像头图像屏幕显示例程
* @author          L
* @version         1.0
* @Target core     CH32V307VCT6
* @date            
*
********************************************************************************************************************/

/* 用户头文件 */
#include "main.h"
#include "headfile.h"
#include "pid.h"
/* 全局变量声明 */

/*********************************************************************

/*屏幕显示数据
 * 200 0 赛道元素标志位 0:直道 1：弯道 2：十字直道 3：十字弯道
 * 200 20 弯道方差
 * 200 40 94-center[vision]
 * 200cx 60 tof测距
 * 200 80 调试直角弯
 * 200 100 左轮转速
 * 200 120 右轮转速
 */

//B车代码（出库，单边桥，直角弯，避障，十字）

// CH9143蓝牙模块串口号
#define CH9143_UART             UART_6
// CH9143蓝牙模块波特率
#define CH9143_UART_BAUD        115200
// CH9143蓝牙模块TXD引脚
#define CH9143_UART_TX_PIN      UART6_TX_C0
// CH9143蓝牙模块RXD引脚
#define CH9143_UART_RX_PIN      UART6_RX_C1
/* 主函数 */
int main(void)
{


    /* 此处声明需要用到的局部变量 */
    /* 智能车初始化 */
    car_init();
    init_PID();
    /* 此处编写单次运行的代码(例如：初始化代码等) */
    ips114_init();     //初始化屏幕
    // 初始化TOF400C测距模块
//    Init_TOF400C();



    ips114_show_string(0,0,"CAM-IPS");
    ips114_show_string(0,20,"DEMO");
    //uart_init(UART_3,115200,UART3_TX_B10,UART3_RX_B11);
    // 初始化CH9143蓝牙模块
    uart_init(CH9143_UART,CH9143_UART_BAUD,CH9143_UART_TX_PIN,CH9143_UART_RX_PIN);
    // 开启串口接收中断
    uart_interrupt_init(CH9143_UART,ENABLE,UARTINT_RX);

    mt9v03x_init_dvp();

    Delay_Ms(100);
    Cross_status=0;//十字状态位
    entered_Cross=0;//是否进入十字标志位
    triangle_flag = 0;//是否进入三岔
    rightangle_flag = 0;//是否进入直角弯
//    out_flag = 0;
//    black_white_first = 0;
//    black_white_flag = 0;
    car_start = 0;
    inbridge_flag=0;
    delay_flag=0;
    bridge_error=0;
    obstacle_flag=0;

    obstacle_time = 0;
    exti_enable(EXTI_Line0, C0, BOTH);
    exti_enable(EXTI_Line2, C2, BOTH);
    exti_enable(EXTI_Line3, C3, BOTH);
    exti_enable(EXTI_Line4, C4, BOTH);
    exti_enable(EXTI_Line5, C5, BOTH);

    //等待按键4,5按下，选择三岔方向
    //接收到蓝牙信号，把car_flag置为1
    while(car_start==0)
    {
        Delay_Ms(100);
    }







//    car_both_rgb_off();//尾灯熄灭
//    Delay_Ms(200);
//
//    car_both_rgb_on(red);//尾灯同时闪烁红色三次，间隔0.5s
//    Delay_Ms(500);
//    car_both_rgb_on(green);
//    Delay_Ms(500);
//    car_both_rgb_off();//尾灯熄灭
    car_start = 0;

    motor_forward(left, 5000);
    motor_forward(right, 4850);
    Delay_Ms(500);
    Delay_Ms(100);
    motor_forward(left, 0);
    motor_forward(right, 0);
    Delay_Ms(100);
    pwm_duty(L_PWM_F, 0);
    pwm_duty(L_PWM_B, 3000);//左轮电机反转
    pwm_duty(R_PWM_F, 3000);
    pwm_duty(R_PWM_B, 0);
    Delay_Ms(460);
    motor_forward(left, 4700);
    motor_forward(right, 4500);
    Delay_Ms(500);
    motor_forward(left, 0);
    motor_forward(right, 0);
    Delay_Ms(1300);

    while(1)
    {



        /* 此处编写需要循环执行的代码 */
        if(mt9v03x_finish_flag_dvp)
        {
            mt9v03x_finish_flag_dvp = 0;
            //ImageHandle(mt9v03x_image_dvp); //OSTU2Image(mt9v03x_image_dvp);
            OSTU2Image(mt9v03x_image_dvp);//阳关算法
        }

        CenterLine(Pixel[0]);
        ips114_show_gray_image(0,0,Pixel[0], MT9V03X_DVP_W, MT9V03X_DVP_H,MT9V03X_DVP_W,MT9V03X_DVP_H,0);
        //Daimxa_Pc_Display188x120();//玲珑眼上位机

        ips114_show_int(200,0,flag,6);

        ips114_show_int(200,40,94-Center_line[vision],6);


        error_average();

        //停车
        if(flag==10)
        {
            motor_forward(left, 5200);
            motor_forward(right,4850);
            Delay_Ms(850);
            motor_forward(left, 0);
            motor_forward(right, 0);
            while(1);
        }
        else
        {
            pid_forward_move(error,&L_PID,&R_PID,flag);
        }

    }
}







