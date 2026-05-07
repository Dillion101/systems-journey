//
// Created by dillion on 5/1/26.
//

/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

my answer: single blank
 */

#include <stdio.h>
#define TABSIZE 8

int main ()
{
    int c;
    int bucket = 0;
    int col = 0;

    while ((c = getchar()) != EOF)
    {
        int nextTab = TABSIZE - (col % TABSIZE);
        // When we hit a space
        if (c == ' ')
        {
            bucket++;
            if (bucket == nextTab)
            {
                printf("\t");
                col = col + nextTab;
                bucket = 0;
            }
            else
            {
                col++;
            }
        }

        else if (c == '\n')
        {
            for (int i = 0; i < bucket; i++)
            {
                printf("%s", " ");
            }
            printf("\n");
            col = bucket = 0;
        }
        // When we hit a character
        else
        {
            for (int i = 0; i < bucket; i++)
            {
                printf("%s", " ");
            }
            printf("%c", c);
            bucket = 0;

            col++;
        }

    }
}