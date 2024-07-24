#include "Bend.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief           检测弯道
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
         if((Left_line[i]==94)&&(Right_line[i]==94))   //全黑
         {
                 continue;
         }

         num++;

         total=total+(94-Center_line[i]);//计算总偏差
     }


     average_x=total/num;  //求平均偏差
     total=0;

     for(i=check_bend_low_row;i<=check_bend_high_row;i++)
          {
              if((Left_line[i]==94)&&(Right_line[i]==94))
              {
                       continue;
              }

              total=total+(94-Center_line[i])*(94-Center_line[i]);//计算偏差的平方和

          }

          S2=(total/num)-(average_x*average_x);//计算方差

          //ips114_show_int(200,20,(int)S2,6);

          if(S2>=check_bend_S2)
              return 1;


             return 0;


  }


//-------------------------------------------------------------------------------------------------------------------
// @brief           检测直角弯道（图像特征：上面一条黑线位于60-120之间）
// @param
// @return          int
//-------------------------------------------------------------------------------------------------------------------
int check_rightangle_bend()
{
    int i,j,line=0;
     int count = 0;


     //上面无左拐点

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

    //寻找左拐点
    else
    {
        for(i=119;i>=0;i--)
        {
            if(Abs(Left_line[i-1], Left_line[i])>=5)
            {
                line = i;
                break;
            }
        }
        if(line>=10&&line<=60&&Left_line[line]<=94&&Right_line[line+15]==187)
        {
            count = 0;

            for (j = Left_line[line]; j <188;++j)
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
            if(count>=(187-Left_line[line]-5))
            {
                return 2;//直行
            }
        }
        else if((line>=60&&Left_line[line]<=80)&&Right_line[line+5]==187)
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
// @brief           直角弯拟合
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
// @brief           普通弯拟合
// @param
// @return          void
//-------------------------------------------------------------------------------------------------------------------
void correct_bend_error()    //弯道拟合
{
    int a1;

    if(Center_line[vision]>94)    //右转
    {
        if(Right_line[vision]==187&&Right_line[vision+2]==187&&Right_line[vision+4]==187&&Right_line[vision-2]==187)  //出现空白
        {

            a1=187-Left_line[117]+Left_line[vision];
//            a2=187-Left_line[117]+Left_line[vision2];
//            a3=187-Left_line[117]+Left_line[vision3];
            Center_line[vision]=(Left_line[vision]+a1)/2;
//            Center_line[vision2]=(Left_line[vision2]+a2)/2;
//            Center_line[vision3]=(Left_line[vision3]+a3)/2;

        }

    }




    else if(Center_line[vision]<94)    //左转
     {

        if(Left_line[vision]==0&&Left_line[vision+2]==0&&Left_line[vision+4]==0&&Left_line[vision-2]==0)  //出现空白
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
// @brief        检测三岔路口
// @param        无
// @return       void
//-------------------------------------------------------------------------------------------------------------------

int check_three()
{
    int i,j,three_flag=1;
    int num=0;
    CX = 0;
    CY = 0;
    if(num_white>=30&&white_line[0]==110)
    {
        for(j=30;j<=150;j++)
        {
            for(i=119;i>=0;i--)
            {
                if(Pixel[i][j]==0&&i>=CY)
                {
                    CX = j;
                    CY = i;
                    break;
                }
                if(Pixel[i][j]==0&&i<CY)
                {
                    three_flag = 0;
                    break;
                }


            }
            if(three_flag == 0)
            {
                break;
            }

        }
    }
    for(j=80;j<=99;j++)
    {
        if(Pixel[0][j]==0)
        {
            num++;
        }
    }
    if(Abs(CX, 94)<=30&&num>=15)
    {

        triangle_flag ++;
        return 1;
    }

    else {
        return 0;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        三岔路口补线
// @param        无
// @return       void
//-------------------------------------------------------------------------------------------------------------------

void correct_three(int turn_flag)
{

    int i,j;
    double k;
    if(triangle_flag>=1)
    {


        //补线
        if(turn_flag == 0)//左转，补右线(传入Abs的值不是double类型)
        {
            k = Abs(119, CY)/Abs(187, CX);
            for(i = CY;i<120;i++)
            {
                j = CX+(i-CY)/k;
                Right_line[i] = j; //更改右边线
                Center_line[i] = (j+Left_line[i])/2;
                Pixel[i][j] = 0; //显示补的右线
            }
        }
        if(turn_flag == 1)
        {
            k = Abs(119, CY)/Abs(CX, 0);
            for(i = CY;i<120;i++)
            {
                j = CX-(i-CY)/k;
                Left_line[i] = j; //更改左边线
                Center_line[i] = (j+Right_line[i])/2;
                Pixel[i][j] = 0; //显示补的左线
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        检测出库
// @param        无
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
// @brief        检测斑马线
// @param        无
// @return       int
//-------------------------------------------------------------------------------------------------------------------
int check_black_white_line()
{
    int i,j;
    int count=0;
    //int end_flag = 0;

    //从第三十行到最低下一行巡线，找斑马线，每找到一次，black_white_first加一
    for(i = 50;i<=100;i++)
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
               black_white_first++;
               break;
           }
    }



    if(count>=15)
        return 1;
    else {
        return 0;
    }


}

//-------------------------------------------------------------------------------------------------------------------
// @brief        检测单边桥
// @param        无
// @return       int
//-------------------------------------------------------------------------------------------------------------------
int check_bridge()
{
    int i,j,count=0;
    int flag1=0,flag2=0;
    int num=0;

    line1=0;
    line2=0;
    if(inbridge_flag==0)//1.inbridge为0没进入单边桥正常寻line1和line2
                        //2.inbridge大于等于1表示进入单边桥正常寻找line1和line2，若line1为0
    {

        for(i=119;i>0;i--)
        {
            if((Center_line[i-1]-Center_line[i])<=-5&&(Center_line[i-1]-Center_line[i])>-20)
            {
                line1=i;
            }
            if((Center_line[i-1]-Center_line[i])>=3&&(Center_line[i-1]-Center_line[i])<20)
            {
                line2=i-1;
            }
            if(line1!=0&&line2!=0&&(line1-line2)>=10)
            {
                flag1 = 1;
                break;
            }
        }//找到line1和line2将flag1置为1
        if(line2>= 8&&flag1)
        {
            if(Abs(Center_line[line1], Center_line[line2])<=5)
            {
                flag2=1;
                for(i=line1-1;i>line2+1;i--)
                {
                    if(Abs(Center_line[i-1], Center_line[i])>2)
                    {
                        flag2=0;
                        break;
                    }
                }
            }

        }

        //        if(Abs(Center_line[line1], Center_line[line2])<=20&&flag1&&(line1-line2)>=30&&(line1-line2)<=100)//
//        {
//            for(i=line1-1;i>=line2+1;i--)
//            {
//                count=0;
//                for(j=Center_line[i];j<=187;j++)
//                {
//                    if((Pixel[i][j]-Pixel[i][j-1])!=0)
//                    {
//                        count++;
//                    }
//                    if(count==3)
//                        break;
//                }
//                if(count==3)
//                {
//                    num++;
//                }
//
//            }
//            if(Abs(num,line1-line2)<=15)
//                flag2=1;
//        }//line1和line2中间向右找突变

        if(flag1&&flag2)
        {
            delay_flag=1;
//            if(line1>115)
//            {
//                inbridge_flag=1;//表示已经进入单边桥
//            }
            return 1;
        }
        else {
            return 0;
        }

    }
//    else if(inbridge_flag==1)
//    {
//        for(i=119;i>0;i--)
//        {
//            if((Center_line[i-1]-Center_line[i])<=-5)//&&(Center_line[i-1]-Center_line[i])>-20
//            {
//                line1=i;
//            }
//            if((Center_line[i-1]-Center_line[i])>=3)//&&(Center_line[i-1]-Center_line[i])<20
//            {
//                line2=i-1;
//            }
//            if(line1!=0&&line2!=0)
//            {
//                flag1 = 1;
//                break;
//            }
//            else if(line1==0&&line2!=0)
//            {
//                line1=120;
//                flag1 = 1;
//                break;
//            }
//        }//找到line2将flag1置为1
//
//        if(flag1)
//        {
//            for(i=line1-1;i>=line2+1;i--)
//            {
//                count=0;
//                for(j=Center_line[i];j<=187;j++)
//                {
//                    if((Pixel[i][j]-Pixel[i][j-1])!=0)
//                    {
//                        count++;
//
//                    }
//                    if(count==3)
//                        break;
//                }
//                if(count==3)
//                {
//                    num++;
//                }
//            }
//            if(Abs(num,line1-line2)<=15)
//                flag2=1;
//        }//line1和line2中间向右找突变
//
//        if(flag1&&flag2)
//        {
//
//            if(line2>=110&&line2<=115)//莫名奇妙找到line2 118
//            {
//                inbridge_flag=2;//退出单边桥
//            }
//            return 1;
//        }

//        else
//        {
//            //inbridge_flag=2;
//            return 0;
//        }
//
//    }
    else {
        return 0;
    }

}

int check_bridge2()
{
    int i,j;
    int line1=0,line2=0;
    int count;
    int num[3];
    int number=0;
    int flag1=0,flag2=0;
    //寻找line1
    if(inbridge_flag==0||inbridge_flag==1)
    {
        if(inbridge_flag==0)
        {
            for(i=119;i>=0;i--)
            {
                count=0;
                num[0]=0;
                num[1]=0;
                num[2]=0;
                for(j=Center_line[i];j<=186;j++)
                {
                    if((Pixel[i][j+1]-Pixel[i][j])!=0)
                    {
                        num[count]=j+1;
                        count++;
                    }
                    if(count==3)
                    {
                        break;
                    }

                }
                if(count==3&&(num[2]-num[1])<=5)
                {
                    line1=i;
                    break;
                }
            }
        }
        if(inbridge_flag==1)
        {
            line1=119;
        }

        //找到line1后寻找line2
        if(line1!=0)
        {
            for(i=line1;i>=0;i--)
            {
                count=0;
                num[0]=0;
                num[1]=0;
                num[2]=0;
                for(j=Center_line[i];j<=186;j++)
                {
                    if((Pixel[i][j+1]-Pixel[i][j])!=0)
                    {
                        num[count]=j+1;
                        count++;
                    }
                    if(count==3)
                    {
                        break;
                    }
                }
                if(count!=3)//count<3
                {
                    line2=i+1;
                    flag1=1;
                    break;
                }
//                else//count==3
//                {
//                    if((num[2]-num[1])>5)
//                    {
//                        line2=i+1;
//                        flag1=1;
//                        break;
//                    }
//                }
            }
        }

        //line1和line2都找到
        if(line1&&line2)
        {
            for(i=line1;i>=line2;i--)
            {
                count=0;
                for(j=Center_line[i];j<=187;j++)
                {
                    if((Pixel[i][j]-Pixel[i][j-1])!=0)
                    {
                        count++;
                    }
                }
                if(count==3)
                {
                    number++;
                }
            }
            if(Abs(number,line1-line2)<=15)
                flag2=1;

        }
        //最终判断
        if(flag1&&flag2)
        {
            if(line1==119)
            {
                inbridge_flag=1;
            }
            if(inbridge_flag==1&&line2>=100&&line1==119)
            {
                inbridge_flag=2;
            }
            return 1;
        }
        else {
            return 0;
        }
    }
    else
    {
        return 0;
    }


}
void correct_bridge(int distance)
{
    int i,j;
    int bridge_flag=0;

        for(i=line1-1;i>line2;i--)
        {
            bridge_flag=0;
            for(j=Center_line[i];j<187;j++)
            {
                if((Pixel[i][j]-Pixel[i][j+1])!=0)
                {
                    bridge_flag++;
                }
                if(bridge_flag==3)
                {
                    Right_line[i]=j;
                    Center_line[i]=(Left_line[i]+Right_line[i])/2+distance;
                    break;
                }
            }
            for(j=line2;j>=0;j--)
            {
                Center_line[j]+=distance;//Center_line[j]=Center_line[line2+1]+distance;
            }
            if(line1!=120)
            {
                for(j=line1;j<=119;j++)
                {
                    Center_line[j]+=distance;//Center_line[j]=Center_line[line1-1]+distance;
                }
            }

        }



}
void correct_bridge2(int distance)
{
    int i,j;
    int bridge_flag=0;

        for(i=line1;i>=line2;i--)
        {
            bridge_flag=0;
            for(j=Center_line[i];j<187;j++)
            {
                if((Pixel[i][j]-Pixel[i][j+1])!=0)
                {
                    bridge_flag++;
                }
                if(bridge_flag==3)
                {
                    Right_line[i]=j;
                    Center_line[i]=(Left_line[i]+Right_line[i])/2+distance;
                    break;
                }
            }
            for(j=line2-1;j>=0;j--)
            {
                Center_line[j]+=distance;//Center_line[j]=Center_line[line2+1]+distance;
            }
            if(line1!=119)
            {
                for(j=line1+1;j<=119;j++)
                {
                    Center_line[j]+=distance;//Center_line[j]=Center_line[line1-1]+distance;
                }
            }

        }



}


int check_obstacle()
{
    int i,j;
    int count=0,num=0,count1=0;
    int count2=0;
    int left=0,right=0;
    int flag=0;
    for(i=0;i<=119;i++)
    {
        if(Pixel[i][94]==0)
            count++;
        if(Pixel[i][94]==255)
        {
            break;
        }
    }
    if(count>=40)//count<=50&&
    {
        for(i=0;i<=count;i++)
        {
            for(j=94;j>=0;j--)
            {
                if(Pixel[i][j]==255)
                {
                    left=j;
                     break;
                }
            }
            for(j=94;j<=187;j++)
            {
                if(Pixel[i][j]==255)
                {
                    right=j;
                     break;
                }
            }
            num+=(right-left-1);

            if(left==0||right==0||right==187||Left_line[count]==0||Right_line[count]==187)
            {
                 count2++;
            }
        }
    }
//    for(j=0;j<187;j++)
//    {
//        if((Pixel[count-10][j]-Pixel[count-10][j+1])!=0)
//        {
//            count1++;
//        }


    //}
    if(num>=1000&&count2==0)//&&count1>=4
        return 1;
    else {
        return 0;
    }
}
//-------------------------------------------------------------------------------------------------------------------
// @brief        检测道路类型
// @param        无
// @return       void
//-------------------------------------------------------------------------------------------------------------------
void road_type()
{

    if(Cross_status==0)//没进十字
    {
        int right=0;


        if((right = check_rightangle_bend())&&rightangle_flag!=2)//判断直角弯（判断到后将rightangle加1）
        {
            if(right==2)//快到直角弯
            {
                flag=9;
            }


            if(right==1)//已到直角弯
            {
                rightangle_flag++;//结束直角弯道
//                inbridge_flag=-1;
                flag = 4;
            }

        }

        else if(rightangle_flag==2&&inbridge_flag==0&&check_bridge())//
        {
            flag=5;
//            correct_bridge(25);

        }
        else if(inbridge_flag==3&&check_obstacle()&&obstacle_flag==0)//
        {
            obstacle_flag=1;
        }
        else if(obstacle_flag==2&&check_black_white_line())
        {
            flag = 10;
        }



        //判断赛道类型




        else if(check_bend()) //判断普通弯道
        {
            if(inbridge_flag==3)//过了单边桥
            {
                flag=6;
            }
            else if(inbridge_flag==0)//直角前
            {
                flag=6;
            }
            else {
                flag=1;
            }
        }
        else         //直线
        {
            flag=0;
        }

    }
}













