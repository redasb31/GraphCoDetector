#include <stdio.h>

int main() {
  // N: Number of customers
  // T: Time of restaurant operation
  int N, T;
  scanf("%d %d", &N, &T);

  // Array to store entry and exit times of customers
  int l[100000], r[100000];

  // Read entry and exit times of each customer
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &l[i], &r[i]);
  }

  // Array to store the number of customers at each time
  int count[100000] = {0};

  // Update count for each customer's entry and exit
  for (int i = 0; i < N; i++) {
    count[l[i]]++; // Increment count at entry time
    count[r[i]]--; // Decrement count at exit time
  }

  // Calculate cumulative count to get the number of customers at each time
  int max_count = 0;
  for (int i = 1; i <= T; i++) {
    count[i] += count[i - 1];
    max_count = (count[i] > max_count) ? count[i] : max_count;
  }

  // Print the maximum number of customers
  printf("%d\n", max_count);

  return 0;
}