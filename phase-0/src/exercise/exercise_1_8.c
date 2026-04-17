//
// Created by dillion on 4/17/26.
//

// Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main ()
{
    int c, nl, tc, bc;
    nl = tc = bc = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            nl++;
        else if (c == '\t')
            tc++;
        else if (c == ' ')
            bc++;
    printf(" New Line Count: %d, Tab Count: %d, Blank Count: %d\n", nl, tc, bc);
}

