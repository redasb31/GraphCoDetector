#include <stdio.h>

int main() {
  // n: number of students
  // t: time of concern
  int n, t;
  scanf("%d %d", &n, &t);

  // h: array to store health conditions of students
  int h[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }

  // current_item: array to store the current item number each student is on
  int current_item[n];
  for (int i = 0; i < n; i++) {
    current_item[i] = 1; // all students start with item 1
  }

  // time_taken: array to store the time taken by each student for their current item
  int time_taken[n];
  for (int i = 0; i < n; i++) {
    time_taken[i] = h[i]; // time taken for the first item is equal to their health condition
  }

  // Simulate the checkup process until the time t
  for (int i = 0; i < t; i++) {
    // For each student
    for (int j = 0; j < n; j++) {
      // If the student has finished their current item
      if (time_taken[j] == 0) {
        // Move to the next item
        current_item[j]++;
        // Time taken for the next item is equal to their health condition
        time_taken[j] = h[j];
      } else {
        // Decrease the time taken for the current item
        time_taken[j]--;
      }
    }
  }

  // Output the current item number for each student
  for (int i = 0; i < n; i++) {
    printf("%d\n", current_item[i]);
  }

  return 0;
}