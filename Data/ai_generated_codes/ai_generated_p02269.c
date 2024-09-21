#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 13
#define MAX_DICT_SIZE 1000000

// Structure to represent a string in the dictionary
typedef struct {
    char str[MAX_STR_LEN];
} String;

// Structure to represent the dictionary
typedef struct {
    String *strings;
    int size;
    int capacity;
} Dictionary;

// Function to initialize the dictionary
Dictionary *init_dict() {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->strings = (String *)malloc(sizeof(String) * 10); // Initial capacity
    dict->size = 0;
    dict->capacity = 10;
    return dict;
}

// Function to insert a string into the dictionary
void insert_str(Dictionary *dict, char *str) {
    // If the dictionary is full, increase its capacity
    if (dict->size == dict->capacity) {
        dict->capacity *= 2;
        dict->strings = (String *)realloc(dict->strings, sizeof(String) * dict->capacity);
    }
    // Copy the string into the dictionary
    strcpy(dict->strings[dict->size].str, str);
    dict->size++;
}

// Function to find a string in the dictionary
int find_str(Dictionary *dict, char *str) {
    // Iterate through the dictionary and compare strings
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->strings[i].str, str) == 0) {
            return 1; // String found
        }
    }
    return 0; // String not found
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize the dictionary
    Dictionary *dict = init_dict();

    char instruction[10];
    char str[MAX_STR_LEN];

    // Process each instruction
    for (int i = 0; i < n; i++) {
        scanf("%s %s", instruction, str);

        // Insert string
        if (strcmp(instruction, "insert") == 0) {
            insert_str(dict, str);
        } 
        // Find string
        else if (strcmp(instruction, "find") == 0) {
            if (find_str(dict, str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    free(dict->strings);
    free(dict);

    return 0;
}