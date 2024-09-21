#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Rook;

// Function to compare two rooks based on their x-coordinates
int compare_x(const void* a, const void* b) {
    Rook* rook1 = (Rook*)a;
    Rook* rook2 = (Rook*)b;
    return rook1->x - rook2->x;
}

// Function to compare two rooks based on their y-coordinates
int compare_y(const void* a, const void* b) {
    Rook* rook1 = (Rook*)a;
    Rook* rook2 = (Rook*)b;
    return rook1->y - rook2->y;
}

// Function to calculate the minimum moves needed to beat the maximum number of rooks
int calculate_moves(Rook* rooks, int n, int i) {
    // Sort rooks by x-coordinate for horizontal movement
    qsort(rooks, n, sizeof(Rook), compare_x);

    // Find the position of the rook to be replaced with the king
    int king_pos = -1;
    for (int j = 0; j < n; j++) {
        if (rooks[j].x == rooks[i].x && rooks[j].y == rooks[i].y) {
            king_pos = j;
            break;
        }
    }

    // Calculate moves in the horizontal direction
    int horizontal_moves = 0;
    if (king_pos > 0) {
        horizontal_moves += rooks[king_pos].x - rooks[king_pos - 1].x - 1;
    }
    if (king_pos < n - 1) {
        horizontal_moves += rooks[king_pos + 1].x - rooks[king_pos].x - 1;
    }

    // Sort rooks by y-coordinate for vertical movement
    qsort(rooks, n, sizeof(Rook), compare_y);

    // Find the position of the rook to be replaced with the king
    king_pos = -1;
    for (int j = 0; j < n; j++) {
        if (rooks[j].x == rooks[i].x && rooks[j].y == rooks[i].y) {
            king_pos = j;
            break;
        }
    }

    // Calculate moves in the vertical direction
    int vertical_moves = 0;
    if (king_pos > 0) {
        vertical_moves += rooks[king_pos].y - rooks[king_pos - 1].y - 1;
    }
    if (king_pos < n - 1) {
        vertical_moves += rooks[king_pos + 1].y - rooks[king_pos].y - 1;
    }

    // Return the minimum number of moves
    return horizontal_moves + vertical_moves;
}

int main() {
    int n;
    scanf("%d", &n);

    Rook* rooks = (Rook*)malloc(n * sizeof(Rook));
    if (rooks == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Read rook positions
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rooks[i].x, &rooks[i].y);
    }

    // Calculate and print minimum moves for each rook
    for (int i = 0; i < n; i++) {
        printf("%d\n", calculate_moves(rooks, n, i));
    }

    free(rooks);

    return 0;
}