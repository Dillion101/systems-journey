//
// Created by dillion on 4/20/26.
//

/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

#define SIZE 256 /* size of array */

int main ()
{
    int c, freq[SIZE];

    // Set all to 0
    for (int i=0; i<SIZE; i++)
    {
        freq[i] = 0;
    }

    // Since we want to count all characters, no need for filtering
    // Thus we just increase the array by one at x when we meet char x
    while ((c = getchar()) != EOF)
    {
        ++freq[c];
    }

    printf("The frequency Histogram for your Characters\n");

    for (int i=0; i<SIZE; i++)
    {
        // Filter out characters which were not captured (0 frequency in the input)
        if (freq[i] != 0)
        {
            // Used %c to display the ASCII value of i (the non-zero frequency caught by the conditional above
            printf("%c %.*s\n", i, freq[i], "***********************");
        }
    }

    printf("\n");
}