#include <stdlib.h>
#include <time.h>

int randomInt(int min, int max)
{
    time_t t;
    // Seed the random function with current time
    srand(time(&t));
    // Calculate a random value between min and max inclusive
    return rand() % (max - min + 1) + min;
}