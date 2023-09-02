#include <stdio.h>

char board[3][3]; // The Tic Tac Toe board

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}
int checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Game still ongoing
            }
        }
    }
    
    return -1; // Draw
}

int main() {
    int player = 1; // Player 1 starts
    int row, col, input;
    
    initializeBoard();
    
    while (1) {
        printBoard();
        printf("Player %d, enter a number (1-9): ", player);
        scanf("%d", &input);
        
        row = (input - 1) / 3;
        col = (input - 1) % 3;
        
        if (input < 1 || input > 9 || board[row][col] != ' ') {
            printf("Invalid input. Try again.\n");
            continue;
        }
        
        board[row][col] = (player == 1) ? 'X' : 'O';
        
        int result = checkWin();
        if (result == 1) {
            printBoard();
            printf("Player %d wins!\n", player);
            break;
        } else if (result == -1) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        
        player = (player == 1) ? 2 : 1;
    }
    
    return 0;
}