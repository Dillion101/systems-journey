//
// Created by dillion on 4/22/26.
//

/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000

/* maximum input line length */
int my_getline(char line[], int maxline);

int main()
{
    int len, i; /* current line length */

    i = 0;
    char line[MAXLINE]; /* current input line */
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        // Loop through line array and do nothing but when it escapes we fortunately have the position
        // or index of last character before traling whitespaces.
        for (i = len-1; line[i] == '\n' || line[i] == ' ' || line[i] == '\t'; i--)

            // Assign next index as end of array
        line[i+1] = '\0';

        // Only print the new line if line is not empty.
        if (line[0] != '\0')
            printf("%s\n", line);

    }
    return 0;
}
// getline: read a line into s, return length

int my_getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

