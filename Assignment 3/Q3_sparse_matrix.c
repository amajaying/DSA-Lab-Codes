#include<stdio.h>
int main(){
<<<<<<< HEAD
    int r,c;
    printf("Enter the no of rows and columns: ");
    scanf("%d %d",&r,&c);
    int arr[r][c];
    printf("Enter the elements: ");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int count=0;
    int total=r*c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    float percentage = (float)count*100/total;
    if(percentage<=60 || percentage>=75){
        printf("Not sparse");
    }else{
        printf("Sparse");
    }
    return 0;
=======
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
>>>>>>> 0f18e4819c9a2bf8e84caf50d79aa97d431cdd3f

}