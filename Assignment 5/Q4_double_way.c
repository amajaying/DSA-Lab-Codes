#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

