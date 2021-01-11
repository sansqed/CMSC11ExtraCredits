/*
Author: Alwyn Dy
Date: 21/1/10
MP 6.1 #3

Ask the user to enter two numbers. The first number represents a positive integer, say n, and the second a positive integer less than 10, say b. Convert n into its equivalent in base b.
*/

#include<stdio.h>


long long int power(int a, int b);

int main(){
    int i=0, n, b;
    long long int converted = 0;

    scanf("%d", &n);
    scanf("%d", &b);

    if (b>=10){
        printf("ERROR: second integer should be less than 10");
    }


    while (n!=0){
        converted += (n%b)*power(10, i);
        n /= b;
        i++;
    }

    printf("%lld", converted);

    return 0;
}

long long int power(int a, int b){
    int i, ans=1;

    for (i=0; i<b; i++){
        ans *= a;
    }

    return ans;
}