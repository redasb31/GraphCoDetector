#include <stdio.h>
#include <string.h>

#define MAX_N 16
#define MAX_K 15

int N, K;
char member_order[MAX_N + 1];
char thread_creators[MAX_N][MAX_K];
int visited_threads[MAX_N];

// Function to check if a given order of members is valid
int is_valid_order(char *order) {
  // Initialize visited threads for each member
  memset(visited_threads, 0, sizeof(visited_threads));
  
  // Iterate through each member in the order
  for (int i = 0; i < N; i++) {
    char current_member = order[i];
    // Iterate through the threads posted by the current member
    for (int j = 0; j < K; j++) {
      char thread_creator = thread_creators[current_member - 'A'][j];
      // Check if the thread has been visited before
      if (visited_threads[thread_creator - 'A']) {
        return 0; // Invalid order
      } else {
        // Mark the thread as visited
        visited_threads[thread_creator - 'A'] = 1;
      }
    }
  }
  return 1; // Valid order
}

// Function to find the lexicographically smallest valid order
void find_lexicographically_smallest_order() {
  // Initialize the order to the lexicographically smallest possible order
  for (int i = 0; i < N; i++) {
    member_order[i] = 'A' + i;
  }
  member_order[N] = '\0';
  
  // Generate all possible permutations of members
  while (1) {
    // Check if the current order is valid
    if (is_valid_order(member_order)) {
      return; // Found a valid order
    }
    
    // Find the next lexicographically greater order
    int i = N - 2;
    while (i >= 0 && member_order[i] >= member_order[i + 1]) {
      i--;
    }
    if (i < 0) {
      break; // All permutations have been checked
    }
    int j = N - 1;
    while (member_order[i] >= member_order[j]) {
      j--;
    }
    // Swap the characters at positions i and j
    char temp = member_order[i];
    member_order[i] = member_order[j];
    member_order[j] = temp;
    // Reverse the characters after position i
    for (int k = i + 1, l = N - 1; k < l; k++, l--) {
      temp = member_order[k];
      member_order[k] = member_order[l];
      member_order[l] = temp;
    }
  }
}

int main() {
  scanf("%d %d", &N, &K);
  // Read the thread creators for each member
  for (int i = 0; i < N; i++) {
    scanf("%s", thread_creators[i]);
  }
  
  // Find the lexicographically smallest valid order
  find_lexicographically_smallest_order();
  
  // Print the valid order
  printf("%s\n", member_order);
  
  return 0;
}