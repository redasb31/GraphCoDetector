#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 5
#define MAX_NAMES 300
#define MAX_DOCUMENTS 1000
#define MAX_PAIRS 100000

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int ancestor[MAX_NAMES];
    int descendant[MAX_NAMES];
} Person;

typedef struct {
    int m;
    char x[MAX_PAIRS][MAX_NAME_LENGTH + 1];
    char y[MAX_PAIRS][MAX_NAME_LENGTH + 1];
} Document;

int find_index(Person *persons, int num_persons, char *name) {
    for (int i = 0; i < num_persons; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add a person to the persons array
int add_person(Person *persons, int *num_persons, char *name) {
    if (*num_persons >= MAX_NAMES) {
        return -1;
    }
    strcpy(persons[*num_persons].name, name);
    persons[*num_persons].ancestor[0] = 0;
    persons[*num_persons].descendant[0] = 0;
    (*num_persons)++;
    return 0;
}

int main() {
    char p[MAX_NAME_LENGTH + 1], q[MAX_NAME_LENGTH + 1];
    int n, num_persons = 0;
    Person persons[MAX_NAMES];
    Document documents[MAX_DOCUMENTS];

    // Read the input
    scanf("%s %s", p, q);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &documents[i].m);
        for (int j = 0; j < documents[i].m; j++) {
            scanf("%s %s", documents[i].x[j], documents[i].y[j]);
        }
    }

    // Add all the names to the persons array
    add_person(persons, &num_persons, p);
    add_person(persons, &num_persons, q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < documents[i].m; j++) {
            int index = find_index(persons, num_persons, documents[i].x[j]);
            if (index == -1) {
                add_person(persons, &num_persons, documents[i].x[j]);
            }
            index = find_index(persons, num_persons, documents[i].y[j]);
            if (index == -1) {
                add_person(persons, &num_persons, documents[i].y[j]);
            }
        }
    }

    // Initialize the ancestor and descendant arrays for each person
    for (int i = 0; i < num_persons; i++) {
        for (int j = 0; j < num_persons; j++) {
            persons[i].ancestor[j] = 0;
            persons[i].descendant[j] = 0;
        }
    }

    // Create a flag for each document to indicate whether it is positive or negative
    int document_flags[MAX_DOCUMENTS];
    for (int i = 0; i < n; i++) {
        document_flags[i] = -1; // -1 indicates not yet assigned
    }

    // Iterate through all possible document interpretations
    for (int i = 0; i < (1 << n); i++) {
        // Initialize the ancestor and descendant arrays for each person
        for (int j = 0; j < num_persons; j++) {
            for (int k = 0; k < num_persons; k++) {
                persons[j].ancestor[k] = 0;
                persons[j].descendant[k] = 0;
            }
        }

        // Assign positive or negative to each document based on the current interpretation
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                document_flags[j] = 1; // Positive
            } else {
                document_flags[j] = 0; // Negative
            }
        }

        // Update ancestor and descendant relationships based on the documents
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < documents[j].m; k++) {
                int x_index = find_index(persons, num_persons, documents[j].x[k]);
                int y_index = find_index(persons, num_persons, documents[j].y[k]);
                if (document_flags[j] == 1) {
                    persons[x_index].descendant[y_index] = 1;
                    persons[y_index].ancestor[x_index] = 1;
                } else {
                    persons[x_index].descendant[y_index] = 0;
                    persons[y_index].ancestor[x_index] = 0;
                }
            }
        }

        // Update ancestor and descendant relationships based on transitivity
        for (int j = 0; j < num_persons; j++) {
            for (int k = 0; k < num_persons; k++) {
                if (persons[j].descendant[k] == 1) {
                    for (int l = 0; l < num_persons; l++) {
                        if (persons[k].descendant[l] == 1) {
                            persons[j].descendant[l] = 1;
                            persons[l].ancestor[j] = 1;
                        }
                    }
                }
            }
        }

        // Check if the interpretation contradicts with the hypothesis that p is an ancestor of q
        int p_index = find_index(persons, num_persons, p);
        int q_index = find_index(persons, num_persons, q);
        if (persons[p_index].descendant[q_index] == 1) {
            // If p is an ancestor of q, check for contradictions
            for (int j = 0; j < num_persons; j++) {
                for (int k = 0; k < num_persons; k++) {
                    if (persons[j].ancestor[k] == 1 && persons[k].ancestor[j] == 1) {
                        // Contradiction: x is an ancestor of y and y is an ancestor of x
                        goto next_interpretation;
                    }
                    if (persons[j].ancestor[k] == 1 && persons[j].descendant[k] == 0) {
                        // Contradiction: x is an ancestor of y and x is not an ancestor of y
                        goto next_interpretation;
                    }
                }
            }
            // No contradiction found, so this interpretation is valid
            printf("Yes\n");
            return 0;
        }
        next_interpretation:;
    }
    // No interpretation found that does not contradict the hypothesis
    printf("No\n");
    return 0;
}