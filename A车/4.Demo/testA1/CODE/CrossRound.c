#include "CrossRound.h"



//-------------------------------------------------------------------------------------------------------------------
// @brief       判断是否到达十字路口
// @param       numl:白线总行数
// @param       b:最后一行找到的白线行数
// @return
//-------------------------------------------------------------------------------------------------------------------

int check_cross_road_out(int num1,int b)   //判断十字
{
    int count=0,j,i;
    if(num1>=20)//中间出现20行白行
    {
        for (j = 187; j >=0;--j)
        {
            for(i = 119;i>=0;i--)
            {
                if (Pixel[i][j]==0&&i>=50&&i<=110)
                {
                    count++;
                    break;
                }
            }
        }
        if(count>=180)
        {
            return 0;

        }
        else
        {
            seek_vary_pot(b);    //找点
            if(Abs(L_U_dot,R_U_dot)<=20&&L_U_dot>=20&&R_U_dot>=20)
            {

                return 1;

            }
            else
               return 0;
        }
    }
    else
    {
        return 0;
    }
}




//-------------------------------------------------------------------------------------------------------------------
// @brief           找十字拐点
// @param           b:最后一行找到的白线行数
// @return          void
//-------------------------------------------------------------------------------------------------------------------
 void seek_vary_pot(int b)
{

 int i=1;

 int interval_UP=2;


 //找左下线
// for(i=1;i<110-a;i++)
// {
//     if(Left_line[a+i]!=0 && (Left_line[a+i]-Left_line[a+i+interval])<=6&&(Left_line[a+i]-Left_line[a+i+interval])>=1  &&   (Left_line[a+i]-Left_line[a+i+2*interval])<=10&&(Left_line[a+i]-Left_line[a+i+2*interval])>=2)
//     {
//         L_D_dot=a+i;
//         break;
//     }
// }
//     if(i>=110-a)
//         L_D_dot=119;
//
//
////找右下线
//     for(i=1;i<110-a;i++)
//      {
//          if(Right_line[a+i]!=187  &&  (Right_line[a+i]-Right_line[a+i+interval])>=-6&&(Right_line[a+i]-Right_line[a+i+interval])<=-1  &&  (Right_line[a+i]-Right_line[a+i+2*interval])>=-10&&(Right_line[a+i]-Right_line[a+i+2*interval])<=-2)
//          {
//              R_D_dot=a+i;
//              break;
//          }
//      }
//          if(i>=110-a)
//          R_D_dot=119;
//


 //找左上线

          for(i=1;i<b-6;i++)
           {
               if(Left_line[b-i]!=0 &&
                       (Left_line[b-i]-Left_line[b-i-interval_UP])>=-5&&(Left_line[b-i]-Left_line[b-i-interval_UP])<=5  &&
                       (Left_line[b-i]-Left_line[b-i-2*interval_UP])>=-10&&(Left_line[b-i]-Left_line[b-i-2*interval_UP])<=10&&
                       (Left_line[b-i]-Left_line[b-i-3*interval_UP])>=-15&&(Left_line[b-i]-Left_line[b-i-3*interval_UP])<=15&&
                       Abs(Left_line[b-i],Left_line[b-i+2*interval_UP])>=15)
               {
                   L_U_dot=b-i;
                   break;
               }
           }
               if(i>=b-10)
                   L_U_dot=0;




//找右上线

            for(i=1;i<b-6;i++)
               {
                  if(Right_line[b-i]!=187 &&
                          (Right_line[b-i]-Right_line[b-i-interval_UP])<=5&&(Right_line[b-i]-Right_line[b-i-interval_UP])>=-5  &&
                          (Right_line[b-i]-Right_line[b-i-2*interval_UP])<=10&&(Right_line[b-i]-Right_line[b-i-2*interval_UP])>=-10&&
                          (Right_line[b-i]-Right_line[b-i-3*interval_UP])<=15&&(Right_line[b-i]-Right_line[b-i-3*interval_UP])>=-15&&
                          Abs(Right_line[b-i],Right_line[b-i+2*interval_UP])>=15)
                    {
                      R_U_dot=b-i;
                      break;
                    }
               }
                  if(i>=b-10)
                     R_U_dot=0;




}


 //-------------------------------------------------------------------------------------------------------------------
 // @brief
 // @param
 // @return
 //-------------------------------------------------------------------------------------------------------------------
