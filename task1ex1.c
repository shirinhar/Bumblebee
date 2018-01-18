#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "simulator.h"


int main(int argc, const char* argv[])
{
    //drive_goto(1000, 1000);
    simulator_startNewSmokeTrail();
    for (int i=0; i<4;i++)
    {
        drive_goto(77,77);
        drive_goto(26,-26);
    }

    return 0;
}