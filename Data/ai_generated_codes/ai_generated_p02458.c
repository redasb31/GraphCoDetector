#include <stdio.h>
#include <stdlib.h>

// Node structure for the multiset
typedef struct Node {
  int data;
  int count;
  struct Node *next;
} Node;

// Function to create a new node
Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->count = 1;
  node->next = NULL;
  return node;
}

// Function to insert an element into the multiset
void insert(Node **head, int data) {
  // If the multiset is empty, create a new node
  if (*head == NULL) {
    *head = newNode(data);
    printf("%d\n", 1);
    return;
  }

  // Iterate through the linked list
  Node *current = *head;
  while (current != NULL) {
    // If the element is already present, increment its count
    if (current->data == data) {
      current->count++;
      printf("%d\n", current->count);
      return;
    }
    current = current->next;
  }

  // If the element is not present, create a new node and insert it at the beginning
  Node *new_node = newNode(data);
  new_node->next = *head;
  *head = new_node;
  printf("%d\n", new_node->count);
}

// Function to find the number of occurrences of an element in the multiset
int find(Node *head, int data) {
  // Iterate through the linked list
  Node *current = head;
  while (current != NULL) {
    // If the element is found, return its count
    if (current->data == data) {
      return current->count;
    }
    current = current->next;
  }
  // If the element is not found, return 0
  return 0;
}

// Function to delete all occurrences of an element from the multiset
void delete(Node **head, int data) {
  // If the multiset is empty, return
  if (*head == NULL) {
    return;
  }

  // If the element is present at the head, remove it
  if ((*head)->data == data) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }

  // Iterate through the linked list
  Node *current = *head;
  Node *previous = NULL;
  while (current != NULL) {
    // If the element is found, remove it
    if (current->data == data) {
      previous->next = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

// Function to dump elements in the range [L, R]
void dump(Node *head, int L, int R) {
  // Iterate through the linked list
  Node *current = head;
  while (current != NULL) {
    // If the element is in the range, print it
    if (current->data >= L && current->data <= R) {
      for (int i = 0; i < current->count; i++) {
        printf("%d\n", current->data);
      }
    }
    current = current->next;
  }
}

int main() {
  int q;
  scanf("%d", &q);

  // Initialize the multiset head to NULL
  Node *head = NULL;

  // Process each query
  for (int i = 0; i < q; i++) {
    int operation, x, L, R;
    scanf("%d", &operation);

    // Handle different operations
    switch (operation) {
      case 0:
        scanf("%d", &x);
        insert(&head, x);
        break;
      case 1:
        scanf("%d", &x);
        printf("%d\n", find(head, x));
        break;
      case 2:
        scanf("%d", &x);
        delete(&head, x);
        break;
      case 3:
        scanf("%d %d", &L, &R);
        dump(head, L, R);
        break;
    }
  }

  return 0;
}