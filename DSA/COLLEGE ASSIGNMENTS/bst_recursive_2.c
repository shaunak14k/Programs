#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct node
{ 
    int value;
    struct node *left;
    struct node *right;
};
struct node * root=NULL, p, newnode;
