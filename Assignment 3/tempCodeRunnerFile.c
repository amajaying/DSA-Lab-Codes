// first check if p is prime or not and then gcd of (x,p)=1 and then

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a;
    int x, p;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter a number: ");
    scanf("%d", &p);
    printf("Enter the power: ");
    scanf("%d", &a);

      printf("Finding GCD:");
    // now checking if p is prime or not:
    int c = 0;
    for(int i = 2; i<p/2; i++){
        if(p%i==0)
            c++;
    }

    if(c>0)
        exit(0);
    else if(c==0){
        printf("Finding GCD:");
        // now finding GCD
        int ans = 0;
        for( int i = 1; i <= x && i <= p; ++i)  
        {  
            if (x % i ==0 && p % i == 0)  
                ans = i; 
        }
        if(ans!=1)
            exit(1);
        else{
            printf("Finding Lastnumber:");
            int z = pow(x,a);
            int lastans = z%p;
            printf("The last ans is: %d",lastans);
        }

  
    }
}