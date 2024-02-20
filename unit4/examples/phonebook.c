#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Open file
    FILE *file = fopen("phonebook.csv", "a");

    // Get strings from user
    string name = get_string("NAME: ");
    string number = get_string("NUMBER: ");

    // Print (write) strings to file
    fprintf(file, "%s, %s\n", name, number);

    // Close the file
    fclose(file);
}