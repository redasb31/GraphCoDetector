#include <stdio.h>
#include <stdlib.h>

// Structure to represent a song
typedef struct Song {
    int length;
    int satisfaction;
    int feature;
} Song;

// Function to compare two songs based on their satisfaction points in descending order
int compareSongs(const void *a, const void *b) {
    Song *songA = (Song *)a;
    Song *songB = (Song *)b;
    return songB->satisfaction - songA->satisfaction;
}

// Function to calculate the total satisfaction points for a given program
int calculateSatisfaction(Song *songs, int n, int *program, int programLength) {
    int totalSatisfaction = 0;
    if (programLength == 0) {
        return 0;
    }
    totalSatisfaction += songs[program[0]].satisfaction;
    for (int i = 1; i < programLength; i++) {
        totalSatisfaction += songs[program[i]].satisfaction -
            (songs[program[i]].feature - songs[program[i - 1]].feature) *
            (songs[program[i]].feature - songs[program[i - 1]].feature);
    }
    return totalSatisfaction;
}

// Function to find the maximum satisfaction points using dynamic programming
int findMaxSatisfaction(Song *songs, int n, int T) {
    // Create a 2D array to store the maximum satisfaction points for each song
    // and the available time
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((T + 1) * sizeof(int));
    }

    // Initialize the base case
    for (int i = 0; i <= T; i++) {
        dp[0][i] = 0;
    }

    // Iterate over each song
    for (int i = 1; i <= n; i++) {
        // Iterate over each available time
        for (int j = 0; j <= T; j++) {
            // If the current song's length is greater than the available time,
            // the maximum satisfaction points are the same as the previous song
            if (songs[i - 1].length > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Calculate the maximum satisfaction points with and without
                // the current song
                int withSong = dp[i - 1][j - songs[i - 1].length] +
                    songs[i - 1].satisfaction;
                int withoutSong = dp[i - 1][j];

                // Choose the maximum satisfaction points
                dp[i][j] = (withSong > withoutSong) ? withSong : withoutSong;
            }
        }
    }

    // The maximum satisfaction points are stored in the last cell of the array
    int maxSatisfaction = dp[n][T];

    // Free the allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return maxSatisfaction;
}

int main() {
    // Read the input
    int N, T;
    scanf("%d %d", &N, &T);

    // Create an array of songs
    Song *songs = (Song *)malloc(N * sizeof(Song));

    // Read the song parameters
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &songs[i].length, &songs[i].satisfaction,
              &songs[i].feature);
    }

    // Sort the songs based on their satisfaction points in descending order
    qsort(songs, N, sizeof(Song), compareSongs);

    // Find the maximum satisfaction points
    int maxSatisfaction = findMaxSatisfaction(songs, N, T);

    // Print the maximum satisfaction points
    printf("%d\n", maxSatisfaction);

    // Free the allocated memory
    free(songs);

    return 0;
}