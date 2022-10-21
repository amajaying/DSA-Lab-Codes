/* Write a menu driven C program to do the following operations for a Circular Linked List:
a) Create a node
b) Insert at beginning
c) Insert at end
d) Insert at any position
e) Delete at beginning
f) Delete at end
g) Delete at any position*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void create()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void insert_begin()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted at beginning");
}

void insert_end()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    printf("Node inserted at end");
}

void insert_pos()
{
    struct node *newNode, *temp;
    int pos, i = 1;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d", pos);
}

void delete_begin()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
        printf("Node deleted from beginning");
    }
}

void delete_end()
{
    struct node *temp, *prevNode;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            prevNode = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
            tail = NULL;
            free(temp);
        }
        else
        {
            prevNode->next = head;
            tail = prevNode;
            free(temp);
        }
        printf("Node deleted from end");
    }
}

void delete_pos()
{
    struct node *temp, *prevNode;
    int pos, i = 1;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = head;
        while (i < pos)
        {
            prevNode = temp;
            temp = temp->next;
            i++;
        }
        if (temp == head)
        {
            head = NULL;
            tail = NULL;
            free(temp);
        }
        else
        {
            prevNode->next = temp->next;
            free(temp);
        }
        printf("Node deleted from position %d", pos);
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\nMENU:\n");
        printf("\n1. Create a node\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at any position\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete at any position\n");
        printf("8. Display LinkedList\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_pos();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;

        default:
            printf("Please enter valid choice..");
        }
    }
    return 0;
}
