#include <stdio.h>
#include <string.h>

int main() {
  char S[100005];
  scanf("%s", S);
  int len = strlen(S);
  
  // Count the occurrences of each character
  int count_a = 0, count_b = 0, count_c = 0;
  for (int i = 0; i < len; i++) {
    if (S[i] == 'a') {
      count_a++;
    } else if (S[i] == 'b') {
      count_b++;
    } else {
      count_c++;
    }
  }

  // If any character appears more than half the length of the string, 
  // it is impossible to avoid a palindrome of length 2 or more
  if (count_a > len / 2 || count_b > len / 2 || count_c > len / 2) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }

  return 0;
}