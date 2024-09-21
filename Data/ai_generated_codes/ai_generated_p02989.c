#include <stdio.h>

int main() {
  // N: Number of problems
  int N;
  // d: Array to store the difficulty of each problem
  int d[100000];
  // count: Counter for the number of problems with difficulty >= K
  int count;
  // choices: Counter for the number of valid choices for K
  int choices = 0;

  // Read the input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &d[i]);
  }

  // Iterate through all possible values of K
  for (int K = 1; K <= 100000; K++) {
    // Reset the count for each value of K
    count = 0;
    // Count the number of problems with difficulty >= K
    for (int i = 0; i < N; i++) {
      if (d[i] >= K) {
        count++;
      }
    }
    // If the number of problems for ARCs and ABCs are the same, increment choices
    if (count == N / 2) {
      choices++;
    }
  }

  // Print the number of choices
  printf("%d\n", choices);

  return 0;
}