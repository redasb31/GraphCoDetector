#include <stdio.h>

int main() {
  // Input the number of elements in the sequence
  int N;
  scanf("%d", &N);

  // Declare an array to store the sequence
  int A[200000];

  // Input the elements of the sequence
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize a counter for the number of integers with the property
  int count = 0;

  // Iterate through each element of the sequence
  for (int i = 0; i < N; i++) {
    // Initialize a flag to indicate if the element has the property
    int hasProperty = 1;

    // Iterate through the other elements of the sequence
    for (int j = 0; j < N; j++) {
      // If the current element is not the same as the element being checked and the current element divides the element being checked, then the element being checked does not have the property
      if (i != j && A[j] != 0 && A[i] % A[j] == 0) {
        hasProperty = 0;
        break;
      }
    }

    // If the element has the property, increment the counter
    if (hasProperty) {
      count++;
    }
  }

  // Print the count of integers with the property
  printf("%d\n", count);

  return 0;
}