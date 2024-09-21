#include <stdio.h>
#include <math.h>

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to find the maximum length of the track
double maxTrackLength(struct Point points[], int n) {
    double maxLength = 0.0;

    // Iterate over all pairs of points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the distance between the points
            double dist = distance(points[i], points[j]);

            // Update the maximum length if the current distance is greater
            if (dist > maxLength) {
                maxLength = dist;
            }
        }
    }

    return maxLength;
}

int main() {
    int n, caseNum = 1;
    while (1) {
        scanf("%d", &n);

        // Exit the loop if n is 0
        if (n == 0) {
            break;
        }

        // Allocate memory for the points
        struct Point points[n];

        // Read the coordinates of the points
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &points[i].x, &points[i].y);
        }

        // Calculate the maximum track length
        double maxLength = maxTrackLength(points, n);

        // Print the case number and the maximum length
        printf("Case %d: %.12lf\n", caseNum, maxLength);
        caseNum++;
    }

    return 0;
}