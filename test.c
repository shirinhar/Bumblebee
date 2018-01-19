//this is the code for task 1.2
//created by team 13

#include <stdio.h>
#include "abdrive.h"
#include "simpletools.h"
#include "simulator.h"

int main(){        
  printf("Enter your string: ");
  char word[256];
  fgets(word, sizeof(word), stdin);
  drive_goto(-170,-170);
  for (int i = 0; i < sizeof(word); i++){
    if (word[i] == 'A')
      {
	putA();
      }
    else if(word[i] == 'I')
      {
	putI();
      }
    else if(word[i] == 'H')
      {
	putH();
      }
    else if(word[i] == 'E')
      {
	putE();
      }
    else if(word[i] == 'F')
      {
	putF();
      }
    else if(word[i] == 'K')
      {
	putK();
      }
    else if(word[i] == 'L')
      {
	putL();
      }
   }
}  

int putH(){
  drive_goto(-26, 25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(60,60);
  simulator_stopSmokeTrail();
  drive_goto(-51, 51);
  drive_goto(39,39);
  drive_goto(-26,25);
  drive_goto(9, 9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(30,30);
  drive_goto(-51,51);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(60, 60);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(15,15);
  drive_goto(26,-25);
  drive_goto(24, 24);
}

int putI(){
  drive_goto(15,15);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(60,60);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(69,69);
  drive_goto(-26,25);
  drive_goto(24,24);
}
  
int putK(){
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(60,60);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(39, 39);
  drive_goto(-39,39);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(43, 43);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(52,52);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(43,43);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-15,15);
  drive_goto(24,24);
  
}

int putL(){
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(60,60);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(69,69);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(15,15);
}
int putE()
{
  drive_goto(-26,25);
  drive_goto(9,9);
  drive_goto(60,60);
  drive_goto(26,-25);
  drive_goto(39,39);
  drive_goto(-51,51);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(39,39);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(15,15);
}

int putA()
{
  drive_goto(-23,23);
  simulator_startNewSmokeTrail();
  drive_goto(61,61);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(39,39);
  drive_goto(-30,30);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(15,15);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-30,30);
  drive_goto(30,30);
  drive_goto(-51,51);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(61,61);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-23,23);
  drive_goto(24,24);
}

int putF()
{
  drive_goto(-26,25);
  drive_goto(60,60);
  drive_goto(26,-25);
  drive_goto(39,39);
  drive_goto(-51,51);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-51,51);
  drive_goto(39,39);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_startNewSmokeTrail();
  drive_goto(30,30);
  simulator_stopSmokeTrail();
  drive_goto(-9,-9);
  drive_goto(-26,25);
  drive_goto(9,9);
  simulator_stopSmokeTrail();
  drive_goto(30,30);

}