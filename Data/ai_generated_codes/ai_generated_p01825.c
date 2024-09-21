#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Structure to represent a segment
typedef struct {
    Point start;
    Point end;
} Segment;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the point where the laser cutter should start cutting a segment
Point find_start_point(Point initial_point, Segment segment) {
    // Calculate the distance between the initial point and the start point of the segment
    double dist_start = distance(initial_point, segment.start);
    // Calculate the distance between the initial point and the end point of the segment
    double dist_end = distance(initial_point, segment.end);
    // Return the closer end point
    return dist_start < dist_end ? segment.start : segment.end;
}

// Function to calculate the total distance traveled by the laser cutter
double calculate_total_distance(Point initial_point, Segment segments[], int n) {
    double total_distance = 0.0;
    // Initialize the current position of the laser cutter to the initial point
    Point current_position = initial_point;
    // Iterate over all the segments
    for (int i = 0; i < n; i++) {
        // Find the point where the laser cutter should start cutting the current segment
        Point start_point = find_start_point(current_position, segments[i]);
        // Add the distance from the current position to the start point to the total distance
        total_distance += distance(current_position, start_point);
        // Add the length of the segment to the total distance
        total_distance += distance(segments[i].start, segments[i].end);
        // Update the current position to the end point of the current segment
        current_position = segments[i].end;
    }
    // Add the distance from the final position to the initial point to the total distance
    total_distance += distance(current_position, initial_point);
    // Return the total distance traveled
    return total_distance;
}

int main() {
    int n; // Number of segments
    Point initial_point; // Initial position of the laser cutter
    Segment segments[300]; // Array to store the segments

    // Read the input
    scanf("%d", &n);
    scanf("%lf %lf", &initial_point.x, &initial_point.y);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf", &segments[i].start.x, &segments[i].start.y, &segments[i].end.x, &segments[i].end.y);
    }

    // Calculate the total distance traveled by the laser cutter
    double total_distance = calculate_total_distance(initial_point, segments, n);

    // Print the output
    printf("%.12lf\n", total_distance);

    return 0;
}