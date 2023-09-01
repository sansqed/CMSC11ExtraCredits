#include<stdio.h>

int main (){

    float rainfall;

    scanf("%f", &rainfall);
    
    if (rainfall > 7.5 && rainfall <= 15)
        printf("Yellow warning");

    else if (rainfall > 15 && rainfall <=30)
        printf("Orange warning");

    else if (rainfall > 30)
        printf("Red warning");

    else 
        printf("No need to worry");

    return 0;
}


/*

< 2.5mm     light
2.5-7.5     moderate
7.5-15      heavy (yellow)      flooding is possible
15-30       intense (orange)    flooding is threatening
> 30        torrential (red)    serious flooding

*/