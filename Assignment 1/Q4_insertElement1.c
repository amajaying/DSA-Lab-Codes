#include<stdio.h>

int main(){
    int n,x;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    int a[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    for(int i=n;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=x;
    printf("The array after insertion is: ");
    for(int l=0;l<=n;l++){
        printf("%d ",a[l]);
    }
    return 0;
}