int link_Line(int V,int row,int type)  //y=bx+a      //最小二乘法拟合
 {
     int i;double a,b;
     double average_x=0,average_y=0,xy=0,xx=0;
     int x;
     int num=8;
     int d_row=0;

     if(row<=30&&Left_line[row]<=40&&type==1)   //暂时  防止左点找到噪声？？？
         return 80;

     if(row<=25&&type==2)
         return 120;



    //拟合
     if(type==1) //拟合左线
     {
        for(i=0;i<num;i++)
        {
            x=row-i;
            if(Abs(Left_line[x],Left_line[x+1])>=4)
            {
                d_row++;
                continue;
            }
            average_x+=x;
            xx+=x*x;
            average_y+=Left_line[x];
            xy+=x*Left_line[x];

        }
        num-=d_row;
        average_x=average_x/num;
        average_y=average_y/num;

        b=(xy-num*average_x*average_y)/(xx-num*average_x*average_x)+0.0;

        a=average_y-b*average_x;

        return (int)(b*V+a);


     }
     else
     {
         for(i=0;i<num;i++)
         {
             x=row-i;
             if(Abs(Right_line[x],Right_line[x+1])>=4)
            {
                  d_row++;
                 continue;
            }

             average_x+=x;
             xx+=x*x;
             average_y+=Right_line[x];
             xy+=x*Right_line[x];

        }
               num-=d_row;
               average_x=average_x/num;
               average_y=average_y/num;

               b=(xy-num*average_x*average_y)/(xx-num*average_x*average_x)+0.0;

               a=average_y-b*average_x;

               return (int)(b*V+a);

     }
 }


//-------------------------------------------------------------------------------------------------------------------
// @brief        返回两整数中较小的数
// @param        a,b
// @return       int
//-------------------------------------------------------------------------------------------------------------------
int min(int a,int b)
{
    if(a>b)
        return b;
    else {
        return a;
    }


}




//-------------------------------------------------------------------------------------------------------------------
// @brief           十字路口补线
// @param
// @return
//-------------------------------------------------------------------------------------------------------------------
void Repair_Line()
 {
    int row;
    int L,R;

    for(row=min(L_U_dot,R_U_dot);row<=119;row++)
    {

        L=link_Line(row,L_U_dot-2,1);

        R=link_Line(row,R_U_dot-2,2);

        Center_line[row]=(L+R)/2;   //求中线？？？  Center_line[row]=(L+R)/2;

        Pixel[row][L] = 0;
        Pixel[row][L] = 0;//显示补的线
    }
 }
//-------------------------------------------------------------------------------------------------------------------
// @brief               进入十字状态后的处理
// @param               无
// @return              void
//-------------------------------------------------------------------------------------------------------------------
void Cross_Round_control()   ///十字状态机
{
//十字区
   if(Cross_status>0)   //Cross_status=0不在  Cross_status=1 发现十字   Cross_status=2 完全进入十字   Cross_status=3 再发现十字
   {

       static int repair_status=1;

       if(repair_status==1)//补线
       {
           seek_vary_pot(white_line[num_white-1]);//找点


           if(Right_line[vision3-2]>=180||Left_line[vision3-2]<=10)
           Repair_Line();
           //补线


       }


       if(Cross_status==1&&repair_status==1&&num_white<=1)  //完全进入 结束补线
       {
           repair_status=0;
           Cross_status++;
       }



       if(Cross_status==2) //完全进入
       {
           if(check_bend()) //弯道
           {
               flag=3;
           }

           else         //直线
           {
               flag=2;
           }


           if(Cross_status!=3&&check_cross_road_out(num_white,white_line[num_white-1])) //再次发现十字
           {
               Cross_status=3;
               repair_status=1;     //开始补线
               flag=2;
           }
       }

       if(Cross_status==3)
       {
           if(num_white<=1)
            {
               entered_Cross=1;
               Cross_status=0;    //结束十字
            }
       }
   }
}







