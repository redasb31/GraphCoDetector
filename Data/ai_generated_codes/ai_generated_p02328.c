#include <stdio.h>
#include <stdlib.h>

// Function to find the largest rectangular area in a histogram
long long maxArea(int *hist, int n) {
  // Initialize the stack and the maximum area
  int *stack = (int *)malloc(sizeof(int) * n);
  int top = -1;
  long long max_area = 0;

  // Iterate through the histogram bars
  for (int i = 0; i <= n; i++) {
    // If the stack is empty or the current bar is taller than the top of the stack
    if (top == -1 || (i < n && hist[i] >= hist[stack[top]])) {
      // Push the current bar onto the stack
      stack[++top] = i;
    } else {
      // If the current bar is shorter than the top of the stack, pop bars from the stack
      // until the stack is empty or the current bar is taller than the top of the stack
      while (top != -1 && (i == n || hist[i] < hist[stack[top]])) {
        // Calculate the area of the rectangle formed by the popped bar
        int tp = stack[top--];
        long long area = hist[tp] * (top == -1 ? i : (i - stack[top] - 1));
        // Update the maximum area
        max_area = (area > max_area) ? area : max_area;
      }
      // Push the current bar onto the stack
      stack[++top] = i;
    }
  }
  // Free the allocated memory
  free(stack);
  // Return the maximum area
  return max_area;
}

int main() {
  // Input the number of bars
  int n;
  scanf("%d", &n);

  // Input the heights of the bars
  int *hist = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &hist[i]);
  }

  // Calculate and print the maximum area
  long long area = maxArea(hist, n);
  printf("%lld\n", area);

  // Free the allocated memory
  free(hist);

  return 0;
}