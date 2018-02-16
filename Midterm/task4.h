#include <stdio.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include <stdlib.h>
#include "ping.h"

// change the robots angle 
void turn(double left_ir,double right_ir,double diff_ping){
	int x=1;
	if (left_ir > right_ir){
		x = -1;
	}
	int tick = 4 * x;
 	drive_speed(tick,-tick);
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
