#include <stdio.h>
#include <stdlib.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "simulator.h"


int main(int argc, const char* argv[])
{
    //drive_goto(1000, 1000);
    
    for (int i=0; i<4;i++)
    {
        simulator_startNewSmokeTrail();
        drive_goto(77,77);
        simulator_stopSmokeTrail();
        drive_goto(-9,-9);        
        drive_goto(-26,26);
        drive_goto(9,9);
        
    }

    return 0;
}
