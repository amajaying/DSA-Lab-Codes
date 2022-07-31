#include <stdio.h>

int maxm(int arr[], int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}

int minm(int arr[], int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < m)
        {
            m = arr[i];
        }
    }
    return m;
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxi = maxm(arr, n);
    int mini = minm(arr, n);

    printf("Maximum num: %d\n", maxi);
    printf("Minimum num: %d\n", mini);
}