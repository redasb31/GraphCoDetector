#include <stdio.h>

int main() {
  // N: Number of books on Desk A
  // M: Number of books on Desk B
  // K: Maximum time allowed
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);

  // A: Reading time for each book on Desk A
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // B: Reading time for each book on Desk B
  int B[M];
  for (int i = 0; i < M; i++) {
    scanf("%d", &B[i]);
  }

  // Initialize pointers for Desk A and Desk B
  int a_ptr = 0;
  int b_ptr = 0;

  // Count the total number of books read
  int book_count = 0;

  // Time elapsed
  int time_elapsed = 0;

  // Greedily read books until time runs out
  while (time_elapsed <= K && (a_ptr < N || b_ptr < M)) {
    // Compare reading time for the top books on both desks
    if (a_ptr < N && b_ptr < M) {
      if (A[a_ptr] <= B[b_ptr]) {
        // Read the book from Desk A if it takes less time
        time_elapsed += A[a_ptr];
        a_ptr++;
        book_count++;
      } else {
        // Read the book from Desk B if it takes less time
        time_elapsed += B[b_ptr];
        b_ptr++;
        book_count++;
      }
    } else if (a_ptr < N) {
      // If only Desk A has books left, read them all
      time_elapsed += A[a_ptr];
      a_ptr++;
      book_count++;
    } else if (b_ptr < M) {
      // If only Desk B has books left, read them all
      time_elapsed += B[b_ptr];
      b_ptr++;
      book_count++;
    }
  }

  // Print the maximum number of books that can be read
  printf("%d\n", book_count);
  return 0;
}