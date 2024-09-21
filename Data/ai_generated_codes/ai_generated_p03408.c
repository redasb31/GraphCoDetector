#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100
#define MAX_STR_LEN 10

int main() {
  int N, M;
  char s[MAX_N][MAX_STR_LEN + 1]; // Array to store blue cards strings
  char t[MAX_M][MAX_STR_LEN + 1]; // Array to store red cards strings
  int blue_count[MAX_STR_LEN + 1] = {0}; // Frequency count of blue cards strings
  int red_count[MAX_STR_LEN + 1] = {0}; // Frequency count of red cards strings

  // Input for number of blue and red cards
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", s[i]);
    // Increment the count for the corresponding string in blue_count
    blue_count[strlen(s[i])]++; 
  }

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%s", t[i]);
    // Increment the count for the corresponding string in red_count
    red_count[strlen(t[i])]++; 
  }

  int max_profit = 0;
  // Iterate through each possible string length
  for (int i = 1; i <= MAX_STR_LEN; i++) {
    // Calculate the profit for each string length
    int profit = blue_count[i] - red_count[i]; 
    // Update max_profit if the current profit is greater
    max_profit = (profit > max_profit) ? profit : max_profit; 
  }

  printf("%d\n", max_profit);
  return 0;
}