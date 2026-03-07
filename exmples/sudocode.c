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