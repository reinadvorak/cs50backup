#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string word = get_string("Input: ");
    int length = strlen(word);
    //a - z is 97 - 122 and A - Z is 65 - 90
    for (int i = 0; i < length; i = i + 1)
    {
        //if (word[i] >= 'a' && word[i] <= 'z')
        if (islower(word[i]))
        {
            //printf("%c", word[i] - 32);
            printf("%c", toupper(word[i]));
        }
        else
        {
            printf("%c", word[i]);
        }
    }

    printf("\n");
}