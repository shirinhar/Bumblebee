#include <stdio.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h"
#include "abdrive.h"
#include "simulator.h"
#include "task4.h"



int main()
{



 double left_ir;
 double right_ir ;
 double second_ping ;
 double closeness = 12;
 simulator_startNewSmokeTrail();

 // leave while loop when 15cm away from wall
 while(ping_cm(8) > 15 ){

   drive_ramp(25,25);

   int tick=0;
   double diff_ir,first_ping,diff_ping;
   first_ping = second_ping;

   second_ping = ping_cm(8);
   left_ir = find_left_ir();
   right_ir = find_right_ir();

   diff_ir = (left_ir - right_ir);


   if (left_ir < closeness){
     turn_right(left_ir,right_ir,diff_ping);
   }

   if (right_ir < closeness){
     turn_left(left_ir,right_ir,diff_ping);
   }

   if (ping_cm(8) <= 15){
     break;
   }
 }
 simulator_stopSmokeTrail();
 go_back();
 position();
}
