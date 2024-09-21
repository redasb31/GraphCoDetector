#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 50
#define MAX_M (MAX_N * (MAX_N - 1))

// Structure to represent a circle
typedef struct {
    int out_degree; // Number of outgoing arrows
    int outgoing_arrows[MAX_N]; // Indices of circles connected by arrows
} Circle;

// Function to check if the goal circle can be reached from the current circle within a given number of steps
bool can_reach_goal(Circle *circles, int current_circle, int steps_left, int goal_circle, int *visited) {
    if (steps_left == 0) {
        return current_circle == goal_circle;
    }
    if (visited[current_circle]) {
        return false;
    }
    visited[current_circle] = 1;
    for (int i = 0; i < circles[current_circle].out_degree; i++) {
        int next_circle = circles[current_circle].outgoing_arrows[i];
        if (can_reach_goal(circles, next_circle, steps_left - 1, goal_circle, visited)) {
            return true;
        }
    }
    return false;
}

// Function to find the minimum number of turns required to reach the goal
int find_min_turns(Circle *circles, int n, int a, int b, int c, int goal_circle) {
    int min_turns = INT_MAX;
    int visited[MAX_N] = {0}; // Array to track visited circles

    // Iterate over all possible combinations of steps
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int steps = 0;
                int current_circle = 1; // Start from circle 1

                // Simulate taking steps using the three numbers
                if (i == 0) { steps += a; }
                if (j == 0) { steps += b; }
                if (k == 0) { steps += c; }

                // Check if the goal can be reached within the current number of steps
                if (can_reach_goal(circles, current_circle, steps, goal_circle, visited)) {
                    min_turns = (steps + 2) / 3; // Calculate the number of turns
                    return min_turns;
                }
            }
        }
    }

    return min_turns;
}

int main() {
    int n, m, a, b, c;
    int u, v;

    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);

    Circle circles[MAX_N]; // Array to store information about circles
    for (int i = 1; i <= n; i++) {
        circles[i].out_degree = 0;
    }

    // Read the arrows connecting the circles
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        circles[u].outgoing_arrows[circles[u].out_degree++] = v;
    }

    // Calculate the minimum number of turns
    int min_turns = find_min_turns(circles, n, a, b, c, n);

    // Print the result
    if (min_turns == INT_MAX) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%d\n", min_turns);
    }

    return 0;
}