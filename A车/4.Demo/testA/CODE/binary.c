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


uint8_t OSTUThreshold_Sun()
{
    int16_t Y;
    uint32_t Amount = 0;//��������
    int  theL1;
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

    //��ȵ�ƽ��ֵ
    theL1 = 0;
    int L1Count = 0;
    for(Y = MinValue + 1; Y < MaxValue; Y++){
        if( HistGram[Y] < HistGram[Y-1] && HistGram[Y] < HistGram[Y+1]){
            theL1 += Y;
            L1Count++;
        }
    }
    theL1 /= L1Count;

    //��gray1
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
    int L3;         //����ȡֵ

    //PA����ֱ�����
    double PA0 = 0;
    for(Y = MinValue; Y <= L2; Y++){
        if(Y<=L1)   PA0 += HistGram[Y];
        else        PA0 += HistGram[Y] * (L2 - Y)/(L2-L1);
    }
    double PA; PA =  PA0 / Amount;
    //��ma
    double ma0 = 0;
    for(Y = MinValue; Y <= L2; Y++){
        if(Y <= L1) ma0 += HistGram[Y] * Y;
        else        ma0 += HistGram[Y] * (L2 - Y)/(L2-L1) * Y;
    }
    double ma;
    ma = ma0 / PA0;

    //�����L1��L2�Ĳ���
    double PB0 = 0;
    for(Y = L1; Y <= L2; Y++){
        PB0 += (Y-L1) / (L2 - L1) * HistGram[Y];
    }

    //���������L1��L2���ֵ�mb���Ӳ���
    double mb0 = 0;
    for(Y = L1; Y <= L2; Y++){
         mb0 += (Y-L1) / (L2 - L1) * HistGram[Y] * Y;
    }
    double mb; //����
    double PB; //����

    //�����L4֮��Ĳ���
    double PC0 = 0;
    double mc0 = 0;
    for(Y = L4; Y <= MaxValue; Y++){
        PC0 += HistGram[Y];
        mc0 += HistGram[Y] * Y;
    }
    double mc; //����
    double PC; //����

    double S = 0;
    int aim = L2 + 1;    //����Ŀ��L3
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
//        PixelIntegral += HistGram[Y] * Y;//�Ҷ�ֵ����
//    }
//    SigmaB = -1;
//    for (Y = MinValue; Y < MaxValue; Y++)
//    {
//        PixelFore = PixelFore + HistGram[Y];    //ǰ�����ص���
//        PixelBack = Amount - PixelFore;         //�������ص���
//        OmegaFore = (double)PixelFore / Amount;//ǰ�����ذٷֱ�
//        OmegaBack = (double)PixelBack / Amount;//�������ذٷֱ�
//        PixelIntegralFore += HistGram[Y] * Y;  //ǰ���Ҷ�ֵ
//        PixelIntegralBack = PixelIntegral - PixelIntegralFore;//�����Ҷ�ֵ
//        MicroFore = (double)PixelIntegralFore / PixelFore;//ǰ���ҶȰٷֱ�
//        MicroBack = (double)PixelIntegralBack / PixelBack;//�����ҶȰٷֱ�
//        Sigma = OmegaFore * OmegaBack * (MicroFore - MicroBack) * (MicroFore - MicroBack);//g
//        if (Sigma > SigmaB)//����������䷽��g
//        {
//            SigmaB = Sigma;
//            Threshold = Y;
//        }
//    }
}



