#include <stdio.h>

int main() {
  // n: length of the sequence
  int n;
  // v: array to store the sequence
  int v[100000];
  // count: number of elements to be replaced
  int count = 0;

  // Read the length of the sequence
  scanf("%d", &n);

  // Read the sequence
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  // Check if the sequence is already /
  // If it is, count = 0
  if (n >= 4) {
    for (int i = 0; i < n - 2; i += 2) {
      if (v[i] == v[i + 2]) {
        // If the sequence is already /, count = 0
        count = 0;
      } else {
        // If the sequence is not /, count = n/2
        count = n / 2;
        // Break the loop because the sequence is not /
        break;
      }
    }
  }

  // If the sequence is not /, calculate the number of elements to be replaced
  // Check if the sequence has only one unique element
  if (count != 0) {
    // Check if the sequence has only one unique element
    for (int i = 1; i < n; i++) {
      if (v[i] != v[0]) {
        // If the sequence has more than one unique element, count = n/2
        count = n / 2;
        // Break the loop because the sequence has more than one unique element
        break;
      }
    }
  }

  // Print the minimum number of elements that needs to be replaced
  printf("%d\n", count);

  return 0;
}