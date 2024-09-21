#include <stdio.h>
#include <string.h>

int is_palindrome(char *str, int start, int end) {
  // Function to check if a substring is a palindrome
  while (start < end) {
    if (str[start] != str[end]) {
      return 0;
    }
    start++;
    end--;
  }
  return 1;
}

int main() {
  char S[100];
  scanf("%s", S);

  int N = strlen(S);
  int mid = (N - 1) / 2;

  // Check if the entire string is a palindrome
  if (!is_palindrome(S, 0, N - 1)) {
    printf("No\n");
    return 0;
  }

  // Check if the first half is a palindrome
  if (!is_palindrome(S, 0, mid)) {
    printf("No\n");
    return 0;
  }

  // Check if the second half is a palindrome
  if (!is_palindrome(S, mid + 1, N - 1)) {
    printf("No\n");
    return 0;
  }

  printf("Yes\n");

  return 0;
}