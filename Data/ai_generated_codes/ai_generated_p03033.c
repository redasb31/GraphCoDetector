#include <stdio.h>
#include <stdlib.h>

// Structure to represent a roadwork
typedef struct Roadwork {
    int start_time;
    int end_time;
    int position;
} Roadwork;

// Function to compare roadworks based on their start time
int compare_roadworks(const void *a, const void *b) {
    Roadwork *ra = (Roadwork *)a;
    Roadwork *rb = (Roadwork *)b;
    return ra->start_time - rb->start_time;
}

// Function to find the distance a person walks before encountering a roadwork
int find_distance(Roadwork *roadworks, int num_roadworks, int start_time) {
    int distance = 0;
    int i = 0;

    // Iterate through the roadworks
    while (i < num_roadworks) {
        // If the roadwork starts before the person reaches the position
        if (roadworks[i].start_time <= start_time + distance) {
            // If the person reaches the position before the roadwork ends
            if (roadworks[i].end_time > start_time + distance) {
                return distance + (roadworks[i].position - distance);
            }
            // If the roadwork ends before the person reaches the position
            else {
                i++;
            }
        }
        // If the roadwork starts after the person reaches the position
        else {
            return -1;
        }
    }
    // If no roadworks encountered
    return -1;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    // Allocate memory for roadworks
    Roadwork *roadworks = (Roadwork *)malloc(sizeof(Roadwork) * N);

    // Read roadwork information
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &roadworks[i].start_time, &roadworks[i].end_time, &roadworks[i].position);
    }

    // Sort roadworks by start time
    qsort(roadworks, N, sizeof(Roadwork), compare_roadworks);

    // Read person starting times
    int *start_times = (int *)malloc(sizeof(int) * Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &start_times[i]);
    }

    // Calculate and print distances for each person
    for (int i = 0; i < Q; i++) {
        int distance = find_distance(roadworks, N, start_times[i]);
        printf("%d\n", distance);
    }

    // Free allocated memory
    free(roadworks);
    free(start_times);

    return 0;
}