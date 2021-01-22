#include<stdio.h>

void main(){
    int c, last_c;
    last_c = 0;
    for(c = getchar(); c != EOF ;)
    {
        if(c == ' ' && last_c == ' ')
        {
            ;
        }
        else{
            putchar(c);
        }
        last_c = c;
        c = getchar();
    }
}