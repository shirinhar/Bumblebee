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
    char str[300];

    printf("Enter word: ");
    scanf("%s", str);
    
    for(int i=0; i<strlen(str); i++)
    {
        char letter = str[i];
        switch(letter)
        {
            case 'I':
                drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(-50,-50);
                drive_goto(26,-26);
                drive_goto(5,5);
                break;

            case 'L':
                drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(-50,-50);
                drive_goto(26,-26);
                drive_goto(25,25);
                drive_goto(-25,-25);
                drive_goto(25,25);
                break;
            
            case 'E':
                drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(26,-26);
                drive_goto(26,26);
                drive_goto(-26,-26);
                drive_goto(-26,26);
                drive_goto(-25,-25);
                drive_goto(26,-26);
                drive_goto(26,26);
                drive_goto(-26,-26);
                drive_goto(-26,26);
                drive_goto(-25,-25);
                drive_goto(26,-26);
                drive_goto(26,26);
                drive_goto(-25,-25);
                drive_goto(25,25);
                break;

            case 'F':
                drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(26,-26);
                drive_goto(30,30);
                drive_goto(-30,-30);
                drive_goto(-26,26);
                drive_goto(-25,-25);
                drive_goto(26,-26);
                drive_goto(26,26);
                drive_goto(-26,-26);
                drive_goto(-26,26);
                drive_goto(-25,-25);
                drive_goto(26,-26);
                drive_goto(26,26);
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
                drive_goto(50,50);
                drive_goto(-25,-25);
                drive_goto(26,-26);
                drive_goto(32,32);
                drive_goto(-10,-10);
                drive_goto(-26,26);
                drive_goto(25,25);
                drive_goto(-50,-50);
                drive_goto(26,-26);

                break;

            case 'K':
                /*drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(-25,-25);
                drive_goto(13,-13);*/
                //first angle for the top
                drive_goto(-26,26);
                drive_goto(50,50);
                drive_goto(-30,-30);
                drive_goto(30,0);
                drive_goto(25,25);
                drive_goto(-30,-30);
                drive_goto(26,-26);
                drive_goto(39,39);
                drive_goto(-14,14);
                break;

            case 'A':
                drive_goto(-17,17);
                drive_goto(58,58);
                drive_goto(-29,-29);
                drive_goto(17,-17);
                drive_goto(28,28);
                drive_goto(-8,-8);
                drive_goto(17,-17);
                drive_goto(-16,-16);
                drive_goto(52,52);
                drive_goto(-7,-7);
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

        drive_goto(15,15);
    }
    
    return 0;
}