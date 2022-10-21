// 3. Write a menu driven C program to implement folding, division and mid-square techniques to search an item using a Hash Table of size 11. Where the given array elements are: 20, 76, -5, 101, 63, 11, 86, 34, 54, 60.

#include<stdio.h>

int main()
{
    int i, j, k, l, m,n, hash[11], choice, key, flag;
    int arr[10]={20, 76, -5, 101, 63, 11, 86, 34, 54, 60};
    for(i=0; i<11; i++)
    {
        hash[i] = -1;
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    printf("Enter the choice of hashing technique: ");
    printf(" \n1. Folding \n2. Division \n3. Mid-Square \n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        // folding
            for(i=0; i<10; i++)
            {
                j = arr[i] % 10;
                k = arr[i] / 10;
                l = j + k;
                m = l % 11;
                if(hash[m] == -1)
                {
                    hash[m] = arr[i];
                }
                else
                {
                    // condition if collision happens
                    n = m;
                    while(hash[n] != -1)
                    {
                        n = (n + 1) % 11;
                    }
                    hash[n] = arr[i];
                }
            }
            flag = 0;
            for(i=0; i<11; i++)
            {
                if(hash[i] == key)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("The key is found");
            }
            else
            {
                printf("The key is not found");
            }
            break;
        case 2:
        // Division
            for(i=0; i<10; i++)
            {
                j = arr[i] % 11;
                if(hash[j] == -1)
                {
                    hash[j] = arr[i];
                }
                else
                {
                    // condition if collision happens
                    k = j;
                    while(hash[k] != -1)
                    {
                        k = (k + 1) % 11;
                    }
                    hash[k] = arr[i];
                }
            }
            flag = 0;
            for(i=0; i<11; i++)
            {
                if(hash[i] == key)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("The key is found");
            }
            else
            {
                printf("The key is not found");
            }
            break;
        case 3:
        // Mid-Square
            for(i=0; i<10; i++)
            {
                j = arr[i] * arr[i];
                k = j % 100;
                l = k / 10;
                m = l % 11;
                if(hash[m] == -1)
                {
                    hash[m] = arr[i];
                }
                else
                {
                    // condition if collision happens
                    n = m;
                    while(hash[n] != -1)
                    {
                        n = (n + 1) % 11;
                    }
                    hash[n] = arr[i];
                }
            }
            flag = 0;
            for(i=0; i<11; i++)
            {
                if(hash[i] == key)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("The key is found");
            }
            else
            {
                printf("The key is not found");
            }
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}

