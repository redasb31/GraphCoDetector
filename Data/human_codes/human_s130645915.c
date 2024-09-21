#include <stdio.h>
#define NMAX 10
#define FMAX 3628800
#define min(a, b) ((a) < (b) ? (a) : (b))

int hash(int *a, int asize);
void rev_sort(int l, int r, int *a, int asize);
void bfs(int *a, int asize, char *memo, int depth, int maxdepth);
int main (void)
{
  int i, n, maxdepth, fact = 1, res = 9, a[NMAX], b[NMAX];
  char memo1[FMAX], memo2[FMAX];
  scanf("%d", &n);
  maxdepth = (n - 1) / 2;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    fact *= i + 1;
    b[i] = i + 1;
  }
  for (i = 0; i < fact; i++) memo1[i] = memo2[i] = n;
  memo1[hash(a, n)] = memo2[hash(b, n)] = 0;
  bfs(a, n, memo1, 0, maxdepth);
  bfs(b, n, memo2, 0, maxdepth);
  for (i = 0; i < fact; i++) res = min(res, memo1[i] + memo2[i]);
  printf("%d\n", res);
}

int hash(int *a, int asize)
{
  int i, j, res = 0, fact = 1;
  for (i = 0; i < asize; i++) {
    int grade = 0;
    for (j = i + 1; j < asize; j++) if (a[i] < a[j]) grade++;
    res += grade * fact;
    fact *= asize - i;
  }
  return res;
}

void rev_sort(int l, int r, int *a, int asize)
{
  int i;
  for (i = 0; i < asize; i++) {
    int temp;
    if (l + i >= r - i) break;
    temp = a[l+i];
    a[l+i] = a[r-i];
    a[r-i] = temp;
  }
}

void bfs(int *a, int asize, char *memo, int depth, int maxdepth)
{
  int i, j;
  if (depth >= maxdepth) return;
  for (i = 0; i < asize; i++) {
    for (j = i + 1; j < asize; j++) {
      int h;
      rev_sort(i, j, a, asize);
      h = hash(a, asize);
      if (memo[h] > depth + 1) {
        memo[h] = depth + 1;
        bfs(a, asize, memo, depth + 1, maxdepth);
      }
      rev_sort(i, j, a, asize);
    }
  }
}
