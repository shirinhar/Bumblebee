#include<stdio.h>
#include<stdlib.h>
// #include<time.h>
// #include"final.h"



struct my_node{

	int x_coordinate;
	int y_coordinate;
	int distance;

	struct my_node*left;
	struct my_node*forward;
	struct my_node*right;
};

struct my_node *create_node(int x_coordinate,int y_coordinate, int distance){
	struct my_node *my_node = (struct my_node*)malloc(sizeof(struct my_node));

  my_node->x_coordinate = x_coordinate;
	my_node->y_coordinate = y_coordinate;
	my_node->distance= distance;

  my_node->left= NULL;
  my_node->right= NULL;
	my_node->forward = NULL;

	while(x_coordinate!=1678){
		my_node -> left = create_node(x_coordinate,y_coordinate,distance);
	}

	printf("x:%d ,y:%d ,d:%d\n",x_coordinate,y_coordinate,distance);

  return my_node;
}

// struct my_node *insert_left(int x_coordinate,int y_coordinate, int distance){
//   my_node -> left = create_node(x_coordinate, y_coordinate, distance);
//   return(my_node);
// }
// struct my_node *insert_middle(struct my_node *node,int x_coordinate,int y_coordinate, int distance){
//   node -> forward = insert_left(node -> forward, x_coordinate, y_coordinate, distance);
//   return(node);
// }
// struct my_node *insert_right(struct my_node *node,int x_coordinate,int y_coordinate, int distance){
//   node -> right = insert_left(node -> right, x_coordinate, y_coordinate, distance);
//   return(node);
// }


struct my_node *intialise()
{
  /*create root*/
  struct my_node*root = create_node(0,0,0);

  root->forward = create_node(0,1,1);
	root->left = NULL;
	root->right = NULL;

  return root;

}
