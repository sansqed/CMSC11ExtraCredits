/*
Author: Alwyn Dy
Date: 21/1/10
MP 6.1 #1

Observe the  following series: 4 8 7 14 12 16 21 28 20 24 35... Ask the user to enter a number n.  Then display the first n elements of the series.
*/


#include<stdio.h>

int main(){

    int n, i, ctr1=0, ctr2=0, num1=4, num2=7;

    scanf("%d", &n);

    for (i=1; i<=n; i++){

        if ( (i+1) % 4 == 0 || i%4 == 0){   // for multiples of 7
            ctr2++;
            printf("%d ", num2*ctr2);
        }

        else {                              // for multiples of 4
            ctr1++;
            printf("%d ", num1*ctr1);
        }
    }

    return 0;
}