#include <stdio.h>
#include <math.h>

// Function to calculate the number of configurations for a given number of people and clubs
long long count_configurations(long long n, long long k) {
  // If there are more clubs than people, there are no valid configurations
  if (k > n) {
    return 0;
  }
  
  // If there are no clubs, there's only one configuration (the empty set)
  if (k == 0) {
    return 1;
  }
  
  // Calculate the number of configurations recursively
  long long count = 0;
  for (long long i = 1; i <= n; i++) {
    count += count_configurations(n - i, k - 1);
  }
  
  return count;
}

int main() {
  long long n;
  
  // Read the number of people from standard input
  scanf("%lld", &n);
  
  // Find the minimum number of clubs required for a name-preserving configuration
  long long k = 1;
  while (count_configurations(n, k) <= 1) {
    k++;
  }
  
  // Calculate the number of configurations for the minimum number of clubs
  long long count = count_configurations(n, k);
  
  // Print the result to standard output
  if (count > 1000) {
    printf("-1\n");
  } else {
    printf("%lld\n", count);
  }
  
  return 0;
}