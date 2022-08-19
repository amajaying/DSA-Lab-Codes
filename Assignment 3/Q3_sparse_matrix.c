#include <stdio.h>
int main(){
    int n,m;
    printf("Enter size of 2D array: ");
    scanf("%d%d", &n, &m);
    int arr[n][m];
    int zeroCount = 0;
    int oneCount = 0;
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==0)
                zeroCount++;
        }
    }
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Zero = %d, One = %d", zeroCount,oneCount);
    int total = n*m;
    printf("Total = %d", total);
    float th = (((float)zeroCount/total)*100);
    printf("Th = %f", th);
    if(th<60 || th>74){
        printf("Not Sparse!");
    }
    else{
        printf("Sparse");
    }

}