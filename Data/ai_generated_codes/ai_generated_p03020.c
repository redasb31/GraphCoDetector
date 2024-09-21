#include <stdio.h>
#include <stdlib.h>

// Structure to store coordinates and count of balls
typedef struct {
    int x;
    int y;
    int count;
} Ball;

// Function to compare the y-coordinates of two balls
int compareY(const void *a, const void *b) {
    Ball *ballA = (Ball *)a;
    Ball *ballB = (Ball *)b;
    return ballA->y - ballB->y;
}

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for red and blue balls
    Ball *redBalls = (Ball *)malloc(N * sizeof(Ball));
    Ball *blueBalls = (Ball *)malloc(N * sizeof(Ball));

    // Read red ball information
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &redBalls[i].x, &redBalls[i].y, &redBalls[i].count);
    }

    // Read blue ball information
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &blueBalls[i].x, &blueBalls[i].y, &blueBalls[i].count);
    }

    // Sort red and blue balls by y-coordinate
    qsort(redBalls, N, sizeof(Ball), compareY);
    qsort(blueBalls, N, sizeof(Ball), compareY);

    // Calculate maximum score
    long long maxScore = 0;
    int redIndex = 0;
    int blueIndex = 0;

    // Iterate through red and blue balls, pairing them based on y-coordinate
    while (redIndex < N && blueIndex < N) {
        // If current red ball's y-coordinate is less than or equal to current blue ball's y-coordinate
        if (redBalls[redIndex].y <= blueBalls[blueIndex].y) {
            // Calculate the score for the current pair
            long long score = abs(redBalls[redIndex].x - blueBalls[blueIndex].x) + abs(redBalls[redIndex].y - blueBalls[blueIndex].y);

            // Add the score to the total score
            maxScore += score * redBalls[redIndex].count;

            // Decrement the count of the current red ball
            redBalls[redIndex].count--;

            // If all red balls at the current y-coordinate are paired, move to the next red ball
            if (redBalls[redIndex].count == 0) {
                redIndex++;
            }
        } else {
            // If current blue ball's y-coordinate is less than current red ball's y-coordinate, move to the next blue ball
            blueIndex++;
        }
    }

    // Print the maximum score
    printf("%lld\n", maxScore);

    // Free allocated memory
    free(redBalls);
    free(blueBalls);

    return 0;
}