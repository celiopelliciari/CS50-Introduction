#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Declaretions of Funtions
long get_card_number(void);
string get_string_card_number(long card_number);
bool is_americanxpress(int number_length, string string_card_number);
bool is_mastercard(int number_length, string string_card_number);
bool is_visa(int number_length, string string_card_number);
bool is_valid_number(int number_length, string string_card_number);

int main(void)
{
    // Get the card number
    long card_number = get_card_number();

    // Convert the long card_number in string
    string string_card_number = get_string_card_number(card_number);

    // Measure the number length
    int number_length = strlen(string_card_number);

    // Verific if probaly is an americaexpress, mastercard or visa
    bool americanexpress = is_americanxpress(number_length, string_card_number);
    bool mastercard = is_mastercard(number_length, string_card_number);
    bool visa = is_visa(number_length, string_card_number);

    // Number verification
    if (americanexpress || mastercard || visa)
    {
        bool valid_number = is_valid_number(number_length, string_card_number);
        if (valid_number == true)
        {
            if (americanexpress)
            {
                printf("Your america express is valid. \n");
            }
            else if (mastercard)
            {
                printf("Your master card is valid. \n");
            }
            else if (visa)
            {
                printf("Your visa is valid. \n");
            }
        }
        else
        {
            printf("Your number isn't valind. \n");
        }
    }
}

// Execution of Funtions
long get_card_number(void)
{
    long card_number = get_long("What's the card number: ");
    return card_number;
}

string get_string_card_number(long card_number)
{
    string string_card_number = malloc(64);
    sprintf(string_card_number, "%lu", card_number);
    return string_card_number;
}

bool is_americanxpress(int number_length, string string_card_number)
{
    bool americanexpress;
    if (number_length == 15)
    {
        // Verific if the two first numbers are compatible with america express (if they are 34 or 37)
        if (string_card_number[0] == '3')
        {
            if (string_card_number[1] == '4')
            {
                americanexpress = true;
            }
            else if (string_card_number[1] == '7')
            {
                americanexpress = true;
            }
            else
            {
                americanexpress = false;
            }
        }
        else
        {
            americanexpress = false;
        }
    }
    else
    {
        americanexpress = false;
    }
    return americanexpress;
}

bool is_mastercard(int number_length, string string_card_number)
{
    bool mastercard;
    if (number_length == 16)
    {
    // Verific if the two first numbers are compatible with master card (if they are 51, 52, 53, 54 or 55)
        if (string_card_number[0] == '5')
        {
            if (string_card_number[1] == '1')
            {
                mastercard = true;
            }
            else if (string_card_number[1] == '2')
            {
                mastercard = true;
            }
            else if (string_card_number[1] == '3')
            {
                mastercard = true;
            }
            else if (string_card_number[1] == '4')
            {
                mastercard = true;
            }
            else if (string_card_number[1] == '5')
            {
                mastercard = true;
            }
            else
            {
                mastercard = false;
            }
        }
        else
        {
            mastercard = false;
        }
    }
    else
    {
        mastercard = false;
    }
    return mastercard;
}

bool is_visa(int number_length, string string_card_number)
{
    bool visa;
    if (number_length == 13 || number_length == 14 || number_length == 15 || number_length == 16)
    {
    // Verific if the first number are compatible with visa (if it is 4)
        if (string_card_number[0] == '4')
        {
            visa = true;
        }
        else
        {
            visa = false;
        }
    }
    else
    {
        visa = false;
    }
    return visa;
}

bool is_valid_number(int number_length, string string_card_number)
{
    // Verific if is a valid card number Part 1
        int sum_digit = 0;
        for (int i = number_length - 2; i >= 0; i = i - 2)
        {
                int digit = string_card_number[i] - '0';
                int multi_digit = digit * 2;
                // If multi_digit has 2 digits
                if (multi_digit >= 10)
                {
                    // Convert the multi_digit in string
                    char multi_digit_string[5];
                    sprintf(multi_digit_string, "%d", multi_digit);

                    // Separe the digits
                    multi_digit = 0;
                    for (int ii = 0; ii != 2; ii++)
                    {
                        int two_digits = multi_digit_string[ii] - '0';
                        multi_digit += two_digits;
                    }
                }
                sum_digit += multi_digit;
        }

        // Verific if is a valid card number Part 2
        for (int i = number_length - 1; i >= 0; i = i - 2)
        {
            int digit = string_card_number[i] - '0';
            sum_digit += digit;
        }

        // Final Verification
        bool valid_number;
        if (sum_digit % 10 == 0)
        {
            valid_number = true;
        }
        else
        {
            valid_number = false;
        }
        return valid_number;
}