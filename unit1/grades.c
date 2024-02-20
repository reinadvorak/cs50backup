#include <cs50.h>
#include <stdio.h>

int main(void){

    int score = get_int("What score did you get? ");

    if (score >= 90 && score <=100) {
        printf("You got an A!\n\n");
    }
    else if (score >= 80 && score < 90){
        printf("You got a B!\n\n");
    }
    else if (score >= 70 && score < 80){
        printf("You got a C!\n\n");
    }
    else if (score >=60 && score < 70){
        printf("You got a D!\n\n");
    }
    else {
        printf("You got a F!\n\n");
    }
}