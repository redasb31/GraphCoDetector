#include <stdio.h>

int main() {
  int n; // length of the sequence
  scanf("%d", &n); // read the length of the sequence

  int v[100000]; // array to store the sequence elements
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]); // read the elements of the sequence
  }

  int count[100001] = {0}; // array to count the frequency of each element
  for (int i = 0; i < n; i++) {
    count[v[i]]++; // increment the count of the element v[i]
  }

  int num_distinct = 0; // count the number of distinct elements
  for (int i = 1; i <= 100000; i++) {
    if (count[i] > 0) {
      num_distinct++; // increment the count of distinct elements if the count of element i is greater than 0
    }
  }

  int min_replacements = 0; // initialize the minimum number of replacements to 0

  // if the number of distinct elements is not 2, or if the sequence is not alternating, we need to make replacements
  if (num_distinct != 2 || (n > 2 && v[0] != v[2])) { 
    min_replacements = n / 2; // we can make the sequence alternating by replacing half of the elements
  } else {
    // if the sequence is already alternating, we only need to replace elements that are not in the correct position
    for (int i = 0; i < n - 1; i += 2) {
      if (v[i] != v[i + 1]) {
        min_replacements++; // increment the count of replacements if the adjacent elements are not equal
      }
    }
  }

  printf("%d\n", min_replacements); // print the minimum number of replacements
  return 0; // return 0 to indicate successful execution
}