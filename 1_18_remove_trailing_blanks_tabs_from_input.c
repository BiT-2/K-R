#include <stdio.h>
#include <conio.h>
#define MAX_LENGTH 1000

/*Program removes all blank space characters between last non blank space character and new line character (\n)*/

int read_line(char []);
int get_last_char_idx(char [], int );
void remove_trailing_blanks(char [], int, int);

void main()
{
    int new_line_idx, last_char_idx, stop = 0;
    /*
    new_line_idx stores the index of the new line character (\n) when blank spaces are present in the input
    last_char_idx stores the index of the last character. all characters after this are either spaces ( ), tabs (\t) or new line (\n)
    stop variable is used to stop accepting input from user
    */
    char input[MAX_LENGTH];
    while (stop != 1)
    {
        new_line_idx = read_line(input);
        
        last_char_idx = get_last_char_idx(input, new_line_idx);
        
        remove_trailing_blanks(input, last_char_idx, new_line_idx);
        printf("Output: \n");
        if(input[0] == '\n')
        {
            printf("Blank Line\n");
        }
        printf("%s \n", input);

        printf("Press 1 to stop. \n");
        scanf("%d", &stop);
    }

}

//Function to read new line into the input character buffer. MAX_LENGTH of line is defined as 1000 characters. need to pass the input array as argument
int read_line(char input[])
{
    int c, i;
    i = 0;
    while ( i < MAX_LENGTH - 1 && (c = getchar()) != EOF && c != '\n')
    {
        input[i] = c;
        ++i;

    }
    input[i] = '\n';
    return i;
}

//Function to get the last character index of the line. Need to provide the input character array and last index of the line as arguments
int get_last_char_idx(char input[], int last_idx)
{
    int i, is_blank_flag = 0; //is_blank_flag keeps track of successive trailing blank characters
    
    for( i = last_idx; i >= 0; --i)
    {
        if(input[i] == '\n')
        {
            is_blank_flag = 1;
            continue;
        }
        else if((input[i] == ' ' || input[i] == '\t') && is_blank_flag == 1)
        {
            is_blank_flag = 1;
        }
        else
        {
            is_blank_flag = 0;
            break;
        }
        
    }
    if(i >= 0) //conditional if to ensure -1 isn't returned as that would be an incorrect array index
    {
        return i;
    }
    else
    {
        return 0;
    }
}

/*function to shift new line character(\n) after the last non blank space character and flush out all blank spaces 
and update the index of the last valid character to be the new line character.*/

void remove_trailing_blanks(char input[], int last_char_idx, int new_line_idx)
{
    input[last_char_idx + 1] = '\n';
    for( int i = last_char_idx + 2; i <= new_line_idx ; i++)
    {
        input[i] = '\0';
    }
}