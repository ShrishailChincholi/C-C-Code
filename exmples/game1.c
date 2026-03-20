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



// Rock,  Paper, Scissors Game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;

    // Random number for computer
    srand(time(0));
    computer = rand() % 3 + 1;

    printf("Rock Paper Scissors Game\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");

    printf("Enter your choice: ");
    scanf("%d", &user);

    printf("Computer chose: %d\n", computer);

    if(user == computer) {
        printf("It's a draw!\n");
    }
    else if((user == 1 && computer == 3) ||
            (user == 2 && computer == 1) ||
            (user == 3 && computer == 2)) {
        printf("You win!\n");
    }
    else {
        printf("You lose!\n");
    }

    return 0;
}



// Quize game
#include <stdio.h>

int main() {
    int score = 0;
    int answer;

    printf("Simple Quiz Game\n");

    // Question 1
    printf("\n1. What is 2 + 2?\n");
    printf("1) 3\n2) 4\n3) 5\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 2) {
        score++;
    }

    // Question 2
    printf("\n2. What is capital of India?\n");
    printf("1) Mumbai\n2) Delhi\n3) Chennai\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 2) {
        score++;
    }

    // Question 3
    printf("\n3. Which language is used for C programming?\n");
    printf("1) English\n2) Machine\n3) Programming Language\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if(answer == 3) {
        score++;
    }

    // Final Score
    printf("\nYour score: %d / 3\n", score);

    return 0;
}