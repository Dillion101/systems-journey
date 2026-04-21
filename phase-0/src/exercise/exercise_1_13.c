//
// Created by dillion on 4/20/26.
//

/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
#define SIZE 10 /* size of array */

int main ()
{
    int c, lend, state;
    int word[SIZE];
    state = OUT;
    lend = 0;

    for (int i = 0; i < SIZE; i++)
    {
        word[i] = 0;
    }

    while ((c = getchar()) != EOF)

        // If not word (whitespace or digit) set state to OUT
        if ( c == ' ' || c == '\n' || c == '\t' || (c >= '0' && c <= '9') )
        {
            /* This condition is to check when we moved from a word to another type of character by verifying if
               previous state was IN and now entering the else right after a word.
               Thus, we add the length to the array and reset the length of word variable. */
            if ( state == IN )
            {
                if ( lend < SIZE )
                    ++word[lend];
                lend = 0;
            }
            state = OUT;
        }
        // Check if it is word
        else
        {
            // increase length of word by one and assign state to IN
            lend+=1;
            state = IN;
        }

    printf("Length of Word\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d %.*s\n", i, word[i], "****************************************");

    }
    printf("\n");
}