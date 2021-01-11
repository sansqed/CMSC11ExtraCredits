/*
Author: Alwyn Dy
Date: 21/1/11
MP 7
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

unsigned long long int perfectNumber(unsigned long long int n);
int multiply(int a, int b);
double power(int a, int b);
long int factorial(int n);
int isPrime(int n);
void menu();
void pause();

int main(){
    int choice, n=-1, i, ctr;
    unsigned long long int temp;

    while (1){
        system("cls"); // clears the screen, uses windows.h
        menu(); //displays menu

        scanf("%d", &choice);

        n=-1;
        switch(choice){

            case 1: //first n perfect numbers
                while (n<0){
                    printf("Enter a positive numer: ");
                    scanf("%d", &n);
                }

                ctr=0;

                
                for (i=1; ctr<n; i++){
                    if (isPrime(i)){
                        temp=power(2, i-1)*(power(2,i)-1); //source: wikipedia lmao
                        if (perfectNumber(temp)){
                            printf("%llu ", temp);
                            ctr++;
                        }
                    }
                }

                break;

            case 2: //factorial w/o multiplication
                while (n<0){
                    printf("Enter a positive numer: ");
                    scanf("%d", &n);
                }

                printf("%ld", factorial(n));
                break;

            case 3: //primality check w/o modulo
                while (n<0){
                    printf("Enter a positive numer: ");
                    scanf("%d", &n);
                }

                if (isPrime(n))
                    printf("%d is prime", n);
                else printf("%d is NOT prime", n);
                
                break;

            case 4: //exit
                return 0;

        }

        pause(); // pause,, otherwise the program will clearscreen after algo is finished, cannot view results
    }


    return 0;
}

//perfect numbers,, unsigned long long int to allow for max possible value
unsigned long long int perfectNumber(unsigned long long int n){
    unsigned long long int i, sum=0;

    for (i=1; i<n; i++){
        if (n%i == 0)
            sum += i;
    }

    if (sum == n)
        return 1;
    else return 0;
}

//checks primality
int isPrime(int n){
    int i;

    for (i=2; i<=sqrt(n); i++){
        if ((float)n/i == (int)n/i) // determines if n has factors. if yes, not prime
            return 0; 
    }

    return 1; // cannot find factors therefore prime
}

//calculates exponential
double power(int x, int y){
    int i; 
    double ans=1;

    for (i=0; i<y; i++){
        ans *= x;
    }

    return ans;
}

long int factorial(int n){
    int i, j;
    // long long int ans, ans1=1, ans2=1;
    int ans=1;

    // int x=2, y=3;

    for (i=2; i<=n; i++) //repeated use of multiply function
        ans = multiply(ans, i);
        

    return ans;
}


int multiply(int a, int b){
    int i, ans=0;

    for (i=1; i<=b; i++) //repeated addition
        ans += a;
    
    return ans;
}



void menu(){
    printf("1. First n Perfect Numbers \n");
    printf("2. Factorial without using the multiplication operator \n");
    printf("3. Primality Check without using the modulo operator \n");
    printf("4. Exit \n\n");
    printf("Enter a number to choose: ");

    return;
}

// just asks the user to enter any key
void pause(){
    char x;
    printf("\nPress any key to continue...");
    x=getch();
    return;
}