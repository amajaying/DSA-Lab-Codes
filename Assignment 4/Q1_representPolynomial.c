#include <stdio.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for(int i=n-1; i>=0; i-- ){
        printf("%dx^%i ", arr[i], i);
        if(i!=0)
            printf("+ ");
    }

}
