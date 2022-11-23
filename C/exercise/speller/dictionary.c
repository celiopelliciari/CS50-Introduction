// Implements a dictionary's functionality

// #include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table // 4880 is the sum of ASCII value of "pneumonoultramicroscopicsilicovolcanoconiosis"
const unsigned int N = 4881;

// Hash table
node *table[N];

// Assing a varible to count number of words in dictionary
unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Lucas's bussiness
    unsigned int size = 0;
    while (word[size] != '\0') size++;
    size++;
    char word_lower[size];

    // Put word in lower case
    for(int i = 0; word[i]; i++)
    {
        if (isalpha(word[i]))
        {
            word_lower[i] = tolower(word[i]);
        }
        else
        {
            word_lower[i] = word[i];
        }
    }

    // Call hash function
    unsigned int index = hash(word_lower);

    // A temporary variable
    node *tmp = table[index];

    // Check tmp
    if (tmp == NULL)
    {
        return false;
    }

    unsigned int a = 0;
    // Check if tmp is equal word
    while (tmp != NULL)
    {
        if (strcmp(tmp->word, word_lower) == 0)
        {
            return true;
        }

        tmp = tmp->next;
        a++;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Assign a temporary variable
    unsigned int ASCII_value = 0;

    // Loop to sum word ASCII value
    for (int i = 0; word[i] != '\0'; i++)
    {
        ASCII_value += word[i];
    }

    return ASCII_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // To open the dictionary file
    FILE *infile = fopen(dictionary, "r");
    // To check if the dictionary file is valid
    if (infile == NULL)
    {
        return false;
    }

    // Assign word variable
    char word[LENGTH];

    while(fscanf(infile, "%s", word) != EOF)
    {
        // A temporary variable
        node *n = malloc(sizeof(node));
        // Check
        if (n == NULL)
        {
            return false;
        }

        // Copy the word to the "n"
        strcpy(n->word, word);

        // Assign a null pointer to "n"
        n->next = NULL;

        // Call hash function
        unsigned int index = hash(word);

        // Sum plus one word in the count
        count++;

        // Copy n structure to table structure in "index" value // "index" is ASCII_value
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            // A temporary variable copy the "table[index]"
            node *tmp = table[index];

            // Pointing the node to temporary variable
            n->next = tmp;

            // The new node added to the "table[index]"
            table[index] = n;
        }
    }

    fclose(infile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free all nodes
    for (int i = 0; i < N; i++)
    {
        // Create a temporary variable and assing with table[i] value
        node *tmp = table[i];

        // Do a loop to erase all nodes in tmp
        while(tmp != NULL)
        {
            // Turn tmp into next node
            tmp = tmp->next;

            // Free table[i]
            free(table[i]);

            table[i] = tmp;
        }
    }
    return true;
}
