#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Finite loop
    // Can use count, i(intire), char(character) or any other
    // First variable is where de loop begin. Second variable is goal of "for". Third variable is a atualization
    for (int i = 0; i < 50; i++)
    {
        printf("Hello, world\n");
        // Can be i +=1 or i++ too
        i = i +1;
    }
}