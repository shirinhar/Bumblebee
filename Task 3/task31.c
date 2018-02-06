#include "simpletools.h"
#include "ping.h"
#include "abdrive.h"
#include "task31.h"
#include <math.h>

#define M_PI 3.14159265358979323846

int main()
{
  // get initial variables
  double second_ir;
  double first_ir =0;
  double second_ping = ping_cm(8);
  second_ir = find_ir();

  // leave while loop when 5cm away from wall
  while(ping_cm(8) >= 5 ){
      
    drive_speed(50,50);  
    int tick=0;
    double diff_ir,first_ping,diff_ping;
    first_ir = second_ir;
    first_ping = second_ping;

    second_ping = ping_cm(8);
    second_ir = find_ir();
        
    diff_ir = (first_ir - second_ir);

    // if robot is not parallel to the wall, enter loop  
    if (diff_ir != 0 && first_ping != second_ping){
      diff_ping = (abs)(first_ping - second_ping);
      get_angle(diff_ir,diff_ping);
    }

    drive_speed(20,20);
    pause(50);
  }  

}