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
int tick = 3,i=0;
double startX, startY, startZ;

double x, y, z, distance;
int left_ticks[250],right_ticks[250];
int distance_forward;
int left_tick, right_tick;

void position(){

	simulator_getPose(&x, &y, &z);
	distance = sqrt(pow(x,2) + pow(y,2));

	printf("Distance: %f\n", distance/32.5);

}

void dead_reckoning(){
	drive_getTicks(&left_ticks[i], &right_ticks[i]);
	printf("l: %d, r: %d i: %d\n", left_ticks[i],right_ticks[i],i);
	i++;
}

void back(){
	drive_ramp(30,30);
	//drive_goto(1,1);
	while (i > -1){		
		left_tick = left_ticks[i-1] - left_ticks [i-2];
		right_tick = right_ticks[i-1] - right_ticks [i-2];
		i = i - 1;
		//drive_speed(50,50);
		drive_goto(right_tick,left_tick);
		//drive_speed(20,20);
	}
}

// change the robots angle
void turn_left(){
 	drive_speed(-tick,tick);
}

void turn_right(){
 	drive_speed(tick,-tick);
}

void go_back(){
	drive_ramp(0,0);
	drive_goto(-18,-18);
	drive_goto(51,-51);
	drive_goto(-18,-18);
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

void get_start_position(){
	simulator_getPose(&startX, &startY, &startZ);	
}

void position_from_start(){
	double endX, endY, endZ;
	simulator_getPose(&endX, &endY, &endZ);

	printf("start: %lf, %lf, %lf\nend: %lf, %lf, %lf\n", startX, startY, startZ,endX, endY, endZ);
	distance = sqrt(pow((endZ-startZ),2) + pow((endY-startY),2) + pow((endX-startX),2));
	printf("Distance: %f\n", distance/32.5);
}
