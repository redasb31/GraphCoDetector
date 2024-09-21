#include <stdio.h>
#include <stdlib.h>

// Structure to represent a robot
typedef struct {
    int x; // Position of the robot
    int l; // Length of the robot's arm
} Robot;

// Comparison function for qsort to sort robots by their starting position
int compare_robots(const void *a, const void *b) {
    Robot *robot_a = (Robot *)a;
    Robot *robot_b = (Robot *)b;
    return robot_a->x - robot_b->x;
}

// Function to determine the maximum number of robots that can be kept
int max_robots(Robot *robots, int n) {
    // Sort the robots by their position
    qsort(robots, n, sizeof(Robot), compare_robots);

    // Initialize the maximum number of robots to 1
    int max_count = 1;

    // Initialize the position of the last kept robot
    int last_x = robots[0].x + robots[0].l;

    // Iterate through the robots
    for (int i = 1; i < n; i++) {
        // If the current robot's starting position is greater than the ending position of the last kept robot
        if (robots[i].x - robots[i].l >= last_x) {
            // Increment the count and update the last kept robot's position
            max_count++;
            last_x = robots[i].x + robots[i].l;
        }
    }

    // Return the maximum number of robots
    return max_count;
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for the robots
    Robot *robots = malloc(n * sizeof(Robot));

    // Read the robot positions and arm lengths
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &robots[i].x, &robots[i].l);
    }

    // Calculate the maximum number of robots that can be kept
    int max_count = max_robots(robots, n);

    // Print the result
    printf("%d\n", max_count);

    // Free the allocated memory
    free(robots);

    return 0;
}