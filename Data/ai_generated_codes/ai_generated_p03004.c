#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    char d;
} Point;

int compare_x(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    return pa->x - pb->x;
}

int compare_y(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    return pa->y - pb->y;
}

int main() {
    int N;
    scanf("%d", &N);

    Point *points = (Point *)malloc(sizeof(Point) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %c", &points[i].x, &points[i].y, &points[i].d);
    }

    // Sort points by x-coordinate
    qsort(points, N, sizeof(Point), compare_x);

    // Calculate the initial x-range
    int x_min = points[0].x;
    int x_max = points[N - 1].x;

    // Sort points by y-coordinate
    qsort(points, N, sizeof(Point), compare_y);

    // Calculate the initial y-range
    int y_min = points[0].y;
    int y_max = points[N - 1].y;

    // Calculate the initial area
    double min_area = (double)(x_max - x_min) * (y_max - y_min);

    // Iterate through each point and update the area based on its movement
    for (int i = 0; i < N; i++) {
        // If the point moves horizontally, update x_min and x_max
        if (points[i].d == 'R' || points[i].d == 'L') {
            if (points[i].d == 'R') {
                x_max = points[i].x + abs(x_max - x_min);
            } else {
                x_min = points[i].x - abs(x_max - x_min);
            }
        } else {
            // If the point moves vertically, update y_min and y_max
            if (points[i].d == 'U') {
                y_max = points[i].y + abs(y_max - y_min);
            } else {
                y_min = points[i].y - abs(y_max - y_min);
            }
        }

        // Calculate the new area and update min_area
        double area = (double)(x_max - x_min) * (y_max - y_min);
        min_area = (area < min_area) ? area : min_area;
    }

    printf("%.10f\n", min_area);
    free(points);
    return 0;
}