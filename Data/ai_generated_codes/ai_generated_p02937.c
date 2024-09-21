#include <stdio.h>
#include <string.h>

int main() {
  char s[100005], t[100005];
  scanf("%s", s);
  scanf("%s", t);

  // Length of strings
  int s_len = strlen(s);
  int t_len = strlen(t);

  // Initialize pointers for s and t
  int s_ptr = 0;
  int t_ptr = 0;

  // Loop through the string s
  int i;
  for (i = 0; i < s_len; i++) {
    // If current character in s matches the current character in t
    if (s[s_ptr] == t[t_ptr]) {
      // Move to the next character in t
      t_ptr++;
      // If we have reached the end of t, we have found a subsequence
      if (t_ptr == t_len) {
        // Print the minimum i
        printf("%d\n", i + 1);
        return 0;
      }
    }
    // Move to the next character in s
    s_ptr = (s_ptr + 1) % s_len;
  }
  // If we haven't found a subsequence by now, t is not a subsequence of s'
  printf("-1\n");
  return 0;
}