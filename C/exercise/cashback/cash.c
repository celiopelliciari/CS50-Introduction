#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    int twenty_five = 0;
    int ten = 0;
    int five = 0;
    int one = 0;

    float c = get_positive_float();
    printf("%f\n", c);

    while (c >= 0.25)
    {
        c = (c - 0.25);
        twenty_five++;
    }
    while (c >= 0.10)
    {
        c = (c - 0.10);
        ten++;
    }
    while (c >= 0.05)
    {
        c = (c - 0.05);
        five++;
    }
    while (c >= 0.01)
    {
        c = (c - 0.01);
        one++;
    }
    printf("You should give %i of $0,25, %i of $0,10, %i of $0,05 and %i of $0,01", twenty_five, ten, five, one);
}

// Prompt for positive float integer
float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float("Positive float integer: ");
    }
    while (n >= 1);
    printf("%f\n", n);
    return n;
}