#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point in 2D space
typedef struct {
    int x;
    int y;
} Point;

// Structure to represent a line segment
typedef struct {
    Point start;
    Point end;
} Line;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to calculate the time taken for the domino to reach a given point
double dominoTime(Point dominoStart, double dominoVelocity, Point target) {
    return distance(dominoStart, target) / dominoVelocity;
}

// Function to calculate the time taken for you to reach a given point
double yourTime(Point yourStart, double yourVelocity, Point target) {
    return distance(yourStart, target) / yourVelocity;
}

// Function to check if a point lies on a line segment
int onSegment(Line line, Point point) {
    return (point.x >= line.start.x && point.x <= line.end.x &&
            point.y >= line.start.y && point.y <= line.end.y);
}

// Function to find the closest point on a line segment to a given point
Point closestPointOnLine(Line line, Point point) {
    // Calculate the vector from the start of the line segment to the given point
    int dx = point.x - line.start.x;
    int dy = point.y - line.start.y;

    // Calculate the vector from the start of the line segment to the end of the line segment
    int lx = line.end.x - line.start.x;
    int ly = line.end.y - line.start.y;

    // Calculate the dot product of the two vectors
    int dot = dx * lx + dy * ly;

    // Calculate the length of the vector from the start of the line segment to the end of the line segment
    int lenSq = lx * lx + ly * ly;

    // Calculate the projection of the vector from the start of the line segment to the given point onto the line segment
    double param = (double)dot / lenSq;

    // If the projection is outside the line segment, return the closest endpoint
    if (param < 0) {
        return line.start;
    } else if (param > 1) {
        return line.end;
    } else {
        // Calculate the closest point on the line segment
        Point closest;
        closest.x = line.start.x + param * lx;
        closest.y = line.start.y + param * ly;
        return closest;
    }
}

int main() {
    int N, i;
    Point dominoChain[1000];
    Point dominoStart, yourStart;
    double dominoVelocity, yourVelocity;

    // Read the number of dominoes
    scanf("%d", &N);

    // Read the coordinates of the dominoes
    for (i = 0; i < N; i++) {
        scanf("%d %d", &dominoChain[i].x, &dominoChain[i].y);
    }

    // Read the starting point of the toppling
    scanf("%d %d %lf", &dominoStart.x, &dominoStart.y, &dominoVelocity);

    // Read your starting point and velocity
    scanf("%d %d %lf", &yourStart.x, &yourStart.y, &yourVelocity);

    // Initialize the minimum time to stop the toppling
    double minTime = INFINITY;

    // Iterate over all line segments of the domino chain
    for (i = 1; i < N; i++) {
        // Create a line segment from the current domino to the next domino
        Line line = {dominoChain[i - 1], dominoChain[i]};

        // Calculate the time taken for the domino to reach the closest point on the line segment
        Point closestPoint = closestPointOnLine(line, dominoStart);
        double dominoTimeToClosest = dominoTime(dominoStart, dominoVelocity, closestPoint);

        // Calculate the time taken for you to reach the closest point on the line segment
        double yourTimeToClosest = yourTime(yourStart, yourVelocity, closestPoint);

        // If you can reach the closest point before the domino
        if (yourTimeToClosest < dominoTimeToClosest) {
            // Calculate the time taken for you to stop the toppling at the closest point
            double stopTime = yourTimeToClosest;

            // Update the minimum time if this is faster
            if (stopTime < minTime) {
                minTime = stopTime;
            }
        }
    }

    // Calculate the time taken for the domino to reach the endpoints of the chain
    double dominoTimeToStart = dominoTime(dominoStart, dominoVelocity, dominoChain[0]);
    double dominoTimeToEnd = dominoTime(dominoStart, dominoVelocity, dominoChain[N - 1]);

    // Calculate the time taken for you to reach the endpoints of the chain
    double yourTimeToStart = yourTime(yourStart, yourVelocity, dominoChain[0]);
    double yourTimeToEnd = yourTime(yourStart, yourVelocity, dominoChain[N - 1]);

    // Update the minimum time if you can reach an endpoint before the domino
    if (yourTimeToStart < dominoTimeToStart && yourTimeToStart < minTime) {
        minTime = yourTimeToStart;
    }
    if (yourTimeToEnd < dominoTimeToEnd && yourTimeToEnd < minTime) {
        minTime = yourTimeToEnd;
    }

    // Print the minimum time to stop the toppling
    printf("%.6lf\n", minTime);

    return 0;
}