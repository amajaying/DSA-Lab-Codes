// WAP to convert an infix expression to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100], top = -1;

void push(char x)
{
    if (top >= 99)
    {
        printf("Stack overflow");
        exit(0);
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

char pop()
{
    char x;
    if (top == -1)
    {
        printf("Stack underflow");
        exit(0);
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/' || x == '%')
    {
        return 2;
    }
    return 0;
}


int main()
{
    char infix[100], postfix[100], temp;
    int i = 0, j = 0;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                postfix[j] = pop();
                j++;
            }
            if (top == -1)
            {
                printf("Invalid infix expression");
                exit(0);
            }
            temp = pop();
            i++;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
        {
            while ((top != -1) && (stack[top] != '(') && (priority(stack[top]) >= priority(infix[i])))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
            i++;
        }
        else
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
    }
    while ((top != -1) && (stack[top] != '('))
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("The postfix expression is: %s", postfix);
    return 0;
}
