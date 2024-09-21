#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 100

// Structure to represent a cell on the grid
typedef struct {
    int x;
    int y;
} Cell;

// Function to check if a cell is valid
int is_valid_cell(int n, int m, Cell cell) {
    return cell.x >= 0 && cell.x < n && cell.y >= 0 && cell.y < m;
}

// Function to get the next cell based on the current direction
Cell get_next_cell(Cell current, int direction) {
    Cell next;
    switch (direction) {
        case 0: // South
            next.x = current.x + 1;
            next.y = current.y;
            break;
        case 1: // East
            next.x = current.x;
            next.y = current.y + 1;
            break;
        case 2: // North
            next.x = current.x - 1;
            next.y = current.y;
            break;
        case 3: // West
            next.x = current.x;
            next.y = current.y - 1;
            break;
        default:
            next.x = -1;
            next.y = -1;
            break;
    }
    return next;
}

// Function to check if a cell is an obstacle
int is_obstacle(char grid[][MAX_M], Cell cell) {
    return grid[cell.x][cell.y] == '#';
}

// Function to check if a cell is the target (creature)
int is_target(char grid[][MAX_M], Cell cell) {
    return grid[cell.x][cell.y] == 'G';
}

// Function to check if a cell is the laser generator
int is_laser_generator(char grid[][MAX_M], Cell cell) {
    return grid[cell.x][cell.y] == 'S';
}

// Function to get the next direction after reflection from a P mirror
int get_next_direction_p(int current_direction) {
    switch (current_direction) {
        case 0: // South
            return 1; // East
        case 1: // East
            return 0; // South
        case 2: // North
            return 3; // West
        case 3: // West
            return 2; // North
        default:
            return -1;
    }
}

// Function to get the next direction after reflection from a Q mirror
int get_next_direction_q(int current_direction) {
    switch (current_direction) {
        case 0: // South
            return 3; // West
        case 1: // East
            return 2; // North
        case 2: // North
            return 1; // East
        case 3: // West
            return 0; // South
        default:
            return -1;
    }
}

// Function to perform BFS to find the shortest path
int bfs(char grid[][MAX_M], Cell start, Cell target, int num_p_mirrors, int num_q_mirrors) {
    // Create a queue to store cells to be visited
    Cell queue[MAX_N * MAX_M];
    int front = 0, rear = 0;

    // Create a visited array to keep track of visited cells
    int visited[MAX_N][MAX_M] = {0};

    // Initialize the queue with the starting cell
    queue[rear++] = start;
    visited[start.x][start.y] = 1;

    // Initialize the number of mirrors used
    int num_mirrors = 0;

    // Perform BFS
    while (front < rear) {
        Cell current = queue[front++];

        // Check if the current cell is the target
        if (is_target(grid, current)) {
            return num_mirrors;
        }

        // Iterate over possible directions
        for (int direction = 0; direction < 4; direction++) {
            // Get the next cell in the current direction
            Cell next = get_next_cell(current, direction);

            // Check if the next cell is valid and not an obstacle
            if (is_valid_cell(MAX_N, MAX_M, next) && !is_obstacle(grid, next) && !visited[next.x][next.y]) {
                // Check if the next cell is a P mirror
                if (grid[next.x][next.y] == 'P' && num_p_mirrors > 0) {
                    // Reflect the laser and update the direction
                    direction = get_next_direction_p(direction);
                    num_p_mirrors--;
                    num_mirrors++;
                } else if (grid[next.x][next.y] == 'Q' && num_q_mirrors > 0) {
                    // Reflect the laser and update the direction
                    direction = get_next_direction_q(direction);
                    num_q_mirrors--;
                    num_mirrors++;
                }

                // Get the next cell after reflection
                next = get_next_cell(current, direction);

                // Check if the next cell is valid and not an obstacle
                if (is_valid_cell(MAX_N, MAX_M, next) && !is_obstacle(grid, next)) {
                    // Add the next cell to the queue
                    queue[rear++] = next;
                    visited[next.x][next.y] = 1;
                }
            }
        }
    }

    // If the target is not reached, return -1
    return -1;
}

int main() {
    int n, m, a;
    char grid[MAX_N][MAX_M];
    Cell laser_generator, creature;

    // Read the input
    scanf("%d %d %d", &n, &m, &a);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                laser_generator.x = i;
                laser_generator.y = j;
            } else if (grid[i][j] == 'G') {
                creature.x = i;
                creature.y = j;
            }
        }
    }

    // Perform BFS to find the shortest path
    int min_mirrors = bfs(grid, laser_generator, creature, a, a);

    // Print the result
    printf("%d\n", min_mirrors);

    return 0;
}