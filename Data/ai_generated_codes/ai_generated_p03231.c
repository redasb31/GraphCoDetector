#include <stdio.h>
#include <string.h>

// Function to find the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

// Function to check if a good string exists and return the length of the shortest one
int find_good_string(int N, int M, char *S, char *T) {
  // Calculate the least common multiple of N and M
  int L = lcm(N, M);

  // Check if the lengths of S and T are compatible with L
  if (L % N != 0 || L % M != 0) {
    return -1; 
  }

  // Iterate through the string S and check if it matches the pattern derived from L
  int i;
  for (i = 0; i < N; i++) {
    if (S[i] != T[i * (M / N) % M]) {
      return -1; 
    }
  }

  // If all checks pass, return the LCM as the length of the shortest good string
  return L; 
}

int main() {
  int N, M;
  char S[100005], T[100005];

  // Read the input values
  scanf("%d %d", &N, &M);
  scanf("%s", S);
  scanf("%s", T);

  // Call the function to find the length of the shortest good string
  int length = find_good_string(N, M, S, T);

  // Print the result
  printf("%d\n", length); 

  return 0;
}