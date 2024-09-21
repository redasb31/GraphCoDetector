#include <stdio.h>

#define NSIZE 50
#define INFTY (1<<21)

void initW(int (*W)[NSIZE], int N, int *L)
{
  int i, j, weight;

  for (i = 0; i < N; i++)
  {
    weight = 0;
    for (j = i; j < N; j++)
    {
      weight += L[j];
      W[i][j] = weight;
    }
  }
}

void calc(int *A, int (*W)[NSIZE], int N, int index, int count, int *ans)
{
  int i, diff;
  for (i = index; i < N; i++)
  {
    A[count] = i;
    calc(A, W, N, i + 1, count + 1, ans);
    diff = getDiff(A, W, N, count);
    if (diff < *ans) *ans = diff;
  }  
}

int getDiff(int *A, int(*W)[NSIZE], int N, int count)
{
  int min, max, start, end, i, weight;

  min = INFTY;
  max = min * (-1);

  A[++count] = N;

  end = 0;
  for (i = 0; i <= count; i++)
  {
    start = end;
    end = A[i];
    weight = W[start][end-1];
    if (weight < min)
    {
      min = weight;
    }
    if (weight > max)
    {
      max = weight;
    }
  }
  return max - min;
}

int main()
{
  int i, N, ans;
  int L[NSIZE];
  int W[NSIZE][NSIZE];
  int A[NSIZE + 1];

  scanf("%d", &N);

  for (i = 0; i < N; i++)
  {
    scanf("%d", &L[i]);
  }

  initW(W,N,L);

  ans = INFTY;
  calc(A, W, N, 1, 0, &ans);

  printf("%d\n", ans);

  return 0;
}
