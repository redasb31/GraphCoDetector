#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Structure to represent a relative position
typedef struct {
    int x;
    int y;
} RelativePosition;

// Function to check if two relative positions are the same
int samePosition(RelativePosition pos1, RelativePosition pos2) {
    return (pos1.x == pos2.x && pos1.y == pos2.y);
}

// Function to check if the given relative positions are valid
int isValidPositions(RelativePosition positions[NUM_PAIRS]) {
    for (int i = 0; i < NUM_PAIRS; i++) {
        for (int j = i + 1; j < NUM_PAIRS; j++) {
            if (samePosition(positions[i], positions[j])) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to calculate the number of arrangements for a given set of relative positions
int countArrangements(RelativePosition positions[NUM_PAIRS]) {
    // Initialize a board to store the arrangement of cards
    char board[BOARD_SIZE][BOARD_SIZE];
    // Initialize a counter for valid arrangements
    int count = 0;
    // Iterate over all possible combinations of cards
    for (int a = 0; a < BOARD_SIZE * BOARD_SIZE; a++) {
        for (int b = 0; b < BOARD_SIZE * BOARD_SIZE; b++) {
            if (a != b) {
                for (int c = 0; c < BOARD_SIZE * BOARD_SIZE; c++) {
                    if (c != a && c != b) {
                        for (int d = 0; d < BOARD_SIZE * BOARD_SIZE; d++) {
                            if (d != a && d != b && d != c) {
                                for (int e = 0; e < BOARD_SIZE * BOARD_SIZE; e++) {
                                    if (e != a && e != b && e != c && e != d) {
                                        for (int f = 0; f < BOARD_SIZE * BOARD_SIZE; f++) {
                                            if (f != a && f != b && f != c && f != d && f != e) {
                                                for (int g = 0; g < BOARD_SIZE * BOARD_SIZE; g++) {
                                                    if (g != a && g != b && g != c && g != d && g != e && g != f) {
                                                        for (int h = 0; h < BOARD_SIZE * BOARD_SIZE; h++) {
                                                            if (h != a && h != b && h != c && h != d && h != e && h != f && h != g) {
                                                                // Initialize the board with all empty cells
                                                                for (int i = 0; i < BOARD_SIZE; i++) {
                                                                    for (int j = 0; j < BOARD_SIZE; j++) {
                                                                        board[i][j] = ' ';
                                                                    }
                                                                }
                                                                // Place the cards on the board according to the chosen positions
                                                                board[a / BOARD_SIZE][a % BOARD_SIZE] = 'A';
                                                                board[b / BOARD_SIZE][b % BOARD_SIZE] = 'A';
                                                                board[c / BOARD_SIZE][c % BOARD_SIZE] = 'B';
                                                                board[d / BOARD_SIZE][d % BOARD_SIZE] = 'B';
                                                                board[e / BOARD_SIZE][e % BOARD_SIZE] = 'C';
                                                                board[f / BOARD_SIZE][f % BOARD_SIZE] = 'C';
                                                                board[g / BOARD_SIZE][g % BOARD_SIZE] = 'D';
                                                                board[h / BOARD_SIZE][h % BOARD_SIZE] = 'D';
                                                                board[(a + positions[0].x) / BOARD_SIZE][(a + positions[0].y) % BOARD_SIZE] = 'E';
                                                                board[(b + positions[1].x) / BOARD_SIZE][(b + positions[1].y) % BOARD_SIZE] = 'E';
                                                                board[(c + positions[2].x) / BOARD_SIZE][(c + positions[2].y) % BOARD_SIZE] = 'F';
                                                                board[(d + positions[3].x) / BOARD_SIZE][(d + positions[3].y) % BOARD_SIZE] = 'F';
                                                                board[(e + positions[4].x) / BOARD_SIZE][(e + positions[4].y) % BOARD_SIZE] = 'G';
                                                                board[(f + positions[5].x) / BOARD_SIZE][(f + positions[5].y) % BOARD_SIZE] = 'G';
                                                                board[(g + positions[6].x) / BOARD_SIZE][(g + positions[6].y) % BOARD_SIZE] = 'H';
                                                                board[(h + positions[7].x) / BOARD_SIZE][(h + positions[7].y) % BOARD_SIZE] = 'H';
                                                                // Check if the arrangement is valid
                                                                if (isValidPositions(positions) && isValidArrangement(board)) {
                                                                    count++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}

// Function to check if an arrangement is valid
int isValidArrangement(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check if all cells are filled
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    // Check for duplicates
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = i; k < BOARD_SIZE; k++) {
                for (int l = j + 1; l < BOARD_SIZE; l++) {
                    if (board[i][j] == board[k][l]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    RelativePosition positions[NUM_PAIRS];
    int x, y;
    while (1) {
        scanf("%d %d", &x, &y);
        // Check if the input is valid
        if (x > 4) {
            break;
        }
        // Store the relative positions
        positions[0].x = x;
        positions[0].y = y;
        scanf("%d %d", &x, &y);
        positions[1].x = x;
        positions[1].y = y;
        scanf("%d %d", &x, &y);
        positions[2].x = x;
        positions[2].y = y;
        scanf("%d %d", &x, &y);
        positions[3].x = x;
        positions[3].y = y;
        positions[4].x = x;
        positions[4].y = y;
        scanf("%d %d", &x, &y);
        positions[5].x = x;
        positions[5].y = y;
        scanf("%d %d", &x, &y);
        positions[6].x = x;
        positions[6].y = y;
        scanf("%d %d", &x, &y);
        positions[7].x = x;
        positions[7].y = y;
        // Calculate and print the number of arrangements
        printf("%d\n", countArrangements(positions));
    }
    return 0;
}