#include <stdio.h>
#include <stdlib.h>

// Structure to store a segment
typedef struct {
    int left;
    int right;
} Segment;

// Function to compare two segments based on their left endpoints
int compareSegments(const void *a, const void *b) {
    Segment *seg1 = (Segment *)a;
    Segment *seg2 = (Segment *)b;
    return seg1->left - seg2->left;
}

// Function to calculate the total distance traveled by Takahashi
int calculateDistance(Segment *segments, int n) {
    int distance = 0;
    int currentPosition = 0; // Takahashi's initial position

    // Sort segments based on their left endpoints
    qsort(segments, n, sizeof(Segment), compareSegments);

    for (int i = 0; i < n; i++) {
        // Calculate the distance to the chosen segment
        distance += abs(currentPosition - segments[i].left);
        currentPosition = segments[i].left; // Update Takahashi's position
        // Calculate the distance within the chosen segment
        distance += abs(segments[i].right - segments[i].left);
        currentPosition = segments[i].right; // Update Takahashi's position
    }

    // Calculate the distance to return to the starting point
    distance += abs(currentPosition - 0);

    return distance;
}

int main() {
    int n;
    scanf("%d", &n);

    Segment *segments = malloc(n * sizeof(Segment));
    if (segments == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read segment information from the input
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &segments[i].left, &segments[i].right);
    }

    // Calculate the total distance
    int totalDistance = calculateDistance(segments, n);

    printf("%d\n", totalDistance);

    free(segments);

    return 0;
}