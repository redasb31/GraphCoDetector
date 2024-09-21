#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 30
#define MAX_K 30
#define MAX_M 50
#define MAX_Q 100000
#define INF LLONG_MAX

typedef long long ll;

// Structure to represent a jewel
typedef struct {
  ll size;
  ll price;
  ll count;
} Jewel;

// Structure to represent a shop
typedef struct {
  int K;
  Jewel jewels[MAX_K];
} Shop;

// Structure to represent a restriction
typedef struct {
  int U;
  int V;
  ll W;
} Restriction;

// Function to perform binary search on a sorted array of jewels
// Returns the index of the first jewel whose size is greater than or equal to the given size
int binarySearch(Jewel jewels[], int start, int end, ll size) {
  if (start > end) {
    return -1;
  }
  int mid = (start + end) / 2;
  if (jewels[mid].size >= size) {
    if (mid == 0 || jewels[mid - 1].size < size) {
      return mid;
    } else {
      return binarySearch(jewels, start, mid - 1, size);
    }
  } else {
    return binarySearch(jewels, mid + 1, end, size);
  }
}

// Function to calculate the minimum total price of jewels required to make a good jewelry box
ll calculateMinPrice(Shop shops[], Restriction restrictions[], int N, int M, ll boxSize) {
  // Create a 2D array to store the minimum price to make a good jewelry box
  // for each shop with a given size constraint
  ll dp[MAX_N + 1][boxSize + 1];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= boxSize; j++) {
      dp[i][j] = INF;
    }
  }

  // Initialize the base case: no shops, no size constraint
  dp[0][0] = 0;

  // Iterate through each shop
  for (int i = 1; i <= N; i++) {
    // Iterate through each size constraint
    for (int j = 0; j <= boxSize; j++) {
      // Iterate through each jewel in the current shop
      for (int k = 0; k < shops[i - 1].K; k++) {
        // Calculate the size constraint for the next shop
        ll nextSize = j - shops[i - 1].jewels[k].size;

        // If the current jewel can be used and the next shop has enough jewels
        if (nextSize >= 0 && shops[i - 1].jewels[k].count > 0) {
          // Check if there is a restriction between the current shop and the next shop
          int valid = 1;
          for (int r = 0; r < M; r++) {
            if ((restrictions[r].U == i && restrictions[r].V == i - 1) ||
                (restrictions[r].V == i && restrictions[r].U == i - 1)) {
              if (restrictions[r].U == i && shops[i - 1].jewels[k].size <= dp[i - 1][nextSize] + restrictions[r].W) {
                valid = 0;
                break;
              } else if (restrictions[r].V == i && dp[i - 1][nextSize] <= shops[i - 1].jewels[k].size + restrictions[r].W) {
                valid = 0;
                break;
              }
            }
          }

          // If the current jewel is valid, update the minimum price
          if (valid) {
            dp[i][j] = min(dp[i][j], dp[i - 1][nextSize] + shops[i - 1].jewels[k].price);
          }
        }
      }
    }
  }

  // Return the minimum price to make a good jewelry box for all shops
  return dp[N][boxSize];
}

int main() {
  int N, M, Q;
  Shop shops[MAX_N];
  Restriction restrictions[MAX_M];
  ll A[MAX_Q];

  // Read the number of shops
  scanf("%d", &N);

  // Read the descriptions of each shop
  for (int i = 0; i < N; i++) {
    scanf("%d", &shops[i].K);
    for (int j = 0; j < shops[i].K; j++) {
      scanf("%lld %lld %lld", &shops[i].jewels[j].size, &shops[i].jewels[j].price, &shops[i].jewels[j].count);
    }
  }

  // Read the number of restrictions
  scanf("%d", &M);

  // Read the restrictions
  for (int i = 0; i < M; i++) {
    scanf("%d %d %lld", &restrictions[i].U, &restrictions[i].V, &restrictions[i].W);
  }

  // Read the number of queries
  scanf("%d", &Q);

  // Read the number of good jewelry boxes for each query
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &A[i]);
  }

  // Iterate through each query
  for (int i = 0; i < Q; i++) {
    // Calculate the minimum price for the current query
    ll minPrice = calculateMinPrice(shops, restrictions, N, M, A[i]);
    // If it is impossible to make a good jewelry box, print -1
    if (minPrice == INF) {
      printf("-1\n");
    } else {
      // Otherwise, print the minimum price
      printf("%lld\n", minPrice);
    }
  }

  return 0;
}