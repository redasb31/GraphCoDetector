#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 1000
#define MAX_T 10000

// Structure to represent an advertisement
typedef struct {
    int points;
    int time;
    int max_watches;
    int watches; // Number of times the advertisement has been watched
} Advertisement;

// Structure to represent a website
typedef struct {
    Advertisement ad;
    int *links;  // Array of indices to linked websites
    int num_links;
} Website;

// Function to calculate the maximum points obtainable from a website
int max_points(Website website, int remaining_time, int visited) {
    // Base case: no time left or already visited
    if (remaining_time <= 0 || visited) {
        return 0;
    }

    // Calculate points with and without watching the advertisement
    int points_with_ad = 0;
    if (website.ad.time <= remaining_time && website.ad.watches < website.ad.max_watches) {
        website.ad.watches++;
        points_with_ad = website.ad.points + max_points(website, remaining_time - website.ad.time, visited);
        website.ad.watches--; // Reset watches for backtracking
    }

    int points_without_ad = 0;
    for (int i = 0; i < website.num_links; i++) {
        points_without_ad = max(points_without_ad, max_points(website.links[i], remaining_time, 1));
    }

    // Return the maximum of the two possibilities
    return max(points_with_ad, points_without_ad);
}

int main() {
    int N, M, T;
    while (scanf("%d %d %d", &N, &M, &T) != EOF && (N || M || T)) {
        // Initialize websites
        Website websites[MAX_N];
        for (int i = 0; i < N; i++) {
            websites[i].links = malloc(sizeof(int) * MAX_M);
            websites[i].num_links = 0;
            scanf("%d %d %d", &websites[i].ad.points, &websites[i].ad.time, &websites[i].ad.max_watches);
            websites[i].ad.watches = 0;
        }

        // Initialize links
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            websites[a - 1].links[websites[a - 1].num_links++] = &websites[b - 1];
        }

        // Calculate and print maximum points
        int max_points_collected = 0;
        for (int i = 0; i < N; i++) {
            max_points_collected = max(max_points_collected, max_points(websites[i], T, 0));
        }
        printf("%d\n", max_points_collected);

        // Free allocated memory
        for (int i = 0; i < N; i++) {
            free(websites[i].links);
        }
    }
    return 0;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}