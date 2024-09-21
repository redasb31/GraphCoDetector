#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to set the i-th bit of a given integer to 1
unsigned long long setBit(unsigned long long num, int i) {
  return num | (1ULL << i); // Use 'ULL' for unsigned long long
}

// Function to clear the i-th bit of a given integer to 0
unsigned long long clearBit(unsigned long long num, int i) {
  return num & (~(1ULL << i)); // Use 'ULL' for unsigned long long
}

// Function to flip the i-th bit of a given integer
unsigned long long flipBit(unsigned long long num, int i) {
  return num ^ (1ULL << i); // Use 'ULL' for unsigned long long
}

// Function to check if the i-th bit of a given integer is set
int testBit(unsigned long long num, int i) {
  return (num >> i) & 1;
}

int main() {
  int n, q;
  scanf("%d", &n);

  // Allocate memory for masks
  unsigned long long* masks = (unsigned long long*)malloc(n * sizeof(unsigned long long));
  if (masks == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  // Read masks
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    masks[i] = 0; // Initialize masks to 0
    for (int j = 0; j < k; j++) {
      int b;
      scanf("%d", &b);
      masks[i] = setBit(masks[i], b); // Set the bits specified in the mask
    }
  }

  scanf("%d", &q);

  // Process queries
  for (int i = 0; i < q; i++) {
    int op, arg;
    scanf("%d %d", &op, &arg);

    switch (op) {
      case 0: // test(i)
        printf("%d\n", testBit(masks[0], arg));
        break;
      case 1: // set(m)
        masks[0] = setBit(masks[0], arg);
        break;
      case 2: // clear(m)
        masks[0] = clearBit(masks[0], arg);
        break;
      case 3: // flip(m)
        masks[0] = flipBit(masks[0], arg);
        break;
      case 4: // all(m)
        printf("%d\n", (masks[arg] & masks[0]) == masks[arg]);
        break;
      case 5: // any(m)
        printf("%d\n", (masks[arg] & masks[0]) != 0);
        break;
      case 6: // none(m)
        printf("%d\n", (masks[arg] & masks[0]) == 0);
        break;
      case 7: // count(m)
        {
          int count = 0;
          for (int j = 0; j < 64; j++) {
            if (testBit(masks[arg], j)) {
              count++;
            }
          }
          printf("%d\n", count);
        }
        break;
      case 8: // val(m)
        printf("%llu\n", masks[arg]);
        break;
    }
  }

  // Free allocated memory
  free(masks);

  return 0;
}