#include <stdio.h>
#include <stdlib.h>

// Structure to represent a balancer
typedef struct Balancer {
    int x;
    int y;
    char state; // 'v' for down, '^' for up
} Balancer;

// Function to check if a state is uniforming
int isUniforming(Balancer *balancers, int n, int m) {
    // Iterate through all wires
    for (int i = 1; i <= n; i++) {
        // Simulate the token movement for each wire
        int currentWire = i;
        for (int j = 0; j < m; j++) {
            if (balancers[j].x == currentWire && balancers[j].state == 'v') {
                currentWire = balancers[j].y;
            } else if (balancers[j].y == currentWire && balancers[j].state == '^') {
                currentWire = balancers[j].x;
            }
        }
        // If the token doesn't end up on the same wire for all starting wires,
        // the state is not uniforming
        if (i != currentWire) {
            return 0;
        }
    }
    // If the token ends up on the same wire for all starting wires,
    // the state is uniforming
    return 1;
}

// Function to find a uniforming state
char *findUniformingState(Balancer *balancers, int n, int m) {
    // Try all possible states (2^M)
    for (int i = 0; i < (1 << m); i++) {
        // Create a state string
        char *state = malloc((m + 1) * sizeof(char));
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                state[j] = '^';
            } else {
                state[j] = 'v';
            }
        }
        state[m] = '\0';
        // Assign states to balancers
        for (int j = 0; j < m; j++) {
            balancers[j].state = state[j];
        }
        // Check if the state is uniforming
        if (isUniforming(balancers, n, m)) {
            // Found a uniforming state
            return state;
        }
        free(state);
    }
    // No uniforming state found
    return NULL;
}

// Function to find a non-uniforming state
char *findNonUniformingState(Balancer *balancers, int n, int m) {
    // Try all possible states (2^M)
    for (int i = 0; i < (1 << m); i++) {
        // Create a state string
        char *state = malloc((m + 1) * sizeof(char));
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                state[j] = '^';
            } else {
                state[j] = 'v';
            }
        }
        state[m] = '\0';
        // Assign states to balancers
        for (int j = 0; j < m; j++) {
            balancers[j].state = state[j];
        }
        // Check if the state is not uniforming
        if (!isUniforming(balancers, n, m)) {
            // Found a non-uniforming state
            return state;
        }
        free(state);
    }
    // No non-uniforming state found
    return NULL;
}

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    Balancer *balancers = malloc(m * sizeof(Balancer));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &balancers[i].x, &balancers[i].y);
    }
    char *state;
    if (t == 1) {
        state = findUniformingState(balancers, n, m);
        if (state) {
            printf("%s\n", state);
            free(state);
        } else {
            printf("-1\n");
        }
    } else if (t == 2) {
        state = findNonUniformingState(balancers, n, m);
        if (state) {
            printf("%s\n", state);
            free(state);
        } else {
            printf("-1\n");
        }
    }
    free(balancers);
    return 0;
}