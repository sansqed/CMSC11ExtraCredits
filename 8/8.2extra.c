/*
Author: Alwyn Dy
Date: 21/1/11
MP 8.2
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int hexToDec (char* str);
int isValidHex (char *str);
long int power(int a, int b);
int atoii(char chara);
int isSubstring(char* str1, char *str2);
int countWords (char *str);

void menu();
void pause();
void createBox(int width, int height, int xPos, int yPos);
void gotoxy(int x, int y);
int choice(int xPos, int yPos, int choices);

int main(){
    int i, digits;
    char str[50], str2[50];

    while (1){
        system("cls"); //clears screen, uses windows.h
        menu(); //display menu

        
        switch(choice(26,4,3)+1){

            case 1: //hex to decimal
                gotoxy(23, 13);
                printf("Enter a string: ");
                gets(str); 

                i=0;
                 //if user entered an invalid hex, loops until valid hex is entered
                while (isValidHex(str)==0){
                    i++;
                    gotoxy(23, 13+i);
                    printf("Enter a string: ");
                    gets(str);
                }


                // puts(str);
                gotoxy(23, 15+i);
                printf("%s in decimal is %d", str, hexToDec(str));
                break;

            case 2: //substring
                gotoxy(23, 13);
                printf("Enter string 1: ");
                gets(str);

                gotoxy(23, 15);
                printf("Enter string 2: ");
                gets(str2); 

                gotoxy(23, 17);
                printf("%s", isSubstring(str, str2)? "Yes it is a substring":"No it is not");
                break;

            case 3: //count words
                gotoxy(23, 13);
                printf("Enter a string: ");
                gets(str);

                gotoxy(23, 15);
                printf("The string has %d words.", countWords(str));
                break;

            case 4:
                return 0;

        }

        pause(); // pause,, otherwise the program will clearscreen after algo is finished, cannot view results
    }


    return 0;
}

//converts hex to decimal
int hexToDec (char* str){
    int len=strlen(str);
    int i=0, dec=0;

    while (i<len){
        switch(str[i]){

            //for letter values
            case 'A': case 'a':
                dec+= (10*power(16,len-1-i)); 
                break;
            case 'B': case 'b':
                dec+= 11*power(16,len-1-i); 
                break;
            case 'C': case 'c':
                dec+= 12*power(16,len-1-i); 
                break;
            case 'D': case 'd':
                dec+= 13*power(16,len-1-i); 
                break;
            case 'E': case 'e':
                dec+= 14*power(16,len-1-i); 
                break;
            case 'F': case 'f':
                dec+= 15*power(16,len-1-i); 
                break;

            //for numeric values
            default:
                dec += atoii(str[i])*power(16,len-1-i); //atoii() converts ascii value of number to int value
                break;
        }
        i++;
        // printf("%d ", dec);
    }

    return dec;
}

//checks if string is a valid hex string
int isValidHex (char *str){
    int i=0, temp, len=strlen(str);

    while (i<len){
        temp=str[i];
        if (temp<48 || (temp>57 && temp<65) || (temp>70 && temp<97) || temp>102) //checks if char is not in accepted ascii value range
            return 0; // not valid if true
        i++; 
    }

    return 1; //otherwise it is valid
}

//calculate exponential
long int power(int a, int b){
    int i; 
    long int ans=1;

    for (i=0; i<b; i++){
        ans *= a;
    }

    return ans;
}

//subtracts 48 from ascii value of number to convert to int
int atoii(char chara){
    return ((int)chara-48);
}

// checks if str1 is substring of str2
int isSubstring(char* str1, char *str2){
    int i, j, flag=0, match=0;
    int lenStr1 = strlen(str1), lenStr2 = strlen(str2);

    //loops until str1 fits in str2
    for (i=0; i<=lenStr2-lenStr1; i++){
        // printf("str2 %c \n", str2[i]);

        if (str1[0]==str2[i]){ // checks if first char of str1 is in str2
            // printf("match!");
            for (j=0; str1[j]!='\0'; j++){ // loops entirety of str1 to check if all char is in str2
                // printf("comparing %c and %c\n", str1[j], str2[j+i]);
                if (str1[j]!= str2[i+j])  //if a char is not same, no match
                    match=0;
                else match=1; //else, str1 is subset of str2
            }
        }

    }
    
    return match;
}

//count number of words in str
int countWords (char *str){
    int i, temp, count=0;

    for (i=0; str[i]!='\0'; i++){ //loops until end of string
        temp=str[i+1]; //temp is just char next of index
        if (str[i]==32 && (temp>=33 && temp<=126)) // must have a space followed by a character to count as a word
            count++; //increment word count
        else if (i==0)
            if (str[0]>=33 && str[0]<=126) // accounts for the blindspot,, index0 wont be evaluated from above algo
                count++;
    }

    return count;

}

void menu (){
	int x=25,y=2, z=3;
	
	createBox(39,10,x-5,y-1);
	gotoxy(x+9,y); printf("MP 8.2");
	
	gotoxy(x,++y+1); printf("[ ] 1. Hexadecimal to Decimal");
	gotoxy(x,++y+1); printf("[ ] 2. Substring");
	gotoxy(x,++y+1); printf("[ ] 3. Count Words");
	gotoxy(x,++y+1); printf("[ ] 4. Exit");

    gotoxy(x-3,++y+2); printf("note: use arrow keys to navigate");
	return;
}


void pause(){
    char x;
    gotoxy(23, 30);
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