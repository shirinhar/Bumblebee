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
int tick = 3,i=1,closeness=12;
double startX, startY, startAng;

double x, y, z, distance;
int left_ticks[250],right_ticks[250];
int distance_forward;
int left_tick, right_tick;


// change the robots angle
void turn_left(){
 	drive_speed(-tick,tick);
 	left_ticks[i]=tick;	
 	right_ticks[i]=-tick;
}

void turn_right(){
 	drive_speed(tick,-tick);
 	left_ticks[i]=-tick;	
 	right_ticks[i]=tick;
}

void back(){
	//drive_speed(30,30)
	//drive_goto(1,1);
	while (i > -1){	
		i = i - 1;
		drive_ramp(30,30);	
		int right_ir=left_ticks[i];
    	int left_ir=right_ticks[i];
    	printf("l: %d, r: %d\n", left_ir,right_ir);
    	pause(23);
		drive_speed(right_ir,left_ir);
	}
}

void turn(){
	drive_speed(0,0);
	drive_goto(-18,-18);
	drive_goto(52,-53);
	drive_goto(-18,-18);
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

	left_ticks[0]=30;
	right_ticks[0]=30;

	double left_ir = find_left_ir();
    double right_ir = find_right_ir();

    //left_ticks[i]=(int)left_ir;
    //right_ticks[i]=(int)right_ir;
    printf("l: %f, r: %f\n", left_ir,right_ir);

	if (left_ir < closeness){
       turn_right();

    }

    else if (right_ir < closeness){
       turn_left();
     }

     else{
     	drive_speed(12,12);
     	left_ticks[i]=12;	
 	right_ticks[i]=12;
     }
     i++;

}


void get_start_position(){
	simulator_getPose(&startX, &startY, &startAng);	
}

void position_from_start(){
	double endX, endY, endAng;
	simulator_getPose(&endX, &endY, &endAng);

	printf("start: %lf, %lf, %lf\nend: %lf, %lf, %lf\n", startX, startY, startAng,endX, endY, endAng);
	distance = sqrt(pow((endX-startX),2) + pow((endY-startY),2));
	double angle = endAng - startAng;
	print("Angle: %f\n", angle*(180/3.14));
	printf("Distance: %f\n", distance/32.5);
}
