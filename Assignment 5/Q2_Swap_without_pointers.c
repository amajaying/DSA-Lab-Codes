#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void create(int n)
{
    struct node *newnode, *temp;
    head = malloc(sizeof(struct node));
    if (head == NULL)
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
        if (temp->next != NULL)
            printf(", ");
        temp = temp->next;
    }
    printf("\n");
}

void swap(int p1, int p2)
{
    int pos1, pos2;
    if (p2 > p1)
    {
        pos1 = p1;
        pos2 = p2;
    }
    else
    {
        pos1 = p2;
        pos2 = p1;
    }
    struct node *prev, *temp;
    int i = 1, j = 1;
    if (pos1 == 1)
        prev = head;
    else
    {
        for (prev = head; i < pos1 - 1; prev = prev->next, i++)
            ;
    }
    for (temp = head; j < pos2; temp = temp->next, j++)
        ;

    if (pos1 == 1)
    {
        head = temp;
        prev->next = temp->next;
        temp->next = prev;
    }
    else
    {
        prev->next->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    display();
}
int main()
{
    int n, pos1, pos2;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    create(n);
    printf("\n\nData before swapping: \n");
    display();

    printf("Enter which two adjacent nodes do you want to swap: ");
    scanf("%d%d", &pos1, &pos2);

    swap(pos1, pos2);

    return 0;
}