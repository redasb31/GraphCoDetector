#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000000000000

// Structure for a line segment
typedef struct {
    int x1, y1;
    int x2, y2;
} Line;

// Structure for a point
typedef struct {
    int x, y;
} Point;

// Function to check if two line segments intersect
int checkIntersection(Line line1, Line line2) {
    // Calculate the slopes and y-intercepts of the two lines
    double m1 = (double)(line1.y2 - line1.y1) / (line1.x2 - line1.x1);
    double c1 = line1.y1 - m1 * line1.x1;
    double m2 = (double)(line2.y2 - line2.y1) / (line2.x2 - line2.x1);
    double c2 = line2.y1 - m2 * line2.x1;

    // Check if the slopes are equal, indicating parallel lines
    if (m1 == m2) {
        return 0;
    }

    // Calculate the x-coordinate of the intersection point
    double x = (c2 - c1) / (m1 - m2);

    // Check if the intersection point lies within both line segments
    if (x >= line1.x1 && x <= line1.x2 && x >= line2.x1 && x <= line2.x2) {
        return 1;
    }
    return 0;
}

// Function to check if a point lies on a line segment
int checkPointOnLine(Line line, Point point) {
    // Calculate the slopes and y-intercepts of the line segment and the line passing through the point and the start point of the line segment
    double m1 = (double)(line.y2 - line.y1) / (line.x2 - line1.x1);
    double c1 = line.y1 - m1 * line.x1;
    double m2 = (double)(point.y - line.y1) / (point.x - line.x1);
    double c2 = line.y1 - m2 * line.x1;

    // Check if the slopes and y-intercepts are equal, indicating that the point lies on the line segment
    if (m1 == m2 && c1 == c2) {
        // Check if the point lies within the line segment
        if ((point.x >= line.x1 && point.x <= line.x2) || (point.x <= line.x1 && point.x >= line.x2)) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the area of the region the cow can reach
int calculateArea(Line* northLines, int n, Line* eastLines, int m) {
    // Initialize the area to 0
    int area = 0;

    // Iterate through each quadrant
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            // Define the starting point for the current quadrant
            Point start = {0, 0};
            start.x *= i;
            start.y *= j;

            // Create a queue to store the points to be explored
            Point* queue = (Point*)malloc(sizeof(Point) * 1000000);
            int front = 0, rear = 0;

            // Add the starting point to the queue
            queue[rear++] = start;

            // Mark the starting point as visited
            int visited[1000][1000] = {0};
            visited[start.x][start.y] = 1;

            // Breadth-first search to explore the reachable region
            while (front < rear) {
                Point current = queue[front++];

                // Iterate through the four directions (up, down, left, right)
                for (int k = 0; k < 4; k++) {
                    // Define the next point based on the current direction
                    Point next = current;
                    if (k == 0) {
                        next.y++;
                    } else if (k == 1) {
                        next.y--;
                    } else if (k == 2) {
                        next.x++;
                    } else if (k == 3) {
                        next.x--;
                    }

                    // Check if the next point is within the bounds of the grid and has not been visited before
                    if (next.x >= -1000 && next.x <= 1000 && next.y >= -1000 && next.y <= 1000 && !visited[next.x][next.y]) {
                        // Check if the next point intersects with any of the line segments
                        int intersects = 0;
                        for (int l = 0; l < n; l++) {
                            if (checkIntersection((Line){northLines[l].x1, northLines[l].y1, northLines[l].x2, northLines[l].y2}, (Line){current.x, current.y, next.x, next.y})) {
                                intersects = 1;
                                break;
                            }
                        }
                        for (int l = 0; l < m; l++) {
                            if (checkIntersection((Line){eastLines[l].x1, eastLines[l].y1, eastLines[l].x2, eastLines[l].y2}, (Line){current.x, current.y, next.x, next.y})) {
                                intersects = 1;
                                break;
                            }
                        }
                        // Check if the next point lies on any of the line segments
                        for (int l = 0; l < n; l++) {
                            if (checkPointOnLine((Line){northLines[l].x1, northLines[l].y1, northLines[l].x2, northLines[l].y2}, next)) {
                                intersects = 1;
                                break;
                            }
                        }
                        for (int l = 0; l < m; l++) {
                            if (checkPointOnLine((Line){eastLines[l].x1, eastLines[l].y1, eastLines[l].x2, eastLines[l].y2}, next)) {
                                intersects = 1;
                                break;
                            }
                        }
                        // If the next point does not intersect with any of the line segments, add it to the queue and mark it as visited
                        if (!intersects) {
                            queue[rear++] = next;
                            visited[next.x][next.y] = 1;
                        }
                    }
                }
            }

            // Free the queue
            free(queue);

            // Calculate the area of the current quadrant
            for (int l = -1000; l <= 1000; l++) {
                for (int r = -1000; r <= 1000; r++) {
                    if (visited[l][r]) {
                        area++;
                    }
                }
            }
        }
    }

    // Check if the area is infinite
    if (area == INF) {
        return INF;
    }

    // Return the calculated area
    return area;
}

int main() {
    // Read the number of north-south lines and east-west lines
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate memory for the line segments
    Line* northLines = (Line*)malloc(sizeof(Line) * n);
    Line* eastLines = (Line*)malloc(sizeof(Line) * m);

    // Read the coordinates of the north-south lines
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &northLines[i].x1, &northLines[i].x2, &northLines[i].y1);
        northLines[i].y2 = northLines[i].y1;
    }

    // Read the coordinates of the east-west lines
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &eastLines[i].x1, &eastLines[i].y1, &eastLines[i].y2);
        eastLines[i].x2 = eastLines[i].x1;
    }

    // Calculate the area of the region the cow can reach
    int area = calculateArea(northLines, n, eastLines, m);

    // Print the calculated area
    if (area == INF) {
        printf("INF\n");
    } else {
        printf("%d\n", area);
    }

    // Free the allocated memory
    free(northLines);
    free(eastLines);

    return 0;
}