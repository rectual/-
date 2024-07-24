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



//��ʵ��Բ
void draw_fill_circle(uint8 x0,uint8 y0,uint8 r,const uint16 color)//д��ʵ��Բ��(x0,y0),�뾶r
{
        uint8 x = 0,y = 0,R = 0;
        for(x = x0-r;x <= x0+r;x++){
            for(y = y0-r; y <= y0+r ;y++ ){
                R = sqrt(pow(r,2)-pow(x-x0,2))+y0; //Բ����  x,y����
                if( (y >= y0 && y <= R) || (y < y0 && y >= 2*y0-R )) {  //�������� Բ������
                    ips114_draw_point(x,y,color);
                }
            }
        }
}




