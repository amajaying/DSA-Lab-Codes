#include<stdio.h>
int binary(int n, int arr[n], int k, int s, int e, int m){
    
    if(s>e){
        return 0;
    }
    // while(s<=e){
        if(arr[m]<k){
            s=m+1;
        }
        else if(arr[m]>k){
            e=m-1;
        }
        else if(arr[m]==k){
            return 1;
        }
        m = s + (e-s)/2; 
        return binary(n,arr,k,s,e,m);
}
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
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2; 
    int ans = binary(n,arr,k,s,e,m);
    if(ans==0){
        printf("Not found!");
    }
    else{
        printf("Found!");
    }
}