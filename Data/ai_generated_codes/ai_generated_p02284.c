#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new node
Node* newNode(int key) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->key = key;
  node->left = node->right = NULL;
  return node;
}

// Function to insert a new node into the BST
Node* insert(Node* node, int key) {
  // If the tree is empty, return a new node
  if (node == NULL) {
    return newNode(key);
  }

  // Otherwise, recur down the tree
  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  }

  // Return the (unchanged) node pointer
  return node;
}

// Function to find a node in the BST
int find(Node* node, int key) {
  // If the tree is empty, return 0 (not found)
  if (node == NULL) {
    return 0;
  }

  // If the key is found, return 1
  if (node->key == key) {
    return 1;
  }

  // Otherwise, recur down the tree
  if (key < node->key) {
    return find(node->left, key);
  } else {
    return find(node->right, key);
  }
}

// Function to perform inorder tree walk
void inorder(Node* node) {
  if (node != NULL) {
    inorder(node->left);
    printf(" %d", node->key);
    inorder(node->right);
  }
}

// Function to perform preorder tree walk
void preorder(Node* node) {
  if (node != NULL) {
    printf(" %d", node->key);
    preorder(node->left);
    preorder(node->right);
  }
}

int main() {
  int m, key;
  char operation[10];
  Node* root = NULL;

  scanf("%d", &m);

  // Process each operation
  for (int i = 0; i < m; i++) {
    scanf("%s", operation);

    if (operation[0] == 'i') {
      scanf("%d", &key);
      root = insert(root, key);
    } else if (operation[0] == 'f') {
      scanf("%d", &key);
      if (find(root, key)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    } else if (operation[0] == 'p') {
      printf(" ");
      inorder(root);
      printf("\n ");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}