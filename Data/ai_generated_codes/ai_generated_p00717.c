#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Structure to represent a polygonal line
typedef struct {
    int num_vertices;
    Point* vertices;
} PolyLine;

// Function to calculate the distance between two points
int distance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Function to compare two polygonal lines for shape similarity
int comparePolyLines(PolyLine line1, PolyLine line2) {
    // Check if the number of vertices is the same
    if (line1.num_vertices != line2.num_vertices) {
        return 0;
    }

    // Calculate the distances between consecutive vertices for both lines
    int* distances1 = (int*)malloc(sizeof(int) * line1.num_vertices);
    int* distances2 = (int*)malloc(sizeof(int) * line2.num_vertices);
    for (int i = 0; i < line1.num_vertices - 1; i++) {
        distances1[i] = distance(line1.vertices[i], line1.vertices[i + 1]);
        distances2[i] = distance(line2.vertices[i], line2.vertices[i + 1]);
    }

    // Compare the distance arrays for both lines
    int match = 1;
    for (int i = 0; i < line1.num_vertices - 1; i++) {
        if (distances1[i] != distances2[i]) {
            match = 0;
            break;
        }
    }

    // Free the dynamically allocated memory
    free(distances1);
    free(distances2);

    return match;
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF && n != 0) {
        // Read the template polygonal line
        PolyLine template;
        scanf("%d", &template.num_vertices);
        template.vertices = (Point*)malloc(sizeof(Point) * template.num_vertices);
        for (int i = 0; i < template.num_vertices; i++) {
            scanf("%d %d", &template.vertices[i].x, &template.vertices[i].y);
        }

        // Read the remaining polygonal lines and compare them to the template
        for (int i = 1; i <= n; i++) {
            PolyLine line;
            scanf("%d", &line.num_vertices);
            line.vertices = (Point*)malloc(sizeof(Point) * line.num_vertices);
            for (int j = 0; j < line.num_vertices; j++) {
                scanf("%d %d", &line.vertices[j].x, &line.vertices[j].y);
            }

            // Check if the line has the same shape as the template
            if (comparePolyLines(template, line)) {
                printf("%d\n", i);
            }

            // Free the dynamically allocated memory for the line
            free(line.vertices);
        }

        // Free the dynamically allocated memory for the template
        free(template.vertices);

        // Print the separator
        printf("+++++\n");
    }

    return 0;
}