#include <stdio.h>
/*Word is defined as anything separated by a blankspace (' '), tabs ('\t') or newline (\n). words can begin with numbers and special characters*/

void main(){
    int i, j, length_count, arr[20], c , greatest_val_idx; 
    /*i, j are counter variables. length_count keeps track of word length. 
    arr[] counts frequency of words with word length corresponding to the array subscript index
    c is to get the input
    greatest_val_idx stores the arr[] index for highest frequency */

    /*Initialize all variables to 0*/
    length_count = 0;
    greatest_val_idx = 0;
    
    for(i = 0; i<20; i++)
    {
        arr[i] = 0;
    }

    /*Count length of each word and increment corresponding count frequency in array*/
    while ((c = getchar()) != EOF )
    {
        if( c != '\n' && c != '\t' && c != ' ')
        {
            ++length_count;
        }
        else if( c == '\n' || c == '\t' || c == ' ')
        {
            if (length_count <20 && length_count >= 0)
            {
                ++arr[length_count];
            }
            else{
                printf("Current word is too long to count.");
            }
            length_count = 0;

        }

    }
    /*Test loop to ensure input is properly counted. Only for small input */
    for(i = 1; i < 20; i++)
    {
        if(arr[i] > 0)
        {
            printf("%d letter count: %d\n", i, arr[i]);
        }
    }
    /* Get the index for the highest frequency*/
    for( j = 1 ; j < 20 ; j++)
    {
        if( arr[j] > arr[greatest_val_idx])
        {
            greatest_val_idx = j;
        }            
    }
    
    /* Create the histogram and y-axis */
    for (i = arr[greatest_val_idx]; i>0; i--)
    {
        
        printf("%d |", i);
        for( j = 1; j < 20; j++)
        {
            if(arr[j] == arr[greatest_val_idx] && arr[j] > 0)
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

    /*Create the x-axis*/
    printf("\n");
    printf("   ");
    for(i = 1 ; i<20; i++)
    {
        printf("%d ", i);
    }
}