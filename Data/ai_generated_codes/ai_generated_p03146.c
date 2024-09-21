#include <stdio.h>

int main() {
  // Input the initial value 's'
  int s;
  scanf("%d", &s);

  // Initialize an array to store the sequence 'a'
  int a[1000001];

  // Initialize the first element of the sequence
  a[1] = s;

  // Initialize the current index and the minimum index 'm'
  int i = 2, m = 1000001;

  // Calculate the sequence 'a' until a repetition is found
  while (i <= 1000000) {
    // Calculate the next element of the sequence based on the previous element
    if (a[i - 1] % 2 == 0) {
      a[i] = a[i - 1] / 2;
    } else {
      a[i] = 3 * a[i - 1] + 1;
    }

    // Check if the current element has already appeared in the sequence
    for (int j = 1; j < i; j++) {
      if (a[i] == a[j]) {
        // Update the minimum index 'm'
        m = i;
        // Stop the loop as the repetition is found
        i = 1000001;
        break;
      }
    }

    // Increment the index
    i++;
  }

  // Print the minimum index 'm'
  printf("%d\n", m);

  return 0;
}