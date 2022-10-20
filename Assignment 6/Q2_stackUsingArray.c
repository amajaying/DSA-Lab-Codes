// Write a C program to implement STACK data structure using array (e.g., PUSH, POP, PEEK, ISEMPTY and ISFULL).
#include<stdio.h>
#include<stdlib.h>

int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);

int main()
{
    top = -1;
    printf("Enter the size of STACK[MAX=100]:");
    scanf("%d", &n);
    printf("STACK OPERATIONS USING ARRAY");
    printf("\n----------------------------------\n");
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT\n");
    printf("\n----------------------------------\n");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exit Point!");
                break;
            }
            default:
            {
                printf("Please Enter a Valid Choice(1/2/3/4)");
            }
        }
    }
    while(choice!=4);
    return 0;
}

void push()
{
    if(top>=n-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<=-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The popped elements is %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("n The elements in STACK ");
        for(i=top; i>=0; i--)
            printf("\n%d ",stack[i]);
        printf("\n");
    }
    else
    {
        printf("The STACK is empty");
    }
}







