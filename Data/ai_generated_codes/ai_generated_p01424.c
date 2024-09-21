#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 10
#define MAX_PAIRS 1000

int main() {
  // Declare variables for input
  int N, M; // Number of words and pairs
  char words[MAX_WORDS][MAX_WORD_LEN + 1]; // Array to store words
  int pairs[MAX_PAIRS][2]; // Array to store pairs

  // Read input
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", words[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &pairs[i][0], &pairs[i][1]);
  }

  // Create an adjacency matrix to represent the graph
  int graph[MAX_WORDS][MAX_WORDS] = {0};
  for (int i = 0; i < M; i++) {
    graph[pairs[i][0] - 1][pairs[i][1] - 1] = 1;
  }

  // Check if there are any cycles in the graph
  int visited[MAX_WORDS] = {0};
  int stack[MAX_WORDS] = {0};
  int top = -1;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      top = -1;
      stack[++top] = i;
      visited[i] = 1;

      while (top != -1) {
        int curr = stack[top];
        for (int j = 0; j < N; j++) {
          if (graph[curr][j] == 1 && !visited[j]) {
            stack[++top] = j;
            visited[j] = 1;
            break;
          } else if (graph[curr][j] == 1 && visited[j]) {
            // Cycle detected
            printf("-1\n");
            return 0;
          }
        }
        top--;
      }
    }
  }

  // Check if there is a word that can be used as a palindrome
  int palindrome_found = 0;
  for (int i = 0; i < N; i++) {
    if (graph[i][i] == 1) {
      palindrome_found = 1;
      break;
    }
  }

  // If no cycle and no palindrome word, then the maximum length is 0
  if (!palindrome_found) {
    printf("0\n");
    return 0;
  }

  // Calculate the maximum palindrome length
  int max_len = 1; // Minimum palindrome length is 1
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (graph[i][j] == 1) {
        // Check if the words can be extended to form a longer palindrome
        int len = 2; // Length of the palindrome
        int curr = j;
        while (graph[curr][i] == 1) {
          len += 2;
          curr = i;
          i = j;
          j = curr;
        }
        max_len = (len > max_len) ? len : max_len;
      }
    }
  }

  // Print the maximum length
  printf("%d\n", max_len);

  return 0;
}