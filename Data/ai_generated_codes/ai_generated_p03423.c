#include <stdio.h>

int main() {
  // N: Number of students
  int N;

  // Input the number of students
  scanf("%d", &N);

  // Calculate the maximum number of groups with 3 or more students
  // We can form N/3 groups of 3 students, and the remaining students 
  // will be in groups of 2 or less.
  int max_groups = N / 3; 

  // Print the result
  printf("%d\n", max_groups);

  return 0;
}