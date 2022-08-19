#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    printf("Enter element to search: ");
    scanf("%d", &k);

    // Applying binary search 
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2; 
    while(s<=e){
        if(arr[m]<k){
            s=m+1;
        }
        else if(arr[m]>k){
            e=m-1;
        }
        else if(arr[m]==k){
            printf("\nFound");
            exit(0);
        }
        m = s + (e-s)/2; 
    }
    printf("Not Found!");
}