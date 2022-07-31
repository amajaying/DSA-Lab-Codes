#include <stdio.h>
int smaxm(int a[], int n){
  int max=a[0];
  int max2=a[0];
  for(int i=0;i<n;i++){
        if(a[i]>max){
            max2=max;
            max=a[i];
        }
       else if(a[i]>max2){
            max2=a[i];
       }
  }
  return max2;
}

int sminm(int a[], int n){
    int min=a[0];
   
    int min2=a[1];
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min2=min;
            min=a[i];
        }
    }
    return min2;
}
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int maxi = smaxm(a,n);
    int mini = sminm(a,n);
    printf("Second maximum element is: %d\n",maxi);
    printf("Second minimum element is: %d\n",mini);
    return 0;
}