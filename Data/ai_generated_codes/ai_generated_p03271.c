#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  // Store the permutation
  int p[N + 1]; // p[0] is unused, so we use index 1 to N
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &p[i]);
  }

  // Check if the permutation can be sorted
  // We maintain a stack to track the increasing sequence
  int stack[N + 1];
  int top = 0;

  // Iterate through the permutation
  for (int i = 1; i <= N; ++i) {
    // If the current element is smaller than the top of the stack, 
    // it can be sorted by reversing the order of the three elements
    // p[i-1], p[i], and p[i+1].
    while (top > 1 && p[i] < p[stack[top - 1]]) {
      // Pop the top two elements from the stack and reverse their order
      top -= 2;
    }

    // If the stack is not empty, it means that the current element 
    // is greater than the top of the stack, so we push it onto the stack.
    if (top > 0) {
      // Check if the current element and the top of the stack are in order
      if (p[i] > p[stack[top]]) {
        // If not, it means that the current element cannot be sorted
        printf("No\n");
        return 0;
      }
    }

    // Push the current element onto the stack
    stack[++top] = i;
  }

  // If the stack is not empty, it means that the permutation can be sorted
  printf("Yes\n");

  return 0;
}