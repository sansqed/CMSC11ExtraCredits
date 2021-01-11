/*
Author: Alwyn Dy
Date: 21/1/11
MP 8.1
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

void getArr (int arr[], int size);
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

int main(){
    int size=10, size2=20; //////////////////////////////////////////////// CHANGE THE SIZE BEFORE SUBMIT
    int choice, i, x, pos, digits;
    int arr[size], arr2[size], freq[10], tempArr[10];

    while (1){
        system("cls"); //clears screen, uses windows.h
        menu(); //display menu

        scanf("%d", &choice);

        
        switch(choice){

            case 1: //reverse
                // ask input
                getArr(arr, size);

                //reverse
                reverse(arr, size);

                //prints reversed array
                printArr(arr, size);

                break;

            case 2: //palindromic
                // ask input
                getArr(arr, size);
                
                
                if (palindromic(arr,size))
                    printf("The array is palindromic");
                else printf("The array is NOT palindromic");

                break;

            case 3: //search
                // ask input
                printf("Enter a sorted array.\n");
                getArr(arr, size);

                // loops unless array is sorted
                //isSorted() implementation below
                while (isSorted(arr, size)==0){ 
                    printf("\nArray is not sorted. Enter again\n");
                    getArr(arr, size);
                }

                printf("Enter a number to search: ");
                scanf("%d", &x);

                //stores position of x,, if x is not in array, pos=-1;
                pos = binarySeach(arr, size, x);

                if (pos == -1)
                    printf("%d is not in the array", x);
                else printf("%d is in index %d", x, pos);

                break;

            case 4: //count n-dgit numbers

                getArr(arr2, size2);
                resetArr(freq, 10); //resets values in freq array to 0

                //counts # of digits per index
                //stores it in freq array
                //index in freq array is just one less than the digit
                for (i=0; i<size2; i++){ 
                    digits=digitCounter(arr2[i]);
                    freq[digits-1]++;
                }


                printArr(freq, 10);
                printf("\n");

                //finds maxfrequency, flags index of tempArr that is has max freq (value is 1 in that location)
                //can accomodate multiple max frequency (i.e. more than 1 digits with appeared the most)
                findMax(freq, 10, tempArr); 

                print1InArray(tempArr, 10); //prints all index+1 that has value of 1 in tempArr
                printf("digit(s) numbers appear the most in the array. \n");

                //same with max frequency
                findMin(freq, 10, tempArr);
                print1InArray(tempArr, 10);
                printf("digit(s) numbers appear the least in the array");
                break;

            case 5: //exits
                return 0;

        }

        pause(); // pause,, otherwise the program will clearscreen after algo is finished, cannot view results
    }


    return 0;
}

//function to ask user to input in array
void getArr (int arr[], int size){
    int i;
    

    for (i=0; i<size; i++){
        printf("Index %d: ", i);
        scanf("%d", &arr[i]);
    }

    return;
}

//function to print array
void printArr(int arr[], int size){
    int i;

    for (i=0; i<size; i++)
        printf("%d ", arr[i]);

    return;
}

//resets values in array to 0
void resetArr(int arr[], int size){
    int i;

    for (i=0; i<size; i++){
        arr[i] = 0;
    }
    return;
}

//reverse array for #1
void reverse (int arr[], int size){
    int i;

    for (i=0; i<size/2; i++){
        swap(&arr[i], &arr[size-1-i]); 
    }

    return;

}

//used in reverse function,, uses pointers
void swap (int* a, int* b){
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;

    return;
}

//checks if palindromic
int palindromic (int arr[], int size){
    int i;

    //loops from both ends to middle
    for (i=0; i<size/2; i++){ 
        if (arr[i] != arr[size-1-i]) //if ends dont match, not palindrome, return 0
            return 0; //not palindrome
    }
    return 1; // is palindrome
}

// checks if sorted
int isSorted(int arr[], int size){
    int i;

    for (i=0; i<size-1; i++){
        if (arr[i] > arr[i+1]) //compares index i to its right,, if index i is bigger, not sorted, return 0
            return 0; //not sorted
    }
    return 1; // is sorted

}

//binary search lmao
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

//counts # of digit in n
int digitCounter (int n){
    int ctr=0;

    //continuouslt divides n by 10 until n==0, increments counter each time
    while (n!=0){ 
        ctr++;
        n /= 10;
    }

    return ctr;
}


void findMax (int arr[], int size, int saveMax[]){
    int i, max=arr[0];

    resetArr(saveMax, 10);

    for (i=1; i<size; i++){ //finds largest value
        if (arr[i]>max)
            max = arr[i];
    }

    //checks if other indexes is also max. if it is, flags the corresponding index of saveMax
    for (i=0; i<size; i++){
        if (max == arr[i])
            saveMax[i]=1;
    }

    return;
}

void findMin(int arr[], int size, int saveMin[]){
    int i, min=arr[0];

    resetArr(saveMin, 10);

    for (i=1; i<size; i++){ //finds smallest value
        if (arr[i]<min && arr[i]!=0)
            min = arr[i];
    }

    // printf("/%d/ ", min);

    //checks if other indexes is also min. if it is, flags the corresponding index of saveMin
    for (i=0; i<size; i++){
        if (min == arr[i])
            saveMin[i]=1;
    }
    return;
}

// prints the index+1 that has value of 1,, flagged from findMin and findMax fns
void print1InArray(int arr[], int size){
    int i;
    for (i=0; i<size; i++){
        if (arr[i]==1)
            printf("%d ", i+1);
    }
    return;
}


void menu(){
    printf("1. Reverse \n");
    printf("2. Palindromic \n");
    printf("3. Search \n");
    printf("4. Count n-digit numbers \n");
    printf("5. Exit \n\n");
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