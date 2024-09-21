#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_Q 500000

// Structure to represent a dynamic array
struct Array {
    int *data;
    int size;
    int capacity;
};

// Function to initialize a new array
struct Array *createArray() {
    struct Array *arr = (struct Array *)malloc(sizeof(struct Array));
    arr->data = (int *)malloc(sizeof(int));
    arr->size = 0;
    arr->capacity = 1;
    return arr;
}

// Function to push an element to the back of the array
void pushBack(struct Array *arr, int x) {
    // If the array is full, double its capacity
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = x;
}

// Function to print the elements of the array
void dump(struct Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Function to clear the array
void clear(struct Array *arr) {
    arr->size = 0;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Create n dynamic arrays
    struct Array *arrays[MAX_N];
    for (int i = 0; i < n; i++) {
        arrays[i] = createArray();
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int op, t, x;
        scanf("%d %d", &op, &t);
        if (op == 0) {
            scanf("%d", &x);
            pushBack(arrays[t], x);
        } else if (op == 1) {
            dump(arrays[t]);
        } else if (op == 2) {
            clear(arrays[t]);
        }
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(arrays[i]->data);
        free(arrays[i]);
    }

    return 0;
}