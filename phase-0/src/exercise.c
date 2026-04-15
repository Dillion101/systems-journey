//
// Created by dillion on 4/15/26.
//

/* Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0. */
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
int main()
{
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}