#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABELS 51
#define MAX_ELEMENTS 301

// Structure to represent a point in 3D space
typedef struct {
    int x;
    int y;
    int z;
} Point;

// Structure to represent a gold bar
typedef struct {
    Point start;
    Point end;
} Bar;

// Function to create a new gold bar
Bar *create_bar(Point start, Point end) {
    Bar *bar = (Bar *)malloc(sizeof(Bar));
    bar->start = start;
    bar->end = end;
    return bar;
}

// Function to check if two points are equal
int points_equal(Point p1, Point p2) {
    return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}

// Function to parse a key description and build the key
Bar **parse_key(char *description, int *num_bars) {
    // Initialize variables
    int num_elements = 0;
    int label = 0;
    Point current_point = {0, 0, 0};
    Point next_point;
    Bar **bars = NULL;

    // Parse the description line by line
    char *line = strtok(description, "\n ");
    while (line != NULL) {
        // Read the number of elements
        if (num_elements == 0) {
            num_elements = atoi(line);
        } else {
            // Read the next element
            if (isdigit(line[0])) {
                // Label
                label = atoi(line);
                current_point = {0, 0, 0};
            } else {
                // Direction
                next_point = current_point;
                switch (line[0]) {
                    case '+':
                        if (line[1] == 'x') next_point.x++;
                        else if (line[1] == 'y') next_point.y++;
                        else if (line[1] == 'z') next_point.z++;
                        break;
                    case '-':
                        if (line[1] == 'x') next_point.x--;
                        else if (line[1] == 'y') next_point.y--;
                        else if (line[1] == 'z') next_point.z--;
                        break;
                }
                // Create a new gold bar
                Bar *new_bar = create_bar(current_point, next_point);
                // Allocate memory for the bars array if necessary
                if (*num_bars == 0) {
                    bars = (Bar **)malloc(sizeof(Bar *));
                    *num_bars = 1;
                } else {
                    bars = (Bar **)realloc(bars, (*num_bars + 1) * sizeof(Bar *));
                    (*num_bars)++;
                }
                // Add the new bar to the array
                bars[*num_bars - 1] = new_bar;
                // Update the current point
                current_point = next_point;
            }
        }
        line = strtok(NULL, "\n ");
    }

    return bars;
}

// Function to check if two keys are the same
int keys_same(Bar **bars1, int num_bars1, Bar **bars2, int num_bars2) {
    // Check if the number of bars is different
    if (num_bars1 != num_bars2) return 0;

    // Check if each bar in the first key is present in the second key
    for (int i = 0; i < num_bars1; i++) {
        int found = 0;
        for (int j = 0; j < num_bars2; j++) {
            if (points_equal(bars1[i]->start, bars2[j]->start) &&
                points_equal(bars1[i]->end, bars2[j]->end)) {
                found = 1;
                break;
            }
        }
        if (!found) return 0;
    }

    return 1;
}

int main() {
    char description1[MAX_ELEMENTS * 80];
    char description2[MAX_ELEMENTS * 80];
    int num_bars1 = 0;
    int num_bars2 = 0;
    Bar **bars1 = NULL;
    Bar **bars2 = NULL;

    // Read the input descriptions
    while (fgets(description1, sizeof(description1), stdin) != NULL) {
        fgets(description2, sizeof(description2), stdin);

        // Parse the descriptions and build the keys
        bars1 = parse_key(description1, &num_bars1);
        bars2 = parse_key(description2, &num_bars2);

        // Check if the keys are the same
        if (keys_same(bars1, num_bars1, bars2, num_bars2)) {
            printf("SAME\n");
        } else {
            printf("DIFFERENT\n");
        }

        // Free the allocated memory
        for (int i = 0; i < num_bars1; i++) {
            free(bars1[i]);
        }
        free(bars1);
        for (int i = 0; i < num_bars2; i++) {
            free(bars2[i]);
        }
        free(bars2);

        // Check for the end of input
        if (fgets(description1, sizeof(description1), stdin) == NULL) break;
    }

    return 0;
}