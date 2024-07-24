#include "CrossRound.h"



//-------------------------------------------------------------------------------------------------------------------
// @brief       �ж��Ƿ񵽴�ʮ��·��
// @param       numl:����������
// @param       b:���һ���ҵ��İ�������
// @return
//-------------------------------------------------------------------------------------------------------------------

int check_cross_road_out(int num1,int b)   //�ж�ʮ��
{
    int count=0,j,i;
    if(num1>=20)//�м����20�а���
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
            seek_vary_pot(b);    //�ҵ�
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
// @brief           ��ʮ�ֹյ�
// @param           b:���һ���ҵ��İ�������
// @return          void
//-------------------------------------------------------------------------------------------------------------------
 void seek_vary_pot(int b)
{

 int i=1;

 int interval_UP=2;


 //��������
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
////��������
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


 //��������

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




//��������

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
int link_Line(int V,int row,int type)  //y=bx+a      //��С���˷����
 {
     int i;double a,b;
     double average_x=0,average_y=0,xy=0,xx=0;
     int x;
     int num=8;
     int d_row=0;

//     if(row<=30&&Left_line[row]<=40&&type==1)   //��ʱ  ��ֹ����ҵ�����������
//         return 80;
//
//     if(row<=25&&type==2)
//         return 120;



    //���
     if(type==1) //�������
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
// @brief        �����������н�С����
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
// @brief           ʮ��·�ڲ���
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

        Center_line[row]=(L+R)/2;   //�����ߣ�����  Center_line[row]=(L+R)/2;

        Pixel[row][L] = 0;
        Pixel[row][L] = 0;//��ʾ������
    }
 }
//-------------------------------------------------------------------------------------------------------------------
// @brief               ����ʮ��״̬��Ĵ���
// @param               ��
// @return              void
//-------------------------------------------------------------------------------------------------------------------
void Cross_Round_control()   ///ʮ��״̬��
{
//ʮ����
   if(Cross_status>0)   //Cross_status=0����  Cross_status=1 ����ʮ��   Cross_status=2 ��ȫ����ʮ��   Cross_status=3 �ٷ���ʮ��
   {

       static int repair_status=1;

       if(repair_status==1)//����
       {
           seek_vary_pot(white_line[num_white-1]);//�ҵ�


           if(Right_line[vision3-2]>=180||Left_line[vision3-2]<=10)
           Repair_Line();
           //����


       }


       if(Cross_status==1&&repair_status==1&&num_white<=1)  //��ȫ���� ��������
       {
           repair_status=0;
           Cross_status++;
       }



       if(Cross_status==2) //��ȫ����
       {
           if(check_bend()) //���
           {
               flag=3;
           }

           else         //ֱ��
           {
               flag=2;
           }


           if(Cross_status!=3&&check_cross_road_out(num_white,white_line[num_white-1])) //�ٴη���ʮ��
           {
               Cross_status=3;
               repair_status=1;     //��ʼ����
               flag=2;
           }
       }

       if(Cross_status==3)
       {
           if(num_white<=1)
            {
               entered_Cross=1;
               Cross_status=0;    //����ʮ��
            }
       }
   }
}







