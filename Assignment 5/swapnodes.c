#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
void create(int n)
{
    struct node *newnode, *temp;
    head=malloc(sizeof(struct node));
    if (head==NULL)
    {
        printf("Node doesn't exist.");
        exit(0);
    }
    printf("Enter data of node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data of node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }   
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if(temp->next!=NULL)
            printf(", ");     
        temp = temp->next;             
    }
    printf("\n");
}


int swap(struct node *list, int pos1, int pos2, int n){
    struct node *temp, *temp1;
    int totalNodes = n;
    int maxPos = (pos1>pos2) ? pos1 : pos2;
    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
    {
        return -1;
    }
    
    if (pos1 == pos2)
    {
        return 1;
    }

    int i=1;
    temp1 = head;
    while(temp1->next!=NULL && i<=maxPos){
        if(i== pos1-1)
            temp = temp1->next;
    }


}