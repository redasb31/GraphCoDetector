#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 20
#define MAX_QUERIES 200000

typedef struct Node {
    char key[MAX_KEY_LENGTH + 1];
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} HashTable;

HashTable *createHashTable() {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->head = NULL;
    return table;
}

// Hash function (simple modulo)
int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % 1000; // Example hash function, adjust as needed
}

// Insert an element into the hash table
void insert(HashTable *table, char *key, int value) {
    int index = hash(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;

    // Check if the key already exists
    Node *current = table->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value; // Update value if key exists
            free(newNode); // Free the newly created node
            return;
        }
        current = current->next;
    }

    newNode->next = table->head;
    table->head = newNode;
}

// Get the value associated with a key
int get(HashTable *table, char *key) {
    int index = hash(key);
    Node *current = table->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return 0; // Key not found
}

// Delete the element associated with a key
void delete(HashTable *table, char *key) {
    int index = hash(key);
    Node *current = table->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                table->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    int q;
    scanf("%d", &q);

    HashTable *table = createHashTable();

    char operation[2];
    char key[MAX_KEY_LENGTH + 1];
    int value;

    for (int i = 0; i < q; i++) {
        scanf("%s %s", operation, key);

        if (operation[0] == '0') {
            scanf("%d", &value);
            insert(table, key, value);
        } else if (operation[0] == '1') {
            printf("%d\n", get(table, key));
        } else if (operation[0] == '2') {
            delete(table, key);
        }
    }

    free(table);
    return 0;
}