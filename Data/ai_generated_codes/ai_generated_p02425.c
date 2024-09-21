#include <stdio.h>
#include <stdint.h>

// Function to test the i-th bit
int test(uint64_t state, int i) {
  return (state >> i) & 1;
}

// Function to set the i-th bit
uint64_t set(uint64_t state, int i) {
  return state | (1ULL << i);
}

// Function to clear the i-th bit
uint64_t clear(uint64_t state, int i) {
  return state & ~(1ULL << i);
}

// Function to flip the i-th bit
uint64_t flip(uint64_t state, int i) {
  return state ^ (1ULL << i);
}

// Function to check if all bits are set
int all(uint64_t state) {
  return state == (1ULL << 64) - 1;
}

// Function to check if at least one bit is set
int any(uint64_t state) {
  return state != 0;
}

// Function to check if all bits are unset
int none(uint64_t state) {
  return state == 0;
}

// Function to count the number of set bits
int count(uint64_t state) {
  int count = 0;
  while (state) {
    count += state & 1;
    state >>= 1;
  }
  return count;
}

// Function to get the decimal value of the state
uint64_t val(uint64_t state) {
  return state;
}

int main() {
  int q;
  scanf("%d", &q);

  // Initialize the state to all off
  uint64_t state = 0;

  // Process each query
  for (int i = 0; i < q; i++) {
    int operation, index;
    scanf("%d %d", &operation, &index);

    switch (operation) {
      case 0: // test(i)
        printf("%d\n", test(state, index));
        break;
      case 1: // set(i)
        state = set(state, index);
        break;
      case 2: // clear(i)
        state = clear(state, index);
        break;
      case 3: // flip(i)
        state = flip(state, index);
        break;
      case 4: // all
        printf("%d\n", all(state));
        break;
      case 5: // any
        printf("%d\n", any(state));
        break;
      case 6: // none
        printf("%d\n", none(state));
        break;
      case 7: // count
        printf("%d\n", count(state));
        break;
      case 8: // val
        printf("%llu\n", val(state));
        break;
    }
  }

  return 0;
}