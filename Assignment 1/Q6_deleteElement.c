#include<stdio.h>

int main(){
    int n,x,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the position of the element to be deleted: ");
    scanf("%d",&pos);
    for(int i=pos;i<n;i++){
        a[i]=a[i+1];
    }
    printf("The array after deletion is: ");
    for(int l=0;l<n-1;l++){
        printf("%d ",a[l]);
    }
    return 0;
}