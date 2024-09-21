#include <stdio.h>

int main() {
  // k: length of the sequence d
  // q: number of queries
  int k, q;
  scanf("%d %d", &k, &q);

  // d: the sequence of k numbers
  int d[5000];
  for (int i = 0; i < k; i++) {
    scanf("%d", &d[i]);
  }

  // Process each query
  for (int i = 0; i < q; i++) {
    // n: length of the sequence a
    // x: the initial value of a
    // m: the modulus for the comparison
    int n, x, m;
    scanf("%d %d %d", &n, &x, &m);

    // count: the number of pairs (a_j, a_j+1) that satisfy the condition
    int count = 0;

    // a_j: the current element of the sequence a
    int a = x;

    // Iterate through the sequence a, starting from the second element
    for (int j = 1; j < n; j++) {
      // Calculate the next element of the sequence a
      a = (a + d[(j - 1) % k]) % k;

      // Compare the current and next element modulo m
      if ((a % m) < ((a + d[j % k]) % m)) {
        count++;
      }
    }

    // Print the count for the current query
    printf("%d\n", count);
  }

  return 0;
}