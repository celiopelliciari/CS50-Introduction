# Get the card number
card_number = int(input("Digit your card number: "))
# Transform the card number into a string
string_card_number = str(card_number)
# Get lenght of card number
lenght_card_number = len(string_card_number)

# Check if card is american express
if lenght_card_number == 15:
    if string_card_number[0] == '3' and string_card_number[1] == '4' or string_card_number[1] == '7':
        luhn_algorithm = 0
        for i in ([0, 2, 4, 6, 8, 10, 12, 14]):
            if (int(string_card_number[i]) * 2 >= 10):
                tmp = str(int(string_card_number[i]) * 2)
                luhn_algorithm += int(tmp[0])
                luhn_algorithm += int(tmp[1])
            else:
                luhn_algorithm += int(string_card_number[i]) * 2
        for i in ([1, 3, 5, 7, 9, 11, 13]):
            luhn_algorithm += int(string_card_number[i])
        tmp = str(luhn_algorithm)
        if tmp[1] == '0':
            print("Your card is a valid american express")
        else:
            print("Your card is not a valid card")

# Check if card is visa
elif lenght_card_number == 13 or lenght_card_number == 16 and string_card_number[0] == '4':
        luhn_algorithm = 0
        if lenght_card_number == 13:
            for i in ([0, 2, 4, 6, 8, 10, 12]):
                if (int(string_card_number[i]) * 2 >= 10):
                    tmp = str(int(string_card_number[i]) * 2)
                    luhn_algorithm += int(tmp[0])
                    luhn_algorithm += int(tmp[1])
                else:
                    luhn_algorithm += int(string_card_number[i]) * 2
            for i in ([1, 3, 5, 7, 9, 11]):
                luhn_algorithm += int(string_card_number[i])
            tmp = str(luhn_algorithm)
            if tmp[1] == '0':
                print("Your card is a valid visa")
            else:
                print("Your card is not a valid card")
        else:
            for i in ([0, 2, 4, 6, 8, 10, 12, 14]):
                if (int(string_card_number[i]) * 2 >= 10):
                    tmp = str(int(string_card_number[i]) * 2)
                    luhn_algorithm += int(tmp[0])
                    luhn_algorithm += int(tmp[1])
                    print(luhn_algorithm)
                else:
                    luhn_algorithm += int(string_card_number[i]) * 2
                    print(luhn_algorithm)
            for i in ([1, 3, 5, 7, 9, 11, 13, 15]):
                luhn_algorithm += int(string_card_number[i])
                print(luhn_algorithm)
            tmp = str(luhn_algorithm)
            if tmp[1] == '0':
                print("Your card is a valid visa")
            else:
                print("Your card is not a valid card")

# Check if card is mastercard
elif lenght_card_number == 16 and (string_card_number[0] == '5') and (string_card_number[1] == '1' or string_card_number[1] == '2' or string_card_number[1] == '3' or string_card_number[1] == '4' or string_card_number[1] == '5'):
        luhn_algorithm = 0
        for i in ([0, 2, 4, 6, 8, 10, 12, 14]):
                if (int(string_card_number[i]) * 2 >= 10):
                    tmp = str(int(string_card_number[i]) * 2)
                    luhn_algorithm += int(tmp[0])
                    luhn_algorithm += int(tmp[1])
                    print(luhn_algorithm)
                else:
                    luhn_algorithm += int(string_card_number[i]) * 2
                    print(luhn_algorithm)
        for i in ([1, 3, 5, 7, 9, 11, 13, 15]):
            luhn_algorithm += int(string_card_number[i])
            print(luhn_algorithm)
        tmp = str(luhn_algorithm)
        if tmp[1] == '0':
            print("Your card is a valid mastercard")
        else:
            print("Your card is not a mastercard")