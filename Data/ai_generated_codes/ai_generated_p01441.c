#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUERY_LEN 1000

// Function to check if a question text contains the query as a substring
bool containsSubstring(const char *questionText, const char *query) {
  return strstr(questionText, query) != NULL;
}

// Function to generate bigrams for a given string
void generateBigrams(const char *str, bool *bigrams) {
  int len = strlen(str);

  // Generate single-character bigrams
  for (int i = 0; i < len; i++) {
    bigrams[str[i]] = true;
  }

  // Generate two-character bigrams
  for (int i = 0; i < len - 1; i++) {
    bigrams[(str[i] << 8) | str[i + 1]] = true;
  }
}

// Function to check if a question text's bigrams contain all the query's bigrams
bool containsAllBigrams(bool *questionBigrams, bool *queryBigrams) {
  for (int i = 0; i < 256 * 256; i++) {
    if (queryBigrams[i] && !questionBigrams[i]) {
      return false;
    }
  }
  return true;
}

// Function to find the shortest question text length causing the issue
int findShortestLength(const char *query) {
  int minLength = MAX_QUERY_LEN + 1; // Initialize with a large value

  // Iterate over all possible question text lengths
  for (int len = 1; len <= MAX_QUERY_LEN; len++) {
    // Generate all possible question texts of length len
    for (int i = 0; i < (1 << (len * 8)); i++) {
      char questionText[MAX_QUERY_LEN + 1];
      int j = 0;
      for (int k = 0; k < len; k++) {
        questionText[j++] = (i >> (k * 8)) & 0xFF;
      }
      questionText[j] = '\0';

      // Check if the question text satisfies the criteria
      if (!containsSubstring(questionText, query) &&
          containsAllBigrams(questionText, query)) {
        // Update minimum length if necessary
        minLength = len;
        break; // No need to check longer texts for the same length
      }
    }
  }

  // Return the minimum length or "No Results" if no such text is found
  return minLength > MAX_QUERY_LEN ? -1 : minLength;
}

int main() {
  char query[MAX_QUERY_LEN + 1];

  while (true) {
    scanf("%s", query);
    if (query[0] == '#') {
      break;
    }

    // Generate bigrams for the query
    bool queryBigrams[256 * 256] = {false};
    generateBigrams(query, queryBigrams);

    // Find the shortest question text length
    int shortestLength = findShortestLength(query);

    // Print the result
    if (shortestLength == -1) {
      printf("No Results\n");
    } else {
      printf("%d\n", shortestLength);
    }
  }

  return 0;
}