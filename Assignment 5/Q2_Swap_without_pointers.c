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
    struct node *node1, *node2, *prev1, *prev2, *temp;
}

int main()
{
    int n, pos1, pos2;
     printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    create(n);
    printf("\n\nData before swapping: \n");
    display();

    printf("Enter which two nodes do you want to swap: ");
    scanf("%d%d", &pos1,&pos2);

    if (swap(head, pos1, pos2, n))
    {
        printf("Data after swapping %d node with %d: \n", pos1, pos2);
        display();
    }
    else 
    {
        printf("Position doesn't exist!\n");
    }

    return 0;


}