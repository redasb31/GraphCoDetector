#include <stdio.h>
#include <string.h>

// Function to convert an integer to a base-36 character
char intToBase36(int num) {
    if (num >= 0 && num <= 9) {
        return num + '0';
    } else if (num >= 10 && num <= 35) {
        return num - 10 + 'A';
    } else {
        return '?';
    }
}

// Function to find the correspondence between switches and bulbs
void findCorrespondence(int N, int M, int Q, char switches[1000][36], char bulbs[1000][1000]) {
    int switchStates[36] = {0}; // Tracks the state of each switch (0 - off, 1 - on)
    int bulbStates[1000] = {0}; // Tracks the state of each bulb (0 - off, 1 - on)

    // Process each operation
    for (int i = 0; i < Q; i++) {
        // Update switch states based on the current operation
        for (int j = 0; j < N; j++) {
            if (switches[i][j] == '1') {
                switchStates[j] = 1 - switchStates[j]; // Toggle the switch state
            }
        }

        // Update bulb states based on the current operation and switch states
        for (int j = 0; j < M; j++) {
            if (bulbs[i][j] == '1') {
                bulbStates[j] = 1 - bulbStates[j]; // Toggle the bulb state
            }
        }
    }

    // Determine the correspondence based on the final bulb and switch states
    for (int i = 0; i < M; i++) {
        // If a bulb is on, find the corresponding switch that is on and controls it
        if (bulbStates[i] == 1) {
            for (int j = 0; j < N; j++) {
                if (switchStates[j] == 1 && (bulbs[0][i] == '1' || switches[0][j] == '1')) { // Check if the switch was toggled at least once
                    printf("%c", intToBase36(j));
                    break;
                }
            }
        } else {
            printf("?"); // If the bulb is off, we cannot determine the switch
        }
    }
    printf("\n");
}

int main() {
    int N, M, Q;
    char switches[1000][36];
    char bulbs[1000][1000];

    while (1) {
        scanf("%d %d %d", &N, &M, &Q);
        if (N == 0 && M == 0 && Q == 0) {
            break; // End of input
        }
        for (int i = 0; i < Q; i++) {
            scanf("%s %s", switches[i], bulbs[i]);
        }
        findCorrespondence(N, M, Q, switches, bulbs);
    }

    return 0;
}