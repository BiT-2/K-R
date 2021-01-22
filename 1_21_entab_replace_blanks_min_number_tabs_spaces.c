#include <stdio.h>

void main()
{
    int c, white_count, tab_width;
    white_count = 0;
    tab_width = 5;

    while(( c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++white_count;
            if((white_count%tab_width) == 0)
            {
                putchar('\\');
                putchar('t');
            }
        }

        else
        {
            for( int i = white_count%tab_width; i > 0; --i)
            {
                putchar('*');
            }
            
            putchar(c);

            if( white_count != 0 )
            {
                white_count = 0;
            }
        }
        
    }
}