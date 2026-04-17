//
// Created by dillion on 4/17/26.
//
#include <stdio.h>

int main ()
{
    int c, nl;
    nl = 0;

    // Standard Input Loop
    while ((c = getchar()) != EOF)

        /* Basically checks the number of times user goes to new line by clicking
        spacebar and increasing the newline counter by one */
        if (c == '\n')
            ++nl;

    // Prints NewLine counter to console after User enters EOF (End of Line) Ctrl+D
    printf("%d\n", nl);
}
