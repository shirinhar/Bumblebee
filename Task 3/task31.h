#include <stdio.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include <stdlib.h>
#include "ping.h"

// change the robots angle 
void get_angle(double diff_ir,double diff_ping){
	double angle, x;
	int tick;
	angle = diff_ir / diff_ping;
    x = (atan(angle)*180)/M_PI;
    tick = (int) round(x*0.284);
    if (tick != 0){
 	  	drive_speed(tick,-tick);
  	}
}

// get the ir reading and return it as a double
double find_ir(){
	double second_ir = 0;
	for(int dacVal = 0; dacVal < 160; dacVal += 8)  // <- add
  	{                                               // <- add
		dac_ctr(26, 0, dacVal);                       // <- add
	    freqout(11, 1, 38000);                        // <- add
	    second_ir += input(10);
	}
	return second_ir;
}