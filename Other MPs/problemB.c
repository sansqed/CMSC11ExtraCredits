#include<stdio.h>

int main(){
    //initialize variables
    float money, exRate, converted;

    //begs for money
    // printf("Enter amount in Euros: ");
    scanf("%f %f", &money, &exRate);
    // while (money < 0) { //loops if money is negative
    //     printf("Amount cannot be negative, enter another amount: ");
    //     scanf("%f", &money);
    // }

    //asks for exchange rate
    // printf("Enter exchange rate: ");
    // scanf("%f", &exRate);
    // while (exRate < 0) { //loops if exchange rate is negative
    //     printf("Exchange rate cannot be negative, enter another: ");
    //     scanf("%f", &exRate);
    // }

    //converts euro to peso
    converted = money*exRate;

    //prints result
    printf("%.2f euro/s with exchange rate %.2f is %.2f pesos.", money, exRate, floor() converted);

    return 0;
}