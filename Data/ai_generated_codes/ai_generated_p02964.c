#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000
#define MAX_A 200000

// Structure to represent a node in the stack
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to push a new node onto the stack
Node* push(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

// Function to pop the top node from the stack
Node* pop(Node* head) {
  if (head == NULL) {
    return NULL;
  }
  Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Function to check if a given value exists in the stack
int contains(Node* head, int data) {
  while (head != NULL) {
    if (head->data == data) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}

int main() {
  int N, K;
  int A[MAX_N];

  // Read input
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize stack
  Node* head = NULL;

  // Iterate through all elements of the sequence
  for (int i = 0; i < N * K; i++) {
    int X = A[i % N]; // Calculate X_i using A

    // Check if X exists in the stack
    if (contains(head, X)) {
      // If X exists, pop elements until X is removed
      while (contains(head, X)) {
        head = pop(head);
      }
    } else {
      // If X doesn't exist, push it onto the stack
      head = push(head, X);
    }
  }

  // Print the final contents of the stack
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");

  return 0;
}