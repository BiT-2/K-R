#include <stdio.h>
#include <stdlib.h>

/*
If a tab character ('\t') is encountered on a tab_marker value that isn't a multiple of tab_width, we should put in the relevant number of blank spaces (tab_marker%tab_width)
If tab_marker is a multiple of tab_width, then the tab column width is full, and no blank spaces need to be put.
For the sake of visual identification, blank spaces in the output are marked as ('*')
*/

void main()
{
    int c, tab_marker, tab_width;
    // tab_marker variable is used to keep track of how many more blank spaces to fill the output with
    // tab_width is supplied to know how big each tab column should be

    tab_marker = 0;
    tab_width = 10;

    while((c = getchar()) != EOF)
    {
        
        tab_marker++;
        if(c == '\n')
        {
            tab_marker = 0;
        }
        else if(c == '\t')
        {
            while ( (tab_marker % tab_width) != 0)
            {
                //putchar('*');
                printf("%d", tab_marker);
                ++tab_marker;
            }
            
        }
        else
        {
            putchar(c);
        }
        
        
    }

}