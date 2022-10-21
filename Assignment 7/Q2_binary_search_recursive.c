// Binary search using recursion

#include<stdio.h>
int binary_search(int arr[], int s, int e, int k){
    int m = (s+e)/2;
    if(s>e)
        return -1;
    
    if(arr[m]==k)
        return m;
    else if(arr[m]>k)
        e=m-1;
    else
        s=m+1;

    return binary_search(arr, s, e, k);
}

int main(){
int n, key, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    int a[n];
    int s = 0, e=n-1;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key: ");
    scanf("%d", &key);
    pos = binary_search(a,s,e,key);
    if (pos == -1)
        printf("Element not found");
    else
        printf("Element Found in pos %d", pos);
}