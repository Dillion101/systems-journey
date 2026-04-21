//
// Created by dillion on 4/20/26.
//

#include <stdio.h>
/* count digits, white space, others */
int main()
{
    int c, i, nwhite, nother;

    // Created an Array with  10 integers
    int ndigit[10];

    // Set Number of White Spaces and Number of Other Characters to zero
    nwhite = nother = 0;

    // Looped through array and set initial value to 0
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    // Collect input characters from terminal
    while ((c = getchar()) != EOF)

        //Check if Character is Digit, if so, increase position in array by 1
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];

        // If character is whitespace, increase white space count by one
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;

        // Character is not digit or white space.
        else
            ++nother;

    // Print digit array showing the number of occurrences of each digit from 0 to 9
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    // Also Printing the number pf others and white space
    printf(", white space = %d, other = %d\n", nwhite, nother);
}