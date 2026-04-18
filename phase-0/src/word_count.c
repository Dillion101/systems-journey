//
// Created by dillion on 4/18/26.
//

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */

int main ()
{
    int c, nl, nw, nc, state;
    state = OUT;

    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        // Book said c = '\t' which is an assignment here instead of boolean check
        // Thus it was changed to c == '\t'
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("\n");
    printf("%d %d %d\n", nl, nw, nc);
}
