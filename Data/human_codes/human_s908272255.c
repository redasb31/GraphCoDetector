#include <stdio.h>
#include <limits.h>

int n;
int mins[270000];

void update(int ul, int ur, int val, int k, int nl, int nr) {
  if (ur < nl || ul > nr)
    return;
  else if (ul <= nl && ur >= nr)
    mins[k] = val;
  else {
    if (mins[k] >= 0) {
      update(nl, nr, mins[k], 2 * k + 1, nl, (nl + nr) / 2);
      update(nl, nr, mins[k], 2 * k + 2, (nl + nr) / 2 + 1, nr);
      mins[k] = -1;
    }
    update(ul, ur, val, 2 * k + 1, nl, (nl + nr) / 2);
    update(ul, ur, val, 2 * k + 2, (nl + nr) / 2 + 1, nr);
  }
}

int min(int n1, int n2) {
  return n1 < n2 ? n1 : n2;
}

int find(int sl, int sr, int nodeID, int nl, int nr) {
  if (sr < nl || sl > nr)
    return INT_MAX;
  else {
    if (mins[nodeID] != -1)
      return mins[nodeID];
    else {
      int left = find(sl, sr, 2 * nodeID + 1, nl, (nl + nr) / 2);
      int right = find(sl, sr, 2 * nodeID + 2, (nl + nr) / 2 + 1, nr);
      return min(left, right);
    }
  }
}

int main() {
  int q, i, j, query, counter, cur, leaves, k, val;

  scanf("%d %d", &n, &q);

  for (leaves = 1; leaves < n; leaves *= 2);

  for (counter = 0; counter < leaves * 2 - 2; counter++)
    mins[counter] = INT_MAX;

  for (counter = 0; counter < q; counter++) {
    scanf("%d", &query);

    if (query) {
      scanf("%d %d", &i, &j);
      printf("%d\n", find(i, j, 0, 0, leaves - 1));
    } else {
      scanf("%d %d %d", &i, &j, &val);
      update(i, j, val, 0, 0, leaves - 1);
    }
  }
}

