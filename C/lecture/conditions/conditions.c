// Conditions and relational operators

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");

    int y = get_int("y> ");

    // Compare if x is bigger than y
    if (x > y)
    {
        printf("%i is bigger than %i\n", x, y);
    }
    // Compare if y is bigger than x
    else if (y > x)
    {
        printf("%i is bigger than %i\n", y, x);
    }
    // Compare if both are equal
    else
    {
        printf("%i and %i are equal", x, y);
    }

}