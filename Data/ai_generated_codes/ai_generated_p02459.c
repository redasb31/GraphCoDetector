#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LEN 20
#define MAX_QUERIES 200000

// Structure to represent a key-value pair
typedef struct {
    char key[MAX_KEY_LEN + 1];
    int value;
} Entry;

// Structure to represent a hash table
typedef struct {
    Entry *entries;
    int capacity;
    int size;
} HashTable;

// Function to create a new hash table
HashTable *createHashTable(int capacity) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->capacity = capacity;
    table->size = 0;
    table->entries = (Entry *)malloc(sizeof(Entry) * capacity);
    return table;
}

// Function to hash a key
int hash(char *key, int capacity) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31 + key[i]) % capacity;
    }
    return hash;
}

// Function to insert or update a key-value pair
void insert(HashTable *table, char *key, int value) {
    int index = hash(key, table->capacity);

    // Linear probing to find an empty slot or the existing key
    while (table->entries[index].key[0] != '\0' && strcmp(table->entries[index].key, key) != 0) {
        index = (index + 1) % table->capacity;
    }

    // Insert or update the key-value pair
    strcpy(table->entries[index].key, key);
    table->entries[index].value = value;

    // Update the size of the hash table
    if (table->entries[index].key[0] == '\0') {
        table->size++;
    }
}

// Function to get the value associated with a key
int get(HashTable *table, char *key) {
    int index = hash(key, table->capacity);

    // Linear probing to find the key
    while (table->entries[index].key[0] != '\0') {
        if (strcmp(table->entries[index].key, key) == 0) {
            return table->entries[index].value;
        }
        index = (index + 1) % table->capacity;
    }

    // Key not found
    return -1;
}

// Function to free the hash table
void freeHashTable(HashTable *table) {
    free(table->entries);
    free(table);
}

int main() {
    int q;
    scanf("%d", &q);

    // Create a hash table with initial capacity
    HashTable *table = createHashTable(100000); 

    char operation[2];
    char key[MAX_KEY_LEN + 1];
    int value;

    for (int i = 0; i < q; i++) {
        scanf("%s %s", operation, key);

        if (operation[0] == '0') {
            scanf("%d", &value);
            insert(table, key, value);
        } else if (operation[0] == '1') {
            int result = get(table, key);
            printf("%d\n", result);
        }
    }

    // Free the hash table
    freeHashTable(table);

    return 0;
}