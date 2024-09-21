#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Structure for a list
typedef struct List {
  Node* head;
  Node* tail;
} List;

// Function to create a new node
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to create a new list
List* createList() {
  List* newList = (List*)malloc(sizeof(List));
  newList->head = NULL;
  newList->tail = NULL;
  return newList;
}

// Function to insert a node at the end of the list
void insert(List* list, int data) {
  Node* newNode = createNode(data);
  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }
}

// Function to dump all elements in a list
void dump(List* list) {
  Node* current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Function to splice elements from one list to another
void splice(List* sourceList, List* targetList) {
  if (sourceList->head == NULL) {
    return;
  }
  if (targetList->head == NULL) {
    targetList->head = sourceList->head;
    targetList->tail = sourceList->tail;
  } else {
    targetList->tail->next = sourceList->head;
    targetList->tail = sourceList->tail;
  }
  sourceList->head = NULL;
  sourceList->tail = NULL;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  // Create an array of lists
  List* lists[n];
  for (int i = 0; i < n; i++) {
    lists[i] = createList();
  }

  // Process each query
  for (int i = 0; i < q; i++) {
    int operation, t, x, s;
    scanf("%d", &operation);
    if (operation == 0) {
      // Insert operation
      scanf("%d %d", &t, &x);
      insert(lists[t], x);
    } else if (operation == 1) {
      // Dump operation
      scanf("%d", &t);
      dump(lists[t]);
    } else if (operation == 2) {
      // Splice operation
      scanf("%d %d", &s, &t);
      splice(lists[s], lists[t]);
    }
  }

  // Free memory
  for (int i = 0; i < n; i++) {
    Node* current = lists[i]->head;
    while (current != NULL) {
      Node* next = current->next;
      free(current);
      current = next;
    }
    free(lists[i]);
  }

  return 0;
}