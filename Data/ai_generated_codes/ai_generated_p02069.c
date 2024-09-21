#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
  long long int l;
  long long int r;
} Interval;

// Function to compare two intervals based on their left endpoint
int compareIntervals(const void *a, const void *b) {
  Interval *intervalA = (Interval *)a;
  Interval *intervalB = (Interval *)b;
  return intervalA->l - intervalB->l;
}

// Function to find the minimum number of intervals needed to cover [0, L)
long long int findMinIntervals(Interval *intervals, int n, long long int L) {
  long long int count = 0;
  long long int currentEnd = 0;
  int i = 0;

  while (currentEnd < L) {
    // Find the interval with the largest right endpoint that starts before or at currentEnd
    while (i < n && intervals[i].l <= currentEnd) {
      if (intervals[i].r > currentEnd) {
        currentEnd = intervals[i].r;
      }
      i++;
    }

    if (currentEnd == L) {
      break;
    }

    // No interval covers currentEnd, so we need to add one more interval
    count++;
  }

  return count;
}

// Function to find the minimum number of intervals needed to ensure all combinations cover [0, L)
long long int findMinCombinations(Interval *intervals, int n, long long int L) {
  long long int count = 0;
  long long int currentEnd = 0;
  int i = 0;

  while (currentEnd < L) {
    // Find the interval with the largest right endpoint that starts before or at currentEnd
    while (i < n && intervals[i].l <= currentEnd) {
      if (intervals[i].r > currentEnd) {
        currentEnd = intervals[i].r;
      }
      i++;
    }

    if (currentEnd == L) {
      break;
    }

    // No interval covers currentEnd, so we need to add one more interval
    count++;
    // Move to the next interval that starts after currentEnd
    while (i < n && intervals[i].l <= currentEnd) {
      i++;
    }
  }

  return count;
}

int main() {
  int n;
  long long int L;

  // Read the input
  scanf("%d %lld", &n, &L);

  Interval *intervals = (Interval *)malloc(n * sizeof(Interval));

  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &intervals[i].l, &intervals[i].r);
  }

  // Sort the intervals by their left endpoints
  qsort(intervals, n, sizeof(Interval), compareIntervals);

  // Calculate the minimum number of intervals and combinations
  long long int minIntervals = findMinIntervals(intervals, n, L);
  long long int minCombinations = findMinCombinations(intervals, n, L);

  // Print the output
  printf("%lld %lld\n", minIntervals, minCombinations);

  free(intervals);

  return 0;
}