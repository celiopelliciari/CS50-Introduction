#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int p_initial = get_int("What's the initial llamas population? ");
    int years = get_int("How many years do you whant calculate? ");

    for (int i = 1; i != years + 1; i++)
    {
        int new_born = p_initial / 3;
        printf("%i llamas will be born in %i year. \n", new_born, i);
        int deaths = p_initial / 4;
        printf("%i llamas will die in %i year. \n", deaths, i);

        p_initial += new_born - deaths;
        printf("The vegetative growth of the llama population in %i year will be %i. \n", i, p_initial);
    }
    printf("In %i years the llama population will be %i \n", years, p_initial);
}