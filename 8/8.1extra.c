/*
Author: Alwyn Dy
Date: 21/1/11
MP 8.1
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

void getArr (int arr[], int size, int xPos, int yPos);
void printArr(int arr[], int size);
void resetArr(int arr[], int size);
void reverse (int arr[], int size);
void swap (int* a, int* b);
int palindromic (int arr[], int size);
int isSorted(int arr[], int size);
int binarySeach(int arr[], int size, int x);
int digitCounter (int n);
void findMax (int arr[], int size, int saveMax[]);
void findMin(int arr[], int size, int saveMin[]);
void print1InArray(int arr[], int size);

void menu();
void pause();
void createBox(int width, int height, int xPos, int yPos);
void gotoxy(int x, int y);
int choice(int xPos, int yPos, int choices);


int main(){
    int size=10, size2=20; //////////////////////////////////////////////// CHANGE THE SIZE BEFORE SUBMIT
    int i, x, pos, digits;
    int arr[size], arr2[size], freq[10], tempArr[10];

    while (1){
        system("cls");
        menu();

        
        switch(choice(26,4,4)+1){

            case 1:
                getArr(arr, size, 23, 13);
                reverse(arr, size);

                gotoxy(23, 13+size+1);
                printArr(arr, size);

                break;

            case 2:
                getArr(arr, size, 23, 13);
                
                gotoxy(23, 13+size+1);
                if (palindromic(arr,size))
                    printf("The array is palindromic");
                else printf("The array is NOT palindromic");

                break;

            case 3:
                gotoxy(23, 13);
                printf("Enter a sorted array.\n");
                getArr(arr, size, 23, 14);

                i=0;
                while (isSorted(arr, size)==0){
                    i++;
                    gotoxy(23, 13 + ((size*i)+1));
                    printf("Array is not sorted. Enter again\n");
                    getArr(arr, size, 23, 14 + ((10*i)+1));
                }


                gotoxy(23, 25 + (size*i)+1);
                printf("Enter a number to search: ");
                scanf("%d", &x);

                pos = binarySeach(arr, size, x);

                gotoxy(23, 27 + (size*i)+1);
                if (pos == -1)
                    printf("%d is not in the array", x);
                else printf("%d is in index %d", x, pos);

                break;

            case 4:
                getArr(arr2, size2, 23, 13);
                resetArr(freq, 10);

                for (i=0; i<size2; i++){
                    digits=digitCounter(arr2[i]);
                    freq[digits-1]++;
                }

                gotoxy(23, 13+size2+1);
                printArr(freq, 10);
                
                gotoxy(10, 15+size2+1);
                findMax(freq, 10, tempArr);
                print1InArray(tempArr, 10);
                printf("digit(s) numbers appear the most in the array.");

                gotoxy(10, 16+size2+1);
                findMin(freq, 10, tempArr);
                print1InArray(tempArr, 10);
                printf("digit(s) numbers appear the least in the array");
                break;

            case 5:
                return 0;

        }

        pause();
    }


    return 0;
}

void getArr (int arr[], int size, int xPos, int yPos){
    int i;
    

    for (i=0; i<size; i++){
        gotoxy(xPos, yPos++);
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

void reverse (int arr[], int size){
    int i;

    for (i=0; i<size/2; i++){
        swap(&arr[i], &arr[size-1-i]);
    }

    return;

}

void swap (int* a, int* b){
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;

    return;
}


int palindromic (int arr[], int size){
    int i;

    for (i=0; i<size/2; i++){
        if (arr[i] != arr[size-1-i])
            return 0;
    }
    return 1;
}

int isSorted(int arr[], int size){
    int i;

    for (i=0; i<size-1; i++){
        if (arr[i] > arr[i+1])
            return 0;
    }
    return 1;

}

int binarySeach(int arr[], int size, int x){
    int l=0, r=size-1, mid;

    while (l<=r){
        mid = (l+r)/2;
        if (arr[mid] < x)
            l = mid + 1;
        else if (arr[mid] > x)
            r = mid - 1;
        else
            return mid;
    }

    return -1;
}

int digitCounter (int n){
    int ctr=0;

    while (n!=0){
        ctr++;
        n /= 10;
    }

    return ctr;
}

void findMax (int arr[], int size, int saveMax[]){
    int i, max=arr[0];

    resetArr(saveMax, 10);

    for (i=1; i<size; i++){
        if (arr[i]>max)
            max = arr[i];
    }

    for (i=0; i<size; i++){
        if (max == arr[i])
            saveMax[i]=1;
    }

    return;
}

void findMin(int arr[], int size, int saveMin[]){
    int i, min=arr[0];

    resetArr(saveMin, 10);

    for (i=1; i<size; i++){
        if (arr[i]<min && arr[i]!=0)
            min = arr[i];
    }

    // printf("/%d/ ", min);

    for (i=0; i<size; i++){
        if (min == arr[i])
            saveMin[i]=1;
    }
    return;
}

void print1InArray(int arr[], int size){
    int i;
    for (i=0; i<size; i++){
        if (arr[i]==1)
            printf("%d ", i+1);
    }
    return;
}


void menu (){
	int x=25,y=2, z=3;
	
	createBox(39,10,x-5,y-1);
	gotoxy(x+9,y); printf("MP 8.1");
	
	gotoxy(x,++y+1); printf("[ ] 1. Reverse");
	gotoxy(x,++y+1); printf("[ ] 2. Palindromic");
	gotoxy(x,++y+1); printf("[ ] 3. Search");
    gotoxy(x,++y+1); printf("[ ] 4. Count n-digit numbers");
	gotoxy(x,++y+1); printf("[ ] 5. Exit");

    gotoxy(x-3,++y+2); printf("note: use arrow keys to navigate");
	return;
}


void pause(){
    char x;
    gotoxy(23, 39);
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