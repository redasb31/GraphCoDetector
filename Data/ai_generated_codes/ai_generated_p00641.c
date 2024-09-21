#include <stdio.h>
#include <stdlib.h>

#define MOD 10007

// Structure to represent a person in the family
typedef struct {
    int partner[2]; // Partners for the family plan
    int fee[2];    // Corresponding call fees
} Person;

// Function to calculate the number of clans modulo MOD
int calculateClans(Person *people, int n) {
    // Create an adjacency matrix to represent the connections
    int **adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Add edges to the adjacency matrix based on family plan connections
    for (int i = 0; i < n; i++) {
        adjMatrix[i][people[i].partner[0]] = 1;
        adjMatrix[people[i].partner[0]][i] = 1;
        adjMatrix[i][people[i].partner[1]] = 1;
        adjMatrix[people[i].partner[1]][i] = 1;
    }

    // Initialize the number of clans to 1 (the empty clan)
    int numClans = 1;

    // Iterate through each person
    for (int i = 0; i < n; i++) {
        // Iterate through all other people
        for (int j = i + 1; j < n; j++) {
            // Check if there is a connection between person i and person j
            if (adjMatrix[i][j] == 1) {
                // Iterate through all people connected to person j
                for (int k = 0; k < n; k++) {
                    // If person k is connected to both i and j, then there are two clans possible
                    if (adjMatrix[j][k] == 1 && adjMatrix[i][k] == 1) {
                        numClans = (numClans + 1) % MOD;
                        break;
                    }
                }
            }
        }
    }

    // Free the adjacency matrix
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    // Return the number of clans modulo MOD
    return numClans;
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        // Allocate memory for the family members
        Person *people = (Person *)malloc(n * sizeof(Person));

        // Read the information about family plan connections for each person
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &people[i].partner[0], &people[i].fee[0], &people[i].partner[1], &people[i].fee[1]);
        }

        // Calculate the number of clans and print the result
        printf("%d\n", calculateClans(people, n));

        // Free the allocated memory
        free(people);
    }

    return 0;
}