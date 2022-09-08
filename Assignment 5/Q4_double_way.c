#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void isEmpty() {
    if(head == NULL){
        printf("The linked list is EMPTY!\n");
    }
}

void insertAtFront()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = head;
    head = temp;
}

void insertAtEnd()
{
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    trav = head;

    if (head == NULL) {
 
        head = temp;
    }
    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
}
void deleteEnd()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (head->next == NULL)
        head = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
}
