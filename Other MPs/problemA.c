#include<stdio.h>

int main(){
    //initialize variables
    long long int n, temp, x;
    int yr=0, month=0, day=0, hr=0, min=0, sec=0;

    printf("Enter time in seconds: ");
    scanf("%lld", &n);

    while (n < 0){ //loops if input is negative
        printf("Time cannot be negative. Enter again: ");
        scanf("%lld", &n);
    }

    temp=n;

    //calculate years
    x=60*60*24*30*12;
    if (n >= x){
        yr = n/x;
        n -= yr*x;
    }

    //calculate months
    x=60*60*24*30;
    if (n >= x){
        month = n/x;
        n -= month*x;
    }

    //calculate days
    x=60*60*24;
    if (n >= x){
        day = n/x;
        n -= day*x;
    }

    //calculate hours
    x=60*60;
    if (n >= x){
        hr = n/x;
        n -= hr*x;
    }

    //calculate minutes
    x=60;
    if (n >= x){
        min = n/x;
        n -= min*x;
    }

    //calculate seconds
    sec = n;

    //print result
    printf("%lld second/s is \n%d year/s, \n%d month/s, \n%d day/s, \n%d hour/s, \n%d minute/s, \n%d second/s.\n\n", temp, yr, month, day, hr, min, sec);
    
    return 0;
}