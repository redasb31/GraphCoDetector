#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define colors
#define BLUE 'B'
#define WHITE 'W'
#define RED 'R'
#define EMPTY 'E'

// Define cube structure
typedef struct {
    char top;
    char front;
    char right;
    char back;
    char left;
    char bottom;
} Cube;

// Define board structure
typedef struct {
    Cube cubes[3][3];
    int empty_x;
    int empty_y;
} Board;

// Function to create a new cube
Cube create_cube(char top) {
    Cube cube;
    cube.top = top;
    cube.front = WHITE;
    cube.right = RED;
    cube.back = WHITE;
    cube.left = RED;
    cube.bottom = top;
    return cube;
}

// Function to create a new board
Board create_board(int empty_x, int empty_y) {
    Board board;
    board.empty_x = empty_x;
    board.empty_y = empty_y;

    // Initialize all cubes with the default orientation
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == empty_x - 1 && j == empty_y - 1) {
                board.cubes[i][j].top = EMPTY;
            } else {
                board.cubes[i][j] = create_cube(BLUE);
            }
        }
    }

    return board;
}

// Function to roll a cube
void roll_cube(Board *board, int x, int y, int direction) {
    Cube *cube = &board->cubes[x][y];

    // Rotate the cube based on the direction
    switch (direction) {
        case 0: // Up
            cube->top = cube->front;
            cube->front = cube->bottom;
            cube->bottom = cube->back;
            cube->back = cube->top;
            break;
        case 1: // Right
            cube->top = cube->right;
            cube->right = cube->bottom;
            cube->bottom = cube->left;
            cube->left = cube->top;
            break;
        case 2: // Down
            cube->top = cube->back;
            cube->back = cube->bottom;
            cube->bottom = cube->front;
            cube->front = cube->top;
            break;
        case 3: // Left
            cube->top = cube->left;
            cube->left = cube->bottom;
            cube->bottom = cube->right;
            cube->right = cube->top;
            break;
    }
}

// Function to check if the board matches the goal state
int check_goal(Board board, char goal[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.cubes[i][j].top != goal[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the puzzle using BFS
int solve_puzzle(Board initial_board, char goal[3][3]) {
    // Initialize queue for BFS
    Board *queue[1000];
    int head = 0, tail = 0;

    // Add initial board to the queue
    queue[tail++] = malloc(sizeof(Board));
    memcpy(queue[tail - 1], &initial_board, sizeof(Board));

    // Keep track of visited states
    int visited[3][3][3][3][3][3][3][3][3][3] = {0};
    visited[initial_board.empty_x - 1][initial_board.empty_y - 1][initial_board.cubes[0][0].top - 'A'][initial_board.cubes[0][1].top - 'A'][initial_board.cubes[0][2].top - 'A'][initial_board.cubes[1][0].top - 'A'][initial_board.cubes[1][1].top - 'A'][initial_board.cubes[1][2].top - 'A'][initial_board.cubes[2][0].top - 'A'][initial_board.cubes[2][1].top - 'A'][initial_board.cubes[2][2].top - 'A'] = 1;

    // Perform BFS
    int steps = 0;
    while (head < tail) {
        Board *current_board = queue[head++];

        // Check if goal state is reached
        if (check_goal(*current_board, goal)) {
            free(current_board);
            return steps;
        }

        // Explore possible moves
        int empty_x = current_board->empty_x;
        int empty_y = current_board->empty_y;

        // Up
        if (empty_x > 1) {
            Board *new_board = malloc(sizeof(Board));
            memcpy(new_board, current_board, sizeof(Board));
            new_board->empty_x = empty_x - 1;
            roll_cube(new_board, empty_x - 2, empty_y - 1, 2);
            if (!visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A']) {
                visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A'] = 1;
                queue[tail++] = new_board;
            } else {
                free(new_board);
            }
        }

        // Right
        if (empty_y < 3) {
            Board *new_board = malloc(sizeof(Board));
            memcpy(new_board, current_board, sizeof(Board));
            new_board->empty_y = empty_y + 1;
            roll_cube(new_board, empty_x - 1, empty_y, 3);
            if (!visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A']) {
                visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A'] = 1;
                queue[tail++] = new_board;
            } else {
                free(new_board);
            }
        }

        // Down
        if (empty_x < 3) {
            Board *new_board = malloc(sizeof(Board));
            memcpy(new_board, current_board, sizeof(Board));
            new_board->empty_x = empty_x + 1;
            roll_cube(new_board, empty_x, empty_y - 1, 0);
            if (!visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A']) {
                visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A'] = 1;
                queue[tail++] = new_board;
            } else {
                free(new_board);
            }
        }

        // Left
        if (empty_y > 1) {
            Board *new_board = malloc(sizeof(Board));
            memcpy(new_board, current_board, sizeof(Board));
            new_board->empty_y = empty_y - 1;
            roll_cube(new_board, empty_x - 1, empty_y - 2, 1);
            if (!visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A']) {
                visited[new_board->empty_x - 1][new_board->empty_y - 1][new_board->cubes[0][0].top - 'A'][new_board->cubes[0][1].top - 'A'][new_board->cubes[0][2].top - 'A'][new_board->cubes[1][0].top - 'A'][new_board->cubes[1][1].top - 'A'][new_board->cubes[1][2].top - 'A'][new_board->cubes[2][0].top - 'A'][new_board->cubes[2][1].top - 'A'][new_board->cubes[2][2].top - 'A'] = 1;
                queue[tail++] = new_board;
            } else {
                free(new_board);
            }
        }

        free(current_board);

        // Increment steps
        steps++;

        // Check if maximum steps reached
        if (steps > 30) {
            while (head < tail) {
                free(queue[head++]);
            }
            return -1;
        }
    }

    // If goal state not reached within 30 steps
    while (head < tail) {
        free(queue[head++]);
    }
    return -1;
}

int main() {
    int empty_x, empty_y;
    char goal[3][3];

    // Read input datasets
    while (1) {
        // Read empty square position
        scanf("%d %d", &empty_x, &empty_y);
        if (empty_x == 0 && empty_y == 0) {
            break;
        }

        // Read goal state
        for (int i = 0; i < 3; i++) {
            scanf("%c %c %c", &goal[i][0], &goal[i][1], &goal[i][2]);
        }

        // Create initial board
        Board initial_board = create_board(empty_x, empty_y);

        // Solve the puzzle
        int steps = solve_puzzle(initial_board, goal);

        // Print result
        printf("%d\n", steps);
    }

    return 0;
}