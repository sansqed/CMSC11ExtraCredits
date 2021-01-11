/*
Author: Alwyn Dy
Date: 21/1/11
MP 6.3
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

int perfectNumber(int n);
double power(int a, int b);
long long int factorial(int n);
void fibo (int n);
void menu();
void pause();

int main(){
    int choice, x=-1, y=-1, n=-1;

    while (1){
        system("cls");
        menu();

        scanf("%d", &choice);

        x=-1;
        y=-1; 
        n=-1;
        switch(choice){

            case 1:
                while (x<0){
                    printf("Enter a positive number: ");
                    scanf("%d", &x);
                }

                if (perfectNumber(x))
                    printf("%d is a perfect number", x);
                else printf("%d is NOT a perfect number", x);
                break;

            case 2:
                printf("Enter value for x: ");
                scanf("%d", &x);

                printf("Enter value for y: ");
                scanf("%d", &y);

                printf("%d raised to the %d is %.2lf", x, y, y<0? 1/power(x,abs(y)):power(x,y));

                break;
            case 3:
                while (n<0){
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }
                printf("%d! = %lld", n, factorial(n));
                break;

            case 4:
                while (n<0){
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }
                
                fibo(n);

                break;
            case 5:
                return 0;
        }

        pause();
    }


    return 0;
}

int perfectNumber(int n){
    int i, sum=0;

    for (i=1; i<n; i++){
        if (n%i == 0)
            sum += i;
    }

    if (sum == n)
        return 1;
    else return 0;
}

double power(int x, int y){
    int i; 
    double ans=1;

    for (i=0; i<y; i++){
        ans *= x;
    }

    return ans;
}

long long int factorial(int n){
    int i;
    long long ans=1;

    for (i=n; i>0; i--){
        if (i != 1){
            printf("%d*",i);
            ans *= i;
        }
        else {
            printf("%d = ",i);
            ans *= i;
        }
    }

    return ans;
}

void fibo (int n){
    int i, a=1, b=1;

    for (i=1; i<=n; i++){
        if (i%2 == 0){
            printf("%d ", b);
            b = a+b;
        }
        else {
            printf("%d ", a);
            a = a+b;
        }

    }
    return;
}


void menu(){
    printf("1. Perfect Number or Not \n");
    printf("2. X Raised to Y \n");
    printf("3. Factorial \n");
    printf("4. Fibonacci \n");
    printf("5. Exit \n\n");
    printf("Enter a number to choose: ");

    return;
}

void pause(){
    char x;
    printf("\nPress any key to continue...");
    x=getch();
    return;
}