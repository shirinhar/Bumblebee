#include <stdio.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "simulator.h"
#include <stdlib.h>
#include "ping.h"
#include "simulator.h"


int x=0, y=0;
int visitedX[50],visitedY[50]; 
int visited_index =0;
int bool = 0;
int posX=0, posY=1;

void turn_right(){
    drive_goto(-9,-9);        
    drive_goto(-26,26);
    drive_goto(9,9);
    posX++;
    posY++;
}

void turn_left(){
    drive_goto(-9,-9);        
    drive_goto(26,-26);
    drive_goto(9,9);
    posX--;
    posY--;
}

void save_coordinates(){
    visitedX[visited_index] = x;
    visitedY[visited_index] = y;
    visited_index++;
}

void change_direction(){
    if (posX>1){
        posX = 0;
    }
    if (posX <-1){
        posX = 0;
    }
    if (posY>1){
        posY = 0;
    }
    if (posY <-1){
        posY = 0;
    } 
}

void go_forth_x(){
    drive_goto(3,3);
    x = x + posX;
}

void go_forth_y(){
    drive_goto(3,3);
    y = y + posY;
}

// get the ir reading and return it as a double
double find_left_ir(){
    double left_ir = 0;
    for(int dacVal = 0; dacVal < 160; dacVal += 8)  // <- add
    {                                               // <- add
        dac_ctr(26, 0, dacVal);                       // <- add
        freqout(11, 1, 38000);                        // <- add
        left_ir += input(10);
    }
    return left_ir;
}

double find_right_ir(){
    double right_ir = 0;
    for(int dacVal = 0; dacVal < 160; dacVal += 8)  // <- add
    {                                               // <- add
        dac_ctr(27, 1, dacVal);                       // <- add
        freqout(1, 1, 38000);
        right_ir += input(2);
    }
    return right_ir;
}

void run(){

    int ping = ping_cm(8);
    double left_ir = find_left_ir();
    double right_ir = find_right_ir();

    printf("%lf, %lf",left_ir,right_ir);

    //here is where I loose my shit
}
