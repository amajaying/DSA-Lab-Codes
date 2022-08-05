#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b;
    printf("Enter the size of 2D array: ");
    scanf("%d%d", &a, &b);

    // creating a 2D dynamic array
    int* arr = malloc((sizeof(int)*a*b));

    // storing 
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            scanf("%d", &arr[i*b+j]);
        }
    }
    printf("\nThe 2D array is: ");

    // Printing
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("%d ", arr[i*b+j]);
        }
    }
}