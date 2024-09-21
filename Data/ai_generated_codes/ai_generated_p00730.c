#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x; // x-coordinate of the top-left corner
    int y; // y-coordinate of the top-left corner
    int w; // width
    int h; // height
} Piece;

// Function to compare two pieces based on their area
int compare_pieces(const void *a, const void *b) {
    Piece *piece1 = (Piece *)a;
    Piece *piece2 = (Piece *)b;
    return (piece1->w * piece1->h) - (piece2->w * piece2->h);
}

// Function to calculate the area of a piece
int area(Piece piece) {
    return piece.w * piece.h;
}

// Function to cut a piece based on the starting point and direction
void cut_piece(Piece *piece, int start, int direction) {
    // Calculate the coordinates of the cut
    int x = piece->x;
    int y = piece->y;
    if (direction == 1) { // East
        x += start;
    } else if (direction == 2) { // South
        y += start;
    } else if (direction == 3) { // West
        x -= start;
    } else { // North
        y -= start;
    }

    // Create new pieces based on the cut
    Piece new_piece1 = {
        piece->x,
        piece->y,
        direction == 1 || direction == 3 ? start : piece->w,
        direction == 2 || direction == 4 ? start : piece->h
    };
    Piece new_piece2 = {
        direction == 1 ? x : piece->x,
        direction == 2 ? y : piece->y,
        direction == 1 || direction == 3 ? piece->w - start : piece->w,
        direction == 2 || direction == 4 ? piece->h - start : piece->h
    };

    // Update the original piece with the new pieces
    *piece = new_piece1;
    *piece = new_piece2;
}

int main() {
    int n, w, d, p, s, i;
    Piece cake;
    Piece *pieces;

    while (1) {
        scanf("%d %d %d", &n, &w, &d);
        if (n == 0 && w == 0 && d == 0) {
            break;
        }

        cake.x = 0;
        cake.y = 0;
        cake.w = w;
        cake.h = d;

        pieces = (Piece *)malloc(sizeof(Piece) * (n + 1));
        pieces[0] = cake;

        for (i = 1; i <= n; i++) {
            scanf("%d %d", &p, &s);

            // Cut the piece based on the starting point and direction
            cut_piece(&pieces[p - 1], s, i % 4 + 1); // Rotate direction for each cut

            // Shift the array to accommodate the new piece
            pieces = (Piece *)realloc(pieces, sizeof(Piece) * (i + 1));
            pieces[i] = pieces[i - 1];
        }

        // Sort the pieces based on their area
        qsort(pieces, n + 1, sizeof(Piece), compare_pieces);

        // Print the area of each piece
        for (i = 0; i <= n; i++) {
            printf("%d ", area(pieces[i]));
        }
        printf("\n");

        free(pieces);
    }

    return 0;
}