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

typedef struct MultiMap {
  Node **table;
  int size;
} MultiMap;

// Function to hash a key
int hash(char *key, int size) {
  int hash = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash = (hash * 31 + key[i]) % size;
  }
  return hash;
}

// Function to create a new node
Node *newNode(char *key, int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  strcpy(node->key, key);
  node->value = value;
  node->next = NULL;
  return node;
}

// Function to create a new multimap
MultiMap *createMultiMap(int size) {
  MultiMap *multimap = (MultiMap *)malloc(sizeof(MultiMap));
  multimap->table = (Node **)calloc(size, sizeof(Node *));
  multimap->size = size;
  return multimap;
}

// Function to insert an element into the multimap
void insert(MultiMap *multimap, char *key, int value) {
  int index = hash(key, multimap->size);
  Node *node = newNode(key, value);
  node->next = multimap->table[index];
  multimap->table[index] = node;
}

// Function to get all values with a specified key
void get(MultiMap *multimap, char *key) {
  int index = hash(key, multimap->size);
  Node *current = multimap->table[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      printf("%d\n", current->value);
    }
    current = current->next;
  }
}

// Function to delete all elements with a specified key
void delete(MultiMap *multimap, char *key) {
  int index = hash(key, multimap->size);
  Node *current = multimap->table[index];
  Node *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      if (previous == NULL) {
        multimap->table[index] = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      current = previous->next;
    } else {
      previous = current;
      current = current->next;
    }
  }
}

// Function to compare two nodes based on their keys
int compareNodes(const void *a, const void *b) {
  Node *nodeA = *(Node **)a;
  Node *nodeB = *(Node **)b;
  return strcmp(nodeA->key, nodeB->key);
}

// Function to dump all elements within a range
void dump(MultiMap *multimap, char *L, char *R) {
  // Create an array to store all nodes within the range
  Node **nodes = (Node **)malloc(sizeof(Node *) * (multimap->size + 1));
  int count = 0;

  // Iterate through all buckets
  for (int i = 0; i < multimap->size; i++) {
    Node *current = multimap->table[i];
    while (current != NULL) {
      // Check if the key is within the range
      if (strcmp(current->key, L) >= 0 && strcmp(current->key, R) <= 0) {
        nodes[count++] = current;
      }
      current = current->next;
    }
  }

  // Sort the nodes based on their keys
  qsort(nodes, count, sizeof(Node *), compareNodes);

  // Print the sorted nodes
  for (int i = 0; i < count; i++) {
    printf("%s %d\n", nodes[i]->key, nodes[i]->value);
  }

  free(nodes);
}

int main() {
  int q;
  scanf("%d", &q);

  // Create a multimap with a size of 100000
  MultiMap *multimap = createMultiMap(100000);

  char query[100];
  char key[MAX_KEY_LENGTH + 1];
  int x;
  char L[MAX_KEY_LENGTH + 1];
  char R[MAX_KEY_LENGTH + 1];

  // Process each query
  for (int i = 0; i < q; i++) {
    scanf("%s", query);

    switch (query[0]) {
      case '0': // Insert operation
        sscanf(query, "%*s %s %d", key, &x);
        insert(multimap, key, x);
        break;
      case '1': // Get operation
        sscanf(query, "%*s %s", key);
        get(multimap, key);
        break;
      case '2': // Delete operation
        sscanf(query, "%*s %s", key);
        delete(multimap, key);
        break;
      case '3': // Dump operation
        sscanf(query, "%*s %s %s", L, R);
        dump(multimap, L, R);
        break;
    }
  }

  // Free the memory allocated for the multimap
  free(multimap->table);
  free(multimap);

  return 0;
}