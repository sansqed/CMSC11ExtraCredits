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

void getArr (int arr[], int size);
void printArr(int arr[], int size);

int hexToDec (char* str);
int isValidHex (char *str);
long int power(int a, int b);
int atoii(char chara);
int isSubstring(char* str1, char *str2);
int countWords (char *str);

void menu();
void pause();

int main(){
    int choice, i, digits;
    char str[50], str2[50];

    while (1){
        system("cls");
        menu();

        scanf("%d", &choice);

        
        switch(choice){

            case 1:
                printf("Enter a string: ");
                gets(str);
                gets(str);

                while (isValidHex(str)==0){
                    printf("Enter a string: ");
                    gets(str);
                }
                // puts(str);
                printf("%s in decimal is %d", str, hexToDec(str));
                break;

            case 2:
                printf("Enter string 1: ");
                gets(str);
                gets(str);

                printf("Enter string 2: ");
                gets(str2);

                printf("%s", isSubstring(str, str2)? "Yes it is a substring":"No it is not");
                break;

            case 3:
                printf("Enter a string: ");
                gets(str);
                gets(str);

                printf("The string has %d words.", countWords(str));
                break;

            case 4:
                return 0;

        }

        pause();
    }


    return 0;
}

void getArr (int arr[], int size){
    int i;
    

    for (i=0; i<size; i++){
        printf("Index %d: ", i);
        scanf("%d", &arr[i]);
    }

    return;
}

void printArr(int arr[], int size){
    int i;

    for (i=0; i<size; i++)
        printf("%d ", arr[i]);

    return;
}

void resetArr(int arr[], int size){
    int i;

    for (i=0; i<size; i++){
        arr[i] = 0;
    }
    return;
}

int hexToDec (char* str){
    int len=strlen(str);
    int i=0, dec=0;

    while (i<len){
        switch(str[i]){
            case 'A': case 'a':
                dec+= 10*power(16,len-1-i); 
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
            default:
                dec += atoii(str[i])*power(16,len-1-i);
                break;
        }
        i++;
        // printf("%d ", dec);
    }

    return dec;
}

int isValidHex (char *str){
    int i=0, temp, len=strlen(str);

    while (i<len){
        temp=str[i];
        if (temp<48 || (temp>57 && temp<65) || (temp>70 && temp<97) || temp>102)
            return 0;
        i++;
    }

    return 1;
}

 long int power(int a, int b){
    int i; 
    long int ans=1;

    for (i=0; i<b; i++){
        ans *= a;
    }

    return ans;
}

int atoii(char chara){
    return ((int)chara-48);
}

int isSubstring(char* str1, char *str2){
    int i, j, flag=0, match=0;
    int lenStr1 = strlen(str1), lenStr2 = strlen(str2);

    for (i=0; i<=lenStr2-lenStr1; i++){
        // printf("str2 %c \n", str2[i]);
        if (str1[0]==str2[i]){
            // printf("match!");
            for (j=0; str1[j]!='\0'; j++){
                // printf("comparing %c and %c\n", str1[j], str2[j+i]);
                if (str1[j]!= str2[i+j])
                    match=0;
                else match=1;
            }
        }

    }
    
    return match;
}

int countWords (char *str){
    int i, temp, count=0;

    for (i=0; str[i]!='\0'; i++){
        temp=str[i+1];
        if (str[i]==32 && (temp>=33 && temp<=126))
            count++;
        else if (i==0)
            if (str[0]>=33 && str[0]<=126)
                count++;
    }

    return count;

}

void menu(){
    printf("1. Hexadecimal to Decimal \n");
    printf("2. Substring \n");
    printf("3. Count Words \n");
    printf("4. Exit \n\n");
    printf("Enter a number to choose: ");

    return;
}

void pause(){
    char x;
    printf("\nPress any key to continue...");
    x=getch();
    return;
}