#include <stdio.h>
#define MIN_LENGTH 80
#define MAX_INPUT 1000
/*Line is defined as a string of characters terminated by a new line (\n) character.*/


int get_length(char [], int );

void main()
{
    int len; //variable to store retrieved length
    char input[MAX_INPUT]; //character array to store 1000 characters of line. Line can be arbitrarily long, but the output will only print first 1000 characters 
    while( (len = get_length(input, MAX_INPUT)) > 0)
    {
        
        if(len > MIN_LENGTH && len <= MAX_INPUT) //Condition to output line < MAX_INPUT
        {
            printf("Length = %d \n", len);
            printf("Input: %s \n", input);
        }

        else if(len > MIN_LENGTH && len > MAX_INPUT) //Print warning that entire line isn't in the output due to input buffer limitation
        {
            printf("Only showing first 1000 characters\n");
            printf("Actual Length = %d \n", len);
            printf("Input: %s \n", input);
        }
    }

    
}

int get_length(char input[], int max_length) //function to get length of line
{
    int total_length, c;
    total_length = 0;
    while( (total_length < max_length - 1) && (c = getchar()) != EOF && c != '\n')
    {
        input[total_length] = c;
        ++total_length;
        
    }

    if(total_length <= max_length - 1 && c == '\n')
    {
        input[total_length] = c;
    }
    else 
    {
        input[total_length] = '\0';
        while( (c = getchar()) != EOF && c != '\n')
        {
            ++total_length;
        }
    }
    
    return total_length;
}