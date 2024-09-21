#include <stdio.h>
#include <stdlib.h>

// Function to check if a given permutation is sorted
int is_sorted(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to simulate the sorting network
int check_network(int n, int d, int wiring[][100]) {
  int *input = malloc(sizeof(int) * n);
  int *output = malloc(sizeof(int) * n);

  // Initialize input with numbers 1 to n
  for (int i = 0; i < n; i++) {
    input[i] = i + 1;
  }

  // Simulate each stage of the network
  for (int stage = 0; stage < d; stage++) {
    // Apply wiring to the input
    for (int i = 0; i < n; i++) {
      output[i] = input[wiring[stage][i] - 1];
    }
    // Swap the input and output arrays
    int *temp = input;
    input = output;
    output = temp;
  }

  // Check if the output is sorted
  int sorted = is_sorted(input, n);

  free(input);
  free(output);

  return sorted;
}

int main() {
  int n, d;
  scanf("%d %d", &n, &d);

  int wiring[100][100];

  // Read wiring information
  for (int i = 0; i < d - 1; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &wiring[i][j]);
    }
  }

  // Check if the network is valid
  if (check_network(n, d, wiring)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}