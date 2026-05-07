//
// Created by dillion on 5/7/26.
//

/*  Deliverable:
    Write and compile your first C program: a calculator that takes two numbers
    and an operator from stdin and prints the result. */

#include <stdio.h>
float calculator (float num1, float num2, char operator);

int main()
{
    printf("Enter your Values\n");
    float num1;
    scanf("%f", &num1);
    float num2;
    scanf("%f", &num2);
    char operator;
    scanf(" %c", &operator);

    printf("The Result is %.3f\n",calculator (num1, num2, operator));

    return 0;
}

float calculator (float num1, float num2, char operator)
{
    float result = 0.0;
    if (operator == '+')
    {
        result = num1 + num2;
    }
    else if (operator == '-') result = num1 - num2;
    else if (operator == '*') result = num1 * num2;
    else if (operator == '/')
    {
        if (num2 != 0) result = num1 / num2;
        else
        {
            printf("Invalid Operation, cannot divide by zero\n");
        }
    }
    else
    {
        printf("Invalid operator!\n");
    }

    return result;
}