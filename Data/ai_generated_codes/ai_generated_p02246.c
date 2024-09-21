#include <stdio.h>
#include <stdlib.h>

// Define the size of the puzzle
#define N 4

// Structure to represent a state of the puzzle
typedef struct {
    int board[N][N];
    int x, y; // Coordinates of the empty space
} State;

// Function to print the current state of the puzzle
void print_state(State state) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", state.board[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the Manhattan distance
int manhattan_distance(State state) {
    int distance = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value = state.board[i][j];
            if (value != 0) {
                int target_row = (value - 1) / N;
                int target_col = (value - 1) % N;
                distance += abs(i - target_row) + abs(j - target_col);
            }
        }
    }
    return distance;
}

// Function to check if a state is the goal state
int is_goal_state(State state) {
    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (state.board[i][j] != count && (i != N - 1 || j != N - 1)) {
                return 0;
            }
            count++;
        }
    }
    return 1;
}

// Function to generate possible next states
int generate_next_states(State current_state, State next_states[4], int *count) {
    // Check for valid moves
    int x = current_state.x;
    int y = current_state.y;
    if (x > 0) { // Move up
        next_states[*count].x = x - 1;
        next_states[*count].y = y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                next_states[*count].board[i][j] = current_state.board[i][j];
            }
        }
        next_states[*count].board[x][y] = current_state.board[x - 1][y];
        next_states[*count].board[x - 1][y] = 0;
        (*count)++;
    }
    if (x < N - 1) { // Move down
        next_states[*count].x = x + 1;
        next_states[*count].y = y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                next_states[*count].board[i][j] = current_state.board[i][j];
            }
        }
        next_states[*count].board[x][y] = current_state.board[x + 1][y];
        next_states[*count].board[x + 1][y] = 0;
        (*count)++;
    }
    if (y > 0) { // Move left
        next_states[*count].x = x;
        next_states[*count].y = y - 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                next_states[*count].board[i][j] = current_state.board[i][j];
            }
        }
        next_states[*count].board[x][y] = current_state.board[x][y - 1];
        next_states[*count].board[x][y - 1] = 0;
        (*count)++;
    }
    if (y < N - 1) { // Move right
        next_states[*count].x = x;
        next_states[*count].y = y + 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                next_states[*count].board[i][j] = current_state.board[i][j];
            }
        }
        next_states[*count].board[x][y] = current_state.board[x][y + 1];
        next_states[*count].board[x][y + 1] = 0;
        (*count)++;
    }
    return *count;
}

// Function to solve the 15 puzzle using A* search
int solve_puzzle(State initial_state) {
    // Priority queue to store states with their costs
    State *queue = (State *)malloc(sizeof(State) * 1000);
    int queue_size = 0;

    // Set the initial state
    queue[0] = initial_state;
    queue_size++;

    // Keep track of visited states
    int visited[N][N][16] = {0};
    visited[initial_state.x][initial_state.y][initial_state.board[initial_state.x][initial_state.y]] = 1;

    // A* search loop
    while (queue_size > 0) {
        // Find the state with the lowest cost in the queue
        int min_cost = manhattan_distance(queue[0]);
        int min_index = 0;
        for (int i = 1; i < queue_size; i++) {
            int cost = manhattan_distance(queue[i]);
            if (cost < min_cost) {
                min_cost = cost;
                min_index = i;
            }
        }
        // Remove the state with the lowest cost from the queue
        State current_state = queue[min_index];
        queue[min_index] = queue[queue_size - 1];
        queue_size--;

        // Check if the current state is the goal state
        if (is_goal_state(current_state)) {
            free(queue);
            return manhattan_distance(current_state); // Return the number of moves
        }

        // Generate possible next states
        State next_states[4];
        int count = 0;
        count = generate_next_states(current_state, next_states, &count);

        // Add the next states to the queue if they haven't been visited
        for (int i = 0; i < count; i++) {
            int x = next_states[i].x;
            int y = next_states[i].y;
            int value = next_states[i].board[x][y];
            if (!visited[x][y][value]) {
                visited[x][y][value] = 1;
                queue[queue_size] = next_states[i];
                queue_size++;
            }
        }
    }

    free(queue);
    return -1; // No solution found
}

int main() {
    State initial_state;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &initial_state.board[i][j]);
            if (initial_state.board[i][j] == 0) {
                initial_state.x = i;
                initial_state.y = j;
            }
        }
    }

    int steps = solve_puzzle(initial_state);
    if (steps == -1) {
        printf("No solution found\n");
    } else {
        printf("%d\n", steps);
    }
    return 0;
}