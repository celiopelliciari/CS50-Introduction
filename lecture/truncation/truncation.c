#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get numbers from user
    // The usuary numbers is always int in this way and the computer won't get de right result
    int x = get_int("x: ");

    int y = get_int("y: ");

    // For fix the code without change everething we can use a cast (float) berore the variable
    float z = ((float) x / (float) y);

    printf("%f\n", z);
}