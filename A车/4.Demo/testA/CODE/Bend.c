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
         if((Left_line[i]==94)&&(Right_line[i]==94))   //ȫ��
         {
                 continue;
         }

         num++;

         total=total+(94-Center_line[i]);//������ƫ��
     }


     average_x=total/num;  //��ƽ��ƫ��
     total=0;

     for(i=check_bend_low_row;i<=check_bend_high_row;i++)
          {
              if((Left_line[i]==94)&&(Right_line[i]==94))
              {
                       continue;
              }

              total=total+(94-Center_line[i])*(94-Center_line[i]);//����ƫ���ƽ����

          }

          S2=(total/num)-(average_x*average_x);//���㷽��

          //ips114_show_int(200,20,(int)S2,6);

          if(S2>=check_bend_S2)
              return 1;


             return 0;


  }


//-------------------------------------------------------------------------------------------------------------------
// @brief           ���ֱ�������ͼ������������һ������λ��60-120֮�䣩
// @param
// @return          int
//-------------------------------------------------------------------------------------------------------------------
int check_rightangle_bend()
{
    int i,j,line=0;
     int count = 0;


     //��������յ�

    for (j = 0; j <=187;j++)
    {
        for(i = 119;i>=0;i--)
        {
            if (Pixel[i][j]==0)
            {
                if((i>=60&&i<120))
                {
                    count++;
                }

                break;
            }

        }
    }
    if(count>=180)
    {

        return 1;
    }

    //Ѱ����յ�
    else
    {
        for(i=119;i>=0;i--)
        {
            if(Abs(Right_line[i-1], Right_line[i])>=5)
            {
                line = i;
                break;
            }
        }
        if(line>=5&&line<=60&&Right_line[line]>=94&&Left_line[line+15]==0)
        {
            count = 0;

            for (j = Right_line[line]; j>=0;--j)
               {
                   for(i = line+5;i>=0;i--)
                   {
                       if (Pixel[i][j]==0&&Abs(line, i)<=5)
                       {
                           count++;

                           break;
                       }

                   }
               }
            if(count>=(Right_line[line]-5))
            {
                return 2;//ֱ��
            }
        }
        else if((line>=60&&Right_line[line]>=100)&&Left_line[line+5]==0)
        {
            count = 0;
            i = line - 5;
            for(j = 0;j<188;j++)
            {

                if(Pixel[i][j]==0)
                    count++;
            }
            if(count>=170)
            {

                 return 1;
            }
            else
            {
                return 0;
            }

        }
        else
        {
            return 0;
        }

    }

}


//-------------------------------------------------------------------------------------------------------------------
// @brief           ֱ�������
// @param
// @return          void
//-------------------------------------------------------------------------------------------------------------------
void correct_rightangle_bend()
{
    int a1,a2,a3;
    flag = 4;

    a1=187-Left_line[117]+Left_line[vision];
    a2=187-Left_line[117]+Left_line[vision2];
    a3=187-Left_line[117]+Left_line[vision3];

    Center_line[vision]=(Left_line[vision]+a1)/2+80;
    Center_line[vision2]=(Left_line[vision]+a2)/2+40;
    Center_line[vision3]=(Left_line[vision]+a3)/2;


}


