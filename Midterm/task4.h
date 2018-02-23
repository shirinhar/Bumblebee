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

int tick = 3,i=1,closeness=12;
double startX, startY, startAng;

double x, y, z, distance;
//int left_ticks[250],right_ticks[250];
int left_wheel, right_wheel;
int distance_forward;
int left_tick, right_tick;


// change the robots angle
void turn_left(){
 	drive_speed(-tick,tick);
 	//left_ticks[i]=tick;	
 	//right_ticks[i]=-tick;
 	push(tick,-tick);
}

void turn_right(){
 	drive_speed(tick,-tick);
 	//left_ticks[i]=-tick;	
 	//right_ticks[i]=tick;
 	push(-tick,tick);
}

void back(){
	//drive_speed(30,30)
	//drive_goto(1,1);
	while (!isempty()){	
		i = i - 1;
		drive_ramp(30,30);	
		int right_ir=pop_left();
    	int left_ir=pop_right();
    	printf("l: %d, r: %d, i: %d\n", left_ir,right_ir,i);
    	pause(21.5);
		drive_speed(right_ir,left_ir);

	}
	printf("fuck");
	drive_ramp(128,128);	
	drive_speed(128,128);
}

void turn(){

	// theres a reason for the angle difference but idk which one is right
	// i can get it to bot
	// got the distance but im not sure its right and idk whick ones is mm
	drive_speed(0,0);
	drive_getTicks(&left_wheel, &right_wheel);
	double angle_rad = (left_wheel-right_wheel)*3.25/105.8;
	double rm = ((0.325*(left_wheel)/angle_rad) + (0.325*(right_wheel)/angle_rad))/2;
	double x = (rm - rm*cos(angle_rad));
	double distance_1 = sqrt( pow(x,2) + pow(rm * sin(angle_rad),2));
	print("Angle: %f\n",((asin(x/distance_1))*(180/3.14)));
	printf("left: %d right: %d Rm: %f Distance: %f\n",left_wheel,right_wheel, rm, distance_1);

	drive_goto(-18,-18);
	drive_goto(52,-51);
	drive_goto(-10,-10);
	pause(15);
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

	push(30,30);

	double left_ir = find_left_ir();
    double right_ir = find_right_ir();

	if (left_ir < closeness){
       turn_right();
    }

    else if (right_ir < closeness){
       turn_left();
    }

     else{
     	drive_speed(12,12);
     	push(12,12);
     }
     peek();
     i++;

}
