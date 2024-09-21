#include <stdio.h>

// Function to calculate the number of white squares in a block
int count_white_squares(int h, int w, int top, int bottom, int left, int right, int **S) {
    int count = 0;
    for (int i = top; i < bottom; i++) {
        for (int j = left; j < right; j++) {
            if (S[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to determine the minimum cuts required
int min_cuts(int H, int W, int K, int **S) {
    int cuts = 0;
    int h_start = 0, h_end = H;
    int w_start = 0, w_end = W;

    while (h_start < h_end || w_start < w_end) {
        // Cut horizontally if necessary
        if (count_white_squares(H, W, h_start, h_end, w_start, w_end, S) > K) {
            int mid = (h_start + h_end) / 2;
            if (count_white_squares(H, W, h_start, mid, w_start, w_end, S) <= K) {
                h_end = mid;
            } else {
                h_start = mid + 1;
            }
            cuts++;
        } else {
            // Cut vertically if necessary
            if (count_white_squares(H, W, h_start, h_end, w_start, w_end, S) > K) {
                int mid = (w_start + w_end) / 2;
                if (count_white_squares(H, W, h_start, h_end, w_start, mid, S) <= K) {
                    w_end = mid;
                } else {
                    w_start = mid + 1;
                }
                cuts++;
            } else {
                // No cut needed, move to the next block
                if (h_start < h_end) {
                    h_start = h_end;
                } else {
                    w_start = w_end;
                }
            }
        }
    }

    return cuts;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);

    // Allocate memory for the chocolate bar matrix
    int **S = (int **)malloc(H * sizeof(int *));
    for (int i = 0; i < H; i++) {
        S[i] = (int *)malloc(W * sizeof(int));
    }

    // Read the chocolate bar configuration
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%1d", &S[i][j]);
        }
    }

    // Calculate the minimum cuts required
    int cuts = min_cuts(H, W, K, S);

    // Print the result
    printf("%d\n", cuts);

    // Free memory
    for (int i = 0; i < H; i++) {
        free(S[i]);
    }
    free(S);

    return 0;
}