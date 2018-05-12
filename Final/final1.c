#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"
#include "final1.h"


int main() {

	simulator_startNewSmokeTrail();
	start();
	int stop = 0;
    while(stop == 0){
        stop = run();
    }
    back();
    return 0;
}
