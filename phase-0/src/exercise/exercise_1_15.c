//
// Created by dillion on 4/21/26.
//

/* Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
   for conversion. */

#include <stdio.h>

double fahr_celc(double fahr)
{
    double celc = (5.0/9.0)*(fahr-32);
    return celc;
}

int main()
{
    double fahrenheit = 100;
    printf("%.3f F is equivalent to %.3f Celsius \n",fahrenheit, fahr_celc(fahrenheit) );

    return 0;
}