#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long int hexToDec (char* str);
long int power(int a, int b);
int isSubstring(char* str1, char *str2);
int countWords (char *str);
int atoii(char chara);
int digitCounter (int n);
void findMax (int arr[], int size, int saveMax[]);
void findMin(int arr[], int size, int saveMin[]);
void print1InArray(int arr[], int size);
void getArr (int arr[], int size);
void printArr(int arr[], int size);
void resetArr(int arr[], int size);

int main(){
    char str[10]="15B";

    // if ('a'==97)
    //     printf("haha");

    // gets (str);
    // puts (str);


    // printf("%d", atoii(str[1]));
    // printf(" decimal is %lu\n", hexToDec("11c"));
    // printf("\n");
    // printf(" decimal is %lu", hexToDec("bcbc"));


    // printf("%d", power(16,4));


    // printf("%d", strlen("strasdf"));

    // printf("%d", isSubstring("detes", "determinesdetes"));

    // printf("%d", countWords("   asdf     asdf  s ! "));
    
    ////////////////////////////////////////////////////
    /* int i, digits, size=10, size2=20;
    int arr[size], arr2[size], freq[10];

    getArr(arr2, size2);
    resetArr(freq, 10);

    for (i=0; i<size2; i++){
        digits=digitCounter(arr2[i]);
        freq[digits-1]++;
    }

    printArr(freq, 10);

    printf("\n%d digit(s) numbers appear the most in the array. ", findMax(freq, 10)+1);
    printf("\n%d digit(s) numbers appear the least in the array", findMin(freq, 10)+1); */

    int tempArr[10];
    int arr[10] = {1, 1, 2, 2, 2};

    findMin(arr, 10, tempArr);
    printArr(tempArr, 10);
    printf("\n");
    print1InArray(tempArr, 10);

    findMax(arr,10,tempArr);
    printf("\n");
    print1InArray(tempArr, 10);


    return 0;

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
        if (arr[i]>arr[max])
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

unsigned long int hexToDec (char* str){
    int len=strlen(str);
    int i=0; 
    unsigned long int dec=0;
    printf("%d\n", len);
    for (i=0; i<len; i++){
        printf("%c %d ", str[i], len-1-i);
        switch(str[i]){
            case 'A': case 'a':
                dec+= 10*power(16,len-1-i); 
                printf("/%d/ ",10*power(16,len-1-i));
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
                dec += (double)atoi(str+i)*power(16,len-1-i);
                printf("/%d/ ",atoi(str+i)*power(16,len-1-i));
                break;
        }
        printf("%d\n", dec);
    }

    return dec;
}

long int power(int a, int b){
    int i; 
    long int ans=1;

    for (i=0; i<b; i++){
        ans *= a;
    }

    return ans;
}

int isSubstring(char* str1, char *str2){
    int i, j, flag=0, match=0;
    int lenStr1 = strlen(str1), lenStr2 = strlen(str2);

    for (i=0; i<=lenStr2-lenStr1; i++){
        printf("str2 %c \n", str2[i]);
        if (str1[0]==str2[i]){
            printf("match!");
            for (j=0; str1[j]!='\0'; j++){
                printf("comparing %c and %c\n", str1[j], str2[j+i]);
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

int atoii(char chara){
    return ((int)chara-48);
}