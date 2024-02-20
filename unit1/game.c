#include <cs50.h>
#include <stdio.h>

    int main(void){
        bool found = false;
        int guesses = 0;
        while (!found){
            guesses = guesses + 1;
        int number = get_int("Guess my number: ");

        if (number == 20){
            printf("You won! It took %i guesses.\n\n", guesses);
            found = true;
        }
        else if (number < 20){
            printf( "Too Low\n\n");
        }
        else{
            printf("To high.\n\n");
        }
     }
}