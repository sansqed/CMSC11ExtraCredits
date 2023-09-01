#include<stdio.h>

int main(){
    int month, day, zod = -1;

    scanf("%d %d", &month, &day);


    switch (month){
        case 1: 
            if (day >= 20 && day <= 31)      zod = 1;
            else if (day > 0 && day < 21)    zod = 12;
            break;
        case 2:
            if (day >= 19 && day <= 29)      zod = 2;
            else if (day > 0 && day < 19)    zod = 1;
            break;
        case 3: 
            if (day >= 21 && day <= 31)      zod = 3;
            else if (day > 0 && day < 21)    zod = 2;
            break;
        case 4: 
            if (day >= 20 && day <= 30)      zod = 4;
            else if (day > 0 && day < 20)    zod = 3;
            break;
        case 5: 
            if (day >= 21 && day <= 31)      zod = 5;
            else if (day > 0 && day < 21)    zod = 4;
            break;
        case 6: 
            if (day >= 21 && day <= 30)      zod = 6;
            else if (day > 0 && day < 21)    zod = 5;
            break;
        case 7: 
            if (day >= 23 && day <= 31)      zod = 7;
            else if (day > 0 && day < 23)    zod = 6;
            break;
        case 8: 
            if (day >= 23 && day <= 31)      zod = 8;
            else if (day > 0 && day < 23)    zod = 7;
            break;
        case 9: 
            if (day >= 23 && day <= 30)      zod = 9;
            else if (day > 0 && day < 23)    zod = 8;
            break;
        case 10: 
            if (day >= 23 && day <= 31)      zod = 10;
            else if (day > 0 && day < 23)    zod = 9;
            break;
        case 11: 
            if (day >= 22 && day <= 30)      zod = 11;
            else if (day > 0 && day < 22)    zod = 10;
            break;
        case 12: 
            if (day >= 22 && day <= 31)      zod = 12;
            else if (day > 0 && day < 22)    zod = 11;
            else                             zod = -1;
            break;
        default:                             zod = -1;
    }
    

    switch (zod){
        case 1: // aquarius
            printf("Tomorrow will be canceled due to lack of interest.");
            break;
        case 2: // pisces
            printf("You are scrupulously honest, frank, and straightforward. Therefore you have few friends.");
            break;
        case 3: // aries
            printf("Do what comes naturally. Seethe and fume and throw a tantrum.");
            break;
        case 4: // taurus
            printf("You have the capacity to learn from mistakes. You'll learn a lot today.");
            break;
        case 5: // gemini
            printf("Of course you have a purpose -- to find a purpose.  ");
            break;
        case 6: // cancer
            printf("Are you a turtle?");
            break;
        case 7: // leo
            printf("You are confused; but this is your normal state.");
            break;
        case 8: // virgo
            printf("You are wise, witty, and wonderful, but you spend too much time reading this sort of trash.");
            break;
        case 9: // libra
            printf("You have the body of a 19 year old. Please return it before it gets wrinkled.");
            break;
        case 10: // scorpio
            printf("You will be Told about it Tomorrow. Go Home and Prepare Thyself.");
            break;
        case 11: // sagitarrius
            printf("Don't look now, but there is a multi-legged creature on your shoulder.");
            break;
        case 12: // capricorn
            printf("It is so very hard to be an on-your-own-take-care-of-yourself-because-there-is-no-one-else-to-do-it-for-you-grown-up.");
            break;
        case -1: default:
            printf("You do not think, therefore you do not exist!");
        
    }

    return 0;
}


/*

1 aquarius        jan 20 - feb 18
2 pisces          feb 19 - mar 20
3 aries           mar 21 - apr 19
4 taurus          apr 20 - may 20
5 gemini          may 21 - jun 20
6 cancer          jun 21 - jul 22
7 leo             jul 23 - aug 22
8 virgo           aug 23 - sep 22
9 libra           sep 23 - oct 22
10 scorpio         oct 23 - nov 21
11 sagitarrius     nov 22 - dec 21
12 capricorn       dec 22 - jan 19


*/