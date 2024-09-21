#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to store Force Point information
typedef struct {
    int x;
    int y;
    char direction;
} ForcePoint;

// Function to compare two Force Points based on their x-coordinate
int compare_x(const void *a, const void *b) {
    ForcePoint *fp1 = (ForcePoint *)a;
    ForcePoint *fp2 = (ForcePoint *)b;
    return fp1->x - fp2->x;
}

// Function to compare two Force Points based on their y-coordinate
int compare_y(const void *a, const void *b) {
    ForcePoint *fp1 = (ForcePoint *)a;
    ForcePoint *fp2 = (ForcePoint *)b;
    return fp1->y - fp2->y;
}

// Function to calculate the maximum speed of a proton
int calculate_max_speed(ForcePoint *force_points, int n) {
    int max_speed = 0;
    int current_speed = 1;
    int i, j, k;
    int x, y;
    char direction;

    // Sort Force Points by x-coordinate
    qsort(force_points, n, sizeof(ForcePoint), compare_x);

    // Iterate through all Force Points
    for (i = 0; i < n; i++) {
        x = force_points[i].x;
        y = force_points[i].y;
        direction = force_points[i].direction;

        // Check for Force Points with the same x-coordinate
        for (j = i + 1; j < n && force_points[j].x == x; j++) {
            // Check if the Force Points are in opposite directions
            if (direction == '>' && force_points[j].direction == '<' ||
                direction == '<' && force_points[j].direction == '>') {
                current_speed *= 2;
                i = j;
                break;
            }
        }

        // Check for Force Points with the same y-coordinate
        for (j = i + 1; j < n && force_points[j].x == x; j++) {
            // Check if the Force Points are in opposite directions
            if (direction == 'v' && force_points[j].direction == '^' ||
                direction == '^' && force_points[j].direction == 'v') {
                current_speed *= 2;
                i = j;
                break;
            }
        }

        // Check for Force Points with the same y-coordinate (after sorting by x-coordinate)
        qsort(force_points + i, n - i, sizeof(ForcePoint), compare_y);
        for (j = i + 1; j < n && force_points[j].y == y; j++) {
            // Check if the Force Points are in opposite directions
            if (direction == '>' && force_points[j].direction == '<' ||
                direction == '<' && force_points[j].direction == '>') {
                current_speed *= 2;
                i = j;
                break;
            }
        }

        // Update the maximum speed
        max_speed = (current_speed > max_speed) ? current_speed : max_speed;
    }

    // Calculate log_2 of the maximum speed
    return (int)log2(max_speed);
}

int main() {
    int n;
    ForcePoint *force_points;

    // Read the number of Force Points
    scanf("%d", &n);

    // Allocate memory for Force Points
    force_points = (ForcePoint *)malloc(n * sizeof(ForcePoint));

    // Read Force Point information
    for (int i = 0; i < n; i++) {
        scanf("%d %d %c", &force_points[i].x, &force_points[i].y, &force_points[i].direction);
    }

    // Calculate the maximum speed of the proton
    int log2_max_speed = calculate_max_speed(force_points, n);

    // Print the log_2 of the maximum speed
    printf("%d\n", log2_max_speed);

    // Free allocated memory
    free(force_points);

    return 0;
}