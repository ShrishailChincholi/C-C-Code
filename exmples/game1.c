#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    // Generate random number
    srand(time(0));
    number = rand() % 100 + 1; // 1 to 100

    printf("🎮 Welcome to Number Guessing Game!\n");
    printf("Guess a number between 1 and 100\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if(guess > number) {
            printf("Too High! ");
        }
        else if(guess < number) {
            printf("Too Low! ");
        }
        else {
            printf("\n Correct! You guessed in %d attempts!\n", attempts);
        }

    } while(guess != number);

    return 0;
}