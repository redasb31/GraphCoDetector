#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100
#define MAX_QUERIES 100000

// Structure to represent a trie node
typedef struct TrieNode {
    struct TrieNode *children[26]; // Array to store pointers to child nodes
    int count; // Counter for the number of words ending at this node
} TrieNode;

// Function to create a new trie node
TrieNode *createNode() {
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (newNode) {
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->count = 0;
    }
    return newNode;
}

// Function to insert a word into the trie
void insert(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->count++;
}

// Function to search for a prefix in the trie
TrieNode *searchPrefix(TrieNode *root, char *prefix) {
    TrieNode *curr = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL) {
            return NULL; // Prefix not found
        }
        curr = curr->children[index];
    }
    return curr; // Return the node corresponding to the prefix
}

// Function to search for a suffix in the trie (starting from a given node)
int searchSuffix(TrieNode *node, char *suffix) {
    if (node == NULL) {
        return 0; // Prefix not found, so suffix cannot be found
    }

    TrieNode *curr = node;
    for (int i = strlen(suffix) - 1; i >= 0; i--) {
        int index = suffix[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0; // Suffix not found
        }
        curr = curr->children[index];
    }

    return curr->count; // Return the count of words ending with the suffix
}

int main() {
    int N, Q;
    char words[MAX_WORDS][MAX_WORD_LEN];
    char prefix[MAX_WORD_LEN], suffix[MAX_WORD_LEN];

    // Read the input
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    // Create the trie
    TrieNode *root = createNode();
    for (int i = 0; i < N; i++) {
        insert(root, words[i]);
    }

    // Process the queries
    for (int i = 0; i < Q; i++) {
        scanf("%s %s", prefix, suffix);
        TrieNode *prefixNode = searchPrefix(root, prefix);
        int count = searchSuffix(prefixNode, suffix);
        printf("%d\n", count);
    }

    return 0;
}