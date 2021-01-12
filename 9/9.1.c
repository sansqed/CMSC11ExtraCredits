/*
Author: Alwyn Dy
Date: 21/1/12
MP 9.1
*/


#include<stdio.h>
#include<stdbool.h>

int logBase10Estimate(int n);
int floorr(float x); //floor function already exists in math.h. changed to floorr()
int ceiling(float x);
int isAlNum(char ch);
int isAlpha(char ch);
int isUpper(char ch);
int isLower(char ch);
char toUpper(char ch);
char toLower(char ch);
int isPunctuation(char ch);
int toInteger(char st[]);
float toFloat(char st[]);
float power(int a, int b); //added by author
int abs(int x);
void stringCopy(char src[], char dest[]);
bool substring(char s1[], char s2[]);
int lenStr (char str[]); //added by author
int stringCompare(char s1[], char s2[]);
void camelCase(char st[]);
void reverse(char st[]);
void swap (char* a, char* b); //added by author
bool humbleNumber(int x);
int isPrime(int x); //added by author
int reverseInt(int x); //initially int reverse(int x) but reverse() already exists

int main(){
    int x=456789;
    // printf("%d", logBase10Estimate(x));

    float y=1231.91234;
    // printf("%d ", floorr(y));
    // printf("%d ", ceiling(y));

    char z = ';';
    // printf("%d ", isAlNum(z));
    // printf("%d ", isAlpha(z));
    // printf("%d ", isUpper(z));
    // printf("%d ", isLower(z));
    // printf("%c ", toUpper(z));
    // printf("%c ", toLower(z));
    // printf("%d ", isPunctuation(z));

    char w[10]="45";
    printf("%d ", toInteger(w));

    // printf("%f", toFloat(w));

    x = 69;
    // printf("%d ", abs(x));

    char u[10]="apple";
    char v[10]= "!m r";

    // stringCopy(u,v);
    // printf("%s\n%s\n", u, v);

    // printf("%d ", substring(v,u));

    
    // printf("%d ", stringCompare(v,u));
    // camelCase(u);
    // printf("%s\n", u);

    // reverse(u);
    // printf("%s", u);


    // printf("%d ", humbleNumber(1));
    // int i;
    // for (i=1; i<50; i++){
    //     if (humbleNumber(i))
    //         printf("%d\n", i);
    // }

    // printf("%d", reverseInt(12345));


    return 0;
}

//returns the log of a number base 10. Just give the integer part. 
int logBase10Estimate(int n){
    int i=0;

    // repeated division of n ny 10 to count digits
    while (n!=0){
        n /= 10;
        i++;
    }

    return i-1;
}

//returns the biggest integer less than x.
int floorr(float x){
    return (int)x; //converts x to int
}

//returns the smallest integer greater than x.
int ceiling(float x){

    //if x has decimals, convert to int and add 1
    //else just convert to int
    if (x != floorr(x))
        return ((int)x)+1;
    else return (int)x;
}

//returns true if the character is a letter or a digit, false otherwise.
int isAlNum(char ch){
    if ((ch>=48 && ch<=57) || (ch>=65 && ch<=90) || (ch>=97 && ch<=122)) //checks ascii code
        return 1;
    else return 0;
}

