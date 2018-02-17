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
int tick = 5;

double x, y, z, distance;
double left_ticks[100],right_ticks[100];
int distance_forward;

void position(){

simulator_getPose(&x, &y, &z);
distance = sqrt(pow(x,2) + pow(y,2));


printf("Distance: %f\n", distance/32.5);

}
// void dead_reckoning(){
// 	while (1) {
//     drive_getTicks(int *left, int *right);
// 		left = left_ticks[]
// 		right = right_ticks[]
// 		pause(100);
// }
}

// change the robots angle
void turn_left(double left_ir,double right_ir,double diff_ping){
 	drive_speed(-tick,tick);
}
void turn_right(double left_ir,double right_ir,double diff_ping){
 	drive_speed(tick,-tick);
}
void go_back(){
	drive_ramp(0,0);
	drive_goto(51,-51);
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
