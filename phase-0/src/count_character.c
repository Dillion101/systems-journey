//
// Created by dillion on 4/16/26.
//

#include <stdio.h>

int main ()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
