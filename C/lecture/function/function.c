#include <cs50.h>
#include <stdio.h>

int i = 0;
void meow(int n);

int main(void)
{
    int n = get_int("n: ");

    meow(n);
}

void meow(int n)
{
    for(i = 0; i < n; i++)
    {
        printf("Meow!\n");
    }
}
