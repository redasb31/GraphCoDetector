#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 20
#define MAX_Q 200000

// Structure to represent a key-value pair
typedef struct {
    char key[MAX_KEY_LEN + 1];
    int value;
} KeyValuePair;

// Structure for a node in the trie
typedef struct TrieNode {
    KeyValuePair *keyValue; // Store key-value pair if it's a word
    struct TrieNode *children[26]; // Array of pointers to children nodes
} TrieNode;

// Function to create a new trie node
TrieNode* createNode() {
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (newNode != NULL) {
        newNode->keyValue = NULL;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

// Function to insert a key-value pair into the trie
void insert(TrieNode *root, char *key, int value) {
    int len = strlen(key);
    TrieNode *current = root;

    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }

    // Store the key-value pair at the end of the word
    current->keyValue = (KeyValuePair *)malloc(sizeof(KeyValuePair));
    strcpy(current->keyValue->key, key);
    current->keyValue->value = value;
}

// Function to search for a key in the trie
KeyValuePair* get(TrieNode *root, char *key) {
    int len = strlen(key);
    TrieNode *current = root;

    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            return NULL;
        }
        current = current->children[index];
    }

    return current->keyValue;
}

// Function to delete a key from the trie
void delete(TrieNode *root, char *key) {
    int len = strlen(key);
    TrieNode *current = root;
    TrieNode *parent = NULL;
    int index;

    for (int i = 0; i < len; i++) {
        index = key[i] - 'a';
        parent = current;
        current = current->children[index];
        if (current == NULL) {
            return; // Key not found
        }
    }

    // If the key is found and it is a leaf node
    if (current->keyValue != NULL && current->keyValue->key[0] != '\0') {
        free(current->keyValue);
        current->keyValue = NULL;

        // Delete the node if it has no children
        if (isLeaf(current)) {
            parent->children[index] = NULL;
            free(current);
        }
    } else {
        return; // Key not found or it's not a leaf node
    }
}

// Function to check if a node is a leaf node
int isLeaf(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

// Function to perform a range search in the trie
void dump(TrieNode *root, char *L, char *R) {
    // Function to recursively traverse the trie and print elements
    void traverse(TrieNode *node, char *prefix) {
        if (node == NULL) {
            return;
        }
        if (node->keyValue != NULL && node->keyValue->key[0] != '\0') {
            // Check if the key is within the range
            if (strcmp(prefix, L) >= 0 && strcmp(prefix, R) <= 0) {
                printf("%s %d\n", node->keyValue->key, node->keyValue->value);
            }
        }
        // Recursively traverse children
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                char newPrefix[MAX_KEY_LEN + 2];
                strcpy(newPrefix, prefix);
                newPrefix[strlen(prefix)] = 'a' + i;
                newPrefix[strlen(prefix) + 1] = '\0';
                traverse(node->children[i], newPrefix);
            }
        }
    }
    // Call the recursive traverse function
    traverse(root, "");
}

int main() {
    int q;
    scanf("%d", &q);

    // Create the trie
    TrieNode *root = createNode();

    char query[100];
    char key[MAX_KEY_LEN + 1];
    int x;
    char L[MAX_KEY_LEN + 1];
    char R[MAX_KEY_LEN + 1];

    for (int i = 0; i < q; i++) {
        scanf("%s", query);

        if (query[0] == '0') { // Insert operation
            sscanf(query, "%*s %s %d", key, &x);
            insert(root, key, x);
        } else if (query[0] == '1') { // Get operation
            sscanf(query, "%*s %s", key);
            KeyValuePair *result = get(root, key);
            if (result != NULL) {
                printf("%d\n", result->value);
            } else {
                printf("0\n");
            }
        } else if (query[0] == '2') { // Delete operation
            sscanf(query, "%*s %s", key);
            delete(root, key);
        } else if (query[0] == '3') { // Dump operation
            sscanf(query, "%*s %s %s", L, R);
            dump(root, L, R);
        }
    }

    // Free the trie
    freeTrie(root);

    return 0;
}

// Function to free the trie
void freeTrie(TrieNode *node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        freeTrie(node->children[i]);
    }
    if (node->keyValue != NULL) {
        free(node->keyValue);
    }
    free(node);
}