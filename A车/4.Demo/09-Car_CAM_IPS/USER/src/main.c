/*********************************************************************************************************************
* @file            main.c
* @brief           摄像头图像屏幕显示例程
* @author          lemon
* @version         1.0
* @Target core     CH32V307VCT6
* @date            2022-3-2
*
********************************************************************************************************************/

/* 用户头文件 */
#include "main.h"
#include "headfile.h"

/* 全局变量声明 */


/* 主函数 */
int main(void)
{
    /* 此处声明需要用到的局部变量 */

    /* 智能车初始化 */
    car_init();

    /* 此处编写单次运行的代码(例如：初始化代码等) */
    ips114_init();     //初始化屏幕
    ips114_show_string(0,0,"CAM-IPS");
    ips114_show_string(0,20,"DEMO");
    mt9v03x_init_dvp();

    Delay_Ms(100);

    while(1)
    {
        /* 此处编写需要循环执行的代码 */
        if(mt9v03x_finish_flag_dvp)
        {
            mt9v03x_finish_flag_dvp = 0;
            // 根据原始图像大小,显示原始图像
            ips114_displayimage032(mt9v03x_image_dvp[0], MT9V03X_DVP_W, MT9V03X_DVP_H);
        }
    }
}





