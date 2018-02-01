
#include "simpletools.h"
#include "ping.h"
#include "abdrive.h"
#include <math.h>

#define M_PI 3.14159265358979323846

int main()
{
  double second_ir = 0;
  double first_ir =0;
  double second_ping = ping_cm(8);
  for(int dacVal = 0; dacVal < 160; dacVal += 8)  // <- add
  {                                               // <- add
    dac_ctr(26, 0, dacVal);                       // <- add
    freqout(11, 1, 38000);                        // <- add
    second_ir += input(10);
  }

  while(1){
      
    drive_speed(50,50);
    int tick=0;
    double diff_ir,first_ping,diff_ping, fuck_me_up_atan,angle;
    first_ir = second_ir;
    first_ping = second_ping;
    second_ir=0;

    second_ping = ping_cm(8);
    for(int dacVal = 0; dacVal < 160; dacVal += 8)  // <- add
    {                                               // <- add
      dac_ctr(26, 0, dacVal);                       // <- add
      freqout(11, 1, 38000);                        // <- add
      second_ir += input(10);
    }
        
    diff_ir = (first_ir - second_ir);
    
      
    if (diff_ir != 0 && first_ping != second_ping){
      diff_ping = (abs)(first_ping - second_ping);
      angle = diff_ir / diff_ping;
      fuck_me_up_atan = (atan(angle)*180)/M_PI;
      tick = (int) round(fuck_me_up_atan*0.284);
      drive_goto(tick,-tick);
    }

    drive_goto(20,20);
    printf("%lf, %lf, %lf, %lf, %d\n",diff_ir, first_ping, second_ping,fuck_me_up_atan,tick);

    pause(100);
  }  

}