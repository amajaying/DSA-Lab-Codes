// wap to linear search using recursion

#include <stdio.h>

int linear_search(int a[], int n, int key, int i)
{
    if (i == n)
        return -1;
    if (a[i] == key)
        return i;
    return linear_search(a, n, key, i + 1);
}

int main()
{
    int n, key, i, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key: ");
    scanf("%d", &key);
    pos = linear_search(a, n, key, 0);
    if (pos == -1)
        printf("Element not found");
    else
        printf("Element Found in pos %d", pos);

}