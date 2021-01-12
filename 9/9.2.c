/*
Author: Alwyn Dy
Date: 21/1/11
MP 9.2
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

int perfectNumber(int n);
double power(int a, int b);
long long int factorial(int n);
long int fibo (int n);
int summation(int n);
long int decToOctal(int n);

void menu();
void pause();

int main(){
    int choice, x=-1, y=-1, n=-1, flag=0;

    while (1){
        system("cls"); // clears the screen,, uses #include<windows.h>
        menu(); // display menu, implementation found below

        scanf("%d", &choice);

        //resets values
        x=-1;
        y=-1; 
        n=-1;
        flag=0;

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
                    printf("%d raised to %d is %.5lf", x, y, 1/power(x,abs(y)));
                else 
                    printf("%d raised to %d is %.0lf", x, y, power(x,y));

                break;
            case 3: //factorial
                while (n<0){  //loops until user gives a positive number
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }
                printf("%d! = ", n);
                printf("%lld", factorial(n));
                break;

            case 4: //fibonacci
                while (n<=0){
                    printf("Enter a positive integer: ");  
                    scanf("%d", &n);
                }
                
                //for prefixes in numbers (e.g. 1st, 2nd, 4th, ....)
                if (n==11 || n==12 || n==13)
                    flag=1;
                printf("The %d%s element of the fibonacci sequence is %ld" ,n , flag==1? "th":n%10==1? "st":n%10==2? "nd":n%10==3? "rd":"th" , fibo(n));

                break;
            
            case 5: //summation
                while (n<0){
                    printf("Enter a positive integer: ");  
                    scanf("%d", &n);
                }
                 
                printf("\n Summation of %d is %d", n, summation(n));
                break;
                
            case 6: //dec to octal
                while (n<0){
                    printf("Enter a positive integer: ");  
                    scanf("%d", &n);
                }

                printf("\n %d in octal is %ld", n, decToOctal(n));
                break;

            case 7: //exit
                return 0;
        }

        pause(); // pause,, otherwise the program will clearscreen after algo is finished, cannot view results
    }


    return 0;
}

int perfectNumber(int n){
    int i, sum=0;

    if (n==0)
        return 0;

    //finds factors and sums it
    for (i=1; i<n; i++){ 
        if (n%i == 0) 
            sum += i;
    }

    if (sum == n)
        return 1; //it is a perfect number
    else return 0; // NOT a perfect number
}

//calculates exponential, recursive
double power(int x, int y){
    if (y==1 || y==-1) //exit condition
        return x;
    else if (y==0)
        return 1;
    
    if (y>=0)
        return x * power(x,y-1);
    else
        return x * power(x,y+1);
}

//calculates factorial, recursive
long long int factorial(int n){

    if (n==1){ //exit condition
        printf("%d = ", n);
        return (long long int)1;
    }
    else if (n==0)
        return 1;

    printf("%d*", n);

    return n * factorial(n-1);
}

//calculates fibonacci sequence
long int fibo (int n){
    if (n==1)
     	return 1;
    
	else if (n==0) 
		return 0;
        
    return fibo(n-1)+fibo(n-2);
}

// recursive summation
int summation(int n){
    if (n==0) //exit condition
        return 0;
    return n + summation(n-1);
}

//recursive decimal to octal conversion
long int decToOctal(int n){
    if (n/8==0) //exit condition
        return n%8;

    return (n%8) + decToOctal(n/8)*10;

}

//menu
void menu(){
    printf("1. Perfect Number or Not \n");
    printf("2. X Raised to Y \n");
    printf("3. Factorial \n");
    printf("4. Fibonacci \n");
    printf("5. Summation \n");
    printf("6. Decimal to Octal \n");
    printf("7. Exit \n\n");
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