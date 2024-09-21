#include <stdio.h>
#include <string.h>

int main() {
  // Input variables
  int L; 
  char s[100001], t[100001]; 

  // Read the length L
  scanf("%d", &L);

  // Read the strings s and t
  scanf("%s %s", s, t);

  // Determine which string is lexicographically smaller
  char* smaller_string = (strcmp(s, t) < 0) ? s : t;
  char* larger_string = (strcmp(s, t) < 0) ? t : s;

  // Calculate the number of times the smaller string can be used
  int count_smaller = L / strlen(smaller_string);

  // Initialize the output string
  char output[100001] = "";

  // Fill the output string with repetitions of the smaller string
  for (int i = 0; i < count_smaller; i++) {
    strcat(output, smaller_string);
  }

  // If there are remaining characters, append the larger string
  int remaining_length = L - (count_smaller * strlen(smaller_string));
  if (remaining_length > 0) {
    strncat(output, larger_string, remaining_length);
  }

  // Print the lexicographically smallest string
  printf("%s\n", output);

  return 0;
}