#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  // Stores the count of opening and closing brackets for each string
  int open_count[1000001] = {0};
  int close_count[1000001] = {0};

  // Stores the total count of opening and closing brackets
  int total_open = 0;
  int total_close = 0;

  char s[1000001];

  // Input and count brackets for each string
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    for (int j = 0; j < len; j++) {
      if (s[j] == '(') {
        open_count[i]++;
        total_open++;
      } else {
        close_count[i]++;
        total_close++;
      }
    }
  }

  // Check if the total count of opening and closing brackets are equal
  if (total_open != total_close) {
    printf("No\n");
    return 0;
  }

  // Check if a bracket sequence can be formed by concatenating the strings
  int current_open = 0;
  for (int i = 0; i < n; i++) {
    // Check if the current count of opening brackets exceeds the total count of closing brackets
    if (current_open + open_count[i] > total_close) {
      printf("No\n");
      return 0;
    }
    // Update the current count of opening brackets
    current_open += open_count[i];
    // Check if the current count of opening brackets is less than the total count of closing brackets
    if (current_open < close_count[i]) {
      printf("No\n");
      return 0;
    }
    // Update the current count of opening brackets after considering the closing brackets
    current_open -= close_count[i];
  }

  // If all conditions are met, a valid bracket sequence can be formed
  printf("Yes\n");
  return 0;
}