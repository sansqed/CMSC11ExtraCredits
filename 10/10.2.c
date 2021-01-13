/*
Author: Alwyn Dy
Date: 21/1/13
MP 10.2
*/

#include<stdio.h>
#include<stdbool.h>

typedef struct {
    unsigned int x, y;
} Point;

typedef struct{
    Point topLeft, botRight;
} Rectangle;

Point getPoint();
void display (Rectangle rect);
int area (Rectangle rect);
int perimeter (Rectangle rect);
void centerPoint (Rectangle rect);
bool isSquare (Rectangle rect);

int main(){
    // initialize int variables
    int n, i;

    // prompts user input # of test cases
    printf("Enter number of test cases: ");
    scanf("%d", &n);

    // initializes Rectangle
    Rectangle rect[n];

    // promts user to enter values for each Rectangle
    for (i=0; i<n; i++){
        rect[i].topLeft = getPoint();
        rect[i].botRight = getPoint();
    }

    // prints output
    for (i=0; i<n; i++){
        printf("/////////////////////////////////////////////////////\n");
        printf("TEST CASE %d:\n", i);

        display(rect[i]);
        printf("\n");

        printf("%s\n", isSquare(rect[i])==1? "SQUARE":"RECTANGLE");

        printf("AREA: %d\n", area(rect[i]));

        printf("PERIMETER: %d\n", perimeter(rect[i]));

        centerPoint(rect[i]);
        printf("\n\n");
    }

    
    return 0;
}

// promts user to enter 2 int values for point
// returns a point
Point getPoint(){
    Point p;

    scanf("%d %d", &p.x, &p.y);

    return p;
}

// displays the rectangle using '#'
void display (Rectangle rect){
    // initialize variables
    int i, j, flag=0, flag2=0;
    int TLX=rect.topLeft.x, TLY=rect.topLeft.y;
    int BRX=rect.botRight.x, BRY=rect.botRight.y;

    // loops entirety of the coordinates
    // prints '#' to the edges of the rectangle
    // if i matches the y coordinates or 
    // x matches the x coordinates, it prints
    // first 2 conditions are for horizontal lines (top & bot)
    // last 2 conditions are for vertical lines (left & right)
    for (i=0; i<=BRY; i++){
        for (j=0; j<=BRX; j++){
            if (j==TLX && i==TLY)       // detects top left coord
                flag=1;
            if (j==TLX && i==BRY)       // detects bottom left coord
                flag2=1;
                
            printf("%c", i==TLY&&flag==1? '#':i==BRY&&flag2==1? '#':j==TLX&&flag==1? '#':j==BRX&&flag==1? '#':' ');
        }
        printf("\n");
    }
    return;
}

int area (Rectangle rect){
    return (rect.botRight.x-rect.topLeft.x) * (rect.botRight.y-rect.topLeft.y);
}

int perimeter(Rectangle rect){
    return ((2*(rect.botRight.x-rect.topLeft.x))+(2*(rect.botRight.y-rect.topLeft.y)));
}

void centerPoint (Rectangle rect){

    // calculates center points
    float x = rect.topLeft.x+((float)(rect.botRight.x-rect.topLeft.x)/2);
    float y = rect.topLeft.y+((float)(rect.botRight.y-rect.topLeft.y)/2);

    printf("CENTER POINT: (%.2f, %.2f)", x, y);

    return;
}

// checks if rect is a square
bool isSquare (Rectangle rect){
    //gets width and height
    int width = rect.botRight.x-rect.topLeft.x;
    int height = rect.botRight.y-rect.topLeft.y;

    // squares have the same width and height
    // returns true if width==height
    // else false
    if (width==height)
        return true;
    else return false;
}
