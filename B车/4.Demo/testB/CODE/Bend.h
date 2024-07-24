#ifndef __Bend_H_
#define __Bend_H_

#include "headfile.h"

int check_bend();
int check_rightangle_bend();
int check_Triangle();
int check_three();
int check_bridge();
int check_bridge2();
int check_obstacle();

void correct_rightangle_bend();
void correct_bend_error();
void correct_triangle(uint A,uint B,int turn_flag);
void correct_bridge(int distance);
void correct_bridge2(int distance);
void road_type();



#define check_bend_low_row    35
#define check_bend_high_row   85

#define check_bend_S2       6

#endif
