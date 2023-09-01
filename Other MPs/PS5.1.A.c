#include<stdio.h>

void swap (int* a, int* b);

int main(){

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (b > a)
        swap(&a , &b);

    if (c > a)
        swap(&a , &c);
    

    if (c > b)
        swap(&b, &c);
    
    printf("%d %d %d", a, b, c);

    return 0;
}

void swap (int* a, int* b){
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;

    return;
}