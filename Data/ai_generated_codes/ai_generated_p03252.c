#include <stdio.h>
#include <string.h>

int main() {
  char S[200001];
  char T[200001];

  // Input the strings S and T
  scanf("%s", S);
  scanf("%s", T);

  // Check if the lengths of S and T are equal
  if (strlen(S) != strlen(T)) {
    printf("No\n");
    return 0;
  }

  // Create an array to store the frequency of each character in S and T
  int freq_S[26] = {0};
  int freq_T[26] = {0};

  // Calculate the frequency of each character in S
  for (int i = 0; i < strlen(S); i++) {
    freq_S[S[i] - 'a']++;
  }

  // Calculate the frequency of each character in T
  for (int i = 0; i < strlen(T); i++) {
    freq_T[T[i] - 'a']++;
  }

  // Compare the frequencies of each character in S and T
  // If the frequencies are not the same, the strings cannot be made equal
  for (int i = 0; i < 26; i++) {
    if (freq_S[i] != freq_T[i]) {
      printf("No\n");
      return 0;
    }
  }

  // If the frequencies are the same, the strings can be made equal
  printf("Yes\n");

  return 0;
}