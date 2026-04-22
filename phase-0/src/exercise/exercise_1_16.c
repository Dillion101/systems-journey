//
// Created by dillion on 4/22/26.
//

/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text. */

#include <stdio.h>
#define MAXLINE 1000

/* maximum input line length */
int my_getline(char line[], int lim);

void copy(char to[], char from[]);
/* print the longest input line */
int main()
{
    int len;
    /* current line length */
    /* maximum length seen so far */
    char line[MAXLINE];
    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    int max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}
/* getline: read a line into s, return length
*/
int my_getline(char s[], int lim)
{
    int c, i, len;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        s[i] = c;
    }

    len = i;
    while (c != '\n' && c != EOF) {
        c = getchar();
        if (c != '\n' && c != EOF)
            ++len;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return len;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}