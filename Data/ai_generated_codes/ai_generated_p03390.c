#include <stdio.h>
#include <math.h>

// Function to calculate the maximum possible number of participants with smaller scores
long long calculate_smaller_scores(long long A, long long B) {
  // Calculate the maximum possible rank in the second contest for participants with smaller scores
  long long max_second_rank = B - 1; 
  // Calculate the maximum possible number of participants with smaller scores
  long long smaller_scores = (max_second_rank * (A - 1));
  // Return the result
  return smaller_scores;
}

int main() {
  // Number of queries
  int Q;
  scanf("%d", &Q);

  // Process each query
  for (int i = 0; i < Q; i++) {
    // Read the ranks of Takahashi in the two contests
    long long A, B;
    scanf("%lld %lld", &A, &B);
    
    // Calculate and print the maximum possible number of participants with smaller scores
    printf("%lld\n", calculate_smaller_scores(A, B));
  }

  return 0;
}