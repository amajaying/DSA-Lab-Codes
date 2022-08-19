#include <stdio.h>
int main(){
    int n,m;
    printf("Enter size of 2D array: ");
    scanf("%d%d", &m, &n);
    int arr[n][m];
    int zeroCount = 0;
    int oneCount = 0;
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==0)
                zeroCount++;
            else if(arr[i][j]==1)
                oneCount++;
        }
    }

}