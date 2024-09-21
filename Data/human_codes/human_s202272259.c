#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int i, j, k;
  int flag = 0;
  int data[501];
  int necessary[501];
  int result[250001];
  int output[501];
  
  for (i = 0; i < 501; i++) {
    necessary[i] = 0;
  }
  for (i = 0; i < 250001; i++) {
    result[i] = 0;
  }

  int N;

  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf(" %d", &data[i]);
  }

  for (i = 1; i < 501; i++) {
    output[i] = N;
  }

  int temp1, temp2, tempn;

  for (i = 1; i <= N; i++) {
    temp1 = 0;
    temp2 = 0;
    for (j = 1; j <= N; j++) {
      if (i == j) {
        temp1 += j - 1;
        temp2 += (N - j);
      }
      else if (data[j] < data[i]) {
        temp1 += j;
      } else {
        temp2 += (N - j + 1);
      }
    }
    if(temp1 > data[i]-1||temp2>(N*N-data[i])){
      flag = 1;
      break;
    }
    else {
      k = 1;
      while (output[i] > N-i+1  && data[i] > k) {
        if (result[k] == 0) {
          result[k] = i;
          output[i]--;
        }
        k++;
      }
      result[data[i]] = i;
      output[i]--;
    }
  }

  if (flag == 1) {
    printf("No");
  } else {
    printf("Yes\n");
    for (i = 1; i <= N; i++) {
      printf("%d\n", output[i]);
      k = output[i] + 1;
      while (output[i] > 0) {
        if (result[k] == 0) {
          result[k] = i;
          output[i]--;
        }
        k++;
      }
    }
    for (i = 1; i <= N * N; i++) {
      printf("%d ", result[i]);
    }
  }
  return 0;
}