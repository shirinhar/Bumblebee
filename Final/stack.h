#include <stdio.h>

int MAXSIZE = 250;       
int stack_left[250]; 
int stack_right[250];    
int top_left = -1;
int top_right = -1;            

int isempty() {

   if(top_left == -1 || top_right == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top_left == MAXSIZE || top_right == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   printf("left peak: %d, right peak: %d\n", stack_left[top_left],stack_right[top_right]); ;
}

int pop_left() {
   int data;
	
   if(!isempty()) {
      data = stack_left[top_left];
      top_left = top_left - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int pop_right() {
   int data;
   
   if(!isempty()) {
      data = stack_right[top_right];
      top_right = top_right - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data_left,int data_right) {

   if(!isfull()) {
      top_left = top_left + 1; 
      top_right = top_right + 1;  
      stack_right[top_right] = data_right;
      stack_left[top_left] = data_left;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}