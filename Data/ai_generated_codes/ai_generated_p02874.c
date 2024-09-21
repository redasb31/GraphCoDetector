#include <stdio.h>
#include <stdlib.h>

// Structure to represent a problem
typedef struct {
  int l;
  int r;
} Problem;

// Function to compare two problems based on their left endpoint
int compare_problems(const void *a, const void *b) {
  Problem *pa = (Problem *)a;
  Problem *pb = (Problem *)b;
  return pa->l - pb->l;
}

// Function to calculate the maximum joyfulness of two contests
long long calculate_max_joyfulness(Problem *problems, int n) {
  // Sort the problems based on their left endpoints
  qsort(problems, n, sizeof(Problem), compare_problems);

  // Initialize variables to track the current contest and its joyfulness
  int current_contest = 1;
  long long total_joyfulness = 0;
  int previous_right = 0;

  // Iterate through the problems
  for (int i = 0; i < n; i++) {
    // If the current problem's left endpoint is greater than the previous right endpoint,
    // it belongs to a new contest
    if (problems[i].l > previous_right) {
      current_contest++;
      previous_right = 0;
    }
    // Calculate the joyfulness of the current contest
    total_joyfulness += problems[i].r - problems[i].l + 1;
    // Update the previous right endpoint
    previous_right = problems[i].r;
  }

  return total_joyfulness;
}

int main() {
  int n;
  scanf("%d", &n);

  // Allocate memory for the problems
  Problem *problems = (Problem *)malloc(n * sizeof(Problem));
  if (problems == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  // Read the problems from the input
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &problems[i].l, &problems[i].r);
  }

  // Calculate and print the maximum joyfulness
  long long max_joyfulness = calculate_max_joyfulness(problems, n);
  printf("%lld\n", max_joyfulness);

  // Free the allocated memory
  free(problems);

  return 0;
}