#include <stdio.h>

#define SIZE 50

int main()
{
  int cnt;
  int N, K;
  int A[SIZE] = {0,};
  int A_COPY[SIZE] = {0,};
  int min = 101;
  int max = 0;
  int min_index = 0;
  int i,j;
  int q = 0;
  int k;
  int ok = 0;

  cnt = scanf("%d %d", &N, &K);

  for (i=0; i<N; i++) {
    cnt = scanf("%d", &A[i]);
    A_COPY[i] = A[i];
    if (min > A[i]) {
      min = A[i];
      min_index = i;
    }
    if (max < A[i]) max = A[i];
  }

  for (i=min; i<max; i++) {
    for(j=0; j<N; j++) {
      if (A_COPY[j] > min) {
        A_COPY[j]--;
        q++;
      }
    }
  }

  ok = 0;
  k = K;
  for (i=0; i<min; i++) {
    q += N;
    if (k == 0){
      ok = 1;
      break;
    }
    k--;
  }
  if (ok == 0) {
    printf("-1");
    return 0;
  }

  k = K;
  printf("%d\n", q);

  for (i=min; i<max; i++) {
    for(j=0; j<N; j++) {
      if (A[j] > min) {
        A[j]--;
        printf("%d ", (j+1));
      }
    }
  }
  
  for (i=0; i<min; i++) {
    for (j=0; j<N; j++) {
      if (j == min_index) continue;
      printf("%d ", (j+1));
    }
    printf("%d ", (min_index+1));
    if (k <= 0) break;
    k--;
  }

  return 0;
} 