//-------------------------------------------------------------------------------------------------------------------
// @brief           ��ͨ�����
// @param
// @return          void
//-------------------------------------------------------------------------------------------------------------------
void correct_bend_error()    //������
{
    int a1;

    if(Center_line[vision]>94)    //��ת
    {
        if(Right_line[vision]==187&&Right_line[vision+2]==187&&Right_line[vision+4]==187&&Right_line[vision-2]==187)  //���ֿհ�
        {

            a1=187-Left_line[117]+Left_line[vision];
//            a2=187-Left_line[117]+Left_line[vision2];
//            a3=187-Left_line[117]+Left_line[vision3];
            Center_line[vision]=(Left_line[vision]+a1)/2;
//            Center_line[vision2]=(Left_line[vision2]+a2)/2;
//            Center_line[vision3]=(Left_line[vision3]+a3)/2;

        }

    }




    else if(Center_line[vision]<94)    //��ת
     {

        if(Left_line[vision]==0&&Left_line[vision+2]==0&&Left_line[vision+4]==0&&Left_line[vision-2]==0)  //���ֿհ�
        {
            a1=Right_line[vision]-(Right_line[117] - 0);
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
        if(num_white>=20)//&&white_line[0]==110
        {
            for(j=30;j<=150;j++)
            {
                for(i=119;i>=0;i--)
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
    //    }
        if(Abs(CX, 94)<=30  && three_flag==0)
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

void correct_three(int turn_flag)
{

    int i,j;
    double k;
    if(triangle_flag>=1)
    {


        //����
        if(turn_flag == 0)//��ת��������(����Abs��ֵ����double����)
        {
            k = Abs(119, CY)/Abs(187, CX);
            for(i = CY;i<120;i++)
            {
                j = CX+(i-CY)/k;
                Right_line[i] = j; //�����ұ���
                Center_line[i] = (j+Left_line[i])/2;
                Pixel[i][j] = 0; //��ʾ��������
            }
        }
        if(turn_flag == 1)
        {
            k = Abs(119, CY)/Abs(CX, 0);
            for(i = CY;i<120;i++)
            {
                j = CX-(i-CY)/k;
                Left_line[i] = j; //���������
                Center_line[i] = (j+Right_line[i])/2;
                Pixel[i][j] = 0; //��ʾ��������
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ������
// @param        ��
// @return       void
//-------------------------------------------------------------------------------------------------------------------
int check_out()
{
    int row,count=0;
    for(row=119;row>=1;row--)
    {
        if((Pixel[row][94]-Pixel[row-1][94])!=0)
        {
            count++;
        }

    }
    if(count>=10)
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
        for(i = 40;i<=100;i++)
        {
               count=0;
               for(j = 0;j<187;j++)
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
int check_bridge()
{
    int i,j,count=0;
    int num=0;

    for(i=22;i<=67;i++)
    {
        for(j = 0;j<=186;j++)
        {
            if((Pixel[i][j]-Pixel[i][j+1])!=0)
            {
                count++;
            }
        }
        if(count==4)
            num++;
    }
    if(num>=40)
    {
        for(i=10;i<=90;i++)
        {
            if((Center_line[i]-Center_line[i+1])>=5)
            {}
        }
    }


}

void correct_in()
{
    int i;
    int A=0,B=0;
    double k;
    for(i=0;i<=118;i++)
    {
        if((Left_line[i]-Left_line[i+1])>=10&&Left_line[i+1]==0)
            A=i;
        if((Left_line[i]-Left_line[i+1])<=-10&&Left_line[i]==0)
        {
            B=i+1;
            break;
        }
    }
    if(A!=0&&B!=0)
    {
        k=(Right_line[B]-Left_line[A])/(B-A);
        for(i=A;i<=B;i++)
        {
            Right_line[i]=(int)((i-A)*k)+Left_line[A];
            Center_line[i]=(Left_line[i]+Right_line[i])/2;
            Pixel[i][Right_line[i]]=0;
        }
    }


}
//-------------------------------------------------------------------------------------------------------------------
// @brief        ����·����
// @param        ��
// @return       void
//-------------------------------------------------------------------------------------------------------------------
void road_type()
{
if(Cross_status==0)
{
    int rightangle;

     if(check_three()&&rightangle_flag==2 && continueflag == 0)//�ж������жϵ���triangle��һ��
     {
        if ( flagLED == 0 ){
            flagLED = 101;
        }

        correct_three(triangle_turn);//���߳���ͨ���

        flag=5;
    }

     else if(continueflag == 0 && Cross_status==0&&entered_Cross==0&&check_cross_road_out(num_white,white_line[num_white-1]))  //����Ƿ񵽴�ʮ��
     {
         flag=2;//ʮ��ֱ����־λ
         Cross_status=1;//����ʮ��״̬
     }

     else if((rightangle = check_rightangle_bend())&&rightangle_flag!=2  && flagAllow)//�ж�ֱ���䣨�жϵ���rightangle��1��
     {
         if(rightangle==2)//�쵽ֱ����
         {
             start++;
             continueflag = 1;
             flag=9;
         }


         if(rightangle==1&&(start>=1))//�ѵ�ֱ����
         {

             rightangle_flag++;//����ֱ�����
             continueflag = 0;
             flag = 4;
         }

     }
    else if(check_black_white_line() && count_tri >= 1)
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

     if(continueflag == 1){
         flag = 9;
     }
}

}
















