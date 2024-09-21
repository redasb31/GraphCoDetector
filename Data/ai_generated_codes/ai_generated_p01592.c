#include <stdio.h>
#include <stdlib.h>

#define MAX_FAULTS 500

// Structure to represent a fault
typedef struct {
    int id; // Fault ID
    int connected[MAX_FAULTS]; // Array to store IDs of connected faults
    int num_connected; // Number of connected faults
} Fault;

// Function to create a fault
Fault* create_fault(int id) {
    Fault* fault = (Fault*)malloc(sizeof(Fault));
    fault->id = id;
    fault->num_connected = 0;
    return fault;
}

// Function to add a connection between two faults
void add_connection(Fault* fault1, Fault* fault2) {
    fault1->connected[fault1->num_connected++] = fault2->id;
    fault2->connected[fault2->num_connected++] = fault1->id;
}

// Function to find the winner of the blame game
char* find_winner(Fault* alice_faults, Fault* bob_faults, int n, int m) {
    // Create a boolean array to track claimed faults
    int claimed_alice[MAX_FAULTS] = {0};
    int claimed_bob[MAX_FAULTS] = {0};

    // Start the game with Alice's first move
    int alice_turn = 1;
    int bob_turn = 0;
    int alice_fault = 1; // Alice starts with fault 1

    // Game loop
    while (1) {
        // Check if Alice has any unclaimed faults connected to the current Bob's fault
        int found = 0;
        for (int i = 0; i < alice_faults[alice_fault - 1].num_connected; i++) {
            if (!claimed_bob[alice_faults[alice_fault - 1].connected[i] - 1]) {
                bob_turn = alice_faults[alice_fault - 1].connected[i];
                found = 1;
                break;
            }
        }
        if (!found) {
            return "Bob"; // Alice loses
        }

        // Check if Bob has any unclaimed faults connected to the current Alice's fault
        found = 0;
        for (int i = 0; i < bob_faults[bob_turn - 1].num_connected; i++) {
            if (!claimed_alice[bob_faults[bob_turn - 1].connected[i] - 1]) {
                alice_turn = bob_faults[bob_turn - 1].connected[i];
                found = 1;
                break;
            }
        }
        if (!found) {
            return "Alice"; // Bob loses
        }

        // Mark the current faults as claimed
        claimed_alice[alice_turn - 1] = 1;
        claimed_bob[bob_turn - 1] = 1;
    }
}

int main() {
    int n, m; // Number of Alice's and Bob's faults
    scanf("%d %d", &n, &m);

    // Create arrays to store Alice's and Bob's faults
    Fault* alice_faults = (Fault**)malloc(n * sizeof(Fault*));
    Fault* bob_faults = (Fault**)malloc(m * sizeof(Fault*));

    // Initialize faults
    for (int i = 0; i < n; i++) {
        alice_faults[i] = create_fault(i + 1);
    }
    for (int i = 0; i < m; i++) {
        bob_faults[i] = create_fault(i + 1);
    }

    // Read relationships between faults
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int b;
            scanf("%d", &b);
            add_connection(alice_faults[i], bob_faults[b - 1]);
        }
    }

    // Find the winner
    char* winner = find_winner(alice_faults, bob_faults, n, m);
    printf("%s\n", winner);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(alice_faults[i]);
    }
    free(alice_faults);
    for (int i = 0; i < m; i++) {
        free(bob_faults[i]);
    }
    free(bob_faults);

    return 0;
}