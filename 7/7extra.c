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
void createBox(int width, int height, int xPos, int yPos);
void gotoxy(int x, int y);
int choice(int xPos, int yPos, int choices);

int main(){
    int n=-1, i, ctr;
    unsigned long long int temp;

    while (1){
        system("cls"); // clears the screen, uses windows.h
        menu(); //displays menu

        n=-1;
        switch(choice(26,4,3)+1){

            case 1: //first n perfect numbers
                gotoxy(23, 13);
                while (n<0){
                    printf("Enter a positive numer: ");
                    scanf("%d", &n);
                }

                ctr=0;

                gotoxy(23, 14);
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
                gotoxy(23, 13);
                while (n<0){
                    printf("Enter a positive numer: ");
                    scanf("%d", &n);
                }
                
                gotoxy(23, 14);
                printf("%ld", factorial(n));
                break;

            case 3: //primality check w/o modulo
                gotoxy(23, 13);
                while (n<0){
                    printf("Enter a positive numer: ");
                    scanf("%d", &n);
                }

                gotoxy(23, 14);
                if (isPrime(n))
                    printf("%d is prime", n);
                else printf("%d is NOT prime", n);
                
                break;

            case 4://exit
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



void menu (){
	int x=25,y=2, z=3;
	
	createBox(65,10,x-5,y-1);
	gotoxy(x+9,y); printf("MP 7");
	
	gotoxy(x,++y+1); printf("[ ] 1. First n Perfect Numbers");
	gotoxy(x,++y+1); printf("[ ] 2. Factorial without using the multiplication operator");
	gotoxy(x,++y+1); printf("[ ] 3. Primality Check without using the modulo operator");
	gotoxy(x,++y+1); printf("[ ] 4. Exit");

    gotoxy(x-3,++y+2); printf("note: use arrow keys to navigate");
	return;
}

// just asks the user to enter any key
void pause(){
    char x;
    gotoxy(23, 17);
    printf("Press any key to continue...");
    x=getch();
    return;
}

//creates double-lined box
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

//allows movement of cursor to (x,y) location,, uses windows.h
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
