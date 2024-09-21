#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100000
#define MAX_D 1000

typedef struct {
    int x;
    int y;
} Point;

int N, D;
Point points[MAX_N];

// Calculate the Manhattan distance between two points
int manhattan_distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Calculate the maximum Manhattan distance between any two points
int max_distance() {
    int max_dist = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            max_dist =  max(max_dist, manhattan_distance(points[i], points[j]));
        }
    }
    return max_dist;
}

// Find the minimum scatteredness
int find_minimum_scatteredness() {
    // The minimum scatteredness is at least the maximum distance between any two points
    int min_scatteredness = max_distance();

    // Check if the scatteredness can be reduced by rotating squares
    for (int side_length = 1; side_length <= min_scatteredness; side_length++) {
        if (side_length % D == 0) {
            // Check if there exists a square with side length 'side_length' that can enclose all points
            int found_square = 1;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    int dist = manhattan_distance(points[i], points[j]);
                    // If the distance between two points exceeds the diagonal of the square, the square cannot enclose all points
                    if (dist > side_length * sqrt(2)) {
                        found_square = 0;
                        break;
                    }
                }
                if (!found_square) {
                    break;
                }
            }
            if (found_square) {
                min_scatteredness = side_length;
                break;
            }
        }
    }
    return min_scatteredness;
}

int main() {
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    printf("%d\n", find_minimum_scatteredness());
    return 0;
}