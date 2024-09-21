#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cube
typedef struct Cube {
    int id;           // ID of the cube
    int on_top_of;   // ID of the cube it's on top of, 0 if on the floor
    struct Cube *next; // Pointer to the next cube in the pile
} Cube;

// Function to create a new cube
Cube* createCube(int id) {
    Cube* newCube = (Cube*)malloc(sizeof(Cube));
    newCube->id = id;
    newCube->on_top_of = 0; // Initially on the floor
    newCube->next = NULL;
    return newCube;
}

// Function to find a cube in a pile
Cube* findCube(Cube* head, int id) {
    Cube* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Cube not found
}

// Function to add a cube on top of another cube
void addCube(Cube** head, int cube_to_add, int cube_to_put_on) {
    Cube* cube_a = findCube(*head, cube_to_add);
    Cube* cube_b = findCube(*head, cube_to_put_on);

    // If both cubes are in the same pile and cube_a is below cube_b, move cube_a up
    if (cube_a != NULL && cube_b != NULL && cube_a->on_top_of == cube_b->on_top_of) {
        // Remove cubes above cube_a
        while (cube_a->next != NULL) {
            Cube* temp = cube_a->next;
            cube_a->next = temp->next;
            temp->on_top_of = 0; // Place them on the floor
            free(temp);
        }

        // Put cube_a on top of cube_b
        cube_a->on_top_of = cube_b->id;
        return;
    }

    // If cube_a is on the floor or not in the same pile as cube_b
    if (cube_a != NULL && (cube_a->on_top_of == 0 || cube_a->on_top_of != cube_b->on_top_of)) {
        // Remove cubes on top of cube_a
        while (cube_a->next != NULL) {
            Cube* temp = cube_a->next;
            cube_a->next = temp->next;
            temp->on_top_of = 0; // Place them on the floor
            free(temp);
        }
        cube_a->on_top_of = cube_to_put_on;
    }
}

// Function to remove a cube from its pile
void removeCube(Cube** head, int cube_id) {
    Cube* cube = findCube(*head, cube_id);
    if (cube != NULL) {
        // Remove cube and place it on the floor
        cube->on_top_of = 0;
        // If it's not the head of the pile, remove it from the linked list
        if (cube->next != NULL) {
            Cube* prev = *head;
            while (prev->next != cube) {
                prev = prev->next;
            }
            prev->next = cube->next;
        }
    }
}

// Function to calculate the height of piles
void calculatePileHeights(Cube* head) {
    Cube* current = head;
    int pileHeight;
    int* pileHeights = (int*)malloc(sizeof(int) * 100);
    int count = 0;
    while (current != NULL) {
        pileHeight = 0;
        Cube* temp = current;
        while (temp != NULL) {
            pileHeight++;
            temp = temp->next;
        }
        if (pileHeight > 0) {
            // Check for duplicates
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (pileHeights[i] == pileHeight) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                pileHeights[count++] = pileHeight;
            }
        }
        current = current->next;
    }

    // Sort the pile heights
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (pileHeights[i] > pileHeights[j]) {
                int temp = pileHeights[i];
                pileHeights[i] = pileHeights[j];
                pileHeights[j] = temp;
            }
        }
    }

    // Print pile heights
    for (int i = 0; i < count; i++) {
        printf("%d\n", pileHeights[i]);
    }
    printf("end\n");

    free(pileHeights);
}

int main() {
    int num_cubes;
    while (scanf("%d", &num_cubes) != EOF && num_cubes != 0) {
        Cube* head = NULL;
        for (int i = 1; i <= num_cubes; i++) {
            head = createCube(i);
            head->next = NULL;
        }
        int i, j;
        while (scanf("%d %d", &i, &j) != EOF && (i != 0 || j != 0)) {
            if (i == j) { // Ignore instruction if putting a cube on itself
                continue;
            }
            if (j == 0) { // Put cube on the floor
                removeCube(&head, i);
            } else { // Put cube on another cube
                addCube(&head, i, j);
            }
        }
        calculatePileHeights(head);
        // Free memory
        Cube* current = head;
        while (current != NULL) {
            Cube* temp = current->next;
            free(current);
            current = temp;
        }
    }
    return 0;
}