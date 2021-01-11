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
        system("cls"); // clears the screen,, uses #include<windows.h>
        menu(); // display menu, implementation found below

        scanf("%d", &choice);

        //resets values
        x=-1;
        y=-1; 
        n=-1;

        // choices
        switch(choice){

            case 1: //perfect num or not

                while (x<0){ //loops until user gives a positive number
                    printf("Enter a positive number: ");
                    scanf("%d", &x);
                }

                if (perfectNumber(x))
                    printf("%d is a perfect number", x);
                else printf("%d is NOT a perfect number", x);
                break;

            case 2: //x raised to y
                printf("Enter value for x: ");
                scanf("%d", &x);

                printf("Enter value for y: ");
                scanf("%d", &y);

                if (y<0)
                    printf("%d raised to the %d is %.5lf", x, y, 1/power(x,abs(y)));
                else 
                    printf("%d raised to the %d is %.0lf", x, y, power(x,y));

                break;
            case 3: //factorial
                while (n<0){  //loops until user gives a positive number
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }
                printf("%d! = %lld", n, factorial(n));
                break;

            case 4: //fibonacci
                while (n<0){
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }
                
                fibo(n);

                break;

            case 5: //exit
                return 0;
        }

        pause(); // pause,, otherwise the program will clearscreen after algo is finished, cannot view results
    }


    return 0;
}

int perfectNumber(int n){
    int i, sum=0;

    //finds factors and sums it
    for (i=1; i<n; i++){ 
        if (n%i == 0) 
            sum += i;
    }

    if (sum == n)
        return 1; //it is a perfect number
    else return 0; // NOT a perfect number
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

//calculates factorial
long long int factorial(int n){
    int i;
    long long ans=1;

    for (i=n; i>0; i--){
        if (i != 1)
            printf("%d*",i); // for printing purposes
        
        else 
            printf("%d = ",i); // for printing purposes
        
        ans *= i; // factorial algo
    }

    return ans;
}

//calculates fibonacci sequence
void fibo (int n){
    int i, a=1, b=1;

    for (i=1; i<=n; i++){
        if (i%2 == 0){ // for even places, b is used
            printf("%d ", b);
            b = a+b;
        }
        else { // for odd places, a is used
            printf("%d ", a);
            a = a+b;
        }

    }
    return;
}

//menu
void menu(){
    printf("1. Perfect Number or Not \n");
    printf("2. X Raised to Y \n");
    printf("3. Factorial \n");
    printf("4. Fibonacci \n");
    printf("5. Exit \n\n");
    printf("Enter a number to choose: ");

    return;
}

// just asks the user to enter any key
void pause(){
    char x;
    printf("\nPress any key to continue...");
    x=getch(); // getch() uses #include<conio.h>
    return;
}