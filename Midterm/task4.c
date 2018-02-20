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
   get_start_position();
   simulator_startNewSmokeTrail();
   drive_speed(30,30);

   // leave while loop when 15cm away from wall
   while(ping_cm(8) > 15 ){

     drive_ramp(30,30);

     int tick=0;
     double diff_ir,first_ping,diff_ping;
     first_ping = second_ping;

     second_ping = ping_cm(8);
     
     //dead_reckoning();

     run();
   }

   simulator_stopSmokeTrail();
   turn();
   pause(20);
   simulator_startNewSmokeTrail();
   back();
   simulator_stopSmokeTrail();
   position_from_start();
}
