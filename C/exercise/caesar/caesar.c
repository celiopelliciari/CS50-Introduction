#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int key = atoi (argv[1]);

    string plaintext = get_string("Plaintext:");

    char ciphertext[8];
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        ciphertext[i] = (plaintext[i] + key);
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}