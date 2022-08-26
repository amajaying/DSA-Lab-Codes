// insert at any position linked list

#include <stdio.h>

struct node
{
    int n;
    struct node *next;
};
struct node *head;
struct node *temp = NULL;
int main()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new_node->n);

    if (head == NULL)
        head = new_node;
    else
    {
        int count = 0;
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            count++;
        }
        int k;
        printf("Enter the position to insert in: ");
        scanf("%d", &k);
        if (k > count)
            printf("Linked list is less than the position");
        else
        {
            int a = 1;
            for (temp = head; a < k - 1; temp = temp->next, ++a)
                ;
            struct node *ab = temp->next;
            temp->next = new_node;
            new_node->next = ab;
        }
    }
}
