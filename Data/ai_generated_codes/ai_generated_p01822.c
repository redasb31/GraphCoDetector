#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_Q 100000

// Structure to represent a point
typedef struct {
    int x, y;
} Point;

// Structure to represent a segment
typedef struct {
    int a, b;
} Segment;

// Function to calculate the cross product of two vectors
int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to check if a point lies on a segment
int on_segment(Point a, Point b, Point c) {
    return cross_product(a, b, c) == 0 &&
           (c.x - a.x) * (c.x - b.x) <= 0 &&
           (c.y - a.y) * (c.y - b.y) <= 0;
}

// Function to check if a point is inside a polygon
int is_inside_polygon(Point query, Point polygon[], int n) {
    int count = 0, j = n - 1;
    for (int i = 0; i < n; i++) {
        if ((polygon[i].y > query.y != polygon[j].y > query.y) &&
            (query.x < (polygon[j].x - polygon[i].x) * (query.y - polygon[i].y) /
                          (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            count++;
        }
        j = i;
    }
    return count % 2 == 1;
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    Point points[MAX_N];
    Segment segments[MAX_M];
    Point queries[MAX_Q];

    // Read points
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Read segments
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &segments[i].a, &segments[i].b);
    }

    // Read queries
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &queries[i].x, &queries[i].y);
    }

    // Check each query point
    for (int i = 0; i < Q; i++) {
        int found_polygon = 0;
        for (int j = 0; j < M; j++) {
            // Create a polygon using the current segment and all its adjacent segments
            int polygon_size = 0;
            Point polygon[MAX_N];
            int current = segments[j].a;
            polygon[polygon_size++] = points[current - 1];
            while (1) {
                // Find the next segment that shares an endpoint with the current segment
                int next_segment = -1;
                for (int k = 0; k < M; k++) {
                    if ((segments[k].a == current && segments[k].b != segments[j].b) ||
                        (segments[k].b == current && segments[k].a != segments[j].a)) {
                        next_segment = k;
                        break;
                    }
                }
                if (next_segment == -1) {
                    break;
                }
                // Add the endpoint of the next segment to the polygon
                if (segments[next_segment].a == current) {
                    current = segments[next_segment].b;
                } else {
                    current = segments[next_segment].a;
                }
                polygon[polygon_size++] = points[current - 1];
            }

            // Check if the query point is inside the polygon
            if (is_inside_polygon(queries[i], polygon, polygon_size)) {
                found_polygon = 1;
                break;
            }
        }
        if (found_polygon) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}