#include <stdio.h>
#include <stdlib.h>

#define N 8

int main(void){
  int i, j, k, n, max, min;
  char tmp, num[N+1];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s", num);
    for(j = N-1; j > 0; j--){
      for(k = 0; k < j; k++){
	if(num[k] > num[k+1]){
	  tmp = num[k];
	  num[k] = num[k+1];
	  num[k+1] = tmp;
	}
      }
    }
    min = atoi(num);
    for(j = 0; j < N/2; j++){
      tmp = num[j];
      num[j] = num[N-1-j];
      num[N-1-j] = tmp;
    }
    max = atoi(num);
    printf("%d\n", max-min);
  }
  return 0;
}