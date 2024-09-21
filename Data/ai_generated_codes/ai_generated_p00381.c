#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of paths from start to end
long long count_paths(char *entrance, char *exit, int start, int end) {
  // Base case: If we've reached the end
  if (start == end) {
    return 1;
  }

  // Initialize the count of paths to 0
  long long count = 0;

  // Iterate over all possible next stars
  for (int i = start + 1; i <= end; i++) {
    // If the entrance and exit letters match or the entrance is before the exit
    if (entrance[start] == exit[i] || entrance[start] < exit[i]) {
      // Recursively calculate the number of paths from the next star to the end
      count = (count + count_paths(entrance, exit, i, end)) % MOD;
    }
  }

  // Return the total count of paths
  return count;
}

int main() {
  int n;
  char entrance[100001], exit[100001];

  // Read the number of stars
  scanf("%d", &n);

  // Read the entrance and exit letters
  scanf("%s", entrance);
  scanf("%s", exit);

  // Calculate the number of paths from star 1 to star n
  long long result = count_paths(entrance, exit, 1, n);

  // Print the result modulo 1000000007
  printf("%lld\n", result);

  return 0;
}