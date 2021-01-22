#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int copy(char to[], char from[]);

void main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;

    while((len = getline(line, MAXLINE)) > 0 )
    {
        if(len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0)
    {
        printf("Longest Line: %s\n", longest);
        printf("Length : %d", max);
    }

}

int getline(char s[], int lim)
{
    int c, i;
    for( i = 0; i < lim  && (c = getchar()) != EOF && c != '\n' ; ++i)
    {
        s[i] = c;
    }
    while( (c = getchar()) != EOF && c != '\n')
    {
        ++i;
    }
    if(i <=lim-1)
    {
        s[i] = '\0';
    }
    
    return i;
}

int copy( char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from [i]) != '\0'){
        ++i;
    }
}