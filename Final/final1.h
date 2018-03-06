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
#include "stack.h"


int x=0, y=0;
int visitedX[100],visitedY[100];
int visitedX_2[100],visitedY_2[100]; 
int distance_from = 19;
int visited_index =0, visited_index_2=0;
int bool = 0;
int posX=0, posY=1;
// 1 is y 0 is x
int what_am_i_on = 1,ticks = 120;

int is_visited_1(int valX,int valY){
    for (int i=0; i < visited_index; i++) {
        if (visitedY[i] == valY && visitedX[i] == valX)
            return 1;
    }
    return 0;
}

int is_visited_2(int valX,int valY){
    for (int i=0; i < visited_index; i++) {
        if (visitedY_2[i] == valY && visitedX_2[i] == valX)
            return 1;
    }
    return 0;
}

void change_direction(){
    // check calculations
    if (posX>2){
        posX = -1;
    }
    if (posX <-2){
        posX = 1;
    }
    if (posY>2){
        posY = -1;
    }
    if (posY <-2){
        posY = 1;
    } 
}

void turn_right(){
    drive_goto(-9,-9);        
    drive_goto(-26,25);
    drive_goto(9,9);
    posX++;
    posY++;
    change_direction();
    if (what_am_i_on == 1){
        what_am_i_on = 0;
    }
    else{
        what_am_i_on = 1;
    }
    push(-9,-9);
    push(-26,25);
    push(9,9);
}

void turn_left(){
    drive_goto(-9,-9);        
    drive_goto(25,-26);
    drive_goto(9,9);
    posX--;
    posY--;
    change_direction();
    if (what_am_i_on == 1){
        what_am_i_on = 0;
    }
    else{
        what_am_i_on = 1;
    }
    push(-9,-9);
    push(25,-26);
    push(9,9);
}

void save_coordinates(){
    visitedX[visited_index] = x;
    visitedY[visited_index] = y;
    visited_index++;
}

void save_coordinates_again(){
    visitedX_2[visited_index_2] = x;
    visitedY_2[visited_index_2] = y;
    visited_index_2++;
}

void go_forth_x(){
    drive_goto(ticks,ticks);
    printf("%d\n", posX);
    if (posX > 0){
        x--;
    }
    if (posX < 0){
        x++;
    }
    push(ticks,ticks);
}

void go_forth_y(){
    drive_goto(ticks,ticks);
    if (posY > 0){
        y++;
    }
    if (posY < 0){
        y--;
    }
    push(ticks,ticks);
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

void go_back_bitch(){
    drive_goto(51,-52);
    int pop_l = pop_left();
    int pop_r = pop_right();
    while(pop_l != -100){
        drive_goto(pop_r,pop_l);
        pop_l = pop_left();
        pop_r = pop_right();
    }
    drive_goto(51,-52);
    x = visitedX[visited_index-1];
    y = visitedY[visited_index-1];
}

void go_fucking_bitch(){
    if (what_am_i_on == 1){
        go_forth_y();
    }
    else{
        go_forth_x();
    }
}

void printer(){
    printf("shoot me\n");
    int help = x;
    int hi = y;
    printf("co:%d, %d ",help,hi);

}

void run(){
    printer();
    int ping = ping_cm(8);
    double left_ir = find_left_ir();
    double right_ir = find_right_ir();

    if (ping < 25 ){
        drive_speed(0,0);

        if(left_ir > distance_from && right_ir > distance_from){
            if(is_visited_2(x,y)==1){
                go_back_bitch();
            }
            else if(is_visited_1(x,y)==1) {
                save_coordinates_again();
                if (left_ir > distance_from && right_ir <= distance_from){
                    turn_right();
                    go_fucking_bitch();
                }
                else{
                    turn_left();
                    go_fucking_bitch();
                }
            }
            else{
                save_coordinates();
                push(-100,-100);
                turn_right();
                go_fucking_bitch();
            }
        }
        else if (left_ir > distance_from && right_ir <= distance_from){
            turn_right();
            go_fucking_bitch();
        }
        else if (right_ir > distance_from && left_ir <= distance_from){
            turn_left();
            go_fucking_bitch();
        }
        //dead end
        else{
            go_back_bitch();
        }
    }
    else if(left_ir > distance_from || right_ir > distance_from ){
        if(is_visited_2(x,y)==1){
            go_back_bitch();
        }
        else if(is_visited_1(x,y)==1){
            save_coordinates_again();
            if (left_ir > distance_from && right_ir <= distance_from){
                turn_right();
                go_fucking_bitch();
            }
            else{
                turn_left();
                go_fucking_bitch();
            }
            // choose other route
        }else{
            save_coordinates();
            push(-100,-100);
            go_fucking_bitch();
        }
       
        
    }
    //going straight
    else{
        go_fucking_bitch();
    }
}
