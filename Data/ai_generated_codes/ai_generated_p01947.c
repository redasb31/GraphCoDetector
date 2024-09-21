#include <stdio.h>
#include <stdlib.h>

// Structure to represent an intersection
typedef struct {
    int id; // Intersection ID
    int row; // Row coordinate
    int col; // Column coordinate
} Intersection;

// Function to find the intersection with the given ID
Intersection* findIntersection(Intersection *intersections, int id, int N) {
    for (int i = 0; i < N * N; i++) {
        if (intersections[i].id == id) {
            return &intersections[i];
        }
    }
    return NULL; // Intersection not found
}

// Function to check if two intersections are adjacent
int isAdjacent(Intersection *a, Intersection *b) {
    return (abs(a->row - b->row) + abs(a->col - b->col)) == 1;
}

// Function to solve the Ninja Map problem
void solveNinjaMap(int N) {
    // Allocate memory for intersections
    Intersection *intersections = malloc(N * N * sizeof(Intersection));
    if (intersections == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize intersections with IDs
    for (int i = 0; i < N * N; i++) {
        intersections[i].id = i + 1;
        intersections[i].row = -1;
        intersections[i].col = -1;
    }

    // Read connections between intersections
    int a, b;
    for (int i = 0; i < 2 * N * N - 2 * N; i++) {
        scanf("%d %d", &a, &b);

        // Find the intersections with the given IDs
        Intersection *intersectionA = findIntersection(intersections, a, N);
        Intersection *intersectionB = findIntersection(intersections, b, N);

        // If either intersection is not found, it's an error
        if (intersectionA == NULL || intersectionB == NULL) {
            printf("Invalid input: Intersection not found.\n");
            exit(1);
        }

        // If both intersections are already placed, check if they are adjacent
        if (intersectionA->row != -1 && intersectionB->row != -1) {
            if (!isAdjacent(intersectionA, intersectionB)) {
                printf("Invalid input: Intersections are not adjacent.\n");
                exit(1);
            }
        } else if (intersectionA->row == -1 && intersectionB->row == -1) {
            // If both are not placed, place them arbitrarily
            intersectionA->row = 0;
            intersectionA->col = 0;
            intersectionB->row = 0;
            intersectionB->col = 1;
        } else if (intersectionA->row == -1) {
            // Place intersection A relative to intersection B
            if (intersectionB->row == 0) {
                intersectionA->row = 0;
                intersectionA->col = intersectionB->col - 1;
            } else if (intersectionB->row == N - 1) {
                intersectionA->row = N - 1;
                intersectionA->col = intersectionB->col + 1;
            } else if (intersectionB->col == 0) {
                intersectionA->row = intersectionB->row - 1;
                intersectionA->col = 0;
            } else if (intersectionB->col == N - 1) {
                intersectionA->row = intersectionB->row + 1;
                intersectionA->col = N - 1;
            }
        } else {
            // Place intersection B relative to intersection A
            if (intersectionA->row == 0) {
                intersectionB->row = 0;
                intersectionB->col = intersectionA->col + 1;
            } else if (intersectionA->row == N - 1) {
                intersectionB->row = N - 1;
                intersectionB->col = intersectionA->col - 1;
            } else if (intersectionA->col == 0) {
                intersectionB->row = intersectionA->row + 1;
                intersectionB->col = 0;
            } else if (intersectionA->col == N - 1) {
                intersectionB->row = intersectionA->row - 1;
                intersectionB->col = N - 1;
            }
        }
    }

    // Print the solved map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Find the intersection with the correct row and column
            for (int k = 0; k < N * N; k++) {
                if (intersections[k].row == i && intersections[k].col == j) {
                    printf("%d ", intersections[k].id);
                    break;
                }
            }
        }
        printf("\n");
    }

    free(intersections);
}

int main() {
    int N;

    scanf("%d", &N);
    solveNinjaMap(N);

    return 0;
}