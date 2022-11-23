#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prenoted functions
float L (int count_letters, int count_words);
float S (int count_words, int count_phrases);

int main (void)
{
    // Get string
    string s = get_string("Insert a string: ");
    char str[50];
    strcpy (str, s);

    // Count letters, words and phrases
    int count_letters = 0;
    int count_words = 1;
    int count_phrases = 0;

    for (int i = 0; str[i] != '\0' ; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            count_letters++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            count_letters++;
        }
        else if (str[i] == ' ')
        {
            count_words++;

        }
        else if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == ';')
        {
            count_phrases++;
        }
    }
    printf("N. letters:  %i, n. words: %i and n. phrases: %i. \n", count_letters, count_words, count_phrases);

    // Indice Coleman-Liau
    float indice_coleman_liau = (0.0588 * L (count_letters, count_words)) - (0.296 * S (count_words, count_phrases)) - 15.8;
    printf("Indice Coleman-Liau: %f. \n", round(indice_coleman_liau));
}

// Execution Functions
float L (int count_letters, int count_words) // Avagere of letters for 100 words
{
    float L = (100.0 / count_words) * count_letters;
    printf("L: %f \n", L);
    return L;
}

float S (int count_words, int count_phrases) // Avagere of phrases for 100 words
{
    float S = (100.0 / count_words) * count_phrases;
    printf("S: %f \n", S);
    return S;
}