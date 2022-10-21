// WAP to employ quadratic probing technique to resolve collision in hashing.
// Use Hash Table Size: 07 Elements are: 76, 40, 48, 5, 55

#include <stdio.h>

int main()
{
    int i, j, k, l, m, n, hash[7], choice, key, flag;
    int arr[5] = {76, 40, 48, 5, 55};
    for (i = 0; i < 7; i++)
    {
        hash[i] = -1;
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    // division
    for (i = 0; i < 5; i++)
    {
        j = arr[i] % 7;
        if (hash[j] == -1)
        {
            hash[j] = arr[i];
        }
        else
        {
            // Quadratic Probing condition if collision happens 
            n = j;
            k = 1;
            while (hash[n] != -1)
            {
                n = (j + k * k) % 7;
                k++;
            }
            hash[n] = arr[i];
        }
    }
    flag = 0;
    for (i = 0; i < 7; i++)
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