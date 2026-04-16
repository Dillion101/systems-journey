//
// Created by dillion on 4/16/26.
//
#include <stdio.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        printf("%d\n", c != EOF);
    }

    return 0;
}
// (getchar() != EOF) is equal to 0.