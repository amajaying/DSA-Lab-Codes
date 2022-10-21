// WAP to solve a postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int stack[100], top = -1;

void push(int num)
{
    if (top >= 99)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

int pop()
{
    int num;
    if (top <= -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        num = stack[top];
        top--;
        return num;
    }
}

int priority(char op)
{
    if (op == '*' || op == '/' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
}

int main()
{
    char postfix[100];
    int i = 0, j = 0, num1, num2, result;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    while (postfix[i] != '\0')
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
            i++;
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%')
        {
            num1 = pop();
            num2 = pop();
            switch (postfix[i])
            {
            case '+':
                result = num2 + num1;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '*':
                result = num2 * num1;
                break;
            case '/':
                result = num2 / num1;
                break;
            case '%':
                result = num2 % num1;
                break;
            }
            push(result);
            i++;
        }
    }
    printf("Result of expression is %d", pop());
    return 0;
}

