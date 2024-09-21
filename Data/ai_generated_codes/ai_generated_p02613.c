#include <stdio.h>
#include <string.h>

int main() {
  // N: number of test cases
  int N;
  scanf("%d", &N);

  // Counters for each verdict
  int AC_count = 0;
  int WA_count = 0;
  int TLE_count = 0;
  int RE_count = 0;

  // Loop through each test case
  for (int i = 0; i < N; i++) {
    char verdict[5];
    scanf("%s", verdict);

    // Increment the corresponding counter based on the verdict
    if (strcmp(verdict, "AC") == 0) {
      AC_count++;
    } else if (strcmp(verdict, "WA") == 0) {
      WA_count++;
    } else if (strcmp(verdict, "TLE") == 0) {
      TLE_count++;
    } else if (strcmp(verdict, "RE") == 0) {
      RE_count++;
    }
  }

  // Print the results in the specified format
  printf("AC x %d\n", AC_count);
  printf("WA x %d\n", WA_count);
  printf("TLE x %d\n", TLE_count);
  printf("RE x %d\n", RE_count);

  return 0;
}