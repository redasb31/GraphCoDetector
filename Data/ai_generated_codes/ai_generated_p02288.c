#include <stdio.h>

// Function to get the left child index
int left(int i) {
    return 2 * i;
}

// Function to get the right child index
int right(int i) {
    return 2 * i + 1;
}

// Function to heapify the subtree rooted at index i
void maxHeapify(int A[], int i, int H) {
    int l = left(i);  // Left child index
    int r = right(i); // Right child index
    int largest = i;   // Index of the largest element

    // If left child is within the heap and greater than the current node
    if (l <= H && A[l] > A[i]) {
        largest = l;
    }

    // If right child is within the heap and greater than the current node
    if (r <= H && A[r] > A[largest]) {
        largest = r;
    }

    // If largest element is not the current node
    if (largest != i) {
        // Swap the values
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        // Recursively heapify the subtree rooted at the largest node
        maxHeapify(A, largest, H);
    }
}

// Function to build a max-heap from an array
void buildMaxHeap(int A[], int H) {
    // Start from the last non-leaf node and go up to the root
    for (int i = H / 2; i >= 1; i--) {
        maxHeapify(A, i, H);
    }
}

int main() {
    int H;
    scanf("%d", &H);

    int A[H + 1]; // Array to store the heap elements

    // Read the elements of the array
    for (int i = 1; i <= H; i++) {
        scanf("%d", &A[i]);
    }

    // Build a max-heap
    buildMaxHeap(A, H);

    // Print the elements of the max-heap
    for (int i = 1; i <= H; i++) {
        printf(" %d", A[i]);
    }

    printf("\n");

    return 0;
}