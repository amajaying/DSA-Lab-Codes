#include <stdio.h>
#include <math.h>

void generateSubsequences(char str[], int n)
{
    int num = 1;
    while (num <= pow(2, n) - 1)
    {
        int temp = num, i = 0;
        while (i < n)
        {
            if ((temp >> i) & 1)
                printf("%c", str[i]);
            i++;
        }
        printf("\n");
        num++;
    }
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int n = 0;
    while (str[n] != '\0')
        n++;
    generateSubsequences(str, n);
    return 0;
}