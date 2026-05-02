// guessing number game
// user have to guess number if number guessed by the user is lower compiler wil tell its lower take another chance and if its higher then it will tell its higher, in this game lowerer chances the user guesses the number wins the game.
#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()

int main()
{
    // 1. Seed the random number generator with the current time
    // This ensures you get different numbers every time the program runs
    srand(time(NULL));

    // Generate a number within a specific range (e.g., 1 to 100)
    int upper = 100, lower = 1;
    int ranged_num = (rand() % (upper - lower + 1)) + lower;
    int n, count = 0;
    do
    {
        printf("guess the number-");
        scanf("%d", &n);
        count++;
        if (ranged_num == n)
        {
            printf("Congratulations you guessed it correctly");
        }
        else if (ranged_num > n)
            printf("Try again your number is too small\n");
        else
            printf("Try again your number is too big\n");
    } while (n != ranged_num);
    printf("\nTotal number of attempts made by user is-%d", count);

    return 0;
}