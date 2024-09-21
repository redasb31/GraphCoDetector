#include <stdio.h>

// Function to check if a tree with 2N vertices satisfying the condition exists
int check_tree(int N) {
  // For N = 1, a simple tree with two nodes connected by an edge satisfies the condition
  if (N == 1) {
    return 1;
  }

  // For any N greater than 1, there is no tree that can satisfy the condition
  // This is because for any path from a vertex i to vertex N+i,
  // the bitwise XOR of the weights will always be 0 (because the weights of i and N+i are the same)
  // and will never be equal to i
  return 0;
}

int main() {
  int N;

  scanf("%d", &N);

  if (check_tree(N)) {
    printf("Yes\n");
    // Print the edges of the tree for N = 1
    printf("1 2\n");
  } else {
    printf("No\n");
  }

  return 0;
}