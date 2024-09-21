#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the Huffman tree
typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(char character, int frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to compare two nodes based on frequency
int compare(const void* a, const void* b) {
    return ((Node*)a)->frequency - ((Node*)b)->frequency;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char* str) {
    // Create a min-heap to store nodes
    int n = strlen(str);
    Node** nodes = (Node**)malloc(n * sizeof(Node*));

    // Calculate frequency of each character
    int frequency[26] = {0};
    for (int i = 0; i < n; i++) {
        frequency[str[i] - 'a']++;
    }

    // Create nodes for each character
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            nodes[count++] = newNode('a' + i, frequency[i]);
        }
    }

    // Build the Huffman tree
    qsort(nodes, count, sizeof(Node*), compare);
    for (int i = 1; i < count; i++) {
        Node* left = nodes[0];
        Node* right = nodes[1];
        Node* parent = newNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        nodes[0] = parent;
        nodes[1] = nodes[i];
        qsort(nodes, count - i + 1, sizeof(Node*), compare);
    }

    return nodes[0];
}

// Function to calculate the length of the encoded string
int huffmanCodingLength(Node* root, char* str) {
    int length = 0;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        Node* current = root;
        while (current->left != NULL || current->right != NULL) {
            if (str[i] == current->character) {
                break;
            }
            length++;
            if (str[i] < current->character) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
    return length;
}

int main() {
    char str[100005];
    scanf("%s", str);
    Node* root = buildHuffmanTree(str);
    int length = huffmanCodingLength(root, str);
    printf("%d\n", length);
    return 0;
}