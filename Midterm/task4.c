#include "simpletools.h"
#include "ping.h"
#include "abdrive.h"
#include "task4.h"
#include <math.h>


int main()
{
  // get initial variables
  double left_ir=0;
  double right_ir =0;
  double second_ping = ping_cm(8);

  // leave while loop when 5cm away from wall
  while(ping_cm(8) >= 5 ){
      
    drive_speed(50,50);  
    int tick=0;
    double diff_ir,first_ping,diff_ping;
    first_ping = second_ping;

    second_ping = ping_cm(8);
    left_ir = find_left_ir();
    right_ir = find_right_ir();
        
    diff_ir = (left_ir - right_ir);

    // if robot is not parallel to the wall, enter loop  
    if (diff_ir != 0 && first_ping != second_ping){
      //diff_ping = (abs)(first_ping - second_ping);
      turn(left_ir,right_ir,diff_ping);
    }

    drive_speed(20,20);
    pause(50);
  }  

}