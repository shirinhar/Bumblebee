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

// dijkstra code referece: http://www.codewithc.com/dijkstras-algorithm-in-c/

struct edge {
    int first;
    int second;

    // the distance from the last node
    int distance_from_last_r[5];
    int distance_from_last_l[5];

    int weight;
};

int new_prev[30]; // just to see if it would work
int x=0, y=0, INF = 30000;
int edge_index=0; // number of edges
int last_x=0,last_y=0;
int distance_between_r[5],distance_between_l[5], distance_between_index = 0;
int visitedX[50],visitedY[50], posYs[50],posXs[50],i_am_on[100];
int visitedX_2[50],visitedY_2[50]; 

int distance_from = 19,ticks = 120;
int visited_index =0, visited_index_2=0;
int posX=0, posY=1;
int n = 60;  // number of maximum edges
int stop = 0;

// 1 is y 0 is x
int what_am_i_on = 1, back_it_up;

struct edge edges[60];  // edges
int all_nodes[] = {0,1,2,3,4,11,12,13,14,21,22,23,24,31,32,33,34};


void clear_array(){
    for (int i = 0; i < 5; ++i)
    {
        distance_between_l[i]=0;
        distance_between_r[i]=0;
    }
}

void start(){
    drive_goto(30,30);  // get to the center of starting node
    clear_array();
}

// calculate weight of each node
void calculate_weight(){   
    for (int j = 0; j < edge_index; ++j)
    {
        int sum = 0;
        for (int i = 0; i < 5; ++i)
        {
            sum = sum + abs(edges[j].distance_from_last_l[i]);
        }
        edges[j].weight = sum;
    }
}

int calculate_optimum_route(){
    // calculate using dijkstra
    int all_node_size = sizeof(all_nodes)/sizeof(int);

    int cost[40][40], start = 0,prev[40];
    int visited_dijk[40], distance_dijk[40];

    // make a cost matrix
    for (int i = 0; i < all_node_size; ++i)
    {
        for (int j = 0; j < all_node_size; ++j)
        {
            int index_i = all_nodes[i];
            int index_j = all_nodes[j];    
            cost[index_i][index_j] = INF;

        }
        visited_dijk[i] = 0;    // don't know why we do it but was in the website
    }

    for (int i = 0; i < edge_index; ++i)
    {
        cost[edges[i].first][edges[i].second] = edges[i].weight;
        cost[edges[i].second][edges[i].first] = edges[i].weight;
    }

    for (int i = 0; i < all_node_size; ++i)
    {
        int index_me = all_nodes[i];
        distance_dijk[index_me] = INF;
        visited_dijk[index_me] = 0;
        prev[index_me] = -1;  
    }

    visited_dijk[start] = 1;
    distance_dijk[start] = 0;

    while(visited_dijk[34]==0)
    {
        int MIN_DISTANCE = INF;
        int m = 0,d;

        for (int i = 0; i < all_node_size; ++i)
        {
            int index_me = all_nodes[i];
            d = distance_dijk[start] + cost[start][index_me];
            if (d < distance_dijk[index_me] && visited_dijk[index_me]==0)
            {
                distance_dijk[index_me]=d;
                prev[index_me] = start;
            }

            if (MIN_DISTANCE>distance_dijk[index_me] && visited_dijk[index_me]==0)
            {
                MIN_DISTANCE = distance_dijk[index_me];
                m = index_me;
            }
        }
        start = m;
        visited_dijk[start] = 1;
    }

    start = 34;
    int length= 0;
    do
    {
        new_prev[length] = start;
        start = prev[start];
        length++;
        
    }while(start != -1);

    return length;
}

void finish_off(int prev_length){
    int left_wheel[30], right_wheel[30], wheel_index = 0;
    left_wheel[0] = 0;
    right_wheel[0] = 0;

    // put fasted route into array
    for (int i = prev_length-1; i > -1; i = i -1)
    {

        int from = new_prev[i];
        int to = new_prev[i-1];
        for (int k = 0; k < edge_index; ++k)
        {
            if (from == edges[k].first && to == edges[k].second)
            {
                // check if they're not the same chon oon tori shayad drive_goto kamtar bashe
                if (edges[k].distance_from_last_l[1] != 0)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        wheel_index++;
                        left_wheel[wheel_index] = edges[k].distance_from_last_l[j];
                        right_wheel[wheel_index] = edges[k].distance_from_last_r[j];
                    }
                }else{
                    left_wheel[wheel_index] += edges[k].distance_from_last_l[0];
                    right_wheel[wheel_index] += edges[k].distance_from_last_r[0];
                }
            }
            else if(from == edges[k].second && to == edges[k].first){
                if (edges[k].distance_from_last_l[1] != 0)
                {
                    for (int j = 3 ; j > -1; j = j -1)
                    {
                        wheel_index++;
                        left_wheel[wheel_index] = edges[k].distance_from_last_l[j];
                        right_wheel[wheel_index] = edges[k].distance_from_last_r[j];
                    }
                }else{
                    left_wheel[wheel_index] += edges[k].distance_from_last_l[0];
                    right_wheel[wheel_index] += edges[k].distance_from_last_r[0];
                }
            }
        }
    }

    // the end
    pause(15);
    for (int i = 0; i < wheel_index + 1; ++i)
    {
        drive_goto(right_wheel[i],left_wheel[i]);
    }
}


// Phase 2
void back(){
    for (int j = 0; j < edge_index; ++j)
    {
        edges[j].weight = 200;
        if (edges[j].first == edges[j].second){
            edges[j].second = 0;
            edges[j].first = 0;
        }

    }

    calculate_weight();
    int prev_length = calculate_optimum_route();
    finish_off(prev_length);    // going the final route

}

