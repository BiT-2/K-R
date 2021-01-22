#include <stdio.h>
void main(){
    int c;
    for(c = getchar(); c != EOF ;)
    {
        if(c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if(c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else if(c == '\b'){
            putchar('\\');
            putchar('b');
        }  
        else
        {
            putchar(c);
        }
        
        c = getchar();
    }
}