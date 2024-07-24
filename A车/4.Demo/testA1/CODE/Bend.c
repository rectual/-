#include "Bend.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief           ������
// @param
// @return          int
//-------------------------------------------------------------------------------------------------------------------
int check_bend()
  {
      int i;
      double num=0;
      double S2=0;
      double average_x=0,total=0;


     for(i=check_bend_low_row;i<=check_bend_high_row;i++)
     {
         if((Left_line[i]==47)&&(Right_line[i]==47))   //ȫ��
         {
                 continue;
         }

         num++;

         total=total+(47-Center_line[i]);//������ƫ��
     }


     average_x=total/num;  //��ƽ��ƫ��
     total=0;

     for(i=check_bend_low_row;i<=check_bend_high_row;i++)
          {
              if((Left_line[i]==47)&&(Right_line[i]==47))
              {
                       continue;
              }

              total=total+(47-Center_line[i])*(47-Center_line[i]);//����ƫ���ƽ����

          }

          S2=(total/num)-(average_x*average_x);//���㷽��

          //ips114_show_int(200,20,(int)S2,6);

          if(S2>=check_bend_S2)
              return 1;


             return 0;


  }





//-------------------------------------------------------------------------------------------------------------------
// @brief           ��ͨ�����
// @param
// @return          void
//-------------------------------------------------------------------------------------------------------------------
void correct_bend_error()    //������
{
    int a1;

    if(Center_line[vision]>47)    //��ת
    {
        if(Right_line[vision]==93&&Right_line[vision+2]==93&&Right_line[vision+4]==93&&Right_line[vision-2]==93)  //���ֿհ�
        {

            a1=187-Left_line[58]+Left_line[vision];
//            a2=187-Left_line[117]+Left_line[vision2];
//            a3=187-Left_line[117]+Left_line[vision3];
            Center_line[vision]=(Left_line[vision]+a1)/2;
//            Center_line[vision2]=(Left_line[vision2]+a2)/2;
//            Center_line[vision3]=(Left_line[vision3]+a3)/2;

        }

    }




    else if(Center_line[vision]<47)    //��ת
     {

        if(Left_line[vision]==0&&Left_line[vision+2]==0&&Left_line[vision+4]==0&&Left_line[vision-2]==0)  //���ֿհ�
        {
            a1=Right_line[vision]-(Right_line[58] - 0);
//            a2=Right_line[vision2]-(Right_line[117] - 0);
//            a3=Right_line[vision3]-(Right_line[117] - 0);
            Center_line[vision]=(Right_line[vision]+a1)/2;
//            Center_line[vision2]=(Right_line[vision2]+a2)/2;
//            Center_line[vision3]=(Right_line[vision3]+a3)/2;

        }
     }
}


//-------------------------------------------------------------------------------------------------------------------
// @brief        �������·��
// @param        ��
// @return       void
//-------------------------------------------------------------------------------------------------------------------

int check_three()
{
    int i,j,three_flag=1;
    int num=0;
    CX = 0;
    CY = 0;
    if(num_white>=10)//&&white_line[0]==110
    {
        for(j=15;j<=75;j++)
        {
            for(i=59;i>=0;i--)
            {
                if(Pixel[i][j]==0)
                {
                    if(i>=CY)
                    {
                        CX = j;
                        CY = i;

                    }
                    else
                    {
                        three_flag = 0;

                    }
                    break;
                }
            }
            if(three_flag == 0)
            {
                break;
            }

        }
    }
//    for(j=80;j<=99;j++)
//    {
//        if(Pixel[0][j]==0)
//        {
//            num++;
//        }
//    }
    if(Abs(CX, 47)<=15&&three_flag==0)//&&num>=15
    {

        triangle_flag=1;
        return 1;
    }

    else {
        return 0;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����·�ڲ���
// @param        ��
// @return       void
//-------------------------------------------------------------------------------------------------------------------

//void correct_three(int turn_flag)
//{
//
//    int i,j;
//    double k;
//    if(triangle_flag>=1)
//    {
//
//
//        //����
//        if(turn_flag == 0)//��ת��������(����Abs��ֵ����double����)
//        {
//            k = Abs(119, CY)/Abs(187, CX);
//            for(i = CY;i<120;i++)
//            {
//                j = CX+(i-CY)/k;
//                Right_line[i] = j; //�����ұ���
//                Center_line[i] = (j+Left_line[i])/2;
//                Pixel[i][j] = 0; //��ʾ��������
//            }
//        }
//        if(turn_flag == 1)
//        {
//            k = Abs(119, CY)/Abs(CX, 0);
//            for(i = CY;i<120;i++)
//            {
//                j = CX-(i-CY)/k;
//                Left_line[i] = j; //���������
//                Center_line[i] = (j+Right_line[i])/2;
//                Pixel[i][j] = 0; //��ʾ��������
//            }
//        }
//    }
//}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ������
// @param        ��
// @return       void
//-------------------------------------------------------------------------------------------------------------------
int check_out()
{
    int row,count=0;
    for(row=59;row>=1;row--)
    {
        if((Pixel[row][47]-Pixel[row-1][47])!=0)
        {
            count++;
        }

    }
    if(count>=5)
    {
        out_flag=1;
        return 1;
    }
    else
    {
        return 0;
    }
}


//-------------------------------------------------------------------------------------------------------------------
// @brief        ��������
// @param        ��
// @return       int
//-------------------------------------------------------------------------------------------------------------------
int check_black_white_line()
{
    int i,j;
    int count=0;
    //int end_flag = 0;

    if(triangle_flag==1)//����������ʶ�������
    {
            //�Ұ����ߣ�ÿ�ҵ�һ��
        for(i = 25;i<=50;i++)
        {
               count=0;
               for(j = 0;j<94;j++)
               {
                   if ((Pixel[i][j]-Pixel[i][j+1])!=0)
                   {
                       count++;
                   }
               }
               if(count>=15)
               {
                   break;
               }
        }
        if(count>=15)
            return 1;
        else {
            return 0;
        }

    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ⵥ����
// @param        ��
// @return       int
//-------------------------------------------------------------------------------------------------------------------
//int check_bridge()
//{
//    int i,j,count=0;
//    int num=0;
//
//    for(i=22;i<=67;i++)
//    {
//        for(j = 0;j<=186;j++)
//        {
//            if((Pixel[i][j]-Pixel[i][j+1])!=0)
//            {
//                count++;
//            }
//        }
//        if(count==4)
//            num++;
//    }
//    if(num>=40)
//    {
//        for(i=10;i<=90;i++)
//        {
//            if((Center_line[i]-Center_line[i+1])>=5)
//            {}
//        }
//    }
//
//
//}
//-------------------------------------------------------------------------------------------------------------------
// @brief        ����·����
// @param        ��
// @return       void
//-------------------------------------------------------------------------------------------------------------------
void road_type()
{


     if(check_three())//�ж������жϵ���triangle��һ��
     {
        if ( flagLED == 0 ){
            flagLED = 101;
        }

        //correct_three(triangle_turn);//���߳���ͨ���

        flag=5;
    }

    else if(check_black_white_line())
    {
        flag=6;
    }


    else if(check_bend()) //�ж���ͨ���
    {
        flag=1;
    }
    else         //ֱ��
    {
        flag=0;
    }


}













