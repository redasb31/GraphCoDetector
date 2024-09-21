#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the factorial of a number modulo MOD
long long factorial(int n) {
  long long result = 1;
  for (int i = 2; i <= n; i++) {
    result = (result * i) % MOD;
  }
  return result;
}

// Function to calculate the number of trees satisfying the condition
long long countTrees(int n, int *d) {
  // Initialize a table to store the number of trees for each subtree rooted at a node
  long long *dp = (long long *)malloc(sizeof(long long) * (n + 1));
  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }

  // Base case: only one tree for a subtree with one node
  dp[1] = 1;

  // Iterate over the nodes from 2 to n
  for (int i = 2; i <= n; i++) {
    // Calculate the number of trees for the subtree rooted at node i
    for (int j = 1; j < i; j++) {
      // If the distance from node 1 to node i is one less than the distance from node 1 to node j,
      // then node i can be a child of node j in the subtree
      if (d[i] == d[j] - 1) {
        dp[i] = (dp[i] + dp[j]) % MOD;
      }
    }
  }

  // The number of trees for the entire tree is equal to the number of trees for the subtree rooted at node n
  long long result = dp[n];

  // Free the allocated memory
  free(dp);

  // Return the result
  return result;
}

int main() {
  // Read the input
  int n;
  scanf("%d", &n);
  int *d = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }

  // Calculate the number of trees
  long long answer = countTrees(n, d);

  // Calculate the factorial of n-1
  long long fact = factorial(n - 1);

  // Calculate the final answer by multiplying the number of trees with the factorial of n-1
  answer = (answer * fact) % MOD;

  // Print the answer
  printf("%lld\n", answer);

  // Free the allocated memory
  free(d);

  return 0;
}