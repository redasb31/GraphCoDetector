#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_H 50
#define MAX_W 50
#define MAX_K 12

// Structure to represent a cell in the accommodation facility
typedef struct {
    int row;
    int col;
    char unit;
} Cell;

// Structure to represent a room
typedef struct {
    Cell* cells;
    int size;
} Room;

// Structure to represent a unit
typedef struct {
    Room* rooms;
    int num_rooms;
} Unit;

// Structure to represent a staff
typedef struct {
    int unit_assignments;
    Unit* assigned_units;
} Staff;

// Function to create a new room
Room* createRoom(Cell* cells, int size) {
    Room* room = (Room*)malloc(sizeof(Room));
    room->cells = cells;
    room->size = size;
    return room;
}

// Function to create a new unit
Unit* createUnit(char unit) {
    Unit* unit_ptr = (Unit*)malloc(sizeof(Unit));
    unit_ptr->rooms = NULL;
    unit_ptr->num_rooms = 0;
    return unit_ptr;
}

// Function to add a room to a unit
void addRoomToUnit(Unit* unit, Room* room) {
    unit->num_rooms++;
    unit->rooms = (Room**)realloc(unit->rooms, unit->num_rooms * sizeof(Room*));
    unit->rooms[unit->num_rooms - 1] = room;
}

// Function to find the connected floor cells in a unit
void findConnectedCells(char** grid, int H, int W, int i, int j, Unit* unit, char current_unit) {
    if (i < 0 || i >= H || j < 0 || j >= W || grid[i][j] == '.' || grid[i][j] != current_unit) {
        return;
    }

    grid[i][j] = '.'; // Mark the current cell as visited
    Cell* cell = (Cell*)malloc(sizeof(Cell));
    cell->row = i;
    cell->col = j;
    cell->unit = current_unit;

    // Create a new room if the cell is adjacent to only one floor cell
    if (i == 0 || i == H - 1 || j == 0 || j == W - 1 ||
        grid[i + 1][j] == '.' || grid[i - 1][j] == '.' || grid[i][j + 1] == '.' || grid[i][j - 1] == '.') {
        Room* room = createRoom(cell, 1); // Create a new room with the current cell
        addRoomToUnit(unit, room); // Add the room to the unit
    } else {
        // Add the cell to the existing room
        Room* room = unit->rooms[unit->num_rooms - 1];
        room->size++;
        room->cells = (Cell**)realloc(room->cells, room->size * sizeof(Cell*));
        room->cells[room->size - 1] = cell;
    }

    // Recursively find connected cells
    findConnectedCells(grid, H, W, i + 1, j, unit, current_unit);
    findConnectedCells(grid, H, W, i - 1, j, unit, current_unit);
    findConnectedCells(grid, H, W, i, j + 1, unit, current_unit);
    findConnectedCells(grid, H, W, i, j - 1, unit, current_unit);
}

// Function to find the units in the accommodation facility
Unit** findUnits(char** grid, int H, int W) {
    Unit** units = NULL;
    int num_units = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] != '.') { // Check for floor cells
                char current_unit = grid[i][j];
                Unit* unit = createUnit(current_unit);
                findConnectedCells(grid, H, W, i, j, unit, current_unit);
                num_units++;
                units = (Unit**)realloc(units, num_units * sizeof(Unit*));
                units[num_units - 1] = unit;
            }
        }
    }

    return units;
}

