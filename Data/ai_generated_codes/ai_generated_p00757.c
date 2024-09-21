#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32

// Structure to represent a rectangular area
typedef struct {
    int x1, y1; // Top-left corner coordinates
    int x2, y2; // Bottom-right corner coordinates
} Area;

// Function to calculate the total demand of an area
int calculate_demand(int demand_table[][MAX_SIZE], Area area) {
    int demand = 0;
    for (int i = area.y1; i < area.y2; i++) {
        for (int j = area.x1; j < area.x2; j++) {
            demand += demand_table[i][j];
        }
    }
    return demand;
}

// Function to split an area vertically
void split_vertical(Area area, Area *area1, Area *area2) {
    // Calculate the middle column
    int middle_column = (area.x1 + area.x2) / 2;

    // Assign coordinates to the sub-areas
    area1->x1 = area.x1;
    area1->y1 = area.y1;
    area1->x2 = middle_column;
    area1->y2 = area.y2;

    area2->x1 = middle_column;
    area2->y1 = area.y1;
    area2->x2 = area.x2;
    area2->y2 = area.y2;
}

// Function to split an area horizontally
void split_horizontal(Area area, Area *area1, Area *area2) {
    // Calculate the middle row
    int middle_row = (area.y1 + area.y2) / 2;

    // Assign coordinates to the sub-areas
    area1->x1 = area.x1;
    area1->y1 = area.y1;
    area1->x2 = area.x2;
    area1->y2 = middle_row;

    area2->x1 = area.x1;
    area2->y1 = middle_row;
    area2->x2 = area.x2;
    area2->y2 = area.y2;
}

// Function to find the best grouping using recursion
void find_best_grouping(int demand_table[][MAX_SIZE], int h, int w, int supply_capacity, int current_level, 
                        Area area, int *max_groups, int *max_reserve, int *current_groups, int *current_reserve) {

    // Calculate the demand of the current area
    int area_demand = calculate_demand(demand_table, area);

    // Base case: If the area demand is less than or equal to the supply capacity, we can create a new group
    if (area_demand <= supply_capacity) {
        *current_groups += 1;
        *current_reserve = supply_capacity - area_demand;

        // Update the maximum groups and reserve if necessary
        if (*current_groups > *max_groups || (*current_groups == *max_groups && *current_reserve > *max_reserve)) {
            *max_groups = *current_groups;
            *max_reserve = *current_reserve;
        }
        return;
    }

    // Recursive case: Split the area and explore both splits
    Area area1, area2;

    // Split vertically
    split_vertical(area, &area1, &area2);
    find_best_grouping(demand_table, h, w, supply_capacity, current_level + 1, area1, max_groups, max_reserve, current_groups, current_reserve);
    find_best_grouping(demand_table, h, w, supply_capacity, current_level + 1, area2, max_groups, max_reserve, current_groups, current_reserve);

    // Split horizontally
    split_horizontal(area, &area1, &area2);
    find_best_grouping(demand_table, h, w, supply_capacity, current_level + 1, area1, max_groups, max_reserve, current_groups, current_reserve);
    find_best_grouping(demand_table, h, w, supply_capacity, current_level + 1, area2, max_groups, max_reserve, current_groups, current_reserve);
}

int main() {
    int h, w, supply_capacity;
    int demand_table[MAX_SIZE][MAX_SIZE];

    while (1) {
        // Read the input
        scanf("%d %d %d", &h, &w, &supply_capacity);
        if (h == 0 && w == 0 && supply_capacity == 0) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &demand_table[i][j]);
            }
        }

        // Initialize the variables for the best grouping
        int max_groups = 0;
        int max_reserve = 0;
        int current_groups = 0;
        int current_reserve = 0;

        // Create an area representing the entire service area
        Area area;
        area.x1 = 0;
        area.y1 = 0;
        area.x2 = w;
        area.y2 = h;

        // Find the best grouping
        find_best_grouping(demand_table, h, w, supply_capacity, 0, area, &max_groups, &max_reserve, &current_groups, &current_reserve);

        // Print the results
        printf("%d %d\n", max_groups, max_reserve);
    }

    return 0;
}