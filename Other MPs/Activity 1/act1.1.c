#include <stdio.h>

int main() {
    int num, input, x, y;
    char ch;
    scanf("%d %d %c", &num, &input, &ch);
    printf("%d %c %d",num, ch, input);
    if(num == 10)
        ch = 45;
    else
        ch = 90;
    while(input < -3)
        printf("num: %d", input);
    input++;
    for(x = 0, y = 1; x<y; x++, input++, ch++)
        x++;

    return 0;
}
