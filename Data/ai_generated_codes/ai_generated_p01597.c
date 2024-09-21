#include <stdio.h>
#include <stdlib.h>

// Structure to represent an obstacle
typedef struct {
    int x1, y1, x2, y2;
} Obstacle;

// Function to check if a point is inside an obstacle
int isInside(Obstacle obstacle, int x, int y) {
    return (x >= obstacle.x1 && x <= obstacle.x2 && y >= obstacle.y1 && y <= obstacle.y2);
}

// Function to check if a point is on the boundary of an obstacle
int isOnBoundary(Obstacle obstacle, int x, int y) {
    return (x == obstacle.x1 || x == obstacle.x2 || y == obstacle.y1 || y == obstacle.y2);
}

// Function to find the next point the mouse will reach after turning left
int getNextPoint(Obstacle *obstacles, int numObstacles, int x, int y, int direction) {
    // 0: right, 1: up, 2: left, 3: down
    if (direction == 0) {
        // Move rightward
        for (int i = 0; i < numObstacles; i++) {
            if (isInside(obstacles[i], x + 1, y)) {
                return 1; // Move upward
            }
        }
        return 0; // Continue moving rightward
    } else if (direction == 1) {
        // Move upward
        for (int i = 0; i < numObstacles; i++) {
            if (isInside(obstacles[i], x, y + 1)) {
                return 2; // Move leftward
            }
        }
        return 1; // Continue moving upward
    } else if (direction == 2) {
        // Move leftward
        for (int i = 0; i < numObstacles; i++) {
            if (isInside(obstacles[i], x - 1, y)) {
                return 3; // Move downward
            }
        }
        return 2; // Continue moving leftward
    } else {
        // Move downward
        for (int i = 0; i < numObstacles; i++) {
            if (isInside(obstacles[i], x, y - 1)) {
                return 0; // Move rightward
            }
        }
        return 3; // Continue moving downward
    }
}

// Function to count the number of possible hiding points
int countHidingPoints(Obstacle *obstacles, int numObstacles) {
    int count = 0;
    int x = 0, y = 0; // Starting position
    int direction = 0; // Initial direction: right
    int visited[40000][40000] = {0}; // Array to track visited points

    // Iterate until the mouse encounters an infinite loop
    while (1) {
        // Check if the current point is a hiding point
        if (visited[x][y] == 2) {
            count++;
        }

        visited[x][y]++; // Mark the point as visited

        // Find the next point and direction
        int nextDirection = getNextPoint(obstacles, numObstacles, x, y, direction);
        if (nextDirection != direction) { // If the direction changes, it means the mouse hit an obstacle
            direction = nextDirection;
            if (visited[x][y] == 2) { // If the mouse is at the same point for the second time, it's a hiding point
                count++;
            }
        }

        // Move to the next point
        if (direction == 0) {
            x++;
        } else if (direction == 1) {
            y++;
        } else if (direction == 2) {
            x--;
        } else {
            y--;
        }

        // Check if the mouse has entered an infinite loop
        if (visited[x][y] >= 3) {
            break;
        }
    }

    return count;
}

int main() {
    int numObstacles;
    scanf("%d", &numObstacles);

    Obstacle *obstacles = (Obstacle *)malloc(numObstacles * sizeof(Obstacle));
    for (int i = 0; i < numObstacles; i++) {
        scanf("%d %d %d %d", &obstacles[i].x1, &obstacles[i].y1, &obstacles[i].x2, &obstacles[i].y2);
    }

    int hidingPoints = countHidingPoints(obstacles, numObstacles);
    printf("%d\n", hidingPoints);

    free(obstacles);

    return 0;
}