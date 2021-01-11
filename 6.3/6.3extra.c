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
void createBox(int width, int height, int xPos, int yPos);
void gotoxy(int x, int y);
int choice(int xPos, int yPos, int choices);

int main(){
    int x=-1, y=-1, n=-1;

    while (1){
        system("cls");
        menu();

        // scanf("%d", &choice);

        x=-1;
        y=-1; 
        n=-1;
        switch(choice(26,4,4)+1){

            case 1:
                while (x<0){
                    gotoxy(23, 13);
                    printf("Enter a positive number: ");
                    scanf("%d", &x);
                }

                gotoxy(23, 14);
                if (perfectNumber(x))
                    printf("%d is a perfect number", x);
                else printf("%d is NOT a perfect number", x);
                break;

            case 2:
                gotoxy(23, 13);
                printf("Enter value for x: ");
                scanf("%d", &x);

                gotoxy(23, 14);
                printf("Enter value for y: ");
                scanf("%d", &y);

                gotoxy(23, 15);

                if (y<0)
                    printf("%d raised to the %d is %.5lf", x, y, 1/power(x,abs(y)));
                else 
                    printf("%d raised to the %d is %.0lf", x, y, power(x,y));

                break;
            case 3:
                gotoxy(23, 13);
                while (n<0){
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }

                gotoxy(23, 14);
                printf("%d! = ", n);
                printf("%lld", factorial(n));
                break;

            case 4:

                gotoxy(23, 13);
                while (n<0){
                    printf("Enter a nonnegative integer: ");  
                    scanf("%d", &n);
                }
                
                gotoxy(23, 14);
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


void menu (){
	int x=25,y=2, z=3;
	
	createBox(37,10,x-5,y-1);
	gotoxy(x+9,y); printf("MP 6.3");
	
	gotoxy(x,++y+1); printf("[ ] 1. Perfect Number or Not");
	gotoxy(x,++y+1); printf("[ ] 2. X Raised to Y");
	gotoxy(x,++y+1); printf("[ ] 3. Factorial");
	gotoxy(x,++y+1); printf("[ ] 4. Fibonacci");
	gotoxy(x,++y+1); printf("[ ] 5. Exit");

    gotoxy(x-3,++y+2); printf("note: use arrow keys to navigate");
	return;
}



void pause(){
    char x;
    gotoxy(23, 17);
    printf("Press any key to continue...");
    x=getch();
    return;
}

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

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

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



