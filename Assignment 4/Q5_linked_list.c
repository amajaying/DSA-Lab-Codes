#include <stdio.h>

struct node
{
    int n;
    struct node *next;
};
struct node *head=NULL;
int main()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new_node->n);
    int option;
    printf("MENU");
    printf("Choose one task: ");
    printf("1. Add Linked List at first.");
    printf("2. Add Linked List at last.");
    printf("3. Add Linked List at any position.");
    printf("4. Display sum of all nodes.");
    scanf("%d", &option);


}
