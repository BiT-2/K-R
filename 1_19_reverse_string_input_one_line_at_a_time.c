#include <stdio.h>
#define MAX_LENGTH 1000

int get_input(char []);
void reverse(char [], int);

/*
Each line can be 1000 characters long and is terminated with a new line character (\n) to begin the reversing process
*/


void main()
{
    int last_char_idx, stop = 0; //variables to store index of last input character and stop accepting input
    char input[MAX_LENGTH]; //array buffer to store input. MAX_LENGTH is 1000 characters
    while(!stop)
    {
        last_char_idx = get_input(input);
        /*
        1. Need this conditional-if because C has the blank character ("\0") as the terminating character for uninitialized arrays.
        2. Lines that are less than 998 characters or lower will have the last returned index as the index of ("\0") while lines that are exactly 999 will not have terminating blank
        character
        3. So we need to pass (last_char_index - 1) as the argument for reverse(char [], int ) function for lines that are 999 or lower in length and (last_char_index) for lines that are 
        1000 characters in length. 
        */
        if(last_char_idx < MAX_LENGTH-1)
        {
            reverse(input, last_char_idx -1 );
        }
        else
        {
            reverse(input, last_char_idx );
        }
        
        printf("Reversed string: %s\n", input); //Print reversed string
        printf("Press 1 to stop\n"); //Input to continue or stop
        scanf("%d", &stop);
    }
}


//function to get input
int get_input(char input[])
{
    int c, i;
    i = 0;
    while ( i < MAX_LENGTH-1 && (c = getchar()) != EOF && c != '\n')
    {
        input[i] = c;
        ++i;
    }
    c = getchar();
    printf("%c\n", c);
    if( i == MAX_LENGTH - 1 && c != '\n')
    {
       
        input[i] = c;
        printf("Terminated at 1000 characters!");
    }
    return i;
    
}

//function to reverse string
void reverse(char input[], int last_char_idx)
{
    
    int temp, i;
    i=0;
    while(i <= last_char_idx/2 )
    {
        temp = input[i];
        input[i] = input[last_char_idx - i];
        input[last_char_idx - i] = temp;
        ++i;
    }
    
}