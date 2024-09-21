#include <stdio.h>

int main() {
  // n: length of the sequence
  // m: number of requests
  int n, m;

  // Read the length of the sequence and the number of requests
  scanf("%d %d", &n, &m);

  // Create an array to store the sequence
  int sequence[n + 1];

  // Initialize the sequence with numbers 1 to n
  for (int i = 1; i <= n; i++) {
    sequence[i] = i;
  }

  // Read the requests
  int request;
  for (int i = 0; i < m; i++) {
    scanf("%d", &request);

    // Move the requested element to the head of the sequence
    // by swapping it with the element at the head
    int temp = sequence[1];
    sequence[1] = sequence[request];
    sequence[request] = temp;
  }

  // Print the sequence after processing all the requests
  for (int i = 1; i <= n; i++) {
    printf("%d\n", sequence[i]);
  }

  return 0;
}