// wap to add two sparse matrices using triplet using linkedlist

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

void create_node(int n, struct node *head)
{
    for (int i = 0; i < n; i++)
    {
        struct node *new_node, *temp;
        int row, col, val;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter col: ");
        scanf("%d", &col);
        printf("Enter val: ");
        scanf("%d", &val);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->row = row;
        new_node->col = col;
        new_node->val = val;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

void displayNodes(struct node *head)
{
    struct node *temp = head;
    printf("\nThe data are: ");
    while (temp != NULL)
    {
        printf("%d %d %d ", temp->row, temp->col, temp->val); 
        temp = temp->next;
    }
}

void add()
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->row == temp2->row && temp1->col == temp2->col)
        {
            struct node *new_node, *temp;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->row = temp1->row;
            new_node->col = temp1->col;
            new_node->val = temp1->val + temp2->val;
            new_node->next = NULL;
            if (head3 == NULL)
            {
                head3 = new_node;
            }
            else
            {
                temp = head3;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->row < temp2->row)
        {
            struct node *new_node, *temp;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->row = temp1->row;
            new_node->col = temp1->col;
            new_node->val = temp1->val;
            new_node->next = NULL;
            if (head3 == NULL)
            {
                head3 = new_node;
            }
            else
            {
                temp = head3;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
            temp1 = temp1->next;
        }
        else if (temp1->row > temp2->row)
        {
            struct node *new_node, *temp;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->row = temp2->row;
            new_node->col = temp2->col;
            new_node->val = temp2->val;
            new_node->next = NULL;
            if (head3 == NULL)
            {
                head3 = new_node;
            }
            else
            {
                temp = head3;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        struct node *new_node, *temp;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->row = temp1->row;
        new_node->col = temp1->col;
        new_node->val = temp1->val;
        new_node->next = NULL;
        if (head3 == NULL)
        {
            head3 = new_node;
        }
        else
        {
            temp = head3;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        struct node *new_node, *temp;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->row = temp2->row;
        new_node->col = temp2->col;
        new_node->val = temp2->val;
        new_node->next = NULL;
        if (head3 == NULL)
        {
            head3 = new_node;
        }
        else
        {
            temp = head3;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        temp2 = temp2->next;
    }

    displayNodes(head3);
}

int main()
{
    int n1, n2;
    printf("Enter the number of nodes in matrix 1: ");
    scanf("%d", &n1);
    create_node(n1, head1);
    printf("Enter the number of nodes in matrix 2: ");
    scanf("%d", &n2);
    create_node(n2, head2);
    displayNodes(head1);
    displayNodes(head2);
    add();
    displayNodes(head3);
    return 0;
}