/*
Author: Alwyn Dy
Date: 21/1/13
MP 10.1
*/

#include<stdio.h>
#include<stdlib.h> // for atoi()
#include<string.h> // for strncpy() and memset()
#include<unistd.h> // for sleep()

// struct for the Term
// a Term consists of a coefficient and exponent
typedef struct {
    int coefficient, exponent;
}Term; 

// contains two terms that are multiplicand
typedef struct {
    Term a, b;
} twoTerms; // 

Term parseTerm(char *str);
void printTerm(Term t);
twoTerms getTwoTerms();
Term multiplyTerms(twoTerms tt);

int main(){

    int t, i;
    char temp[10];

    printf("Enter number of test cases: ");
    scanf("%d", &t);
    gets(temp); // to nullify scanf effects

    twoTerms inTerm[t];

    // prompts user to enter t testcases
    for (i=0; i<t; i++){
        printf("%d: ", i);
        inTerm[i] = getTwoTerms();
    }

    sleep(0.5); // adds delay
    printf("\n\nmultiplying...\n\n");
    sleep(0.5); // adds delay

    //displaying of multiplied term
    for (i=0; i<t; i++){
        printTerm(multiplyTerms(inTerm[i]));
        printf("\n");
    }

    return 0;
}

// parses the string to Term
// returns a Term
Term parseTerm(char *str){
    // initialize variables
    int i, varFlag=-1, caretFlag=-1;
    Term t;    
    
    // parses coefficient
    if (str[0]=='x' || str[0]=='X')         // for coefficients of 1, (e.g. x^2)
        t.coefficient = 1; 
    else 
        t.coefficient = atoi(str); 

    // if coefficient is 0, exponent is automatically 0
    // ends function
    if (t.coefficient == 0){
        t.exponent = 0;
        return t;
    }

    for (i=0; str[i]!='\0'; i++){
        if (str[i]=='x' || str[i]=='X')     // detects variable in string
            varFlag=i;

        if (str[i]=='^')                    // detects caret (^) in string
            caretFlag=i;
    }

    // parses exponent
    if (varFlag!=-1 && caretFlag!=-1)       // for strings with '^' && 'x'
        t.exponent = atoi(str+caretFlag+1);
    else if (varFlag!=-1 && caretFlag==-1)  // for strings without '^' (i.e. exponent is 1, x^1)
        t.exponent = 1;
    else if (varFlag==-1 && caretFlag==-1)  // for strings without exponent (i.e. exponent is 0, x^0)
        t.exponent = 0;
    
    return t;
}

//prints the term
void printTerm(Term t){

    // print conditions for coefficient
    if (t.coefficient !=1 )
        printf("%d", t.coefficient);

    //print conditions for exponent
    if (t.coefficient != 0){            // ONLY prints when coefficient is not 0
        if (t.exponent == 1)            // prints when exponent is 1
            printf("x");
        else if (t.exponent != 0)       // ONLY prints when exponent is nonzero
            printf("x^%d", t.exponent);
    }

    // printf("\n %d %d", t.coefficient, t.exponent); //for debugging
    
    return;
}

// prompt user to enter string
// finds the delimeter (i.e. space) in the string
// passes the first and second terms to parseTerm() to convert to Term
// returns a twoTerms struct that contains the two terms entered by user
twoTerms getTwoTerms(){
    //initialize variables
    int i;
    char str[30], temp[30];
    twoTerms tt;

    memset(temp, '\0', sizeof(temp));   //resets temp string to avoid extra char

    // prompts user input
    gets(str);

    for (i=0; str[i]!=' '; i++);        //searches for the delimeter (i.e. space)

    strncpy(temp, str, i+1);            //copies first term to temp string
    tt.a = parseTerm(temp);             //parses the temp string for the first term
    tt.b = parseTerm(str+i+1);          //parses the second term

    return tt;
}

// multiplies the two terms stored in tt (i.e. tt.a & tt.b)
// returns a Term that is a product of the two terms
Term multiplyTerms(twoTerms tt){
    //initialize variable
    Term t;

    t.coefficient = tt.a.coefficient * tt.b.coefficient;    // multiplies the coefficient values
    t.exponent = tt.a.exponent + tt.b.exponent;             // adds the exponent values
    
    return t;
}
