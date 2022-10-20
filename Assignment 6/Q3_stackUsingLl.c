// Write a C program to implement STACK data structure using linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void display();

int main()
{
    int choice;
    while(1)
    {
        printf("1.Push \n2.Pop \n3.Display \n4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }
}

void push()
{
    int value;
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Not able to push element");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d",&value);
        if(top==NULL)
        {
            ptr->data = value;
            ptr -> next = NULL;
            top=ptr;
        }
        else
        {
            ptr->data = value;
            ptr->next = top;
            top=ptr;
        }
        printf("Item pushed");
    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = top->data;
        ptr = top;
        top = top->next;
        free(ptr);
        printf("Item popped");
    }
}

void display()
{
    int i;
    struct node *ptr;
    ptr=top;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {   printf("Stack elements are: ");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}