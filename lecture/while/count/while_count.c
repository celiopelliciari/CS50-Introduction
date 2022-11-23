#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Finite loop
    // Can use count, i(intire), char(character) or any other
    int i = 0;
    while (i < 50)
    {
        printf("Hello, world\n");
        // Can be i +=1 or i++ too
        i = i +1;
    }
}