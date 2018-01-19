#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "simulator.h"


int main(int argc, const char* argv[])
{
    char str[300];

    printf("Enter word: ");
    scanf("%s", str);

    drive_goto(-170,-170);

    for(int i=0; i<strlen(str); i++)
    {
        char letter = str[i];
        switch(letter)
        {
            case 'I':
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(50,50);
                simulator_stopSmokeTrail();
                drive_goto(-50,-50);
                drive_goto(26,-26);
                drive_goto(5,5);
                break;

            case 'L':
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(50,50);
                simulator_stopSmokeTrail();
                drive_goto(-50,-50);
                drive_goto(26,-25);
                simulator_startNewSmokeTrail();
                drive_goto(30,30);
                simulator_stopSmokeTrail();
                break;

            case 'E':
                 drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(50,50);
                simulator_stopSmokeTrail();
                drive_goto(-9,-9);
                drive_goto(26,-26);
                drive_goto(9,9);
                simulator_startNewSmokeTrail();
                drive_goto(35,35);
                simulator_stopSmokeTrail();
                drive_goto(-35,-35);
                drive_goto(-9,-9);
                drive_goto(-26,26);
                drive_goto(9,9);
                simulator_startNewSmokeTrail();
                drive_goto(-25,-25);
                simulator_stopSmokeTrail();
                drive_goto(26,-26);
                simulator_startNewSmokeTrail();
                drive_goto(35,35);
                drive_goto(-35,-35);
                simulator_stopSmokeTrail();
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(-25,-25);
                simulator_stopSmokeTrail();
                drive_goto(-9,-9);
                drive_goto(26,-26);
                drive_goto(9,9);
                simulator_startNewSmokeTrail();
                drive_goto(35,35);
                simulator_stopSmokeTrail();
                drive_goto(10,10);
                break;

            case 'F':
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(50,50);
                simulator_stopSmokeTrail();
                drive_goto(-9,-9);
                drive_goto(26,-26);
                drive_goto(9,9);
                simulator_startNewSmokeTrail();
                drive_goto(35,35);
                simulator_stopSmokeTrail();
                drive_goto(-35,-35);
                drive_goto(-9,-9);
                drive_goto(-26,26);
                drive_goto(9,9);
                simulator_startNewSmokeTrail();
                drive_goto(-25,-25);
                simulator_stopSmokeTrail();
                drive_goto(26,-26);
                simulator_startNewSmokeTrail();
                drive_goto(26,26);
                drive_goto(-26,-26);
                simulator_stopSmokeTrail();
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(-25,-25);
                simulator_stopSmokeTrail();
                drive_goto(-9,-9);
                drive_goto(26,-26);
                //simulator_startNewSmokeTrail();
                drive_goto(30,30);
                //simulator_stopSmokeTrail();
                break;

            case 'H':
                /*drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(-25,-25);
                drive_goto(26,-26);
                drive_goto(25,25);
                drive_goto(-26,26);
                drive_goto(25,25);
                drive_goto(-50,-50);
                drive_goto(26,-26);*/

                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(50,50);
                drive_goto(-25,-25);
                simulator_stopSmokeTrail();
                drive_goto(26,-26);
                simulator_startNewSmokeTrail();
                drive_goto(32,32);
                drive_goto(-10,-10);
                simulator_stopSmokeTrail();
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(25,25);
                drive_goto(-50,-50);
                simulator_stopSmokeTrail();
                drive_goto(26,-26);

                break;

            case 'K':
                /*drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(-25,-25);
                drive_goto(13,-13);*/
                //first angle for the top
                drive_goto(-26,26);
                simulator_startNewSmokeTrail();
                drive_goto(50,50);
                drive_goto(-30,-30);
                simulator_stopSmokeTrail();
                drive_goto(30,0);
                simulator_startNewSmokeTrail();
                //**** whats going on here??
                drive_goto(25,25);
                drive_goto(-30,-30);
                simulator_stopSmokeTrail();
                drive_goto(26,-26);
                simulator_startNewSmokeTrail();
                drive_goto(53,53);
                simulator_stopSmokeTrail();
                drive_goto(-15,15);
                break;

            case 'A':
                drive_goto(-17,17);
                simulator_startNewSmokeTrail();
                drive_goto(58,58);
                drive_goto(-29,-29);
                simulator_stopSmokeTrail();
                drive_goto(17,-17);
                simulator_startNewSmokeTrail();
                drive_goto(28,28);
                drive_goto(-8,-8);
                simulator_stopSmokeTrail();
                drive_goto(17,-17);
                simulator_startNewSmokeTrail();
                drive_goto(-15,-15);
                drive_goto(58,58);
                drive_goto(-7,-7);
                simulator_stopSmokeTrail();
                drive_goto(-17,17);

                /*drive_goto(-17,17);
                drive_goto(58,58);
                drive_goto(-29,-29);
                drive_goto(17,-17);
                drive_goto(28,28);
                drive_goto(8,8);
                drive_goto(17,-17);
                drive_goto(-16,-16);
                drive_goto(58,58);
                drive_goto(-17,17);*/
                break;

            default:
                printf("letter %c not found",letter);
                break;

        }

        drive_goto(12,12);
    }

    return 0;
}
