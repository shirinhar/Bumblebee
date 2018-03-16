#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"
#include "final1.h"


int main() {
    simulator_startNewSmokeTrail();
    //hardcoded the first square
	drive_goto(150,150);
    while(1){
        run();
    }
    return 0;
}
