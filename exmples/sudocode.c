#include <stdio.h>

#define N 9

// Print Sudoku board
void printBoard(int board[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if number is safe
int isSafe(int board[N][N], int row, int col, int num)
{
    for(int x = 0; x < N; x++)
        if(board[row][x] == num || board[x][col] == num)
            return 0;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}

int solveSudoku(int board[N][N])
{
    int row, col, empty = 0;

    for(row = 0; row < N; row++)
    {
        for(col = 0; col < N; col++)
        {
            if(board[row][col] == 0)
            {
                empty = 1;
                break;
            }
        }
        if(empty) break;
    }

    if(!empty)
        return 1;

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if(solveSudoku(board))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}


int main()
{
    int board[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(solveSudoku(board))
        printBoard(board);
    else
        printf("No solution exists");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice, guess;

    // Generate random number (1–6)
    srand(time(0));
    dice = rand() % 6 + 1;

    printf("Dice Game\n");
    printf("Guess the dice number (1 to 6): ");
    scanf("%d", &guess);

    printf("Dice rolled: %d\n", dice);

    if(guess == dice) {
        printf("Correct guess\n");
    } else {
        printf("Wrong guess\n");
    }

    return 0;
}


// Output
// Dice Game
// Guess the dice number (1 to 6): 4
// Dice rolled: 2
// Wrong guess