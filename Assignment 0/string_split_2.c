#include <stdio.h>
void split(char str[50], int a, char c){
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            if (a == 0)
            {
                for (int j = 0; j < i; j++)
                {
                    printf("%c", str[j]);
                }
                   printf("\t");
            }
            else
            {
                printf("%s\t", str + i + 1);
               
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
    printf("Enter the char for splitting: ");
    scanf(" %c",&c);
    printf("Enter 0 or 1: ");
    scanf("%d",&a);
    
    split(str,a,c);
}
