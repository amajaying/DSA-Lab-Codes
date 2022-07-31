#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of characters: ");
    scanf("%d",&n);
    int o;
    printf("Enter offset: ");
    scanf("%d",&o);
    char ch[n];
    printf("Enter the characters: ");
    for(int i=0; i<n; i++){
        scanf(" %c", &ch[i]);
    }

   for(int i=0; i<n; i++){
    int c = ch[i]+o;
    if((c>=65 && c<=90)||(c>=97 && c<=122)){
        printf("%C ", c);
    }
    else if(c<65|| c<97){
        int z=26+c;
        printf("%c ", z);
    }
   }
    return 0;
}