// see if node has been visited once
int is_visited_1(int valX,int valY){
    for (int i=0; i < visited_index; i++) {
        if (visitedY[i] == valY && visitedX[i] == valX)
            return 1;
    }
    return 0;
}

// see if node has been visited twice
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
    else if (posX <-2){
        posX = 1;
    }
    if (posY>2){
        posY = -1;
    }
    else if (posY <-2){
        posY = 1;
    } 
}

// check what axis you are on
void im_on(){
    if (what_am_i_on == 1){
        what_am_i_on = 0;
    }
    else{
        what_am_i_on = 1;
    }
}

// find distance between two nodes
void save_distance_between(int tick_r, int tick_l){
    distance_between_r[distance_between_index]=tick_r;
    distance_between_l[distance_between_index]=tick_l;
    distance_between_index++;
}

void turn_right(){
    drive_goto(-9,-9);        
    drive_goto(-26,25);
    drive_goto(9,9);
    posX--;
    posY--;
    change_direction();
    im_on();
    save_distance_between(-9,-9);
    save_distance_between(-26,25);
    save_distance_between(9,9);
    push(-9,-9);
    push(-26,25);
    push(9,9);
}

void turn_left(){
    drive_goto(-9,-9);        
    drive_goto(25,-26);
    drive_goto(9,9);
    posX++;
    posY++;
    change_direction();
    im_on();
    save_distance_between(-9,-9);
    save_distance_between(25,-26);
    save_distance_between(9,9);
    push(-9,-9);
    push(25,-26);
    push(9,9);
}

void save_coordinates(){
    visitedX[visited_index] = x;
    visitedY[visited_index] = y;
    posXs[visited_index] = posX;
    posYs[visited_index] = posY;
    i_am_on[visited_index] = what_am_i_on;
    push_single(visited_index);
    visited_index++;
}

void save_coordinates_again(){
    visitedX_2[visited_index_2] = x;
    visitedY_2[visited_index_2] = y;
    visited_index_2++;
}

// go forward on the x axis
void go_forth_x(){
    drive_goto(ticks,ticks);
    save_distance_between(ticks,ticks);
    last_x =x;
    last_y = y;
    if (posX > 0){
        x++;
    }
    if (posX < 0){
        x--;
    }
    push(ticks,ticks);
}

// go forward on the y axis
void go_forth_y(){
    drive_goto(ticks,ticks);
    save_distance_between(ticks,ticks);
    last_y = y;
    last_x = x;
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

// go to the last point fo decision
void go_back(){
    drive_goto(51,-52);
    int pop_l = pop_left();
    int pop_r = pop_right();
    while(pop_l != -100){
        drive_goto(pop_r,pop_l);
        if (isempty() == 1){
            stop = 1;
            break;
        }
        pop_l = pop_left();
        pop_r = pop_right();
    }
    drive_goto(51,-52);
    int pop_me = pop_single();
    x = visitedX[pop_me];
    last_x = x;
    y = visitedY[pop_me];
    last_y = y;
    posY = posYs[pop_me];
    posX = posXs[pop_me];
    what_am_i_on = i_am_on[pop_me];
    back_it_up = 1;
}

void go_forward(){
    if (what_am_i_on == 1){
        go_forth_y();
    }
    else{
        go_forth_x();
    }
}

void make_graph(){

    edges[edge_index].first = (last_x*10) + last_y;
    edges[edge_index].second = (x*10) + y;
    for (int i = 0; i < 5; ++i)
    {
        edges[edge_index].distance_from_last_l[i] = distance_between_l[i];
        edges[edge_index].distance_from_last_r[i] = distance_between_r[i];
    }
    distance_between_index = 0;
    clear_array();
    edge_index++;
}

int run(){

    int ping = ping_cm(8);
    double left_ir = find_left_ir();
    double right_ir = find_right_ir();

    // if wall infront
    if ( ping < 25 ){

        if(left_ir > distance_from && right_ir > distance_from){
            // visited twice
            if(is_visited_2(x,y)==1){
                go_back();
            }
            // visited once
            else if(is_visited_1(x,y)==1 && back_it_up != 0) {
                save_coordinates_again();
                if (left_ir > distance_from && right_ir <= distance_from){
                    turn_right();
                    go_forward();
                }
                else{
                    turn_left();
                    go_forward();
                }
            }
            else if(is_visited_1(x,y)==1){
                save_coordinates_again();
                go_back();
            }
            else{
                save_coordinates();
                push(-100,-100);
                turn_right();
                go_forward();
            }
        }
        else if (left_ir > distance_from && right_ir <= distance_from){
            turn_right();
            go_forward();
        }
        else if (right_ir > distance_from && left_ir <= distance_from){
            turn_left();
            go_forward();
        }
        //dead end
        else{
            go_back();
        }
    }
    else if(left_ir > distance_from || right_ir > distance_from ){
        if(is_visited_2(x,y)==1){
            go_back();
        }
        else if(is_visited_1(x,y)==1 && back_it_up != 0){
            save_coordinates_again();
            if (left_ir > distance_from && right_ir <= distance_from){
                turn_right();
                go_forward();
            }
            else{
                turn_left();
                go_forward();
            }

            // choose other route
        }
        else if(is_visited_1(x,y)==1){
            save_coordinates_again();
            go_back();
        }
        else{
            save_coordinates();
            push(-100,-100);
            go_forward();
        }
            
    }
    //going straight
    else{
        go_forward();
    }

    if (back_it_up == 1){
        back_it_up = 2;
    }else if(back_it_up == 2){
        back_it_up = 0;
    }

    make_graph();   // make the node

    return stop;
}
