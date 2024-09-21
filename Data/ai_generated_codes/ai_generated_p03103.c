#include <stdio.h>
#include <limits.h>

// Function to find the minimum amount of money needed to buy M cans
int find_min_cost(int N, int M, int A[], int B[]) {
  // Create a priority queue (using a min-heap) to store the cost per can for each store
  // We use a min-heap to efficiently pick the store with the cheapest price per can
  int min_heap[N];
  int heap_size = 0;

  // Add all stores to the priority queue (min-heap)
  for (int i = 0; i < N; i++) {
    min_heap[heap_size++] = i;
  }

  // Function to heapify the min-heap after adding or removing elements
  void heapify(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Find the smallest among current node, left child, and right child
    if (left < heap_size && A[min_heap[left]] / B[min_heap[left]] < A[min_heap[smallest]] / B[min_heap[smallest]]) {
      smallest = left;
    }
    if (right < heap_size && A[min_heap[right]] / B[min_heap[right]] < A[min_heap[smallest]] / B[min_heap[smallest]]) {
      smallest = right;
    }

    // Swap if necessary and recursively heapify the subtree
    if (smallest != index) {
      int temp = min_heap[index];
      min_heap[index] = min_heap[smallest];
      min_heap[smallest] = temp;
      heapify(smallest);
    }
  }

  // Function to extract the minimum element (store with the cheapest price per can) from the min-heap
  int extract_min() {
    int min = min_heap[0];
    min_heap[0] = min_heap[heap_size - 1];
    heap_size--;
    heapify(0);
    return min;
  }

  // Build the min-heap from the initial state
  for (int i = (heap_size - 1) / 2; i >= 0; i--) {
    heapify(i);
  }

  // Calculate the total cost
  int total_cost = 0;
  while (M > 0) {
    // Get the store with the cheapest price per can
    int store_index = extract_min();

    // Buy as many cans as possible from the selected store
    int cans_to_buy = B[store_index];
    if (cans_to_buy > M) {
      cans_to_buy = M;
    }
    M -= cans_to_buy;

    // Update the total cost
    total_cost += cans_to_buy * A[store_index];

    // If the store has more cans available, add it back to the heap
    if (B[store_index] > cans_to_buy) {
      B[store_index] -= cans_to_buy;
      min_heap[heap_size++] = store_index;
      heapify(0); // Heapify from root after adding the element
    }
  }

  return total_cost;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int A[N], B[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  // Calculate and print the minimum cost
  int min_cost = find_min_cost(N, M, A, B);
  printf("%d\n", min_cost);

  return 0;
}