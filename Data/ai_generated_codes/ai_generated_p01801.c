#include <stdio.h>
#include <stdbool.h>

#define MAX_H 20
#define MAX_W 20

// Structure to represent the board
typedef struct {
    char cells[MAX_H][MAX_W];
    int h, w;
} Board;

// Function to initialize the board
void init_board(Board *board, int h, int w) {
    board->h = h;
    board->w = w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            board->cells[i][j] = '.'; // Initialize all cells to empty
        }
    }
}

// Function to print the board
void print_board(Board *board) {
    for (int i = 0; i < board->h; i++) {
        for (int j = 0; j < board->w; j++) {
            printf("%c", board->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to make a move on the board
bool make_move(Board *board, int row, int col) {
    // Check if the chosen cell is valid
    if (row < 0 || row >= board->h || col < 0 || col >= board->w || board->cells[row][col] != '.') {
        return false;
    }

    // Mark the chosen cell as a wall
    board->cells[row][col] = 'X';

    // Extend the wall in all four directions
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) {
                continue; // Skip the chosen cell
            }
            int r = row + dr;
            int c = col + dc;
            while (r >= 0 && r < board->h && c >= 0 && c < board->w && board->cells[r][c] != 'X') {
                board->cells[r][c] = 'X';
                r += dr;
                c += dc;
            }
        }
    }

    return true;
}

// Function to check if a player can make a move
bool can_move(Board *board) {
    for (int i = 0; i < board->h; i++) {
        for (int j = 0; j < board->w; j++) {
            if (board->cells[i][j] == '.') {
                return true; // There is an empty cell
            }
        }
    }
    return false; // No empty cells available
}

// Function to determine the winner of the game
bool check_winner(Board *board) {
    // The first player wins if they can make a move
    return can_move(board);
}

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    Board board;
    init_board(&board, h, w);

    // Read the initial board configuration
    for (int i = 0; i < h; i++) {
        scanf("%s", board.cells[i]);
    }

    // Determine the winner
    if (check_winner(&board)) {
        printf("First\n");
    } else {
        printf("Second\n");
    }

    return 0;
}