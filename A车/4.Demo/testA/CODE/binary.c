/*
 * binary.c
 *
 *  Created on: 2023年3月25日
 *  Author: heavywood
 */

#include "binary.h"

/***************************************************************
* 函数名称：void GetHistGram(uint8_t Image[Height][Width])
* 功能说明：获取图像的灰度信息
* 参数说明：图像灰度数据
* 函数返回：void
* 修改时间：
* 备 注：
***************************************************************/
void GetHistGram(uint8 Image[120][188])
{
    int X,Y;
    for (Y = 0; Y < 256; Y++)
    {
        HistGram[Y] = 0; //初始化灰度直方图（每个灰度值个数均为0）
    }
    for (Y = 0; Y < MT9V03X_DVP_H; Y++)
    {
        for (X = 0; X < MT9V03X_DVP_W; X++)
        {
            HistGram[Image[Y][X]]++; //统计每个灰度值的个数信息
        }
    }
}

/***************************************************************
* 函数名称：OSTUThreshold()
* 功能说明：OSTU法求阈值
* 参数说明：
* 函数返回：Threshold
* 修改时间：
* 备 注：
***************************************************************/
uint8_t OSTUThreshold()
{
    int16_t Y;
    uint32_t Amount = 0;//像素总数
    uint32_t PixelFore = 0;//
    uint32_t PixelIntegralFore = 0;//
    uint32_t PixelIntegral = 0;//灰度值*该灰度值个数 的总和
    int32_t PixelIntegralBack = 0;//
    int32_t PixelBack = 0;//
    double OmegaFore, OmegaBack, MicroFore, MicroBack, SigmaB, Sigma; // 类间方差;
    int16_t MinValue, MaxValue;
    uint8_t Threshold = 0;

    for (MinValue = 0; MinValue < 256 && HistGram[MinValue] == 0; MinValue++) ;        //获取最小灰度的值
    for (MaxValue = 255; MaxValue > MinValue && HistGram[MinValue] == 0; MaxValue--) ; //获取最大灰度的值

    if (MaxValue == MinValue)
    {
        return MaxValue;          // 图像中只有一个颜色
    }
    if (MinValue + 1 == MaxValue)
    {
        return MinValue;      // 图像中只有二个颜色
    }

    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        Amount += HistGram[Y];        //  像素总数
    }

    PixelIntegral = 0;
    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        PixelIntegral += HistGram[Y] * Y;//灰度值总数
    }
    SigmaB = -1;
    for (Y = MinValue; Y < MaxValue; Y++)
    {
        PixelFore = PixelFore + HistGram[Y];    //前景像素点数
        PixelBack = Amount - PixelFore;         //背景像素点数
        OmegaFore = (double)PixelFore / Amount;//前景像素百分比
        OmegaBack = (double)PixelBack / Amount;//背景像素百分比
        PixelIntegralFore += HistGram[Y] * Y;  //前景灰度值
        PixelIntegralBack = PixelIntegral - PixelIntegralFore;//背景灰度值
        MicroFore = (double)PixelIntegralFore / PixelFore;//前景灰度百分比
        MicroBack = (double)PixelIntegralBack / PixelBack;//背景灰度百分比
        Sigma = OmegaFore * OmegaBack * (MicroFore - MicroBack) * (MicroFore - MicroBack);//g
        if (Sigma > SigmaB)//遍历最大的类间方差g
        {
            SigmaB = Sigma;
            Threshold = Y;
        }
    }
    return Threshold;
}

//int otsuThreshold(uint8 data[120][188], uint16 width, uint16 height)
//{
//    #define GrayScale 256
//    int pixelCount[GrayScale] = {0};                                //每个灰度值所含像素个数
//    float pixelPro[GrayScale] = {0};                                // 每个灰度值所占总像素比例
//    int Sumpix = width * height;                                    //总像素点数
//    int threshold = 0;
//
//        for(int j=0;j<height;j++)
//          {
//                        for(int i=0;i<width;i++)
//                        {
//                            data[j][i] = mt9v03x_image_dvp[j][i];
//                        }
//                    }
//
//        for(int j=0;j<height;j++)                  //灰度直方图
//          {
//                        for(int i=0;i<width;i++)
//                        {
//                            pixelCount[(int)data[j][i]]++;
//                        }
//                    }
//
//float w0=0, w1=0, u0Sum=0, u1Sum=0, u0=0, u1=0, u=0, variance=0, maxVariance = 0;
////目标像素占总图像比例w0
////背景像素占总图像比例w1
////目标平均灰度值u0    前景
////背景平均灰度值u1    背景
////总平均灰度值u
////类间方差 variance
////最大类间方差 maxVariance
//
////------------------------计算每个像素在整幅图像中的比例-----------------------------//
//for (int i = 0; i < GrayScale; i++)
//{
//   pixelPro[i] = (float)pixelCount[i] / Sumpix;
//   u += i * pixelPro[i];                                                    //总平均灰度
//}
//
//for (int i = 0; i < GrayScale; i++)     // i作为阈值 阈值从1-255遍历
//{
//   for (int j = 0; j < GrayScale; j++)    //求目标前景和背景
//   {
//      if (j <= i)   //前景部分
//      {
//         w0 += pixelPro[j];
//         u0Sum += j * pixelPro[j];
//      }
//      else   //背景部分
//      {
//          w1 += pixelPro[j];
//          u1Sum += j * pixelPro[j];
//      }
//   }
//   u0 = u0Sum / w0;
//   u1 = u1Sum / w1;
//
//   variance = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);  //类间方差计算公式
//
//   if (variance > maxVariance)   //判断是否为最大类间方差
//   {
//      maxVariance = variance;
//      threshold = i;
//   }
//}
//        return threshold;
//}





