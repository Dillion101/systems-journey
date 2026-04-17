//
// Created by dillion on 4/17/26.
//

/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank */

#include <stdio.h>

int main ()
{
    int c, prev_was_space;
    prev_was_space = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && prev_was_space == ' '){}
        else
        {
            printf("%c", c);
        }
        prev_was_space = c;
    }
}