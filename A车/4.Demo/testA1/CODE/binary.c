/*
 * binary.c
 *
 *  Created on: 2023��3��25��
 *  Author: heavywood
 */

#include "binary.h"

/***************************************************************
* �������ƣ�void GetHistGram(uint8_t Image[Height][Width])
* ����˵������ȡͼ��ĻҶ���Ϣ
* ����˵����ͼ��Ҷ�����
* �������أ�void
* �޸�ʱ�䣺
* �� ע��
***************************************************************/
void GetHistGram(uint8 Image[120][188])
{
    int X,Y;
    for (Y = 0; Y < 256; Y++)
    {
        HistGram[Y] = 0; //��ʼ���Ҷ�ֱ��ͼ��ÿ���Ҷ�ֵ������Ϊ0��
    }
    for (Y = 0; Y < MT9V03X_DVP_H; Y++)
    {
        for (X = 0; X < MT9V03X_DVP_W; X++)
        {
            HistGram[Image[Y][X]]++; //ͳ��ÿ���Ҷ�ֵ�ĸ�����Ϣ
        }
    }
}

/***************************************************************
* �������ƣ�OSTUThreshold()
* ����˵����OSTU������ֵ
* ����˵����
* �������أ�Threshold
* �޸�ʱ�䣺
* �� ע��
***************************************************************/
uint8_t OSTUThreshold()
{
    int16_t Y;
    uint32_t Amount = 0;//��������
    uint32_t PixelFore = 0;//
    uint32_t PixelIntegralFore = 0;//
    uint32_t PixelIntegral = 0;//�Ҷ�ֵ*�ûҶ�ֵ���� ���ܺ�
    int32_t PixelIntegralBack = 0;//
    int32_t PixelBack = 0;//
    double OmegaFore, OmegaBack, MicroFore, MicroBack, SigmaB, Sigma; // ��䷽��;
    int16_t MinValue, MaxValue;
    uint8_t Threshold = 0;

    for (MinValue = 0; MinValue < 256 && HistGram[MinValue] == 0; MinValue++) ;        //��ȡ��С�Ҷȵ�ֵ
    for (MaxValue = 255; MaxValue > MinValue && HistGram[MinValue] == 0; MaxValue--) ; //��ȡ���Ҷȵ�ֵ

    if (MaxValue == MinValue)
    {
        return MaxValue;          // ͼ����ֻ��һ����ɫ
    }
    if (MinValue + 1 == MaxValue)
    {
        return MinValue;      // ͼ����ֻ�ж�����ɫ
    }

    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        Amount += HistGram[Y];        //  ��������
    }

    PixelIntegral = 0;
    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        PixelIntegral += HistGram[Y] * Y;//�Ҷ�ֵ����
    }
    SigmaB = -1;
    for (Y = MinValue; Y < MaxValue; Y++)
    {
        PixelFore = PixelFore + HistGram[Y];    //ǰ�����ص���
        PixelBack = Amount - PixelFore;         //�������ص���
        OmegaFore = (double)PixelFore / Amount;//ǰ�����ذٷֱ�
        OmegaBack = (double)PixelBack / Amount;//�������ذٷֱ�
        PixelIntegralFore += HistGram[Y] * Y;  //ǰ���Ҷ�ֵ
        PixelIntegralBack = PixelIntegral - PixelIntegralFore;//�����Ҷ�ֵ
        MicroFore = (double)PixelIntegralFore / PixelFore;//ǰ���ҶȰٷֱ�
        MicroBack = (double)PixelIntegralBack / PixelBack;//�����ҶȰٷֱ�
        Sigma = OmegaFore * OmegaBack * (MicroFore - MicroBack) * (MicroFore - MicroBack);//g
        if (Sigma > SigmaB)//����������䷽��g
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
//    int pixelCount[GrayScale] = {0};                                //ÿ���Ҷ�ֵ�������ظ���
//    float pixelPro[GrayScale] = {0};                                // ÿ���Ҷ�ֵ��ռ�����ر���
//    int Sumpix = width * height;                                    //�����ص���
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
//        for(int j=0;j<height;j++)                  //�Ҷ�ֱ��ͼ
//          {
//                        for(int i=0;i<width;i++)
//                        {
//                            pixelCount[(int)data[j][i]]++;
//                        }
//                    }
//
//float w0=0, w1=0, u0Sum=0, u1Sum=0, u0=0, u1=0, u=0, variance=0, maxVariance = 0;
////Ŀ������ռ��ͼ�����w0
////��������ռ��ͼ�����w1
////Ŀ��ƽ���Ҷ�ֵu0    ǰ��
////����ƽ���Ҷ�ֵu1    ����
////��ƽ���Ҷ�ֵu
////��䷽�� variance
////�����䷽�� maxVariance
//
////------------------------����ÿ������������ͼ���еı���-----------------------------//
//for (int i = 0; i < GrayScale; i++)
//{
//   pixelPro[i] = (float)pixelCount[i] / Sumpix;
//   u += i * pixelPro[i];                                                    //��ƽ���Ҷ�
//}
//
//for (int i = 0; i < GrayScale; i++)     // i��Ϊ��ֵ ��ֵ��1-255����
//{
//   for (int j = 0; j < GrayScale; j++)    //��Ŀ��ǰ���ͱ���
//   {
//      if (j <= i)   //ǰ������
//      {
//         w0 += pixelPro[j];
//         u0Sum += j * pixelPro[j];
//      }
//      else   //��������
//      {
//          w1 += pixelPro[j];
//          u1Sum += j * pixelPro[j];
//      }
//   }
//   u0 = u0Sum / w0;
//   u1 = u1Sum / w1;
//
//   variance = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);  //��䷽����㹫ʽ
//
//   if (variance > maxVariance)   //�ж��Ƿ�Ϊ�����䷽��
//   {
//      maxVariance = variance;
//      threshold = i;
//   }
//}
//        return threshold;
//}





/***************************************************************
* �������ƣ�BinaryImage(uint8_t Image[Height][Width])
* ����˵����ͼ���ֵ��
* ����˵����
* �������أ�void
* �޸�ʱ�䣺
* �� ע��
***************************************************************/
void BinaryImage(uint8 Image[120][188])
{
    int i = 0, j = 0;
    for(i = 0; i < 60; i++){
        for(j = 0; j < 94; j++){
            Pixel[i][j] = 0;
        }
    }
    for(i = 0;i < 60;i++)
    {

        for(j = 0; j<94;j++)
        {

            Pixel[i][j]=Image[i*2][j*2];
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
 *  �������ƣ�Bin_Image_Filter()
 *  ����˵�����������
 *  ����˵������
 *  �������أ���
 *  ��    ע��
*************************************************************************/

void Bin_Image_Filter()
{
    uint nr; //��
    uint nc; //��

    for (nr = 1; nr < 60; nr++)
    {
        for (nc = 1; nc < 94; nc++)
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
* �������ƣ�OSTU2Image(uint8 Image[120][188])
* ����˵�����������ô������ֵ
* ����˵����
* �������أ�void
* �޸�ʱ�䣺
* �� ע��
***************************************************************/
void OSTU2Image(uint8 Image[120][188])
{

    int i = 0, j = 0;
    GetHistGram(Image);//��ȡԭʼ�Ҷ�ͼ�����ص�ĻҶ�ֱ��ͼ
    Threshold = OSTUThreshold();//�������ֵ�����Ҷ�ֱ��ͼ��
    //С����ֵ��Ϊ��ֵ��������ֵ����
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
    GetHistGram(Pixel);//��ȡ���δ���ͼ��ĻҶ�ֱ��ͼ
    Threshold = OSTUThreshold();//�������ֵ��˫��Ҷ�ֱ��ͼ��
    //��ֵ��
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
* �������ƣ�ImageHandle(uint8_t Image[Height][Width])
* ����˵����ͼ���ֵ������
* ����˵����
* �������أ�void
* �޸�ʱ�䣺
* �� ע��
***************************************************************/
void ImageHandle(uint8 Image[120][188])
{
    GetHistGram(Image); //��ȡ�Ҷ�ֱ��ͼ
    Threshold = OSTUThreshold(); //�������ֵ
    BinaryImage(Image); //��ֵ��
    Bin_Image_Filter(); //�������
}






