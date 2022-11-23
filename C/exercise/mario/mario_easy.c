#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n = get_int("Height: ");
    // Control the height
    for (int h = 0; h < n; h++)
    {
        // Control number of ' '
        for (int v = 1; v < (n-h) ; v++)
        {
            printf(" ");
        }

        // Control the number of '#'
        for (int j = 0; j <= h; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}