#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8 // Acceleration due to gravity
#define EPSILON 1e-6 // Tolerance for floating-point comparisons

// Structure to represent an obstacle
typedef struct {
    int left;
    int bottom;
    int right;
    int top;
} Obstacle;

// Function to check if a point is inside an obstacle
int isInsideObstacle(Obstacle obstacle, double x, double y) {
    return (x >= obstacle.left - EPSILON && x <= obstacle.right + EPSILON &&
            y >= obstacle.bottom - EPSILON && y <= obstacle.top + EPSILON);
}

// Function to simulate the white bird's trajectory
int simulateTrajectory(int V, int X, int Y, Obstacle obstacles[], int N) {
    double angle; // Launch angle in radians
    double vx, vy; // Horizontal and vertical velocity components
    double t; // Time elapsed
    double x, y; // Position of the white bird

    // Iterate over different launch angles
    for (angle = 0; angle <= M_PI / 2; angle += 0.01) {
        // Calculate initial velocity components
        vx = V * cos(angle);
        vy = V * sin(angle);

        // Reset time and position
        t = 0;
        x = 0;
        y = 0;

        // Simulate the trajectory until the white bird hits the ground
        while (y >= 0) {
            // Update position based on velocity and time
            x += vx * t;
            y += vy * t - 0.5 * GRAVITY * t * t;

            // Check for collision with obstacles
            for (int i = 0; i < N; i++) {
                if (isInsideObstacle(obstacles[i], x, y)) {
                    // Collision occurred, break the loop
                    goto nextAngle;
                }
            }

            // Check if the white bird is above the pig
            if (x >= X - EPSILON && x <= X + EPSILON && y >= Y - EPSILON) {
                // The white bird can drop an egg bomb
                return 1;
            }

            // Increment time
            t += 0.01;
        }

nextAngle:
        // Continue to the next launch angle
    }

    // No suitable launch angle found
    return 0;
}

int main() {
    int N, V, X, Y;
    scanf("%d %d %d %d", &N, &V, &X, &Y);

    Obstacle obstacles[50]; // Array to store obstacles

    // Read obstacle data
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &obstacles[i].left, &obstacles[i].bottom, &obstacles[i].right, &obstacles[i].top);
    }

    // Simulate the trajectory
    if (simulateTrajectory(V, X, Y, obstacles, N)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}