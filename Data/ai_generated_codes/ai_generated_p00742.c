#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 13
#define MAX_LEN 9
#define MAX_CHARS 11

int strings[MAX_STRINGS][MAX_LEN];
char str[MAX_STRINGS][MAX_LEN];
int char_to_digit[26];
int num_chars;

// Function to check if a digit assignment is valid
int valid_assignment(int string_count) {
  int sum = 0;
  for (int i = 0; i < string_count - 1; i++) {
    int num = 0;
    for (int j = 0; j < strlen(str[i]); j++) {
      num = num * 10 + char_to_digit[str[i][j] - 'A'];
    }
    sum += num;
  }

  int target_num = 0;
  for (int j = 0; j < strlen(str[string_count - 1]); j++) {
    target_num = target_num * 10 + char_to_digit[str[string_count - 1][j] - 'A'];
  }

  return sum == target_num;
}

// Recursive function to try all possible digit assignments
void backtrack(int index, int string_count) {
  if (index == num_chars) {
    if (valid_assignment(string_count)) {
      // Increment the count of valid assignments
      // (This would be where you print the case number if needed)
    }
    return;
  }

  // Assign digits from 0 to 9
  for (int i = 0; i <= 9; i++) {
    char_to_digit[index] = i;

    // Check if the most significant digit is 0
    if (index == 0 && i == 0 && string_count > 1) {
      continue;
    }

    // Recursively try assignments for the next character
    backtrack(index + 1, string_count);
  }
}

int main() {
  int string_count;
  while (scanf("%d", &string_count) != EOF && string_count != 0) {
    // Read the strings
    for (int i = 0; i < string_count; i++) {
      scanf("%s", str[i]);
    }

    // Initialize the char_to_digit array
    num_chars = 0;
    for (int i = 0; i < string_count; i++) {
      for (int j = 0; j < strlen(str[i]); j++) {
        if (char_to_digit[str[i][j] - 'A'] == 0) {
          char_to_digit[str[i][j] - 'A'] = -1;
          num_chars++;
        }
      }
    }

    // Start backtracking
    backtrack(0, string_count);

    // Print the number of valid assignments
    printf("%d\n", valid_assignment(string_count));
  }

  return 0;
}