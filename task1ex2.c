#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "simulator.h"


int main(int argc, const char* argv[])
{
    simulator_startNewSmokeTrail();
    drive_goto(1000, -1000);
    
    
    return 0;
}