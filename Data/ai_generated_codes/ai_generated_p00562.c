#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_H 500
#define MAX_W 500

// Structure to represent a player
typedef struct {
    int x, y;
    int has_ball;
    int fatigue;
} Player;

// Structure to represent the state of the game
typedef struct {
    Player players[MAX_N];
    int ball_x, ball_y;
    int n;
    int h, w;
    int a, b, c;
} State;

// Function to initialize the game state
void init_state(State *state, int h, int w, int a, int b, int c, int n) {
    state->h = h;
    state->w = w;
    state->a = a;
    state->b = b;
    state->c = c;
    state->n = n;

    // Initialize players
    for (int i = 0; i < n; i++) {
        state->players[i].has_ball = 0;
        state->players[i].fatigue = 0;
    }

    // Player 1 starts with the ball
    state->players[0].has_ball = 1;
}

// Function to calculate the fatigue cost of kicking the ball
int kick_cost(int distance, int a, int b) {
    return a * distance + b;
}

// Function to calculate the distance between two points
int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Function to check if a point is within the field
int in_field(int x, int y, int h, int w) {
    return (x >= 0 && x <= h && y >= 0 && y <= w);
}

// Function to calculate the minimum fatigue cost for the clearance process
int min_fatigue(State *state) {
    // Create a queue to store the states to be explored
    State *queue[MAX_N * MAX_H * MAX_W];
    int head = 0, tail = 0;

    // Add the initial state to the queue
    queue[tail++] = state;

    // Create a visited array to keep track of visited states
    int visited[MAX_H][MAX_W][MAX_N] = {0};
    visited[state->ball_x][state->ball_y][0] = 1;

    // While the queue is not empty
    while (head < tail) {
        // Get the current state from the queue
        State *current = queue[head++];

        // If the ball is at the manager's position, we have reached the goal
        if (current->ball_x == current->players[current->n - 1].x &&
            current->ball_y == current->players[current->n - 1].y) {
            return current->players[current->n - 1].fatigue;
        }

        // Explore all possible actions for each player
        for (int i = 0; i < current->n; i++) {
            // If the player has the ball
            if (current->players[i].has_ball) {
                // Kick the ball in all four directions
                for (int dx = -1; dx <= 1; dx += 2) {
                    for (int dy = -1; dy <= 1; dy += 2) {
                        for (int p = 1; p <= current->w; p++) {
                            // Calculate the new ball position
                            int new_ball_x = current->ball_x + dx * p;
                            int new_ball_y = current->ball_y + dy * p;

                            // Check if the new ball position is within the field
                            if (in_field(new_ball_x, new_ball_y, current->h, current->w)) {
                                // Create a new state with the ball moved
                                State *new_state = (State *)malloc(sizeof(State));
                                *new_state = *current;
                                new_state->ball_x = new_ball_x;
                                new_state->ball_y = new_ball_y;
                                new_state->players[i].has_ball = 0;
                                new_state->players[i].fatigue += kick_cost(p, current->a, current->b);

                                // Check if this state has been visited before
                                if (!visited[new_state->ball_x][new_state->ball_y][i]) {
                                    // Add the new state to the queue
                                    queue[tail++] = new_state;
                                    visited[new_state->ball_x][new_state->ball_y][i] = 1;
                                }
                            }
                        }
                    }
                }

                // Place the ball
                State *new_state = (State *)malloc(sizeof(State));
                *new_state = *current;
                new_state->players[i].has_ball = 0;

                // Check if this state has been visited before
                if (!visited[new_state->ball_x][new_state->ball_y][i]) {
                    // Add the new state to the queue
                    queue[tail++] = new_state;
                    visited[new_state->ball_x][new_state->ball_y][i] = 1;
                }
            } else {
                // Move the player in all four directions
                for (int dx = -1; dx <= 1; dx += 2) {
                    for (int dy = -1; dy <= 1; dy += 2) {
                        // Calculate the new player position
                        int new_x = current->players[i].x + dx;
                        int new_y = current->players[i].y + dy;

                        // Check if the new player position is within the field
                        if (in_field(new_x, new_y, current->h, current->w)) {
                            // Create a new state with the player moved
                            State *new_state = (State *)malloc(sizeof(State));
                            *new_state = *current;
                            new_state->players[i].x = new_x;
                            new_state->players[i].y = new_y;
                            new_state->players[i].fatigue += current->c;

                            // If the player is moving to the ball position
                            if (new_x == current->ball_x && new_y == current->ball_y && !current->players[i].has_ball) {
                                new_state->players[i].has_ball = 1;
                            }

                            // Check if this state has been visited before
                            if (!visited[current->ball_x][current->ball_y][i]) {
                                // Add the new state to the queue
                                queue[tail++] = new_state;
                                visited[current->ball_x][current->ball_y][i] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return -1; // No solution found
}

int main() {
    int h, w, a, b, c, n;
    scanf("%d %d", &h, &w);
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &n);

    State state;
    init_state(&state, h, w, a, b, c, n);

    // Read player positions
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &state.players[i].x, &state.players[i].y);
        state.ball_x = state.players[0].x;
        state.ball_y = state.players[0].y;
    }

    // Calculate the minimum fatigue cost
    int min_fatigue_cost = min_fatigue(&state);

    // Print the result
    printf("%d\n", min_fatigue_cost);

    return 0;
}