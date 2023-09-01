/*
Author: Alwyn Dy
Date: 21/1/11
MP 6.2

Generate a random number from 1-100. Ask the user to guess this number. Give him/her 5 tries. If in the 5th try he/she isn't able to guess the number, reveal the magic number. If he/she is able to guess the number within the allotted tries, congratulate the user. Use the "higher/lower" scheme to give clues to the user. 
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randNum();

int main(){
    int i, n;
    int randNumb = randNum();

    // intro statement
    printf("Welcome! \n A random number between 1-100 has been generated. Guess the number within 5 tries or something unfortunate will happen. \n You have been warned uwu.");
    for (i=1; i<=5; i++){
        printf("\n\nAttempt %d \n Enter a number: ", i);
        scanf("%d", &n);

        // input number is HIGHER
        if (n < randNumb)
            printf("OOPS!!!!!!!!!!! \n The actual number is higher.");

        // input number is HIGHER
        else if (n > randNumb)
            printf("WRONG!!!!!!!!!!! \n The actual number is lower.");

        // input number is CORRECT
        else {
            printf("Congratulations! You have guessed the number. \n Your prize is... nothing :D");
            return 1;
        } 
    }

    // failed guess
    printf("\n\nFOOL!!!! The number was %d. HAHAHAHA", randNumb);
    return 0;
}

// generate random num below 101 [1-100]
int randNum(){
    srand((unsigned int)time(NULL));  //sets the seed of  the random() function to the system time
    return (rand()*rand())%101;
}