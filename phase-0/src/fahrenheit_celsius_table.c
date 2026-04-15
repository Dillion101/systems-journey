//
// Created by dillion on 4/15/26.
//
#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

/* lower limit of table */
/* upper limit */
/* step size */
/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}