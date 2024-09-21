#include <stdio.h>
#include <string.h>

// Function to check if all characters are '0'
int allZeroes(char *s, int n) {
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') {
      return 0;
    }
  }
  return 1;
}

int main() {
  char s[100005];
  scanf("%s", s);
  int n = strlen(s);
  
  // Binary search for the maximum K
  int left = 1, right = n;
  int maxK = 0;
  while (left <= right) {
    int mid = (left + right) / 2;
    
    // Make a copy of the string to perform operations on
    char temp[100005];
    strcpy(temp, s);
    
    // Try to turn all characters into '0' using segments of length mid
    int flag = 1;
    for (int i = 0; i <= n - mid; i++) {
      // Invert characters in the segment
      for (int j = i; j < i + mid; j++) {
        if (temp[j] == '0') {
          temp[j] = '1';
        } else {
          temp[j] = '0';
        }
      }
      
      // Check if all characters are '0'
      if (allZeroes(temp, n)) {
        flag = 0;
        break;
      }
    }
    
    // Update binary search bounds
    if (flag == 0) {
      maxK = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  
  printf("%d\n", maxK);
  return 0;
}