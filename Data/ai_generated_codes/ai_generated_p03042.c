#include <stdio.h>

int main() {
  // Input the digit sequence S.
  char S[5];
  scanf("%s", S);

  // Extract the year and month components.
  int year = (S[0] - '0') * 10 + (S[1] - '0');
  int month1 = (S[2] - '0') * 10 + (S[3] - '0');
  int month2 = (S[0] - '0') * 10 + (S[1] - '0');

  // Check if the sequence is valid in YYMM format.
  int valid_yymm = (year >= 0 && year <= 99 && month1 >= 1 && month1 <= 12);

  // Check if the sequence is valid in MMYY format.
  int valid_mmyy = (month2 >= 1 && month2 <= 12 && year >= 0 && year <= 99);

  // Print the appropriate output based on the validity checks.
  if (valid_yymm && valid_mmyy) {
    printf("AMBIGUOUS\n"); // Valid in both formats
  } else if (valid_yymm) {
    printf("YYMM\n"); // Valid only in YYMM format
  } else if (valid_mmyy) {
    printf("MMYY\n"); // Valid only in MMYY format
  } else {
    printf("NA\n"); // Not valid in either format
  }

  return 0;
}