/*
Author: Alwyn Dy
Date: 21/1/10
MP 6.1 #2

Ask the user to enter a number, say n.  Determine if this number is a Germain Prime or not.  A number n is said to be Germain if it is prime and 2*n + 1 is also prime.  Samples: 5 is Germain because 5 is prime and so is 2*5+1 which is 11.  7 is not Germain, although it is prime, 2*7+1 is not prime.
*/

#include<stdio.h>
#include<math.h>

int isPrime(int num);

int main(){
    int n;

    scanf("%d", &n);

    if (isPrime(n) && isPrime((2*n)+1))
        printf("It is a Germain Prime");
    else printf("It is NOT a Germain Prime");

    return 0;
}

int isPrime(int num){

    int i;

    for (i=2; i<=sqrt(num); i++){

        if (num%i == 0)
            return 0;
    }

    return 1;
    
}