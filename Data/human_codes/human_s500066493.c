#include<stdio.h>
#include<string.h>

int main(void)
{
  int A[4];
  int B[4];
  int hit, blow;
  int i, j;

  hit = blow = 0;

  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));

  while(scanf("%d %d %d %d", &A[0], &A[1], &A[2], &A[3]) != EOF){
    for (i = 0;i < 4;i++){
      scanf("%d", &B[i]);
    }

    for (i = 0;i < 4;i++){
      if (A[i] == B[i]){
	hit++;
      }
    }

    for (i = 0;i < 4;i++){
      for (j = 0;j < 4;j++){
	if(A[i] == B[j]){
	  blow++;
	}
      }
    }
  
    printf("%d %d\n", hit, blow - hit);
    
    hit = blow = 0;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
  }

  return 0;
}