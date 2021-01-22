#include <stdio.h>
#define IN 0
#define OUT 1

void main(){

    int c, last_c, state;
    state = OUT;
    last_c = 0;
    while( (c = getchar()) != EOF)
    {
        if((c != ' ' && c != '\t' && c != '\n') ||  state == OUT)
        {
            putchar(c);
            state = IN;
        }
        else if( (c == ' ' || c == '\t' || c == '\n') && state == IN)
        {
            putchar('\n');
            state = OUT;
        }
    }
}