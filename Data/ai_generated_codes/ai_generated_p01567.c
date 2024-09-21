#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum number of paste operations
int calculate_paste_operations(char *tree) {
  // Base case: If the tree is a leaf node, no operations are required
  if (strcmp(tree, "()") == 0) {
    return 0;
  }

  // Calculate the number of operations for the left and right subtrees
  int left_operations = calculate_paste_operations(tree + 1);
  int right_operations = calculate_paste_operations(tree + strlen(tree) - 2);

  // Return the maximum of the left and right operations plus 1 (for pasting the subtrees)
  return 1 + (left_operations > right_operations ? left_operations : right_operations);
}

int main() {
  char tree[100000]; // Maximum size of the tree string

  // Read the input string representing the binary tree
  scanf("%s", tree);

  // Calculate and print the minimum number of paste operations
  printf("%d\n", calculate_paste_operations(tree));

  return 0;
}