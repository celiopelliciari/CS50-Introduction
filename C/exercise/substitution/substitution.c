#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    char *key = argv[1];
    // Check length
    if (strlen(key) != 26)
    {
        printf("debug_1 Enter 26 diferent letters. \n");
        return 1;
    }
    // Check letters
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("debug_2 Enter 26 diferent letters. \n");
            return 1;
        }
    }
    // Check diferent letters
    for (int i = 0; key[i] != '\0'; i++)
    {
        int count = 0;
        for (int j = i +1; key[j] != '\0'; j++)
        {
            if (key[i] == key[j])
            {
                count++;
                if (count >= 2)
                {
                    printf("debug_3 Enter 26 diferent letters. \n");
                    return 1;
                }
            }
        }
    }
    // Insert plaintext
    string plaintext = get_string("Insert plaintext: \n");
    // Cripto
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        int index = 0;
        // Check letters
        if (isalpha(plaintext[i]))
        {
            // Check lower
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                index = plaintext[i] - 97;
                plaintext[i] = tolower(key[index]);
            }
            // Check upper
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                index = plaintext[i] - 65;
                plaintext[i] = toupper(key[index]);
            }
        }
    }
    printf("%s \n", plaintext);
}