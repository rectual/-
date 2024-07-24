#include "show.h"



void Left_line_draw()
{
    for(int row = MT9V03X_DVP_H-1; row >0; row--)
     ips114_draw_point(Left_line[row]+2,row,blue);

}




void Right_line_draw()
{

    for(int row = MT9V03X_DVP_H-1; row >0; row--)
         ips114_draw_point(Right_line[row]-2,row,green);


}




void Center_line_draw()
{

    for(int row = MT9V03X_DVP_H-1; row >0; row--)
         ips114_draw_point(Center_line[row],row,red);

}



//画实心圆
void draw_fill_circle(uint8 x0,uint8 y0,uint8 r,const uint16 color)//写画实心圆心(x0,y0),半径r
{
        uint8 x = 0,y = 0,R = 0;
        for(x = x0-r;x <= x0+r;x++){
            for(y = y0-r; y <= y0+r ;y++ ){
                R = sqrt(pow(r,2)-pow(x-x0,2))+y0; //圆方程  x,y反置
                if( (y >= y0 && y <= R) || (y < y0 && y >= 2*y0-R )) {  //点限制在 圆方程内
                    ips114_draw_point(x,y,color);
                }
            }
        }
}




