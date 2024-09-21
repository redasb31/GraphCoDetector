#include <stdio.h>

int main() {
  int N; // Number of days
  scanf("%d", &N);

  // Declare arrays to store happiness points for each activity
  int a[N], b[N], c[N];

  // Read happiness points for each day
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
  }

  // Declare arrays to store maximum happiness achievable ending with each activity
  int dp_a[N], dp_b[N], dp_c[N];

  // Initialize for the first day
  dp_a[0] = a[0];
  dp_b[0] = b[0];
  dp_c[0] = c[0];

  // Dynamic programming approach to calculate maximum happiness
  for (int i = 1; i < N; i++) {
    // Calculate maximum happiness ending with activity A
    dp_a[i] = a[i] +  // Happiness from doing A on the current day
            max(dp_b[i - 1], dp_c[i - 1]); // Maximum happiness from previous day ending with B or C

    // Calculate maximum happiness ending with activity B
    dp_b[i] = b[i] +  // Happiness from doing B on the current day
            max(dp_a[i - 1], dp_c[i - 1]); // Maximum happiness from previous day ending with A or C

    // Calculate maximum happiness ending with activity C
    dp_c[i] = c[i] +  // Happiness from doing C on the current day
            max(dp_a[i - 1], dp_b[i - 1]); // Maximum happiness from previous day ending with A or B
  }

  // Find the maximum happiness among all activities on the last day
  int max_happiness = max(dp_a[N - 1], max(dp_b[N - 1], dp_c[N - 1]));

  printf("%d\n", max_happiness);

  return 0;
}

// Helper function to find the maximum of two integers
int max(int x, int y) {
  return (x > y) ? x : y;
}