// WAP to solve a prefix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100], top = -1;

void push(int item)
{
    if (top >= 99)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0)
    {
        printf("Stack Underflow");
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

int priority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char prefix[100], temp;
    int i = 0, j = 0, op1, op2, result;
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);
    strrev(prefix);
    while (prefix[i] != '\0')
    {
        if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%')
        {
            op1 = pop();
            op2 = pop();
            switch (prefix[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '%':
                result = op1 % op2;
                break;
            }
            push(result);
            i++;
        }
        else
        {
            push(prefix[i] - '0');
            i++;
        }
    }
    printf("The result of the prefix expression is: %d", pop());
    return 0;
}
