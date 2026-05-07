//
// Created by dillion on 4/30/26.
//

// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#include <stdio.h>
#define TABSIZE 8

int main() {
    int c, col;
    col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSIZE - (col % TABSIZE);
            for (int i = 0; i < spaces; i++) {
                printf(" ");
            }
            col += spaces;
        } else if (c == '\n') {
            printf("\n");
            col = 0;
        } else {
            printf("%c", c);
            col++;
        }
    }
    return 0;
}