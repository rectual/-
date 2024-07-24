/*
 * center_line.c
 *
 *  Created on: 
 *  Author: heavywood
 */
#include "center_line.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        计算两数差值的绝对值
// @param        a            第一个数字
// @param        b            第二个数字
// @return       double
//-------------------------------------------------------------------------------------------------------------------
double Abs(double a,double b){
        if(a-b<0){
                return b - a;
        }
        return a - b;
}


//-------------------------------------------------------------------------------------------------------------------
// @brief        平方根计算
// @param        value           数字
// @return       double
//-------------------------------------------------------------------------------------------------------------------
double sqrt(double value){
        double i,last=0,cur=0;
        for(i=0;i*i<value;i++);
        i--;
        do{
                last = cur;
                i = (value/i+i)/2;
                cur = i*i;
        }while(Abs(cur,last) > E);
        return i;
}



//-------------------------------------------------------------------------------------------------------------------
// @brief        寻找边线和中线
// @param        uint8 img[120][188]            图像二维数组
// @return       void
//-------------------------------------------------------------------------------------------------------------------
void CenterLine(uint8 img[120][188])
{
    white_line[0]=0;

    num_white=0;num_L=0;num_R=0;num_R_row=0;

    first1=1;WtoB_R=0;first2=1;WtoB_L=60;first3=1;
    int row,col;


    for(row = MT9V03X_DVP_H / 2 - 1; row >0; row--)
    {
        //最底下一行寻找中心点
        if(row==MT9V03X_DVP_H / 2 - 1)
        {
            //从中间向左扫线找黑点，找不到赋0
            for(col = MT9V03X_DVP_W/4; col > 0; col--)
            {
                  if(img[row][col]==0xFF && img[row][col-1]==0x00)
                  {
                      Left_line[row] = col;
                      break;
                  }
                  else
                  {
                      Left_line[row] = 0;
                  }
            }

            //从中间向右扫线找黑点，找不到赋187
            for(col = MT9V03X_DVP_W/4; col < MT9V03X_DVP_W / 2 - 1; col++)
            {
                if(img[row][col]==0xFF && img[row][col+1]==0x00)
                {
                    Right_line[row] = col;
                    break;
                }
                else
                {
                    Right_line[row] = 93;
                }
            }
        }


        //对于其他行
        else
        {
            //左右边线相差较大时
            if(Abs(Right_line[row+1],Left_line[row+1])>=4)
            {
                //取上一行的中心点迭代求中心点
                for(col=Center_line[row+1]; col > 0; col--)
                {
                    if(img[row][col]==0xFF && img[row][col-1]==0x00)
                    {
                        Left_line[row] = col;
                        break;
                    }
                    else
                    {
                        Left_line[row] = 0;
                    }
                }

                for(col=Center_line[row+1]; col < MT9V03X_DVP_W / 2 - 1; col++)
                {

                    if(img[row][col]==0xFF && img[row][col+1]==0x00)
                    {
                        Right_line[row] = col;
                        break;
                    }
                    else
                    {
                        Right_line[row] = 93;
                    }
                }
            }

            //左右边线相差较小时，将当前行左右边线全置为94
            else
            {
                Right_line[row]=47;
                Left_line[row]=47;
            }
        }


        //每寻找完一行的左右边线后
        if(Right_line[row]!=47&&Left_line[row]!=47)//如果左右边线不近（即区域不全黑）
        {
            if(Left_line[row]<=2 && Right_line[row]>=92&&row<=55&&row>=10)   //20-110行之间出现一行几乎全白，num_white加一
            {
                white_line[num_white]=row;
                num_white++;
            }

            if( (Left_line[row] == 0)&&(Right_line[row] != 93) )   //只有左边丢线，num_L加一
            {
                num_L++;
            }

            if((Left_line[row] != 0)&&(Right_line[row] == 93))  //只有右边丢线，num_R加一
            {
                if(first1==1)  //第一次找到右边丢线时，记录此行？
                {
                    num_R_row=row;
                    first1=0;
                }

                num_R++;
            }



            if(row<=58&&(Right_line[row]-Right_line[row+1]<=-2)&&first2==1&&Right_line[row+1]==83)//寻找图像右边线从丢线到有线的突变行
            {

                WtoB_R=row+1;
                first2=0;

            }

            if(row<=58&&(Left_line[row]-Left_line[row+1]>=2)&&first3==1&&Left_line[row+1]==0)//寻找图像左边线从丢线到有线的突变行
            {

                WtoB_L=row;
                first3=0;

            }

        }
        Center_line[row] = (Left_line[row] + Right_line[row])/2;//计算中心线
    }








    //未进入十字时，判断赛道类型flag:0 直道 1弯道 2十字直道4直角弯道
    road_type();

    //进入十字时，判断十字类型并补线flag:2 十字直道 3十字弯道
    //Cross_Round_control();




    //�������error
    if(flag==1)//判断出弯道
        correct_bend_error();//拟合弯道



//    显示中线
//    for (row = 0; row < 119; row++)
//    {
//
//        Pixel[row][Center_line[row]] = 0;
//    }

}