// Function to calculate the minimum time required to check all rooms
int calculateMinimumTime(Unit** units, int num_units, Staff** staffs, int num_staffs, int s, int t, int T_move, int T_check) {
    int total_time = 0;

    // Assign units to staffs
    for (int i = 0; i < num_units; i++) {
        int staff_index = i % num_staffs;
        staffs[staff_index]->unit_assignments++;
        staffs[staff_index]->assigned_units = (Unit**)realloc(staffs[staff_index]->assigned_units, staffs[staff_index]->unit_assignments * sizeof(Unit*));
        staffs[staff_index]->assigned_units[staffs[staff_index]->unit_assignments - 1] = units[i];
    }

    // Calculate the time taken by each staff to check the rooms
    for (int i = 0; i < num_staffs; i++) {
        int current_time = 0;
        int total_rooms = 0;
        for (int j = 0; j < staffs[i]->unit_assignments; j++) {
            total_rooms += staffs[i]->assigned_units[j]->num_rooms;
        }

        // Calculate the time to reach the first room in the first unit
        current_time += T_move * abs(s - staffs[i]->assigned_units[0]->rooms[0]->cells[0]->row) + T_move * abs(t - staffs[i]->assigned_units[0]->rooms[0]->cells[0]->col);

        // Calculate the time to check the rooms in the assigned units
        for (int j = 0; j < staffs[i]->unit_assignments; j++) {
            for (int k = 0; k < staffs[i]->assigned_units[j]->num_rooms; k++) {
                current_time += T_check; // Time to check the room
                if (k < staffs[i]->assigned_units[j]->num_rooms - 1) {
                    // Time to move to the next room in the same unit
                    current_time += T_move * abs(staffs[i]->assigned_units[j]->rooms[k]->cells[0]->row - staffs[i]->assigned_units[j]->rooms[k + 1]->cells[0]->row) +
                                   T_move * abs(staffs[i]->assigned_units[j]->rooms[k]->cells[0]->col - staffs[i]->assigned_units[j]->rooms[k + 1]->cells[0]->col);
                }
            }

            // Time to move to the first room in the next unit
            if (j < staffs[i]->unit_assignments - 1) {
                current_time += T_move * abs(staffs[i]->assigned_units[j]->rooms[staffs[i]->assigned_units[j]->num_rooms - 1]->cells[0]->row -
                                              staffs[i]->assigned_units[j + 1]->rooms[0]->cells[0]->row) +
                               T_move * abs(staffs[i]->assigned_units[j]->rooms[staffs[i]->assigned_units[j]->num_rooms - 1]->cells[0]->col -
                                              staffs[i]->assigned_units[j + 1]->rooms[0]->cells[0]->col);
            }
        }

        // Time to return to the starting cell (s, t)
        current_time += T_move * abs(staffs[i]->assigned_units[staffs[i]->unit_assignments - 1]->rooms[staffs[i]->assigned_units[staffs[i]->unit_assignments - 1]->num_rooms - 1]->cells[0]->row - s) +
                       T_move * abs(staffs[i]->assigned_units[staffs[i]->unit_assignments - 1]->rooms[staffs[i]->assigned_units[staffs[i]->unit_assignments - 1]->num_rooms - 1]->cells[0]->col - t);

        // Update the total time
        total_time = (total_time > current_time) ? total_time : current_time; // Take the maximum time among all staffs
    }

    return total_time;
}

int main() {
    int H, W, K, s, t, T_move, T_check;
    char** grid;

    // Input the dimensions of the accommodation facility and the number of staffs
    scanf("%d %d %d", &H, &W, &K);

    // Input the starting position, movement time, and check time
    scanf("%d %d %d %d", &s, &t, &T_move, &T_check);

    // Allocate memory for the grid
    grid = (char**)malloc(H * sizeof(char*));
    for (int i = 0; i < H; i++) {
        grid[i] = (char*)malloc((W + 1) * sizeof(char));
    }

    // Input the grid representing the accommodation facility
    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
    }

    // Find the units in the accommodation facility
    Unit** units = findUnits(grid, H, W);

    // Create staffs
    Staff** staffs = (Staff**)malloc(K * sizeof(Staff*));
    for (int i = 0; i < K; i++) {
        staffs[i] = (Staff*)malloc(sizeof(Staff));
        staffs[i]->unit_assignments = 0;
        staffs[i]->assigned_units = NULL;
    }

    // Calculate the minimum time required to check all rooms
    int minimum_time = calculateMinimumTime(units, H * W, staffs, K, s - 1, t - 1, T_move, T_check);

    // Print the minimum time
    printf("%d\n", minimum_time);

    // Free allocated memory
    for (int i = 0; i < H; i++) {
        free(grid[i]);
    }
    free(grid);
    for (int i = 0; i < K; i++) {
        free(staffs[i]);
    }
    free(staffs);
    for (int i = 0; i < H * W; i++) {
        free(units[i]);
    }
    free(units);

    return 0;
}