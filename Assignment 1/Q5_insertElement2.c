#include<stdio.h>

int main(){
    int n,x,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    int a[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    printf("Enter the position of the element to be inserted: ");
    scanf("%d",&pos);

    for(int i=n;i>pos;i--){
        a[i]=a[i-1];
    }
    a[pos]=x;
    printf("The array after insertion is: ");
    for(int l=0;l<=n;l++){
        printf("%d ",a[l]);
    }
    return 0;
}