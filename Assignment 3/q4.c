#include <stdio.h>

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, target, auxiliary);
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, source, target);
}

// Function to print the chessboard for the Eight Queens problem
void printBoard(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed safely
int isSafe(int board[8][8], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    for (i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

// Function to solve the Eight Queens problem using backtracking
int solveNQueens(int board[8][8], int col) {
    if (col >= 8) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1)) {
                return 1;
            }

            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    int choice;
    printf("Menu:\n");
    printf("1. Solve the Tower of Hanoi problem\n");
    printf("2. Solve the Eight Queens problem\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int n;
        printf("Enter the number of disks for the Tower of Hanoi: ");
        scanf("%d", &n);
        towerOfHanoi(n, 'A', 'B', 'C');
    } else if (choice == 2) {
        int board[8][8] = {0};
        if (solveNQueens(board, 0)) {
            printf("Solution to the Eight Queens problem:\n");
            printBoard(board);
        } else {
            printf("No solution found for the Eight Queens problem.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

