#include <stdio.h>
#include <stdlib.h>

// Structure to store the information about each segment
typedef struct Segment {
    int l; // Left endpoint of the segment
    int r; // Right endpoint of the segment
    long long a; // Value associated with the segment
} Segment;

// Function to compare two segments based on their left endpoint
int compareSegments(const void *a, const void *b) {
    Segment *seg1 = (Segment *)a;
    Segment *seg2 = (Segment *)b;
    return seg1->l - seg2->l;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Allocate memory for segments
    Segment *segments = (Segment *)malloc(M * sizeof(Segment));

    // Read the segments and their associated values
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lld", &segments[i].l, &segments[i].r, &segments[i].a);
    }

    // Sort the segments in ascending order of their left endpoints
    qsort(segments, M, sizeof(Segment), compareSegments);

    // Initialize the maximum score
    long long maxScore = 0;

    // Use a greedy approach to maximize the score
    int currentRight = 0; // Keep track of the rightmost endpoint covered so far
    for (int i = 0; i < M; i++) {
        // If the current segment's left endpoint is greater than the current right endpoint,
        // it means the current segment is not overlapping with the previous segments
        if (segments[i].l > currentRight) {
            // Add the value of the current segment to the score
            maxScore += segments[i].a;
            // Update the rightmost endpoint covered
            currentRight = segments[i].r;
        } else {
            // If the current segment overlaps with the previous segments,
            // consider the segment with the maximum associated value
            if (segments[i].a > segments[i - 1].a) {
                // Update the score with the maximum value
                maxScore -= segments[i - 1].a;
                maxScore += segments[i].a;
                // Update the rightmost endpoint covered
                currentRight = segments[i].r;
            }
        }
    }

    // Print the maximum score
    printf("%lld\n", maxScore);

    // Free the allocated memory
    free(segments);

    return 0;
}