//returns true if the character is a letter, false otherwise.
int isAlpha(char ch){
    if ((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) //checks ascii code
        return 1;
    else return 0;
}

//returns true if the character is an uppercase letter, false otherwise.
int isUpper(char ch){
    if ((ch>=65 && ch<=90)) //checks ascii code
        return 1;
    else return 0;
}

//returns true if the character is a lowercase letter, false otherwise.
int isLower(char ch){
    if ((ch>=97 && ch<=122)) //checks ascii code
        return 1;
    else return 0;
}

//returns the uppercase equivalent if the character is a lower case letter, otherwise, return the character itself.
char toUpper(char ch){
    if (isLower(ch))
        return (int)ch-32; //based on ascii
    else return ch;
}

//returns the lower case equivalent if the character is an uppercase letter, otherwise, return the character itself
char toLower(char ch){
    if (isUpper(ch))
        return (int)ch+32; //based on ascii
    else return ch;
}

//returns true if ch is a punctuation, false otherwise.
int isPunctuation(char ch){
    //period, comma, semi-colon, colon, question mark, and the exclamation point
    if (ch==46 || ch==44 || ch==58 || ch==59 || ch==63 || ch==33) //based on ascii
        return 1;
    else return 0;
}

// returns the integer equivalent of st. Assume that st is a valid numerical string.
int toInteger(char st[]){
    int i=0, converted=0;

    //gets char in st, converts to int. 
    //shifts the converted to the right to place next digit
    while (st[i]!='\0'){
        converted += st[i]-48; //based on ascii
        if (st[i+1]!='\0')
            converted *= 10;
        i++;
    }
    return converted;
}

//returns the float equivalent of st. Assume that st is a valid string representation of a float value.
float toFloat(char st[]){
    int i=0, flag=-1;
    float converted=0;

    
    while (st[i]!='\0'){

        //detects period in string
        if (st[i]=='.')
            flag=i;

        //same algo with toInteger()    
        if (flag==-1 && st[i]!='.'){
            converted += st[i]-48;
            if (st[i+1]!='.')
                converted *= 10;
        }

        //after the decimal sign, num is converted to fraction (e.g. 1/10, 1/100, ...)
        else if (flag!=-1 && st[i]!='.') {
            converted += (st[i]-48)*(power(10,-(i-flag)));
        }
        i++;
    }
    return converted;
}

//calculates exponential,, used in toFloat()
float power(int a, int b){
    int i, flag=0; 
    float ans=1;

    if (b<0){
        abs(b);
        flag=1;
    }

    for (i=0; i<b; i++)
        ans *= a;
    

    if (flag==1)
        return 1/ans;
    else return ans;
}

//returns the absolute value of x.
int abs(int x){
    if (x<0) return (x*-1); //if negative, multiply -1
    else return x;
}

//copies the contents of src to dest character by character.
void stringCopy(char src[], char dest[]){
    int i;

    //loops entire src string and assigns each char to the dest string
    for (i=0; src[i]!='\0'; i++){
        dest[i] = src[i];
    }
    dest[i]='\0';

    return;
}

//returns true if s2 is a substring of s1, false otherwise.
bool substring(char s1[], char s2[]){
    int i, j, match=0;
    int lenStr1 = lenStr(s1), lenStr2 = lenStr(s2);

    //loops until str1 fits in str2
    for (i=0; i<=lenStr2-lenStr1; i++){
        // printf("str2 %c \n", str2[i]);
        
        if (s1[0]==s2[i]){ // checks if first char of str1 is in str2
            // printf("match!");
            for (j=0; s1[j]!='\0'; j++){ // loops entirety of str1 to check if all char is in str2
                // printf("comparing %c and %c\n", str1[j], str2[j+i]);
                if (s1[j]!= s2[i+j])  //if a char is not same, no match
                    match=0;
                else match=1; //else, str1 is subset of str2
            }
        }
    }
    
    return match;
}

// counts length of string
int lenStr (char str[]){
    int i=-1, ctr=0;

    //loops entire string, increment counter
    while (str[++i]!='\0')
        ctr++;
    
    return ctr;
}

//returns 0 if s1 and s2 are the same, -1 if s1 comes before s2 in dictionary ordering and 1 if s1 comes after s2 in dictionary ordering.
int stringCompare(char s1[], char s2[]){
    int i=0;

    //loops until 1 string has been fully traversed
    //compares each char in s1 and s2
    for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
        if (toLower(s1[i])<toLower(s2[i]))
            return -1;
        else if (toLower(s1[i])>toLower(s2[i]))
            return 1;
        else return 0;
    }
}

//displays st in camel case. The characters are displayed in upper case and lower case alternately. Example: st = "apple", output = "ApPlE"
void camelCase(char st[]){
    int i;
	
    //traverses entire st, even indexes will be uppercase, odd indexes will be lowercase
	for (i=0; st[i]!='\0'; i++){
		if (i%2==1)
            st[i] = toLower(st[i]);
			
		else
			st[i] = toUpper(st[i]);
			
	}
	return;
}

//reverses the contents of the string. Do not use a temporary string.
void reverse(char st[]){
    int i, len=lenStr(st);

    //swaps ends of the array together until i reaches the middle
    for (i=0; i<len/2; i++)
        swap(&st[i], &st[len-1-i]);

    return;
}

//swaps the place of 2 char,, used in reverse()
void swap (char* a, char* b){
    char temp;

    temp=*a;
    *a=*b;
    *b=temp;

    return;
}

//determines if x is a humble number or not. A number whose only prime factors are 2, 3, 5 or 7. 1 is an exception (it is considered humble). The following are the first 20 humble numbers: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27.
bool humbleNumber(int x){
    int i;

    //prime numbers greater than 7 are not humble numbers
    if (x>7 && isPrime(x))
        return false;
    else{
        for (i=2; i<x; i++){

            // checks if there are factors of x that are not 2,3,5,7
            if (isPrime(i) && i!=2 && i!=3 && i!=5 && i!=7 && x%i==0)
                return false;

        }
    }
    return true;

}

//primality check,, used in humbleNumber()
int isPrime(int x){
    int i;

    for (i=2; i<x; i++){
        if (x%i == 0)
            return 0;
    }
    return 1;
}

//returns the reverse equivalent of a number. Sample: if x = 158, return 851.
int reverseInt(int x){
    int i, len = logBase10Estimate(x)+1, temp=0;

    //gets leftmost digit if x, adds to temp 
    //multpliy temp by 10 to allow next digit
    for (i=0; i<len; i++){
        temp += x%10;
        temp *= 10;
        x /= 10;
    }

    temp /= 10; //removes 0 in leftmost digit

    return temp;
}