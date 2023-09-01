#include<stdio.h>
#include<math.h>

int fibo(int n);

int main(){
    // fibo(5);

    int n;

    scanf("%d", &n);
    printf(" %d", n);
    return 0;
}

int fibo(int n){
    printf("%d ", n);

    if (n==1)
            return 1;
        
    else if (n==0) 
        return 0;
        
    return fibo(n-1)+fibo(n-2);
}