#include <stdio.h>
#include <stdlib.h>

int isSafe(int board[][10], int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return 0;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}

int solveNQueens(int board[][10], int col, int n) {
    if (col >= n) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1, n)) {
                return 1;
            }
            board[i][col] = 0;
        }
    }
    return 0;
}

void printSolution(int board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int board[10][10] = {0};

    if (solveNQueens(board, 0, n) == 1) {
        printSolution(board, n);
    } else {
        printf("Solution does not exist\n");
    }
    return 0;
}

