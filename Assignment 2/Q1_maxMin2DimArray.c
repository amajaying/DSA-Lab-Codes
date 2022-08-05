#include <stdio.h>
int main(){
    int a, b;
    printf("Enter the size of 2D array: ");
    scanf("%d%d", &a, &b);
    int arr[a][b];
    printf("Enter %d elements of the array: ", a*b);
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int max = arr[0][0];
    int min = arr[0][0];
    
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if(max<arr[i][j])
                max=arr[i][j];

            if(min>arr[i][j])
                min=arr[i][j];
        }
    }

    printf("\nMaximum No: %d", max);
    printf("\nMinimum No: %d", min);

}