/***************************************************************
* 函数名称：BinaryImage(uint8_t Image[Height][Width])
* 功能说明：图像二值化
* 参数说明：
* 函数返回：void
* 修改时间：
* 备 注：
***************************************************************/
void BinaryImage(uint8 Image[120][188])
{

    int i = 0, j = 0;
    for(i = 0;i < MT9V03X_DVP_H;i++)
    {

        for(j = 0; j< MT9V03X_DVP_W;j++)
        {
            Pixel[i][j]=Image[i][j];
            if(Pixel[i][j] >= Threshold)
            {
                Pixel[i][j] = 255;
            }
            else
            {
                Pixel[i][j] = 0;
            }
        }
    }
}
/*************************************************************************
 *  函数名称：Bin_Image_Filter()
 *  功能说明：过滤噪点
 *  参数说明：无
 *  函数返回：无
 *  备    注：
*************************************************************************/

void Bin_Image_Filter()
{
    uint nr; //行
    uint nc; //列

    for (nr = 1; nr < 119; nr++)
    {
        for (nc = 1; nc < 187; nc++)
        {
            if ((Pixel[nr][nc] == 0)
                    && (Pixel[nr - 1][nc] + Pixel[nr + 1][nc] + Pixel[nr][nc + 1] + Pixel[nr][nc - 1] > 510))
            {
                Pixel[nr][nc] = 255;
            }
            else if ((Pixel[nr][nc] == 255)
                    && (Pixel[nr - 1][nc] + Pixel[nr + 1][nc] + Pixel[nr][nc + 1] + Pixel[nr][nc - 1] < 510))
            {
                Pixel[nr][nc] = 0;
            }
        }
    }
}











/***************************************************************
* 函数名称：OSTU2Image(uint8 Image[120][188])
* 功能说明：两次利用大津法求阈值
* 参数说明：
* 函数返回：void
* 修改时间：
* 备 注：
***************************************************************/
void OSTU2Image(uint8 Image[120][188])
{

    int i = 0, j = 0;
    GetHistGram(Image);//获取原始灰度图像像素点的灰度直方图
    Threshold = OSTUThreshold();//大津法求阈值（多峰灰度直方图）
    //小于阈值置为阈值，大于阈值不变
    for(i = 0;i < MT9V03X_DVP_H;i++)
    {

        for(j = 0; j< MT9V03X_DVP_W;j++)
        {
            Pixel[i][j]=Image[i][j];
            if(Pixel[i][j] <= Threshold)
            {
                Pixel[i][j] = Threshold;
            }
        }
    }
    GetHistGram(Pixel);//获取二次处理图像的灰度直方图
    Threshold = OSTUThreshold();//大津法求阈值（双峰灰度直方图）
    //二值化
    for(i = 0;i < MT9V03X_DVP_H;i++)
    {

        for(j = 0; j< MT9V03X_DVP_W;j++)
        {
            if(Pixel[i][j] <= Threshold)
            {
                Pixel[i][j] = 0;
            }
            else
            {
                Pixel[i][j] = 255;
            }
        }
    }
    Bin_Image_Filter();
}




/***************************************************************
* 函数名称：ImageHandle(uint8_t Image[Height][Width])
* 功能说明：图像二值化处理
* 参数说明：
* 函数返回：void
* 修改时间：
* 备 注：
***************************************************************/
void ImageHandle(uint8 Image[120][188])
{
    GetHistGram(Image); //获取灰度直方图
    Threshold = OSTUThreshold(); //大津法求阈值
    BinaryImage(Image); //二值化
    Bin_Image_Filter(); //过滤噪点
}


