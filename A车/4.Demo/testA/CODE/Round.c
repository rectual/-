//#include "Round.h"
//
//
//int T1()   //判断左线是否为直线
//{
//    int interval=2;
//    int start=100;
//    int c=0;
//    int w=0;
//        for(int i=0;i<=25;i++)
//        {
//
//           if((Left_line[start-i*interval]-Left_line[start-(i+1)*interval]>=-3)  &&
//                   (Left_line[start-i*interval]-Left_line[start-(i+1)*interval]<=0))
//           {
//
//           }
//
//           else
//           {
//               c++;
//           }
//
//
//           if(Left_line[start-i]==0)
//                 w++;
//
//        }
//
//
//
//        if(c<=5&&w<=5)
//        {
//        return 1;
//        }
//
//
//        else
//        {
//
//            return 0;
//
//        }
//}
//
//
//
//
//
//
//static int T3() //检测入环岛的拐点
//{
//    int status=0;
//    int row;
//    int i=0;
//
//    for(row=110;row>=40;row--)
//    {
//        if((Right_line[row]-Right_line[row-2])<=-10)
//    {
//        status=1;    //发现跳变行
//        break;
//
//    }
//
//    }
//
//    if(status==1)
//    {
//        for(i=0;i<=3;i++)
//        {
//        if(Right_line[row-i-5]<=170||(!(Right_line[row+i]-Right_line[row+i+1]>=-4&&Right_line[row+i]-Right_line[row+i+1]<=0)))
//        break;
//        }
//    }
//
//
//    if(status==1&&i==4)
//    return 1;
//
//    else
//    return 0;
//
//}
//
//
//
//static int T4(int row)   //检测状态2  判断下方是否丢线
//{
//   for(int i=0;i<=25;i++)
//   {
//       if(Right_line[row+i]<=170)
//       return 0;
//
//   }
//
//   return 1;
//}
//
//
//
//
//int check_round(int L,int R,int num_R,int entered_Cross)   //检测环岛
//{
//
//    if(entered_Cross==1)
//    if(L<=10&&T1()&&T3())
//      return 1;
//
//   return 0;
//}
//
//
//
//int check_Round_status2(int row)   //检测环岛状态2 准备补线
//{
//    row=row-2;
//   if(T4(row+5)
//   &&(row<=70)&&(row>=40)&&
//   (Right_line[row-2]-Right_line[row-4]<=2)&&(Right_line[row-4]-Right_line[row-6]<=2)&&(Right_line[row-6]-Right_line[row-8]<=2)&&(Right_line[row-8]-Right_line[row-10]<=2)
//   &&(Right_line[row-2]-Right_line[row-4]>=-1)&&(Right_line[row-4]-Right_line[row-6]>=-1)&&(Right_line[row-6]-Right_line[row-8]>=-1)&&(Right_line[row-8]-Right_line[row-10]>=-1))
//
//       return 1;
//
//       return 0;
//}
//
//
//
//int check_Round_status3()  //检测环岛状态3  入环
//{
//      if(round_dot1_row>enter_round||round_dot1_row==enter_round)
//      {
//          return 1;
//      }
//      return 0;
//}
//
//int check_Round_status4(int num1)   //检测环岛状态4  出环
//{
//    if(num1>=25)
//    {
//    return 1;
//    }
//
//    return 0;
//}
//
//
//
//int check_Round_status5(int L)   //检测环岛状态5  出环完成开始补线
//{
//
//       if(T1())
//       {
//
//          return 1;
//       }
//
//         return 0;
//
//
//}
//
//
//
//int check_Round_status6()   //检测环岛状态6  环岛结束
//{
//    if(Right_line[vision-10]<=175&&Right_line[vision+10]<=175&&Right_line[vision]<175)
//    return 1;
//
//  else {
//    return 0;
//}
//}
//
//
//void seek_round_dot1(uint8 img[120][188])    //找上点
//{
//    uint8 status=0;
//    static int first=1;
//
//        for(int row=110;row>=20;row--)
//        {
//            for(int col=170;col>=12;col--)
//            {
//
//                if((img[row][col]==0)&&(img[row-2][col]==0)&&(img[row-4][col]==0)&&(img[row-8][col]==0)
//                        &&(img[row][col]-img[row+8][col]==-255)&&(img[row][col]-img[row][col-3]==-255)
//                        &&(img[row][col]-img[row][col-8]==-255)&&(img[row][col]-img[row+1][col+5]==-255)
//                        &&(img[row][col]-img[row+1][col-5]==-255)&&(img[row][col]-img[row-1][col+1]==0)&&(img[row][col]-img[row-1][col-1]==0)
//                        &&(img[row][col]-img[row][col-12]==-255))
//                {
//
//                  if(first==1&&col>=70&&col<=160)
//                  {
//                      round_dot1_col=col;
//                      round_dot1_row=row;
//
//                      status=1;
//                      first=0;
//                      break;
//                  }
//
//                  else if(first==0&&row-round_dot1_row<=30&&col-round_dot1_col>=-50&&row-round_dot1_row>=-5&&col-round_dot1_col<=30)
//                  {
//                     round_dot1_col=col;
//                     round_dot1_row=row;
//                     status=1;
//                     break;
//                  }
//
//                  else
//                  {
//                    status=1;
//                    break;
//                  }
//
//                }
//            }
//
//
//            if(round_dot1_row>=enter_round)
//            {
//                first=1;
//
//            }
//
//
//
//            if(status==1)
//            {
//              break;
//            }
//        }
//
//
//    }
//
//
//
//
//int seek_dot1(int row,int V)   //状态1补线拟合
//{
//    static float k,b;
//
//    for(int i=0;Right_line[row-i-1]!=187;i++)
//    {
//
//        if((Right_line[row-i]-Right_line[row-i-6]<=0)&&(Right_line[row-i]-Right_line[row-i+6]<=0))
//        {
//
//            if((row-i-1)<=20)
//              return (int)(k*V+b);
//
//
//         k=(Right_line[row-i]-187+0.0)/(row-i-1-119+0.0);
//         b=187-k*119;
//
//
//         return (int)(k*V+b);
//        }
//    }
//
//    return 187-Left_line[V];
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//void Repair_Round_status1(int row)   //进入补线
//{
//
//    for(int i=vision1+2;i<=vision3-2;i--)
//    {
//        if(Right_line[i]!=187&&Right_line[i-3]<=170)  //右边有线
//     {
//
//             Center_line[i]=(Left_line[i] + Right_line[i])/2;
//
//
//     }
//
//     else
//    {
//       {
//           Center_line[i]=((Left_line[i]+ seek_dot1(row,i))/2);   //上线拟合
//
//       }
//
//    }
//    }
//}
//
//
//void Repair_Round_status2()   //入环补线
//{
//    float k,b,L;
//    k=(round_dot1_col-0-0.0)/(round_dot1_row-119-0.0);
//    b=0-k*119;
//
//
//    for(int V=vision1+2;V<=vision3-2;V++)
//    {
//        L=k*V+b;
//    Center_line[V]=(int)((187+L)/2)+round_correct_bend_error;
//    }
//}
//
//
//
//void Repair_Round_status4()   //出环补线
//{
//
//Center_line[vision1]=94+out_round;
//Center_line[vision2]=94+out_round;
//Center_line[vision3]=94+out_round;
//}
//
//void Repair_Round_status5(int row,int num_R_row)  //结束环岛补线
//{
//
//    Center_line[vision]=(Left_line[vision1]+road_width)/2+20;
//    Center_line[vision]=(Left_line[vision2]+road_width)/2+20;
//    Center_line[vision]=(Left_line[vision3]+road_width)/2+20;
//}
//
//
//void Round_control()
//{
//    //环岛区
//       if(Round_status>0)
//       {
//           if(Round_status==1)
//           {
//               //检测
//               if(check_Round_status2(WtoB_R))
//               {
//                   Round_status=2;
//                   flag=5;
//               }
//
//                if(Round_status==1)
//                {
//                   //补线
//                    Repair_Round_status1(WtoB_R);
//
//                }
//           }
//
//
//           if(Round_status==2)
//           {
//
//
//            if(Round_status==2)
//            {
//              //找点
//              seek_round_dot1(Pixel);
//
//              //补线
//              Repair_Round_status2();
//            }
//
//            if(check_Round_status3())
//             {
//                Round_status=3;
//                flag=5;
//             }
//
//
//           }
//
//
//           if(Round_status==3)
//           {
//               if(check_Round_status4(num_white))  //弯道检测出环
//                  Round_status=4;
//           }
//
//
//           if(Round_status==4)  //出环
//           {
//               //补线
//               Repair_Round_status4();
//               //检测
//
//               if(check_Round_status5(num_L))  //检测出环完毕
//               {
//               Round_status=5;
//               flag=4;
//               round_dot1_row=0;
//               round_dot1_col=0;
//               }
//           }
//
//
//             if(Round_status==5)  //出环
//             {
//
//                 Repair_Round_status5(WtoB_R,num_R_row);
//
//
//
//                 if(check_Round_status6())
//                 {
//                     round_dot1_row=0;
//                     round_dot1_col=0;
//                     Round_status=0;
//                     entered_Cross=0;
//                 }
//
//             }
//
//
//       }
//
//
//}











