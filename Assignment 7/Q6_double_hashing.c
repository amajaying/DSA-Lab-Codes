// WAP to employ double hasing to resolve collision in hashing.
// Use Hash Table Size: 10 Elements are: 34, 55, 12, 8, 45, 37, 88, 98, 54, 32

#include <stdio.h>

int main()
{
    int i, j, k, l, m, n, hash[10], choice, key, flag;
    int arr[10] = {34, 55, 12, 8, 45, 37, 88, 98, 54, 32};
    for (i = 0; i < 10; i++)
    {
        hash[i] = -1;
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    // division
    for (i = 0; i < 10; i++)
    {
        j = arr[i] % 10;
        if (hash[j] == -1)
        {
            hash[j] = arr[i];
        }
        else
        {
            // Double Hashing condition if collision happens 
            n = j;
            k = 1;
            while (hash[n] != -1)
            {
                n = (j + k * (7 - arr[i] % 7)) % 10;
                k++;
            }
            hash[n] = arr[i];
        }
    }
    flag = 0;
    for (i = 0; i < 10; i++)
    {
        if (hash[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("The key is found");
    }
    else
    {
        printf("The key is not found");
    }
    return 0;
}
