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

int swap(struct node *list, int pos1, int pos2, int n)
{
    struct node *node1, *node2, *prev1, *prev2, *temp;
    int i;
    const int maxPos = (pos1 > pos2) ? pos1 : pos2;

    const int totalNodes = n;
    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
    {
        return -1;
    }
    
    if (pos1 == pos2)
    {
        return 1;
    }
    i = 1;
    temp  = list;
    prev1 = NULL;
    prev2 = NULL;
    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }
    if (node1 != NULL && node2 != NULL)
    {
        if (prev1 != NULL)
            prev1->next = node2;
        if (prev2 != NULL)
            prev2->next = node1;
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

    return 1;
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