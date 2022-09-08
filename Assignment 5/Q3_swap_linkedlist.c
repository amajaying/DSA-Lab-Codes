#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head, int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp;
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    printf("Creating linked list 1:\n");
    char continue1 = 'y';
    struct node *head1 = NULL;
    while (1)
    {
        int value;
        printf("Enter data: ");
        scanf("%d", &value);
        head1 = create(head1, value);
        getchar();
        printf("Want to add more nodes(Y/N)?: ");
        scanf("%c", &continue1);
        if (continue1 == 'n' || continue1 == 'N')
        {
            break;
        }
    }
    printf("Creating linked list 2:\n");
    char continue2 = 'y';
    struct node *head2 = NULL;
    while (1)
    {
        int value;
        printf("Enter data: ");
        scanf("%d", &value);
        head2 = create(head2, value);
        getchar();
        printf("Want to add more nodes(Y/N)?: ");
        scanf("%c", &continue2);
        if (continue2 == 'n' || continue2 == 'N')
        {
            break;
        }
    }
    printf("\nBefore swapping:\n");
    printf("Linked list 1:\n");
    display(head1);
    printf("\nLinked list 2:\n");
    display(head2);
    struct node *temphead;
    temphead = head1;
    head1 = head2;
    head2 = temphead;
    printf("\nAfter swapping:\n");
    printf("Linked list 1:\n");
    display(head1);
    printf("\nLinked list 2:\n");
    display(head2);
}