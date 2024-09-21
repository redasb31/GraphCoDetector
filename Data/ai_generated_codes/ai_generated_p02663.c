#include <stdio.h>

int main() {
  // Input variables
  int H1, M1, H2, M2, K;

  // Read input from the user
  scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);

  // Calculate the total time in minutes Takahashi is up
  int total_minutes = (H2 * 60 + M2) - (H1 * 60 + M1);

  // Calculate the length of the period in which Takahashi can start studying
  int study_period_length = total_minutes - K;

  // Print the length of the study period
  printf("%d\n", study_period_length);

  return 0;
}