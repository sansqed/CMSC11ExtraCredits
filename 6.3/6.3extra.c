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
int fibo (int n);
void menu();
void pause();
void createBox(int width, int height, int xPos, int yPos);
void gotoxy(int x, int y);
int choice(int xPos, int yPos, int choices);

int main(){
    int x=-1, y=-1, n=-1, flag, flag2;

    while (1){
        system("cls"); // clears the screen,, uses #include<stdio.h>
        menu(); // display menu, implementation found below

        // scanf("%d", &choice);

        //resets values
        x=-1;
        y=-1; 
        n=-1;
        flag=0;
        flag2=0;

        //choice fn is for arrow keys navigation, implementation found below
        // uses up/down to navigate
        //parameters(xPos, yPos, #OfChoices)
        switch(choice(26,4,4)+1){

            case 1: //perfect num or not
                while (x<0){ //loops until user gives a positive number
                    gotoxy(23, 13); //gotoxy() to move terminal cursor to (x,y) coordinates
                    printf("Enter a positive number: ");
                    scanf("%d", &x);
                }

                gotoxy(23, 14);
                if (perfectNumber(x))
                    printf("%d is a perfect number", x);
                else printf("%d is NOT a perfect number", x);
                break;

            case 2://x raised to y
                gotoxy(23, 13);
                printf("Enter value for x: ");
                scanf("%d", &x);

                gotoxy(23, 14);
                printf("Enter value for y: ");
                scanf("%d", &y);

                gotoxy(23, 15);

                if (y<0)
                    printf("%d raised to %d is %.5lf", x, y, 1/power(x,abs(y)));
                else 
                    printf("%d raised to %d is %.0lf", x, y, power(x,y));

                break;
            case 3: //factorial
                while (n<0){ //loops until user gives a positive number
                    gotoxy(23, 13+flag);
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                    flag++;
                }

                gotoxy(23, 14+flag);
                printf("%d! = ", n);
                printf("%lld", factorial(n));
                break;

            case 4: //fibonacci

                while (n<0){
                    gotoxy(23, 13+flag);
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                    flag++;
                }
                
                //for prefixes in numbers (e.g. 1st, 2nd, 4th, ....)
                gotoxy(23, 14+flag);
                if (n==11 || n==12 || n==13)
                    flag2=1;
                printf("The %d%s element is %ld" ,n , flag2==1? "th":n%10==1? "st":n%10==2? "nd":n%10==3? "rd":"th" , fibo(n));

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
    else return 0; //NOT a perfect number
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
            printf("%d*",i); //for printing purposes
        
        else 
            printf("%d = ",i); //for printing purposes
        
        ans *= i; //factorial algo
    }

    return ans;
}

//calculates fibonacci sequence
int fibo (int n){
    int i, a, b;

    for (i=0; i<=n; i++){
        if (i%2 == 0){ // for even places, a is used
            if (i==0)
                a=0;
            else a = a+b;

            if (i==n)
                return a;
        }
        else { // for odd places, b is used
            if (i==1)
                b=1;
            else b = a+b;

            if (i==n)
                return b;
        }
    }
}


//menu
void menu (){
	int x=25,y=2, z=3; // starts box at location (25,2)
	
	createBox(37,10,x-5,y-1); // draws a box, implementation below
	gotoxy(x+9,y); printf("MP 6.3"); //header
	
	gotoxy(x,++y+1); printf("[ ] 1. Perfect Number or Not");
	gotoxy(x,++y+1); printf("[ ] 2. X Raised to Y");
	gotoxy(x,++y+1); printf("[ ] 3. Factorial");
	gotoxy(x,++y+1); printf("[ ] 4. Fibonacci");
	gotoxy(x,++y+1); printf("[ ] 5. Exit");

    gotoxy(x-3,++y+2); printf("note: use arrow keys to navigate");
	return;
}


// just asks the user to enter any key
void pause(){
    char x;
    gotoxy(23, 25);
    printf("Press any key to continue...");
    x=getch(); // getch() uses #include<conio.h>
    return;
}


//creates a double-lined box
void createBox(int width, int height, int xPos, int yPos){
	int row=0, col=0;
	for (row=0; row<=height; row++){
		for (col=0; col<=width; col++){
			gotoxy(xPos+col, yPos+row);
			printf("%c", row==0? col==0? 201:col==width? 187:205 : row==height? col==0? 200: col==width? 188:205 :col==0? 186: col==width? 186:0);
		}
	}
	return;
}

//function to move cursor at (x,y) location
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

// function for arrow keys navigation
int choice(int xPos, int yPos, int choices){
	
	int pos=-1;
	int i;
	
	while (getch()==224){ //exits loop when press any other key
		switch(getch()){
			case 80: //down
				pos++;

				gotoxy(xPos, yPos+(pos-1)); 
				printf(" ");
				
				if (pos>choices){
					pos=0;
					gotoxy(xPos,yPos+choices); 
					printf(" ");
				}
				
								
				break;
			case 72: //up
				pos--;
				
				gotoxy(xPos, yPos+(pos+1)); 
				printf(" ");
				
				if (pos<=-1){
					pos=choices;
					gotoxy(xPos,yPos); 
					printf(" ");
				}
				
						
				break;
		} // pos: 0-2

		gotoxy(0,0);printf("%d", pos);
		
		gotoxy(xPos, yPos+pos); printf(">");
		
	}
	
	return pos;
	
}



