#include <stdio.h>
#include <string.h>

int main() {
  // Read the number of people
  int N;
  scanf("%d", &N);

  // Initialize counters for each starting letter
  int M_count = 0;
  int A_count = 0;
  int R_count = 0;
  int C_count = 0;
  int H_count = 0;

  // Read each person's name and update the counters
  char S[11];
  for (int i = 0; i < N; i++) {
    scanf("%s", S);
    if (S[0] == 'M') {
      M_count++;
    } else if (S[0] == 'A') {
      A_count++;
    } else if (S[0] == 'R') {
      R_count++;
    } else if (S[0] == 'C') {
      C_count++;
    } else if (S[0] == 'H') {
      H_count++;
    }
  }

  // Calculate the number of ways to choose three people
  long long count = 0; // Use long long to handle large values
  count += (long long)M_count * (long long)A_count * (long long)R_count;
  count += (long long)M_count * (long long)A_count * (long long)C_count;
  count += (long long)M_count * (long long)A_count * (long long)H_count;
  count += (long long)M_count * (long long)R_count * (long long)C_count;
  count += (long long)M_count * (long long)R_count * (long long)H_count;
  count += (long long)M_count * (long long)C_count * (long long)H_count;
  count += (long long)A_count * (long long)R_count * (long long)C_count;
  count += (long long)A_count * (long long)R_count * (long long)H_count;
  count += (long long)A_count * (long long)C_count * (long long)H_count;
  count += (long long)R_count * (long long)C_count * (long long)H_count;

  // Print the result
  printf("%lld\n", count);

  return 0;
}