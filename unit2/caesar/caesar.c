#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_int(string number);

int main(int argc, string argv[])
{
    // Make sure you only have 2 command-line arguments.
    bool error1 = argc != 2;
    if (error1)
    {
        printf("Usage: ./substring key\n");
        return 1;
    }

    // Make sure key is only made of digits.
    //  if(!(isdigit(CHAR))) will check if a CHAR is NOT a digit.
    bool isNumber = check_int(argv[1]);
    bool error2 = !(isNumber);
    if (error2)
    {
        printf("key must be an integer!\n");
        return 1;
    }

    // Change key from string to int.
    int key = atoi(argv[1]);

    if (key > 26)
    {
        key = key - 26;
    }

    // Prompt the user for text.
    string text = get_string("plaintext: ");

    // Change text to ciphertext
    // Loop through each char of text one at a time.
    // If the char is a letter, then change it.
    // You can detect a letter using isalpha().
    // If the char is not a letter, then don't change it.
    char temp;

    // LOWER CASE LETTER EXAMPLE
    // We subtract 97 because all the lowercase letters are 97
    // above the alphabetic index ... 0, 1, 2, ..., 25.
    // Then % 26 divides by 26 and give the remainder.
    // This allows us to loop around and stay within 0 to 26.
    // Then we go back to ASCII by adding 97.
    printf("ciphertext: ");
    int length = strlen(text);
    for (int i = 0; i < length; i = i + 1)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                temp = ((text[i] - 97 + key) % 26) + 97;
            }
            if (isupper(text[i]))
            {
                temp = ((text[i] - 65 + key) % 26) + 65;
            }
        }
        else
        {
            temp = text[i];
        }
        printf("%c", temp);
    }

    printf("\n");
}

bool check_int(string number)
{
    int length = strlen(number);
    for (int i = 0; i < length; i = i + 1)
    {
        if (!(isdigit(number[i])))
        {
            return false;
        }
    }
    return true;
}