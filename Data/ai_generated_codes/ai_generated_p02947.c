#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int isAnagram(char *str1, char *str2) {
  // If the lengths are different, they cannot be anagrams
  if (strlen(str1) != strlen(str2)) {
    return 0;
  }

  // Create a frequency array for both strings
  int freq1[26] = {0};
  int freq2[26] = {0};

  // Count the frequency of each character in str1
  for (int i = 0; str1[i] != '\0'; i++) {
    freq1[str1[i] - 'a']++;
  }

  // Count the frequency of each character in str2
  for (int i = 0; str2[i] != '\0'; i++) {
    freq2[str2[i] - 'a']++;
  }

  // Compare the frequency arrays
  for (int i = 0; i < 26; i++) {
    if (freq1[i] != freq2[i]) {
      return 0;
    }
  }

  // If all frequencies match, they are anagrams
  return 1;
}

int main() {
  int N;
  scanf("%d", &N);

  // Array to store the strings
  char strings[100005][11];

  // Read the strings
  for (int i = 0; i < N; i++) {
    scanf("%s", strings[i]);
  }

  // Count the number of anagram pairs
  int count = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      // Check if strings[i] and strings[j] are anagrams
      if (isAnagram(strings[i], strings[j])) {
        count++;
      }
    }
  }

  // Print the count
  printf("%d\n", count);

  return 0;
}