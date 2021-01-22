#include <stdio.h>
/*
Count the frequency of each symbol in a sentence.
arr[0] stores frequency of blank spaces ( ), tabs (\t) and new line (\n)
arr[1] to arr[27] stores frequency of characters A-Z and a-z. Lower and upper case character are the same. 
So encountering an A or a would increase count of arr[1] by 1. So on and so forth.
arr[27] to arr[36] stores frequency of digits 0-9
arr[37] stores all other special characters (sc)
*/

void main(){
    
    /*variable declaration
    i, j are counter variables
    c is to fetch input
    greatest_idx stores index of max frequency symbol for arr[]
    temp is to store value of max frequency when plotting histogram 
    */
    int c, arr[38], i, j, greatest_idx, temp;
    
    temp = greatest_idx = 0;
    for(i = 0; i < 38; i++)
    {
        arr[i] = 0;
    }

    /* Loop to compute frequencies of each symbol for input*/
    while( (c = getchar()) != EOF )
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            ++arr[0];
        }
        else if( c >= 'A' && c <= 'Z' )
        {
            ++arr[c - 'A' + 1];
        }
        else if( c >= 'a' && c <= 'z' )
        {
            ++arr[c - 'a' + 1];
        }
        else if (c > '0' && c <= '9')
        {
            ++arr[ c - '0' + 27];

        }
        else
        {
            ++arr[37];
        }
        
    }
    
    /*Test loop to ensure each symbol is correctly calculated*/
    for( i = 0; i  < 38; i ++)
    {
        if(arr[i] > 0 && i == 0)
        {
            printf("Count of blank space (%c): %d\n", i + 32,arr[i] );
        }
        else if(arr[i] > 0 && (i > 0 && i <27))
        {
            printf("Count of %c : %d \n", i + 'A' -1, arr[i]);
        }
        else if(arr[i] > 0 && (i >=27 && i <= 36))
        {
            printf("Count of %c : %d \n", i + 21, arr[i]);
        }
        else if(i == 37)
        {
            printf("Count of punctutation: %d \n", arr[i]);
        }
        
    }

    /*Loop to find index of greatest frequency */
    for ( i = 0; i < 38; i++)
    {
        if(arr[i] > arr[greatest_idx])
        {
            greatest_idx = i;
        }
    }
    
    /* Loop to plot histogram and y-axis*/
    for ( i = arr[greatest_idx]; i > 0; i--)
    {
        if(i > 9)
        {
            printf("%d |", i);
        }
        else
        {
            printf(" %d |",i);
        }
        temp = arr[greatest_idx];
        for ( j = 0; j < 38 ; j++)
        {
            
            if(arr[j] == temp && arr[j] > 0)
            {
                printf("* ");
                --arr[j];
            }
            else
            {
                printf("  ");
            }
            
        }
        printf("\n");
    }

    printf("    ");
    
    /* Loop to plot x-axis */
    for( i = 0; i < 38; i++)
    {
        if(i == 0)
        {
            printf("%c ", i+32);
        }
        else if(i > 0 && i < 27)
        {
            printf("%c ", i + 'A' - 1);
        }
        else if( i >= 27 && i <=36)
        {
            printf("%c ", i + 21);
        }
        else if(i == 37)
        {
            printf("sc"); //sc = special character
        }
    }


}