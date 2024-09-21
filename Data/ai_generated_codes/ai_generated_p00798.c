#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

// Structure to represent a position in the warehouse
typedef struct {
    int x;
    int y;
} Position;

// Structure to represent the warehouse state
typedef struct {
    int width;
    int height;
    int grid[MAX_SIZE][MAX_SIZE];
    Position cargo;
    Position goal;
    Position warehouseman;
} Warehouse;

// Function to print the warehouse grid for debugging
void print_warehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->height; i++) {
        for (int j = 0; j < warehouse->width; j++) {
            printf("%d ", warehouse->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a position is valid within the warehouse bounds
int is_valid_position(Warehouse *warehouse, Position position) {
    return position.x >= 0 && position.x < warehouse->width && position.y >= 0 && position.y < warehouse->height;
}

// Function to check if a position is empty (no obstacle or cargo)
int is_empty(Warehouse *warehouse, Position position) {
    return is_valid_position(warehouse, position) && warehouse->grid[position.y][position.x] == 0;
}

// Function to check if a move is possible in a given direction
int is_move_possible(Warehouse *warehouse, int direction) {
    Position new_position;
    switch (direction) {
        case 0: // North
            new_position = (Position){warehouse->warehouseman.x, warehouse->warehouseman.y - 1};
            break;
        case 1: // East
            new_position = (Position){warehouse->warehouseman.x + 1, warehouse->warehouseman.y};
            break;
        case 2: // South
            new_position = (Position){warehouse->warehouseman.x, warehouse->warehouseman.y + 1};
            break;
        case 3: // West
            new_position = (Position){warehouse->warehouseman.x - 1, warehouse->warehouseman.y};
            break;
        default:
            return 0;
    }
    return is_empty(warehouse, new_position);
}

// Function to move the warehouseman to a new position
void move_warehouseman(Warehouse *warehouse, int direction) {
    Position new_position;
    switch (direction) {
        case 0: // North
            new_position = (Position){warehouse->warehouseman.x, warehouse->warehouseman.y - 1};
            break;
        case 1: // East
            new_position = (Position){warehouse->warehouseman.x + 1, warehouse->warehouseman.y};
            break;
        case 2: // South
            new_position = (Position){warehouse->warehouseman.x, warehouse->warehouseman.y + 1};
            break;
        case 3: // West
            new_position = (Position){warehouse->warehouseman.x - 1, warehouse->warehouseman.y};
            break;
        default:
            return;
    }
    warehouse->grid[warehouse->warehouseman.y][warehouse->warehouseman.x] = 0;
    warehouse->grid[new_position.y][new_position.x] = 4;
    warehouse->warehouseman = new_position;
}

// Function to push the cargo in a given direction
int push_cargo(Warehouse *warehouse, int direction) {
    Position new_position;
    switch (direction) {
        case 0: // North
            new_position = (Position){warehouse->cargo.x, warehouse->cargo.y - 1};
            break;
        case 1: // East
            new_position = (Position){warehouse->cargo.x + 1, warehouse->cargo.y};
            break;
        case 2: // South
            new_position = (Position){warehouse->cargo.x, warehouse->cargo.y + 1};
            break;
        case 3: // West
            new_position = (Position){warehouse->cargo.x - 1, warehouse->cargo.y};
            break;
        default:
            return 0;
    }

    // Check if the push is valid
    if (!is_valid_position(warehouse, new_position) || warehouse->grid[new_position.y][new_position.x] != 0) {
        return 0;
    }

    // Push the cargo
    warehouse->grid[warehouse->cargo.y][warehouse->cargo.x] = 0;
    warehouse->grid[new_position.y][new_position.x] = 2;
    warehouse->cargo = new_position;

    return 1;
}

// Function to recursively explore possible moves and push actions
int solve_warehouse(Warehouse *warehouse, int pushes) {
    // Check if the cargo is at the goal
    if (warehouse->cargo.x == warehouse->goal.x && warehouse->cargo.y == warehouse->goal.y) {
        return pushes;
    }

    // Try pushing the cargo in all directions
    for (int direction = 0; direction < 4; direction++) {
        if (is_move_possible(warehouse, direction) && push_cargo(warehouse, direction)) {
            int result = solve_warehouse(warehouse, pushes + 1);
            // Undo the push for backtracking
            push_cargo(warehouse, direction);
            if (result != -1) {
                return result;
            }
        }
    }

    // Try moving the warehouseman in all directions
    for (int direction = 0; direction < 4; direction++) {
        if (is_move_possible(warehouse, direction)) {
            move_warehouseman(warehouse, direction);
            int result = solve_warehouse(warehouse, pushes);
            // Undo the move for backtracking
            move_warehouseman(warehouse, (direction + 2) % 4); // Move back in opposite direction
            if (result != -1) {
                return result;
            }
        }
    }

    // No possible moves found
    return -1;
}

int main() {
    Warehouse warehouse;
    int w, h;

    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) {
            break;
        }
        warehouse.width = w;
        warehouse.height = h;

        // Initialize the warehouse grid
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &warehouse.grid[i][j]);
                if (warehouse.grid[i][j] == 2) {
                    warehouse.cargo = (Position){j, i};
                } else if (warehouse.grid[i][j] == 3) {
                    warehouse.goal = (Position){j, i};
                } else if (warehouse.grid[i][j] == 4) {
                    warehouse.warehouseman = (Position){j, i};
                }
            }
        }

        // Solve the warehouse problem
        int pushes = solve_warehouse(&warehouse, 0);

        // Print the result
        printf("%d\n", pushes);
    }
    return 0;
}