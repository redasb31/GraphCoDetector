#include <stdio.h>
#include <limits.h>

int nums[270000], nums2[270000];
int leaves;

void add(int node, int l, int r, int nl, int nr, int val) {
  if (nl <= l && r <= nr) {
    nums[node] += val;
    nums2[node] += val;
  } else if (nl > r || l > nr) {
  
  } else {
    if (nums2[node]) {
      nums2[node * 2 + 1] += nums2[node];
      nums2[node * 2 + 2] += nums2[node];
      nums[node * 2 + 1] += nums2[node];
      nums[node * 2 + 2] += nums2[node];
      nums2[node] = 0;
    }
    add(node * 2 + 1, l, (l + r) / 2, nl, nr, val);
    add(node * 2 + 2, (l + r) / 2 + 1, r, nl, nr, val);
    
    if (nums[node * 2 + 1] < nums[node * 2 + 2])
      nums[node] = nums[node * 2 + 1];
    else
      nums[node] = nums[node * 2 + 2];
  }
}

int find(int node, int l, int r, int nl, int nr) {
  if (nl > r || l > nr)
    return INT_MAX;
  else if (nl <= l && r <= nr)
    return nums[node];
  else {
    if (nums2[node]) {
      nums2[node * 2 + 1] += nums2[node];
      nums2[node * 2 + 2] += nums2[node];
      nums[node * 2 + 1] += nums2[node];
      nums[node * 2 + 2] += nums2[node];
      nums2[node] = 0;
    }
    
    int leftVal = find(node * 2 + 1, l, (l + r) / 2, nl, nr);
    int rightVal = find(node * 2 + 2, (l + r) / 2 + 1, r, nl, nr);

    if (leftVal < rightVal)
      return leftVal;
    else
      return rightVal;
  }
}


int main() {
  int n, q, i, x, y, z, command;

  scanf("%d %d", &n, &q);

  for (leaves = 1; leaves < n; leaves *= 2);

  memset(nums, 0, sizeof(nums));
  memset(nums2, 0, sizeof(nums2));

  for (i = 0; i < q; i++) {
    scanf("%d %d %d", &command, &x, &y);

    if (command)
      printf("%d\n", find(0, 0, leaves, x, y));
    else {
      scanf("%d", &z);
      add(0, 0, leaves, x, y, z);
    }
  }
}

