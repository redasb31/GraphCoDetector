#include <stdio.h>
#include <math.h>

// Function to calculate the maximum number of participants with scores smaller than Takahashi's
long long calculate_max_participants(long long A, long long B) {
  // Calculate the maximum possible rank in the first contest for a participant to have a smaller score than Takahashi
  long long max_rank_first = B - 1; 
  // Calculate the maximum possible number of participants in the first contest with a smaller rank
  long long max_participants_first = max_rank_first; 
  
  // Calculate the maximum possible rank in the second contest for a participant to have a smaller score than Takahashi
  long long max_rank_second = A - 1; 
  // Calculate the maximum possible number of participants in the second contest with a smaller rank
  long long max_participants_second = max_rank_second; 

  // Return the maximum possible number of participants with a smaller score
  return max_participants_first + max_participants_second;
}

int main() {
  int Q; // Number of queries
  scanf("%d", &Q);

  for (int i = 0; i < Q; i++) {
    long long A, B; // Takahashi's ranks in the first and second contests
    scanf("%lld %lld", &A, &B);

    // Calculate and print the maximum number of participants with a smaller score
    printf("%lld\n", calculate_max_participants(A, B));
  }

  return 0;
}