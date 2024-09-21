#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to check if the audio signal can be recovered uniquely.
int check_unique(int *signal, int n, int broken_value) {
  // Check if there are consecutive broken samples.
  if (signal[0] == broken_value && signal[1] == broken_value) {
    return 0;
  }

  // Check if the audio signal is valid.
  for (int i = 1; i < n - 1; i++) {
    if (signal[i] == broken_value) {
      // Check if the broken sample is odd.
      if (i % 2 == 1) {
        // Check if the broken sample is smaller than its neighbors.
        if (signal[i - 1] >= broken_value || signal[i + 1] >= broken_value) {
          return 0;
        }
      } else {
        // Check if the broken sample is larger than its neighbors.
        if (signal[i - 1] <= broken_value || signal[i + 1] <= broken_value) {
          return 0;
        }
      }
    }
  }

  // Check if the last sample is broken.
  if (signal[n - 1] == broken_value) {
    // Check if the broken sample is odd.
    if ((n - 1) % 2 == 1) {
      // Check if the broken sample is smaller than its neighbor.
      if (signal[n - 2] >= broken_value) {
        return 0;
      }
    } else {
      // Check if the broken sample is larger than its neighbor.
      if (signal[n - 2] <= broken_value) {
        return 0;
      }
    }
  }

  // If all checks pass, the audio signal can be recovered uniquely.
  return 1;
}

// Function to find the possible values of the broken samples.
int find_values(int *signal, int n, int broken_value) {
  int min_value = INT_MAX;
  int max_value = INT_MIN;
  int count = 0;

  // Find the minimum and maximum values of the neighboring samples.
  for (int i = 1; i < n - 1; i++) {
    if (signal[i] == broken_value) {
      count++;
      if (i % 2 == 1) {
        // Find the minimum value of the neighboring samples.
        min_value = (min_value < signal[i - 1]) ? min_value : signal[i - 1];
        min_value = (min_value < signal[i + 1]) ? min_value : signal[i + 1];
      } else {
        // Find the maximum value of the neighboring samples.
        max_value = (max_value > signal[i - 1]) ? max_value : signal[i - 1];
        max_value = (max_value > signal[i + 1]) ? max_value : signal[i + 1];
      }
    }
  }

  // If there are no broken samples, return -1.
  if (count == 0) {
    return -1;
  }

  // If the minimum and maximum values are the same, there is only one possible value.
  if (min_value == max_value) {
    return min_value;
  }

  // If the minimum and maximum values are different, there are multiple possible values.
  return 0;
}

int main() {
  int n, broken_value;
  int *signal;

  // Read the input.
  while (scanf("%d", &n) != EOF && n != 0) {
    signal = (int *)malloc(sizeof(int) * n);

    // Read the audio signal.
    for (int i = 0; i < n; i++) {
      char input[10];
      scanf("%s", input);
      if (input[0] == 'x') {
        signal[i] = -1;
      } else {
        signal[i] = atoi(input);
      }
    }

    // Find the broken value.
    broken_value = signal[0];
    for (int i = 1; i < n; i++) {
      if (signal[i] != broken_value && signal[i] != -1) {
        broken_value = signal[i];
        break;
      }
    }

    // Check if the audio signal can be recovered uniquely.
    if (check_unique(signal, n, broken_value)) {
      // Find the possible values of the broken samples.
      int possible_value = find_values(signal, n, broken_value);

      // Print the output.
      if (possible_value == -1) {
        printf("none\n");
      } else if (possible_value == 0) {
        printf("ambiguous\n");
      } else {
        printf("%d\n", possible_value);
      }
    } else {
      printf("none\n");
    }

    free(signal);
  }

  return 0;
}