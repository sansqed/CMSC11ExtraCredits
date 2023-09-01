#include<stdio.h>
#include<math.h>

long long int factorial(int n);
int multiply(int a, int b);

int main(){


//Factorial without using the multiplication operator
    printf("%lld", factorial(5));
    // printf("%d", multiply(5,3));



// primality check without modulo
    /* 
    int x=5;

    // if ((float)x/2 != (int)x/2)
    //     printf("prime");
    // else printf("not prime");

    unsigned long long int i;
    for (i=0; i<8589869056; i++)
        printf("%llu \n", i); 
    */


    return 0;
}

long long int factorial(int n){
    int i, j;
    // long long int ans, ans1=1, ans2=1;
    int ans=1;

    // int x=2, y=3;

    for (i=2; i<=n; i++)
        ans = multiply(ans, i);
        

    return ans;
}


int multiply(int a, int b){
    int i, ans=0;

    for (i=1; i<=b; i++)
        ans += a;
    
    return ans;
}