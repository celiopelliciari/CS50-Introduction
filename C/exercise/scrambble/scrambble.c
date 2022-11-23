#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score1(string word1);
int compute_score2(string word2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score1(word1);
    int score2 = compute_score2(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 win.");
    }
    else if (score2 > score1)
    {
        printf("Player 2 win.");
    }
    else
    {
        printf("Tie! \n");
    }
}

int compute_score1(string word1)
{
    int total_value_word1 = 0;
    // Compute value of word1
    for (int i = 0; word1[i] != '\0'; i++)
    {
        if (isalpha(word1[i]))
        {
            if (isupper(word1[i]))
            {
            int compute_char_word1 = word1[i] - 65;
            int value_char_word1 = POINTS[compute_char_word1];
            total_value_word1 += value_char_word1;
            }
            else
            {
            int compute_char_word1 = word1[i] - 97;
            int value_char_word1 = POINTS[compute_char_word1];
            total_value_word1 += value_char_word1;
            }
        }
    }
    printf("Player 1 value: %i \n", total_value_word1);
    return total_value_word1;
}

int compute_score2(string word2)
{
    int total_value_word2 = 0;
    // Compute value of word2
    for (int i = 0; word2[i] != '\0'; i++)
    {
        if (isalpha(word2[i]))
        {
            if (isupper(word2[i]))
            {
                int compute_char_word2 = word2[i] - 65;
                int value_char_word2 = POINTS[compute_char_word2];
                total_value_word2 += value_char_word2;
            }
            else
            {
                int compute_char_word2 = word2[i] - 97;
                int value_char_word2 = POINTS[compute_char_word2];
                total_value_word2 += value_char_word2;
            }
        }
    }
    printf("Player 2 value: %i \n", total_value_word2);
    return total_value_word2;
}