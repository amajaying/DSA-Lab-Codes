// Not completed!
#include <stdio.h>

void subseq(char arr[], int n){
    int i,j,k,l;
    for(l=1;l<=n;l++){
        for( i=0;i<=n-l;i++){
            j=i+l-1;
            for(k=i;k<=j;k++)
            printf("%c",arr[k]);
             printf(" ");
        }
}
}

int main(){
    char input[30];
    printf("Enter string: ");
    scanf("%s",input);
    int len=0;
    while(input[len]!='\0'){
      len++;
    }
    subseq(input,len);
    return 0;
}