#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a node in the trie
typedef struct TrieNode {
    struct TrieNode *children[26]; // 26 for lowercase letters
    int is_word_end; // Flag to indicate if the node marks the end of a word
} TrieNode;

// Function to create a new trie node
TrieNode *create_node() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word_end = 0;
    return node;
}

// Function to insert a word into the trie
void insert(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = create_node();
        }
        curr = curr->children[index];
    }
    curr->is_word_end = 1;
}

// Function to search a word in the trie
int search(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0; // Word not found
        }
        curr = curr->children[index];
    }
    return curr->is_word_end; // Word found only if the last node marks the end of a word
}

// Function to find the minimum number of operations
int find_min_operations(char *s, TrieNode *root, int len) {
    int operations = 0;
    for (int i = 0; i < len; i++) {
        // Check if the substring starting from current position is a forbidden word
        char *substring = s + i;
        if (search(root, substring)) {
            operations++; // If it is, apply an operation
        }
    }
    return operations;
}

int main() {
    char s[100005];
    int n;
    scanf("%s\n%d", s, &n);

    // Create a trie to store the forbidden words
    TrieNode *root = create_node();
    char p[100005];
    for (int i = 0; i < n; i++) {
        scanf("%s", p);
        insert(root, p);
    }

    // Find the minimum number of operations
    int len = strlen(s);
    int min_operations = find_min_operations(s, root, len);

    // Print the result
    printf("%d\n", min_operations);

    // Free the trie memory (not shown here for simplicity, but it's recommended)

    return 0;
}