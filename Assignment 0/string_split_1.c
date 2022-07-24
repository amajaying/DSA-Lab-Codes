#include <stdio.h>
void split(char str[50], int a){
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            if (a == 0)
            {
                for (int j = 0; j < i; j++)
                {
                    printf("%c", str[j]);
                }
            }
            else
            {
                printf("%s", str + i + 1);
            }
        }
        i++;
    }  
}

int main()
{
    int a;
    char str[50];
    char c;
    printf("Type the string: ");
    scanf("%s",str);
    printf("Enter 0 or 1: ");
    scanf("%d",&a);
    split(str,a);
}