uint8_t OSTUThreshold_Sun()
{
    int16_t Y;
    uint32_t Amount = 0;//像素总数
    int  theL1;
    int16_t MinValue, MaxValue;
    uint8_t Threshold = 0;

    for (MinValue = 0; MinValue < 256 && HistGram[MinValue] == 0; MinValue++) ;        //获取最小灰度的值
    for (MaxValue = 255; MaxValue > MinValue && HistGram[MinValue] == 0; MaxValue--) ; //获取最大灰度的值

    if (MaxValue == MinValue)
    {
        return MaxValue;          // 图像中只有一个颜色
    }
    if (MinValue + 1 == MaxValue)
    {
        return MinValue;      // 图像中只有二个颜色
    }

    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        Amount += HistGram[Y];        //  像素总数
    }

    //求谷点平均值
    theL1 = 0;
    int L1Count = 0;
    for(Y = MinValue + 1; Y < MaxValue; Y++){
        if( HistGram[Y] < HistGram[Y-1] && HistGram[Y] < HistGram[Y+1]){
            theL1 += Y;
            L1Count++;
        }
    }
    theL1 /= L1Count;

    //求gray1
    int gray1 = HistGram[MinValue];
    for(Y = MinValue + 1; Y <= theL1; Y++){
        if(HistGram[Y] > gray1) gray1 = Y;
    }
    int gray2 = HistGram[theL1];
    for(Y = HistGram[theL1]; Y < MaxValue; Y++){
        if(HistGram[Y] > gray2) gray2 = Y;
    }

    int L1 = gray1;
    int L2 = gray1 + 20;
    int L4 = gray2;
    int L3;         //滑动取值

    //PA可以直接求出
    double PA0 = 0;
    for(Y = MinValue; Y <= L2; Y++){
        if(Y<=L1)   PA0 += HistGram[Y];
        else        PA0 += HistGram[Y] * (L2 - Y)/(L2-L1);
    }
    double PA; PA =  PA0 / Amount;
    //求ma
    double ma0 = 0;
    for(Y = MinValue; Y <= L2; Y++){
        if(Y <= L1) ma0 += HistGram[Y] * Y;
        else        ma0 += HistGram[Y] * (L2 - Y)/(L2-L1) * Y;
    }
    double ma;
    ma = ma0 / PA0;

    //先求出L1到L2的部分
    double PB0 = 0;
    for(Y = L1; Y <= L2; Y++){
        PB0 += (Y-L1) / (L2 - L1) * HistGram[Y];
    }

    //可以先求出L1到L2部分的mb分子部分
    double mb0 = 0;
    for(Y = L1; Y <= L2; Y++){
         mb0 += (Y-L1) / (L2 - L1) * HistGram[Y] * Y;
    }
    double mb; //待算
    double PB; //待算

    //先求出L4之后的部分
    double PC0 = 0;
    double mc0 = 0;
    for(Y = L4; Y <= MaxValue; Y++){
        PC0 += HistGram[Y];
        mc0 += HistGram[Y] * Y;
    }
    double mc; //待算
    double PC; //待算

    double S = 0;
    int aim = L2 + 1;    //储存目标L3
    for(L3 = L2 + 1; L3 < L4; L3++){
        PB0 += HistGram[Y];
        mb0 += HistGram[Y] * Y;
        double PB1 = PB0;
        double mb1 = mb0;
        for(Y = L3; Y < L4; Y++){
            PB1 += HistGram[Y] * (L4 - Y) / (L4 - L3);
            mb1 += HistGram[Y] * (L4 - Y) / (L4 - L3) * Y;
        }
        PB = PB1 / Amount;
        mb = mb1 / PB1;

        double PC1 = PC0;
        double mc1 = mc0;
        for(Y = L3; Y < L4; Y++){
            PC1 += HistGram[Y] * (Y - L3) / (L4 - L3);
            mc1 += HistGram[Y] * (Y - L3) / (L4 - L3) * Y;
        }

        PC = PC1 / Amount;
        mc = mc1 / PC1;

        double S1 = PA * PB * PC * (mc - mb) * (mc - ma) * (mb - ma);
        if(S1 > S){
            S = S1;
            aim = L3;
        }

    }
    return (aim + L2) / 2;


//    PixelIntegral = 0;
//    for (Y = MinValue; Y <= MaxValue; Y++)
//    {
//        PixelIntegral += HistGram[Y] * Y;//灰度值总数
//    }
//    SigmaB = -1;
//    for (Y = MinValue; Y < MaxValue; Y++)
//    {
//        PixelFore = PixelFore + HistGram[Y];    //前景像素点数
//        PixelBack = Amount - PixelFore;         //背景像素点数
//        OmegaFore = (double)PixelFore / Amount;//前景像素百分比
//        OmegaBack = (double)PixelBack / Amount;//背景像素百分比
//        PixelIntegralFore += HistGram[Y] * Y;  //前景灰度值
//        PixelIntegralBack = PixelIntegral - PixelIntegralFore;//背景灰度值
//        MicroFore = (double)PixelIntegralFore / PixelFore;//前景灰度百分比
//        MicroBack = (double)PixelIntegralBack / PixelBack;//背景灰度百分比
//        Sigma = OmegaFore * OmegaBack * (MicroFore - MicroBack) * (MicroFore - MicroBack);//g
//        if (Sigma > SigmaB)//遍历最大的类间方差g
//        {
//            SigmaB = Sigma;
//            Threshold = Y;
//        }
//    }
}



