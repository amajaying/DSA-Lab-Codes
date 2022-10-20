// WAP to convert an infix expression to prefix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100], top = -1;

void push(char);
char pop();
int priority(char);

int main()
{
    char infix[100], prefix[100], temp;
    int i = 0, j = 0;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    strrev(infix);
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
                prefix[j] = pop();
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
                prefix[j] = pop();
                j++;
            }
            push(infix[i]);
            i++;
        }
        else
        {
            prefix[j] = infix[i];
            j++;
            i++;
        }
    }
    while ((top != -1) && (stack[top] != '('))
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
    strrev(prefix);
    printf("The prefix expression is: %s", prefix);
    return 0;
}

void push(char x)
{
    if (top >= 99)
    {
        printf("Stack Overflow");
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
    if (top < 0)
    {
        printf("Stack Underflow");
        exit(1);
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