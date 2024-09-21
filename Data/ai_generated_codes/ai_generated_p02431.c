#include <stdio.h>
#include <stdlib.h>

// Structure for dynamic array
typedef struct {
  int *arr; // Pointer to array elements
  int capacity; // Capacity of array
  int size; // Number of elements in array
} Vector;

// Function to initialize a new vector
Vector *createVector() {
  Vector *v = (Vector *)malloc(sizeof(Vector));
  v->capacity = 1; // Initial capacity of 1
  v->size = 0; // Initially empty
  v->arr = (int *)malloc(sizeof(int) * v->capacity); // Allocate memory for 1 element
  return v;
}

// Function to push an element to the back of the vector
void pushBack(Vector *v, int x) {
  // If vector is full, double the capacity
  if (v->size == v->capacity) {
    v->capacity *= 2;
    v->arr = (int *)realloc(v->arr, sizeof(int) * v->capacity); // Reallocate memory
  }

  v->arr[v->size] = x; // Add element at the end
  v->size++; // Increase size
}

// Function for random access
void randomAccess(Vector *v, int p) {
  if (p < 0 || p >= v->size) {
    printf("Invalid index\n");
    return;
  }
  printf("%d\n", v->arr[p]); // Print the element at index p
}

// Function to remove the last element
void popBack(Vector *v) {
  if (v->size == 0) {
    printf("Vector is empty\n");
    return;
  }
  v->size--; // Decrease size
}

// Function to free memory associated with the vector
void freeVector(Vector *v) {
  free(v->arr);
  free(v);
}

int main() {
  int q, op, x, p;
  scanf("%d", &q); // Read number of queries

  Vector *v = createVector(); // Create a new vector

  // Process each query
  for (int i = 0; i < q; i++) {
    scanf("%d", &op);

    if (op == 0) {
      scanf("%d", &x);
      pushBack(v, x); // Push element to the back
    } else if (op == 1) {
      scanf("%d", &p);
      randomAccess(v, p); // Random access
    } else if (op == 2) {
      popBack(v); // Pop element from the back
    }
  }

  freeVector(v); // Free the vector
  return 0;
}