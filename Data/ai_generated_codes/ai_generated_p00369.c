#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the difference between the largest and smallest values in a string
int calculate_difference(char *str) {
  int max = 0, min = 99999999; // Initialize min to a large value
  int len = strlen(str);
  
  for (int i = 0; i < len; i++) {
    // Convert char to integer
    int num = str[i] - '0';
    if (num > max) {
      max = num;
    }
    if (num < min) {
      min = num;
    }
  }
  return max - min;
}

// Function to find the minimum years
int find_min_years(char *str) {
  int len = strlen(str);
  int min_years = 99999999; // Initialize to a large value

  for (int i = 1; i < len; i++) {
    // Create substring from 0 to i
    char *left_str = malloc(i + 1);
    strncpy(left_str, str, i);
    left_str[i] = '\0';

    // Create substring from i to len
    char *right_str = malloc(len - i + 1);
    strcpy(right_str, str + i);

    // Calculate the difference for both substrings
    int diff1 = calculate_difference(left_str);
    int diff2 = calculate_difference(right_str);

    // Find the minimum difference between the two substrings
    int min_diff = (diff1 < diff2) ? diff1 : diff2;

    // Update the minimum years if the current difference is smaller
    if (min_diff < min_years) {
      min_years = min_diff;
    }

    free(left_str);
    free(right_str);
  }
  return min_years;
}

int main() {
  char str[100001];
  scanf("%s", str);
  int min_years = find_min_years(str);
  printf("%d\n", min_years);
  return 0;
}