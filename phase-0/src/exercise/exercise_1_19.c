//
// Created by dillion on 4/22/26.
//

/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

/* maximum input line length */
int my_getline(char line[], int maxline);

void reverse(char s[], int len);

int main()
{
    int len; /* current line length */

    char line[MAXLINE]; /* current input line */
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        reverse(line, len);
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

void reverse(char s[], int len)
{
    int swap = 0;
    int i = 0;
    int j=len-2;

    for (; i < j; i++, j--)
    {
        swap = s[i];
        s[i] = s[j];
        s[j] = swap;
    }
}